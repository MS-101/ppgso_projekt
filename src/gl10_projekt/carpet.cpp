//
// Created by marti on 5. 12. 2021.
//

#include "carpet.h"
#include <shaders/diffuse_frag_glsl.h>
#include <shaders/diffuse_vert_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Carpet::mesh;
std::unique_ptr<ppgso::Shader> Carpet::shader;
std::unique_ptr<ppgso::Texture> Carpet::texture;

Carpet::Carpet() {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("carpet.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("skybox.obj");
    scale = {1,0,25};
    position = {0,0.01,30};
    rotation = {0,0,3.14};
}

bool Carpet::update(Scene &scene, float dt) {
    generateModelMatrix();
    return true;
}

void Carpet::render(Scene &scene) {
    shader->use();

    // use camera
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);

    // render mesh
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("Texture", *texture);
    mesh->render();
}