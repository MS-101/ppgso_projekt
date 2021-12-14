//
// Created by marti on 13. 12. 2021.
//

#include "cameraKeyframe.h"

void cameraKeyframe::setKeyframe(glm::vec3 newPosition, glm::vec3 newBack) {
    position = newPosition;
    back = newBack;
}

glm::vec3 cameraKeyframe::getPosition() {
    return position;
}

glm::vec3 cameraKeyframe::getBack() {
    return back;
}
