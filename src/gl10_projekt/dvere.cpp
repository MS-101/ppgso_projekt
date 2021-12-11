//
// Created by Kefalin on 6. 12. 2021.
//
#include "dvere.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>

#include "scene.h"

std::unique_ptr<ppgso::Mesh> Dvere::mesh;
std::unique_ptr<ppgso::Shader> Dvere::shader;
std::unique_ptr<ppgso::Texture> Dvere::texture;

Dvere::Dvere() {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("dvere.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("dvere.obj");
    position = {0,0,20};
    scale = {0.022,0.02,0.02};
    rotation = {4.7,-3.14,0};
}

bool Dvere::update(Scene &scene, float dt) {
    if (is_alive) {
        generateModelMatrix();
        return true;
    } else {
        return false;
    }
}

void Dvere::render(Scene &scene) {
    shader->use();
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
