//
// Created by Kefalin on 3. 12. 2021.
//
#include "stol.h"
#include <shaders/texture_frag_glsl.h>
#include <shaders/texture_vert_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Stol::mesh;
std::unique_ptr<ppgso::Shader> Stol::shader;
std::unique_ptr<ppgso::Texture> Stol::texture;

Stol::Stol() {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(texture_vert_glsl, texture_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("stol.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("stol.obj");
    position = {0, 0, 3};
    scale = {0.015,0.015,0.015};
    rotation = {0,0,1.57};
}

bool Stol::update(Scene &scene, float dt) {
    generateModelMatrix();
    return true;
}

void Stol::render(Scene &scene) {
    shader->use();
    // Set up light
    shader->setUniform("LightDirection", scene.lightDirection);

    // use camera
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);
    shader->setUniform("viewPos",scene.camera->position);

    // render mesh
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("Texture", *texture);
    mesh->render();
}
