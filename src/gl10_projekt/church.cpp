//
// Created by Kefalin on 12. 11. 2021.
//
#include "church.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Church::mesh;
std::unique_ptr<ppgso::Shader> Church::shader;
std::unique_ptr<ppgso::Texture> Church::texture;

Church::Church() {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("kostol.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("kostol.obj");
    scale = {0.008,0.008,0.008};
    position = {0,0,0};
    rotation = {-1.57,0,3.14};
}

bool Church::update(Scene &scene, float dt) {
    generateModelMatrix();
    return true;
}

void Church::render(Scene &scene) {
    shader->use();
    // Set up light
    shader->setUniform("LightDirection", scene.lightDirectionDown);

    // use camera
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);

    // render mesh
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("Texture", *texture);
    mesh->render();
}
