//
// Created by marti on 5. 12. 2021.
//

#include "grass_plane.h"
#include <shaders/texture_frag_glsl.h>
#include <shaders/texture_vert_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> grass_plane::mesh;
std::unique_ptr<ppgso::Shader> grass_plane::shader;
std::unique_ptr<ppgso::Texture> grass_plane::texture;

grass_plane::grass_plane() {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(texture_vert_glsl, texture_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("grass.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("skybox.obj");
    scale = {50,0,50};
    position = {0,0,0};
    rotation = {0,0,3.14};
}

bool grass_plane::update(Scene &scene, float dt) {
    generateModelMatrix();
    return true;
}

void grass_plane::render(Scene &scene) {
    shader->use();

    // use camera
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);

    // render mesh
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("Texture", *texture);
    mesh->render();
}