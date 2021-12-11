//
// Created by Kefalin on 6. 12. 2021.
//
#include "ministrant.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Ministrant::mesh;
std::unique_ptr<ppgso::Shader> Ministrant::shader;
std::unique_ptr<ppgso::Texture> Ministrant::texture;

Ministrant::Ministrant(glm::vec3 position_of_object, std::string my_name) {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("ministrant.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("ministrant.obj");
    position = position_of_object;
    scale = {4,4,4};
    name = std::move(my_name);
}

bool Ministrant::update(Scene &scene, float dt) {
    if (is_alive) {
        generateModelMatrix();
        return true;
    } else {
        return false;
    }
}

void Ministrant::render(Scene &scene) {
    shader->use();
    // Set up light
    shader->setUniform("LightDirection", scene.lightDirection);

    // use camera
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);
    shader->setUniform("viewPos",scene.camera->position);

    shader->setUniform("pointLights[0].constant", 9.0f);
    shader->setUniform("pointLights[1].constant", 9.0f);
    shader->setUniform("pointLights[2].constant", 9.0f);
    shader->setUniform("pointLights[0].linear", 0.5f);
    shader->setUniform("pointLights[1].linear", 0.5f);
    shader->setUniform("pointLights[2].linear", 0.5f);
    shader->setUniform("pointLights[0].quadratic", 0.5f);
    shader->setUniform("pointLights[1].quadratic", 0.5f);
    shader->setUniform("pointLights[2].quadratic", 0.5f);

    shader->setUniform("pointLights[0].diffuse", {1.0f, 1.0f, 1.0f});
    shader->setUniform("pointLights[1].diffuse", {1.0f, 1.0f, 1.0f});
    shader->setUniform("pointLights[2].diffuse", {1.0f, 1.0f, 1.0f});

    shader->setUniform("pointLights[0].specular", {0.5f, 0.5f, 0.5f});
    shader->setUniform("pointLights[1].specular", {0.5f, 0.5f, 0.5f});
    shader->setUniform("pointLights[2].specular", {0.5f, 0.5f, 0.5f});

    shader->setUniform("pointLights[0].ambient", {0.1f, 0.1f, 0.1f});
    shader->setUniform("pointLights[1].ambient", {0.1f, 0.1f, 0.1f});
    shader->setUniform("pointLights[2].ambient", {0.1f, 0.1f, 0.1f});


    // render mesh
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("Texture", *texture);
    mesh->render();
}
