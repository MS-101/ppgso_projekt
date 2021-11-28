#pragma once
#include <ppgso/ppgso.h>

#include "object.h"

class Slnko final : public Object {
private:
    static std::unique_ptr<ppgso::Shader> shader;
    static std::unique_ptr<ppgso::Mesh> mesh;
    static std::unique_ptr<ppgso::Texture> texture;

public:
    /*
     * Create new projectile
     */
    explicit Slnko();

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