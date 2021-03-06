//
// Created by marti on 5. 12. 2021.
//

#pragma once
#include <ppgso/ppgso.h>

#include "object.h"

class Tree final : public Object {
private:
    static std::unique_ptr<ppgso::Shader> shader;
    static std::unique_ptr<ppgso::Mesh> mesh;
    static std::unique_ptr<ppgso::Texture> texture;
public:
    explicit Tree(glm::vec3 position_of_object);

    bool update(Scene &scene, float dt) override;

    void render(Scene &scene) override;
};
