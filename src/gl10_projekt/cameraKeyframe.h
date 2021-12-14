//
// Created by marti on 13. 12. 2021.
//

#include <ppgso/ppgso.h>

class cameraKeyframe {
private:
    glm::vec3 position{0,0,0};
    glm::vec3 back{0,0,0};

public:
    glm::vec3 getPosition();
    glm::vec3 getBack();

    void setKeyframe(glm::vec3 newPosition, glm::vec3 newBack);
};
