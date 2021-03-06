//
// Created by Kefalin on 3. 12. 2021.
//

#pragma once
#include <ppgso/ppgso.h>

#include "object.h"

/*!
 * Object representing a rocket projectile that will accelerate from the ship one created
 */
class Bench final : public Object {
private:
    static std::unique_ptr<ppgso::Shader> shader;
    static std::unique_ptr<ppgso::Mesh> mesh;
    static std::unique_ptr<ppgso::Texture> texture;

public:

    explicit Bench(glm::vec3 position_of_object);

    /*!
     * Update projectile position
     * @param scene Scene to update
     * @param dt Time delta
     * @return true to delete the object
     */
    bool update(Scene &scene, float dt) override;

    /*!
     * Render projectile
     * @param scene Scene to render in
     */
    void render(Scene &scene) override;

};
