//
// Created by marti on 14. 12. 2021.
//

#pragma once
#include <ppgso/ppgso.h>
#include "object.h"

class pianist_hat final : public Object {
private:
    static std::unique_ptr<ppgso::Shader> shader;
    static std::unique_ptr<ppgso::Mesh> mesh;
    static std::unique_ptr<ppgso::Texture> texture;

public:
    pianist_hat(glm::vec3 object_position, glm::vec3 object_rotation, glm::vec3 object_scale);

    bool update(Scene &scene, float dt) override;

    void render(Scene &scene) override;
};