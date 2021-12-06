//
// Created by Kefalin on 12. 11. 2021.
//
#include "knaz.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>

#include <utility>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Knaz::mesh;
std::unique_ptr<ppgso::Shader> Knaz::shader;
std::unique_ptr<ppgso::Texture> Knaz::texture;

Knaz::Knaz(glm::vec3 position_of_object, std::string my_name,glm::vec3 scale_priest) {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("kengura.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("kengura.obj");
    position = position_of_object;
    scale = scale_priest;
    rotation = {-1.57,0,-1.57};
    name = std::move(my_name);
}

bool Knaz::update(Scene &scene, float dt) {
    if (is_alive) {
        generateModelMatrix();
        return true;
    } else {
        return false;
    }
}

void Knaz::render(Scene &scene) {
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
