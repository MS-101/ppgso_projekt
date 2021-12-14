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
    acc = -9.8f;
    velocity = {0,0,0};
    push = {0,0,1};
}

bool Bottle::update(Scene &scene, float dt) {
    if (is_alive) {
        drag = 0.5 * 0.4 * 0.2 * 1.29 * velocity.y * velocity.y; //vypocet odporu vzduchu, 0.5*koeficient odporu*povrch*hustota prostredia*rychlost^2
        velocity += acc * dt;
        position.z += push.z * dt * 0.5; //vypocet posunutia smerok k veriacim pomocou tlacenia na flasu
        position.y += (velocity.y-drag) * dt * 0.01; //vypocet pozicie za urcenia rychlosti minus odpor krat cas, vynasobenie 0.01 ako offset pre animaciu
        if(position.y < 0) return false; //zmiznutie flase po padnuti na zem
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
