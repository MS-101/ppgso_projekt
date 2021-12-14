//
// Created by marti on 13. 12. 2021.
//


#include "animationHandler.h"
#include "scene.h"

class scene2Handler {
private:
    Scene *assignedScene = nullptr;
    float time = 0;
    bool animation_initialized = false;
    animationHandler myAnimationHandler;

    void createBelievers();
    void createStaff();
    void terminateBelievers();
    void terminateStaff();

public:
    explicit scene2Handler(Scene *newScene);
    void initScene();
    bool believersEnterChurch(float dt);
    bool believersSitOnBenches(float dt);
    bool cameraMoveToAltar(float dt);
    bool staffEnterChurch(float dt);
    bool cameraTurnToPeople(float dt);
    bool sermon(float dt);
    bool beginHostia(float dt);
    bool believersEnterLine(float dt);
    bool believersLeaveLine(float dt);
    bool endHostia(float dt);
    bool cameraTurnToStaff(float dt);
    bool staffLeaveChurch(float dt);
    bool believersLeaveBenches(float dt);
    bool believersLeaveChurch(float dt);
    bool cameraLeaveChurch(float dt);
};
