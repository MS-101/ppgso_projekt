//
// Created by Kefalin on 7. 11. 2021.
//

#include "lamp.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Lamp::mesh;
std::unique_ptr<ppgso::Shader> Lamp::shader;
std::unique_ptr<ppgso::Texture> Lamp::texture;

Lamp::Lamp() {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("lampa.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("lampa.obj");
    scale = {0.015,0.015,0.015};
    rotation = {-1.57,0,0};
    position = {-3, 0, 3};
}

bool Lamp::update(Scene &scene, float dt) {
    if (is_alive) {
        generateModelMatrix();
        return true;
    } else {
        return false;
    }
}

void Lamp::render(Scene &scene) {
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
