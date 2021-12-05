//
// Created by Kefalin on 5. 12. 2021.
//
#include "knaz_interior.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Knaz_interier::mesh;
std::unique_ptr<ppgso::Shader> Knaz_interier::shader;
std::unique_ptr<ppgso::Texture> Knaz_interier::texture;

Knaz_interier::Knaz_interier() {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("kengura.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("kengura.obj");
    position = {0,-1,-20};
    scale = {0.02,0.02,0.02};
    rotation = {-1.57,0,-1.57};
}

bool Knaz_interier::update(Scene &scene, float dt) {
    position.z = position.z + 0.0003f;

    if (position.z > -2){
        position.z = -2;
    }
    generateModelMatrix();
    return true;
}

void Knaz_interier::render(Scene &scene) {
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
