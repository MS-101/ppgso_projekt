//
// Created by Kefalin on 7. 11. 2021.
//


#include "lampa.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Lampa::mesh;
std::unique_ptr<ppgso::Shader> Lampa::shader;
std::unique_ptr<ppgso::Texture> Lampa::texture;

Lampa::Lampa() {
    rotMomentum = {0.0f, 0.0f,glm::linearRand(-ppgso::PI/4.0f, ppgso::PI/4.0f)};
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("lampa.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("lampa.obj");
}

bool Lampa::update(Scene &scene, float dt) {
    rotation += rotMomentum * dt;
    generateModelMatrix();
    return true;
}

void Lampa::render(Scene &scene) {
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
