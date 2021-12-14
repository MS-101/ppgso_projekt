//
// Created by Kefalin on 6. 12. 2021.
//
#include "bottle.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>

#include "scene.h"

std::unique_ptr<ppgso::Mesh> Bottle::mesh;
std::unique_ptr<ppgso::Shader> Bottle::shader;
std::unique_ptr<ppgso::Texture> Bottle::texture;

Bottle::Bottle(glm::vec3 position_of_object, std::string my_name) {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("flasa.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("flasa.obj");
    position = {0,1,4};
    scale = {2,2,2};
    rotation = {3.14,3.14,0};
    name = std::move(my_name);
}

bool Bottle::update(Scene &scene, float dt) {
    if (is_alive) {
        generateModelMatrix();
        return true;
    } else {
        return false;
    }
}

void Bottle::render(Scene &scene) {
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
