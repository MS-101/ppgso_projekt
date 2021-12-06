//
// Created by marti on 5. 12. 2021.
//

#include "tree.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Tree::mesh;
std::unique_ptr<ppgso::Shader> Tree::shader;
std::unique_ptr<ppgso::Texture> Tree::texture;

Tree::Tree(glm::vec3 position_of_object) {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("tree.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("tree.obj");
    position = position_of_object;
    scale = {0.1,0.1,0.1};
    rotation = {4.7,0,0};
}

bool Tree::update(Scene &scene, float dt) {
    generateModelMatrix();
    return true;
}

void Tree::render(Scene &scene) {
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
