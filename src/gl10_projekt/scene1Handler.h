//
// Created by marti on 13. 12. 2021.
//

#include "animationHandler.h"
#include "scene.h"

class scene1Handler {
private:
    Scene *assignedScene = nullptr;
    float time = 0;
    bool animation_initialized = false;
    animationHandler myAnimationHandler;

    void createEnteringBelievers();
    void createLeavingBelievers();
    void terminateBelievers();

public:
    explicit scene1Handler(Scene *newScene);
    void initScene(glm::vec3 cameraStartPos, glm::vec3 cameraStartBack);
    bool cameraSpinAroundChurch(float dt);
    bool believersEnterChurch(float dt);
    bool cameraEnterChurch(float dt);
    bool believersLeaveChurch(float dt);
    bool cameraLeaveChurch(float dt);
};

