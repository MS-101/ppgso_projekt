//
// Created by marti on 5. 12. 2021.
//

#include "indoorFloor.h"
#include <shaders/texture_frag_glsl.h>
#include <shaders/texture_vert_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> IndoorFloor::mesh;
std::unique_ptr<ppgso::Shader> IndoorFloor::shader;
std::unique_ptr<ppgso::Texture> IndoorFloor::texture;

IndoorFloor::IndoorFloor() {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(texture_vert_glsl, texture_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("floor.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("skybox.obj");
    scale = {50,0,50};
    position = {0,0,30};
    rotation = {0,0,3.14};
}

bool IndoorFloor::update(Scene &scene, float dt) {
    generateModelMatrix();
    return true;
}

void IndoorFloor::render(Scene &scene) {
    shader->use();

    // use camera
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);

    // render mesh
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("Texture", *texture);
    mesh->render();
}