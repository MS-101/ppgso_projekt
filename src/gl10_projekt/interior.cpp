//
// Created by Kefalin on 5. 12. 2021.
//
#include "interior.h"
#include <shaders/texture_frag_glsl.h>
#include <shaders/texture_vert_glsl.h>

#include "scene.h"

std::unique_ptr<ppgso::Mesh> Interior::mesh;
std::unique_ptr<ppgso::Shader> Interior::shader;
std::unique_ptr<ppgso::Texture> Interior::texture;

Interior::Interior() {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(texture_vert_glsl, texture_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("walls.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("skybox.obj");
    scale = {20,20,20};
}

bool Interior::update(Scene &scene, float dt) {
    generateModelMatrix();
    return true;
}

void Interior::render(Scene &scene) {
    shader->use();
    // use camera
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);

    // render mesh
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("Texture", *texture);
    mesh->render();
}