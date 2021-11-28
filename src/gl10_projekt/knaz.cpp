//
// Created by Kefalin on 12. 11. 2021.
//
#include "knaz.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Knaz::mesh;
std::unique_ptr<ppgso::Shader> Knaz::shader;
std::unique_ptr<ppgso::Texture> Knaz::texture;

Knaz::Knaz() {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("kengura.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("kengura.obj");
    position = {0,0,-20};
    scale = {0.007,0.007,0.007};
    rotation = {-1.57,0,-1.57};
}

bool Knaz::update(Scene &scene, float dt) {
    position = {0,0,baseZ};
    baseZ = baseZ + 0.0003f;

    if (baseZ > -6){
        baseZ = -6;
        return false;
    }
    generateModelMatrix();
    return true;
}

void Knaz::render(Scene &scene) {
    shader->use();
    // Set up light
    shader->setUniform("LightDirection", scene.lightDirection);

    // use camera
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);

    // render mesh
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("Texture", *texture);
    mesh->render();
}
