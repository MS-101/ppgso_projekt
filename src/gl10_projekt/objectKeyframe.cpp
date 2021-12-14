//
// Created by marti on 12. 12. 2021.
//

#include "objectKeyframe.h"

void objectKeyframe::setKeyframe(glm::vec3 newPosition, glm::vec3 newRotation, glm::vec3 newScale) {
    position = newPosition;
    rotation = newRotation;
    scale = newScale;
}

glm::vec3 objectKeyframe::getPosition() {
    return position;
}

glm::vec3 objectKeyframe::getRotation() {
    return rotation;
}

glm::vec3 objectKeyframe::getScale() {
    return scale;
}
