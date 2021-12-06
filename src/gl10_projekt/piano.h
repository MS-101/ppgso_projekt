//
// Created by Kefalin on 6. 12. 2021.
//
#pragma once
#include <ppgso/ppgso.h>
#include "object.h"

class Piano final : public Object {
private:
    static std::unique_ptr<ppgso::Shader> shader;
    static std::unique_ptr<ppgso::Mesh> mesh;
    static std::unique_ptr<ppgso::Texture> texture;

public:

    Piano();

    bool update(Scene &scene, float dt) override;

    void render(Scene &scene) override;
};
