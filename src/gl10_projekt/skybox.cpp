//
// Created by Kefalin on 20. 11. 2021.
//
//
// Created by Kefalin on 12. 11. 2021.
//
#include "skybox.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Skybox::mesh;
std::unique_ptr<ppgso::Shader> Skybox::shader;
std::unique_ptr<ppgso::Texture> Skybox::texture;

Skybox::Skybox() {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("skybox.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("skybox.obj");
    scale = {50,50,50};
    position = {0,0,0};
    rotation = {0,0,3.14};
}

bool Skybox::update(Scene &scene, float dt) {
    generateModelMatrix();
    return true;
}

void Skybox::render(Scene &scene) {
    shader->use();
    // Set up light
    shader->setUniform("LightDirection", scene.skyLight);

    // use camera
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);

    // render mesh
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("Texture", *texture);
    mesh->render();
}

