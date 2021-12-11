#ifndef _PPGSO_SCENE_H
#define _PPGSO_SCENE_H

#include <memory>
#include <map>
#include <list>

#include "object.h"
#include "camera.h"

/*
 * Scene is an object that will aggregate all scene related data
 * Objects are stored in a list of objects
 * Keyboard and Mouse states are stored in a map and struct
 */
class Scene {
  public:

    void update(float time);

    void render();

    std::vector<Object*> intersect(const glm::vec3 &position, const glm::vec3 &direction);

    // Camera object
    std::unique_ptr<Camera> camera;

    // All objects to be rendered in scene
    std::list< std::unique_ptr<Object> > objects;

    // Lights, in this case using only simple directional diffuse lighting
    glm::vec3 lightDirectionUp{1.0f, 1.0f, 1.0f};
    glm::vec3 lightDirectionDown{-1.0f, -1.0f, -1.0f};

};

#endif // _PPGSO_SCENE_H
