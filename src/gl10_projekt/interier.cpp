//
// Created by Kefalin on 28. 11. 2021.
//
#include "interier.h"
#include <shaders/texture_frag_glsl.h>
#include <shaders/texture_vert_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Interier::mesh;
std::unique_ptr<ppgso::Shader> Interier::shader;
std::unique_ptr<ppgso::Texture> Interier::texture;

Interier::Interier() {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(texture_vert_glsl, texture_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("sphere.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("skybox.obj");
    position = {0,0,0};
    rotation = {0,0,3.14};
}

bool Interier::update(Scene &scene, float dt) {
    generateModelMatrix();
    return true;
}

void Interier::render(Scene &scene) {
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
