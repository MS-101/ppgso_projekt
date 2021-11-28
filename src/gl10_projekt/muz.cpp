//
// Created by Kefalin on 26. 11. 2021.
//

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

Muz::Muz(glm::vec3 position_of_object) {
    // Initialize static resources if needed
    if (!shader) shader = std::make_unique<ppgso::Shader>(diffuse_vert_glsl, diffuse_frag_glsl);
    if (!texture) texture = std::make_unique<ppgso::Texture>(ppgso::image::loadBMP("man.bmp"));
    if (!mesh) mesh = std::make_unique<ppgso::Mesh>("man.obj");
    position = position_of_object;
    scale = {1.7,1.7,1.7};
}

bool Muz::update(Scene &scene, float dt) {
    position.z = position.z + 0.0002f;
    if (position.z > -8){
        position.x = 0;
    }
    if (position.z  > -5.5){
        return false;
    }
    generateModelMatrix();
    return true;
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
