//
// Created by Kefalin on 12. 11. 2021.
//
#include "muz.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Muz::mesh;
std::unique_ptr<ppgso::Shader> Muz::shader;
std::unique_ptr<ppgso::Texture> Muz::texture;

Muz::Muz(glm::vec3 position_of_object, std::string my_name,glm::vec3 scale_man,glm::vec3 rotation_man) {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("man.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("man.obj");
    position = position_of_object;
    scale = scale_man;
    name = std::move(my_name);
    rotation = rotation_man;
}

bool Muz::update(Scene &scene, float dt) {
    if (is_alive) {
        generateModelMatrix();
        return true;
    } else {
        return false;
    }
}

void Muz::render(Scene &scene) {
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
