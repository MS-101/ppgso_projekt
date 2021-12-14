//
// Created by marti on 12. 12. 2021.
//

#include <ppgso/ppgso.h>
#include "object.h"

class objectKeyframe {
private:
    glm::vec3 position{0,0,0};
    glm::vec3 rotation{0,0,0};
    glm::vec3 scale{1,1,1};

public:
    glm::vec3 getPosition();
    glm::vec3 getRotation();
    glm::vec3 getScale();

    void setKeyframe(glm::vec3 newPosition, glm::vec3 newRotation, glm::vec3 newScale);
};
