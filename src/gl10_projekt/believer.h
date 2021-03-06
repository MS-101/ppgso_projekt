//
// Created by Kefalin on 12. 11. 2021.
//

#pragma once
#include <ppgso/ppgso.h>
#include "object.h"

class Believer final : public Object {
private:
    static std::unique_ptr<ppgso::Shader> shader;
    static std::unique_ptr<ppgso::Mesh> mesh;
    static std::unique_ptr<ppgso::Texture> texture;

public:

    explicit Believer(glm::vec3 position_of_object, std::string my_name,glm::vec3 scale_man,glm::vec3 rotation_man);

    bool update(Scene &scene, float dt) override;

    void render(Scene &scene) override;

};
