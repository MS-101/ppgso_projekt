//
// Created by Kefalin on 28. 11. 2021.
//
#include "sun.h"
#include <shaders/texture_frag_glsl.h>
#include <shaders/texture_vert_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Sun::mesh;
std::unique_ptr<ppgso::Shader> Sun::shader;
std::unique_ptr<ppgso::Texture> Sun::texture;

Sun::Sun() {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(texture_vert_glsl, texture_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("sun.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("sphere.obj");
    position = {-17,20,0};
    scale = {2.5,2.5,2.5};
    rotation = {-1.57,0,3.14};
}

bool Sun::update(Scene &scene, float dt) {
    generateModelMatrix();
    return true;
}

void Sun::render(Scene &scene) {
    shader->use();
    // Set up light

    // use camera
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);

    // render mesh
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("Texture", *texture);

    mesh->render();
}
