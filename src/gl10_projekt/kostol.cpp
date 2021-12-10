//
// Created by Kefalin on 12. 11. 2021.
//
#include "kostol.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Kostol::mesh;
std::unique_ptr<ppgso::Shader> Kostol::shader;
std::unique_ptr<ppgso::Texture> Kostol::texture;

Kostol::Kostol() {
    rotMomentum = {0.0f, 0.0f,glm::linearRand(-ppgso::PI/4.0f, ppgso::PI/4.0f)};
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("kostol.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("kostol.obj");
    scale = {0.008,0.008,0.008};
    position = {0,0,0};
    rotation = {-1.57,0,3.14};
}

bool Kostol::update(Scene &scene, float dt) {
    generateModelMatrix();
    return true;
}

void Kostol::render(Scene &scene) {
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
