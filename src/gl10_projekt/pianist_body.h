//
// Created by marti on 14. 12. 2021.
//

#pragma once
#include <ppgso/ppgso.h>
#include "object.h"
#include "pianist_head.h"

class pianist_body final : public Object {
private:
    static std::unique_ptr<ppgso::Shader> shader;
    static std::unique_ptr<ppgso::Mesh> mesh;
    static std::unique_ptr<ppgso::Texture> texture;
    std::unique_ptr<pianist_head> head;

public:
    pianist_body(glm::vec3 object_position, std::string my_name, glm::vec3 object_rotation, glm::vec3 object_scale);

    bool update(Scene &scene, float dt) override;

    void render(Scene &scene) override;

    void terminate();
};