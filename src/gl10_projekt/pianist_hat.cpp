//
// Created by marti on 14. 12. 2021.
//

#include "pianist_hat.h"
#include <shaders/texture_frag_glsl.h>
#include <shaders/texture_vert_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> pianist_hat::mesh;
std::unique_ptr<ppgso::Shader> pianist_hat::shader;
std::unique_ptr<ppgso::Texture> pianist_hat::texture;

pianist_hat::pianist_hat(glm::vec3 object_position, glm::vec3 object_rotation, glm::vec3 object_scale) {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(texture_vert_glsl, texture_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("black.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("skybox.obj");
    position = object_position;
    rotation = object_rotation;
    scale = object_scale;
}

bool pianist_hat::update(Scene &scene, float dt) {
    if (is_alive) {
        generateModelMatrix();
        return true;
    } else {
        return false;
    }
}

void pianist_hat::render(Scene &scene) {
    shader->use();

    // use camera
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);

    // render mesh
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("Texture", *texture);
    mesh->render();
}