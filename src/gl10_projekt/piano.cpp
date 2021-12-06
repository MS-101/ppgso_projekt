//
// Created by Kefalin on 6. 12. 2021.
//
#include "piano.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>

#include "scene.h"

std::unique_ptr<ppgso::Mesh> Piano::mesh;
std::unique_ptr<ppgso::Shader> Piano::shader;
std::unique_ptr<ppgso::Texture> Piano::texture;

Piano::Piano() {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("piano.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("piano.obj");
    position = {-5, 0, 2};
    scale = {6.5,6.5,6.5};
    rotation = {3.14,3.14,0};
}

bool Piano::update(Scene &scene, float dt) {
    if (is_alive) {
        generateModelMatrix();
        return true;
    } else {
        return false;
    }
}

void Piano::render(Scene &scene) {
    shader->use();
    shader->setUniform("LightDirection", scene.lightDirection);
    // use camera
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);

    // render mesh
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("Texture", *texture);
    mesh->render();
}
