//
// Created by Kefalin on 6. 12. 2021.
//
#include "door.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>

#include "scene.h"

std::unique_ptr<ppgso::Mesh> Door::mesh;
std::unique_ptr<ppgso::Shader> Door::shader;
std::unique_ptr<ppgso::Texture> Door::texture;

Door::Door(glm::vec3 object_position, glm::vec3 object_rotation) {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("dvere.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("dvere.obj");
    position = object_position;
    scale = {0.022,0.02,0.02};
    rotation = object_rotation;
}

bool Door::update(Scene &scene, float dt) {
    if (is_alive) {
        generateModelMatrix();
        return true;
    } else {
        return false;
    }
}

void Door::render(Scene &scene) {
    shader->use();
    shader->setUniform("LightDirection", scene.lightDirectionUp);
    // use camera
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);

    // render mesh
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("Texture", *texture);
    mesh->render();
}
