//
// Created by marti on 12. 12. 2021.
//

#pragma once
#include <ppgso/ppgso.h>
#include "objectKeyframe.h"
#include "cameraKeyframe.h"
#include "camera.h"

class animationHandler {
private:
    std::vector<objectKeyframe> objectKeyframeVector1;
    std::vector<objectKeyframe> objectKeyframeVector2;
    std::vector<Object *> keyframeObjects;
    unsigned int objectCounter;

    cameraKeyframe cameraKeyframe1;
    cameraKeyframe cameraKeyframe2;
    Camera *myCamera;

    objectKeyframe interpolateObject(objectKeyframe firstKeyframe, objectKeyframe secondKeyframe, float t);
    cameraKeyframe interpolateCamera(float t);

    void setObjectTransformation(Object *myObject, objectKeyframe newKeyframe);
    void setCameraTransformation(cameraKeyframe newKeyframe);
public:
    void init();
    void addObject(Object *newObject, objectKeyframe firstKeyframe, objectKeyframe secondKeyframe);
    void addCamera(Camera *newCamera, cameraKeyframe firstKeyframe, cameraKeyframe secondKeyframe);
    void animate(float t);
};
