//
// Created by marti on 14. 12. 2021.
//

#include "pianist_body.h"
#include <shaders/texture_frag_glsl.h>
#include <shaders/texture_vert_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> pianist_body::mesh;
std::unique_ptr<ppgso::Shader> pianist_body::shader;
std::unique_ptr<ppgso::Texture> pianist_body::texture;

pianist_body::pianist_body(glm::vec3 object_position, std::string my_name, glm::vec3 object_rotation, glm::vec3 object_scale) {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(texture_vert_glsl, texture_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("black.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("skybox.obj");
    position = object_position;
    rotation = object_rotation;
    scale = object_scale;
    name = my_name;

    glm::vec3 head_position = object_position;
    glm::vec3 head_rotation = object_rotation;
    glm::vec3 head_scale = object_scale;

    head_position.y += 2;
    head_scale *= 2;

    head = std::make_unique<pianist_head>(head_position, head_rotation, head_scale);
}

bool pianist_body::update(Scene &scene, float dt) {
    if (is_alive) {
        generateModelMatrix();

        head->position = position;
        head->rotation = rotation;

        head->scale = scale;

        head->position.y += 2;
        head->scale *= 2;

        head->update(scene, dt);

        return true;
    } else {
        return false;
    }
}

void pianist_body::render(Scene &scene) {
    shader->use();

    // use camera
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);

    // render mesh
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("Texture", *texture);
    mesh->render();

    head->render(scene);
}

void pianist_body::terminate() {
    is_alive = false;
    head->terminate();
}