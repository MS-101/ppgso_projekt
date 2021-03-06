//
// Created by Kefalin on 3. 12. 2021.
//
#include "bench.h"
#include <shaders/diffuse_vert_glsl.h>
#include <shaders/diffuse_frag_glsl.h>
#include "scene.h"

std::unique_ptr<ppgso::Mesh> Bench::mesh;
std::unique_ptr<ppgso::Shader> Bench::shader;
std::unique_ptr<ppgso::Texture> Bench::texture;

Bench::Bench(glm::vec3 position_of_object) {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("lavicka.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("lavicka.obj");
    position = position_of_object;
    scale = {0.02,0.025,0.02};
}

bool Bench::update(Scene &scene, float dt) {
    generateModelMatrix();
    return true;
}

void Bench::render(Scene &scene) {
    shader->use();
    // Set up light
    shader->setUniform("LightDirection", scene.lightDirectionDown);

    // use camera
    shader->setUniform("ProjectionMatrix", scene.camera->projectionMatrix);
    shader->setUniform("ViewMatrix", scene.camera->viewMatrix);

    // render mesh
    shader->setUniform("ModelMatrix", modelMatrix);
    shader->setUniform("Texture", *texture);
    mesh->render();
}
