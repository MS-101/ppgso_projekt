//
// Created by Kefalin on 12. 11. 2021.
//

#pragma once
#include <ppgso/ppgso.h>

#include "object.h"

class Kostol final : public Object {
private:
    static std::unique_ptr<ppgso::Shader> shader;
    static std::unique_ptr<ppgso::Mesh> mesh;
    static std::unique_ptr<ppgso::Texture> texture;

    glm::vec3 rotMomentum;
public:
    Kostol();

    bool update(Scene &scene, float dt) override;

    void render(Scene &scene) override;
};
