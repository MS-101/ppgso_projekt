//
// Created by marti on 14. 12. 2021.
//

#include "pianist_head.h"
#include <shaders/texture_frag_glsl.h>
#include <shaders/texture_vert_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> pianist_head::mesh;
std::unique_ptr<ppgso::Shader> pianist_head::shader;
std::unique_ptr<ppgso::Texture> pianist_head::texture;

pianist_head::pianist_head(glm::vec3 object_position, glm::vec3 object_rotation, glm::vec3 object_scale) {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(texture_vert_glsl, texture_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("brown.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("sphere.obj");
    position = object_position;
    rotation = object_rotation;
    scale = object_scale;

    glm::vec3 hat_position = object_position;
    glm::vec3 hat_rotation = object_rotation;
    glm::vec3 hat_scale = object_scale;

    hat_position.y += 1;
    hat_scale /= 2;
    hat_scale.y /= 2;

    hat = std::make_unique<pianist_hat>(hat_position, hat_rotation, hat_scale);
}

bool pianist_head::update(Scene &scene, float dt) {
    if (is_alive) {
        generateModelMatrix();

        hat->position = position;
        hat->rotation = rotation;
        hat->scale = scale;

        hat->position.y += 1;
        hat->scale /= 2;
        hat->scale.y /= 2;

        hat->update(scene, dt);

        return true;
    } else {
        return false;
    }
}

void pianist_head::render(Scene &scene) {
    shader->use();

    // use camera
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);

    // render mesh
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("Texture", *texture);
    mesh->render();

    hat->render(scene);
}

void pianist_head::terminate() {
    is_alive = false;
    hat->terminate();
}