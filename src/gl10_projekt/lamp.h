//
// Created by Kefalin on 7. 11. 2021.
//

#pragma once
#include <ppgso/ppgso.h>
#include "object.h"

class Lamp final : public Object {
private:
    static std::unique_ptr<ppgso::Shader> shader;
    static std::unique_ptr<ppgso::Mesh> mesh;
    static std::unique_ptr<ppgso::Texture> texture;

public:
    Lamp();

    bool update(Scene &scene, float dt) override;

    void render(Scene &scene) override;
};
