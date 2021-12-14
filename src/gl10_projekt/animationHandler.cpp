//
// Created by marti on 12. 12. 2021.
//

#include "animationHandler.h"

void animationHandler::init() {
    keyframeObjects.clear();
    objectKeyframeVector1.clear();
    objectKeyframeVector2.clear();
    objectCounter = 0;

    myCamera = nullptr;
}

void animationHandler::addObject(Object *newObject, objectKeyframe firstKeyframe, objectKeyframe secondKeyframe) {
    keyframeObjects.push_back(newObject);
    objectKeyframeVector1.push_back(firstKeyframe);
    objectKeyframeVector2.push_back(secondKeyframe);

    objectCounter++;
}

void animationHandler::addCamera(Camera *newCamera, cameraKeyframe firstKeyframe, cameraKeyframe secondKeyframe) {
    myCamera = newCamera;
    cameraKeyframe1 = firstKeyframe;
    cameraKeyframe2 = secondKeyframe;
}

objectKeyframe animationHandler::interpolateObject(objectKeyframe firstKeyframe, objectKeyframe secondKeyframe, float t) {
    glm::vec3 newPosition = (1 - t) * firstKeyframe.getPosition() + t * secondKeyframe.getPosition();
    glm::vec3 newRotation = (1 - t) * firstKeyframe.getRotation() + t * secondKeyframe.getRotation();
    glm::vec3 newScale = (1 - t) * firstKeyframe.getScale() + t * secondKeyframe.getScale();

    objectKeyframe newKeyframe;
    newKeyframe.setKeyframe(newPosition, newRotation, newScale);

    return newKeyframe;
}

cameraKeyframe animationHandler::interpolateCamera(float t) {
    glm::vec3 newPosition = (1 - t) * cameraKeyframe1.getPosition() + t * cameraKeyframe2.getPosition();
    glm::vec3 newBack = (1 - t) * cameraKeyframe1.getBack() + t * cameraKeyframe2.getBack();

    cameraKeyframe newKeyframe;
    newKeyframe.setKeyframe(newPosition, newBack);

    return newKeyframe;
}

void animationHandler::setObjectTransformation(Object *myObject, objectKeyframe newKeyFrame) {
    myObject->position = newKeyFrame.getPosition();
    myObject->rotation = newKeyFrame.getRotation();
    myObject->scale = newKeyFrame.getScale();
}

void animationHandler::setCameraTransformation(cameraKeyframe newKeyframe) {
    myCamera->position = newKeyframe.getPosition();
    myCamera->back = newKeyframe.getBack();
}

void animationHandler::animate(float t) {
    if (myCamera != nullptr) {
        cameraKeyframe newCameraKeyframe = interpolateCamera(t);
        setCameraTransformation(newCameraKeyframe);
    }

    for (unsigned int i = 0; i < objectCounter; i++) {
        objectKeyframe newObjectKeyframe = interpolateObject(objectKeyframeVector1.at(i), objectKeyframeVector2.at(i), t);
        setObjectTransformation(keyframeObjects.at(i), newObjectKeyframe);
    }
}
