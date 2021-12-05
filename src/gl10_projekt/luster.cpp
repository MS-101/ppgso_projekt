//
// Created by Kefalin on 3. 12. 2021.
//
#include "luster.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Luster::mesh;
std::unique_ptr<ppgso::Shader> Luster::shader;
std::unique_ptr<ppgso::Texture> Luster::texture;

Luster::Luster() {
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("luster.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("luster.obj");
    scale = {0.05,0.05,0.05};
    rotation = {-1.57,0,0};
    position = {0,10,0};
}

bool Luster::update(Scene &scene, float dt) {
    generateModelMatrix();
    return true;
}

void Luster::render(Scene &scene) {
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
