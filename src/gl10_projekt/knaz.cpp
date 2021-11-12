//
// Created by Kefalin on 12. 11. 2021.
//
#include "knaz.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Knaz::mesh;
std::unique_ptr<ppgso::Shader> Knaz::shader;
std::unique_ptr<ppgso::Texture> Knaz::texture;

Knaz::Knaz() {
    rotMomentum = {0.0f, 0.0f,glm::linearRand(-ppgso::PI/4.0f, ppgso::PI/4.0f)};
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("knaz.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("knaz.obj");
}

bool Knaz::update(Scene &scene, float dt) {
    rotation += rotMomentum * dt;
    generateModelMatrix();
    return true;
}

void Knaz::render(Scene &scene) {
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
