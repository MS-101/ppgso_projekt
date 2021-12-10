//
// Created by Kefalin on 6. 12. 2021.
//
#include "kriz.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>

#include "scene.h"

std::unique_ptr<ppgso::Mesh> Kriz::mesh;
std::unique_ptr<ppgso::Shader> Kriz::shader;
std::unique_ptr<ppgso::Texture> Kriz::texture;

Kriz::Kriz() {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("kriz.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("kriz.obj");
    position = {-1,2,-5};
    scale = {10,10,10};
    rotation = {3.14,3.14,0};
}

bool Kriz::update(Scene &scene, float dt) {
    if (is_alive) {
        generateModelMatrix();
        return true;
    } else {
        return false;
    }
}

void Kriz::render(Scene &scene) {
    shader->use();
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
