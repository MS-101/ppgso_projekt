//
// Created by marti on 13. 12. 2021.
//

#include "scene2Handler.h"

#include "interior.h"
#include "indoorFloor.h"
#include "carpet.h"
#include "door.h"
#include "altar.h"
#include "bench.h"
#include "bottle.h"
#include "piano.h"
#include "chandelier.h"
#include "cross.h"
#include "lamp.h"
#include "believer.h"
#include "priest.h"
#include "ministrant.h"
#include "pianist_body.h"

scene2Handler::scene2Handler(Scene *newScene) {
    assignedScene = newScene;
}

void scene2Handler::initScene() {
    assignedScene->objects.clear();

    // nastavenie kamery
    assignedScene->camera->position = {0, 2, 15};
    assignedScene->camera->back = {0, 0, 1};

    // hlavne objekty
    auto my_interior = std::make_unique<Interior>();
    auto indoorFloor = std::make_unique<IndoorFloor>();
    auto carpet = std::make_unique<Carpet>();
    auto mainDoor = std::make_unique<Door>(glm::vec3{0,0,20}, glm::vec3{4.7,-3.14,0});
    auto staffDoor = std::make_unique<Door>(glm::vec3{-10,0,-18}, glm::vec3{5,-3.14,0});
    auto altar = std::make_unique<Altar>();
    auto cross = std::make_unique<Cross>();
    auto piano = std::make_unique<Piano>();
    assignedScene->objects.push_back(std::move(my_interior));
    assignedScene->objects.push_back(std::move(indoorFloor));
    assignedScene->objects.push_back(std::move(carpet));
    assignedScene->objects.push_back(std::move(mainDoor));
    assignedScene->objects.push_back(std::move(staffDoor));
    assignedScene->objects.push_back(std::move(altar));
    assignedScene->objects.push_back(std::move(cross));
    assignedScene->objects.push_back(std::move(piano));

    // lavicky
    auto bench1 = std::make_unique<Bench>(glm::vec3 {3,0,7});
    auto bench2 = std::make_unique<Bench>(glm::vec3 {-3,0,7});
    auto bench3 = std::make_unique<Bench>(glm::vec3 {3,0,9});
    auto bench4 = std::make_unique<Bench>(glm::vec3 {-3,0,9});
    auto bench5 = std::make_unique<Bench>(glm::vec3 {3,0,11});
    auto bench6 = std::make_unique<Bench>(glm::vec3 {-3,0,11});
    assignedScene->objects.push_back(std::move(bench1));
    assignedScene->objects.push_back(std::move(bench2));
    assignedScene->objects.push_back(std::move(bench3));
    assignedScene->objects.push_back(std::move(bench4));
    assignedScene->objects.push_back(std::move(bench5));
    assignedScene->objects.push_back(std::move(bench6));

    // osvetlenie
    auto chandelier = std::make_unique<Chandelier>();
    auto lamp1 = std::make_unique<Lamp>(glm::vec3{-3, 0, 3});
    auto lamp2 = std::make_unique<Lamp>(glm::vec3{3, 0, 3});
    assignedScene->objects.push_back(std::move(chandelier));
    assignedScene->objects.push_back(std::move(lamp1));
    assignedScene->objects.push_back(std::move(lamp2));

    // rozbitelna flasa
    auto bottle = std::make_unique<Bottle>(glm::vec3{0,1,4}, "rizling");
    assignedScene->objects.push_back(std::move(bottle));
}

void scene2Handler::createBelievers() {
    glm::vec3 scaleBelievers = {1.7,1.7,1.7};
    glm::vec3 rotationBelievers = {0,0,M_PI};
    auto believer1 = std::make_unique<Believer>(glm::vec3{1,0,13}, "believer1", scaleBelievers, rotationBelievers);
    auto believer2 = std::make_unique<Believer>(glm::vec3{-1,0,13}, "believer2", scaleBelievers, rotationBelievers);
    auto believer3 = std::make_unique<Believer>(glm::vec3{1,0,14}, "believer3", scaleBelievers, rotationBelievers);
    auto believer4 = std::make_unique<Believer>(glm::vec3{-1,0,14}, "believer4", scaleBelievers, rotationBelievers);
    assignedScene->objects.push_back(std::move(believer1));
    assignedScene->objects.push_back(std::move(believer2));
    assignedScene->objects.push_back(std::move(believer3));
    assignedScene->objects.push_back(std::move(believer4));
}

void scene2Handler::createStaff() {
    glm::vec3 scaleMinistrants = {4, 4, 4};
    glm::vec3 rotationMinistrants = {0, 0,  1.0/3.0 * M_PI};
    auto priest = std::make_unique<Priest>(glm::vec3{-9, 0, -13}, "priest", glm::vec3{0.01,0.01,0.01}, glm::vec3{-1.57,0,-1.57 + 1.0/3.0 * M_PI});
    auto ministrant1 = std::make_unique<Ministrant>(glm::vec3{-10, 0.5, -15}, "ministrant1", rotationMinistrants, scaleMinistrants);
    auto ministrant2 = std::make_unique<Ministrant>(glm::vec3{-8, 0.5, -15}, "ministrant2", rotationMinistrants, scaleMinistrants);
    auto pianist = std::make_unique<pianist_body>(glm::vec3{-9, 1.01, -13}, "pianist", glm::vec3{0, 0, 0}, glm::vec3{1, 1, 1});
    assignedScene->objects.push_back(std::move(priest));
    assignedScene->objects.push_back(std::move(ministrant1));
    assignedScene->objects.push_back(std::move(ministrant2));
    assignedScene->objects.push_back(std::move(pianist));
}

void scene2Handler::terminateBelievers() {
    Object* believer1 = assignedScene->findObjectByName("believer1");
    if (believer1 != nullptr) {
        believer1->terminate();
    }

    Object* believer2 = assignedScene->findObjectByName("believer2");
    if (believer2 != nullptr) {
        believer2->terminate();
    }

    Object* believer3 = assignedScene->findObjectByName("believer3");
    if (believer3 != nullptr) {
        believer3->terminate();
    }

    Object* believer4 = assignedScene->findObjectByName("believer4");
    if (believer4 != nullptr) {
        believer4->terminate();
    }
}

void scene2Handler::terminateStaff() {
    Object* priest = assignedScene->findObjectByName("priest");
    if (priest != nullptr) {
        priest->terminate();
    }

    Object* ministrant1 = assignedScene->findObjectByName("ministrant1");
    if (ministrant1 != nullptr) {
        ministrant1->terminate();
    }

    Object* ministrant2 = assignedScene->findObjectByName("ministrant2");
    if (ministrant2 != nullptr) {
        ministrant2->terminate();
    }

    Object* pianist = assignedScene->findObjectByName("pianist");
    if (pianist != nullptr) {
        pianist->terminate();
    }
}

bool scene2Handler::believersEnterChurch(float dt) {
    if (!animation_initialized) {
        myAnimationHandler.init();

        createBelievers();

        objectKeyframe keyframe1;
        objectKeyframe keyframe2;

        Object* believer1 = assignedScene->findObjectByName("believer1");
        if (believer1 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{1, 0, 13}, {0,0, M_PI}, believer1->scale);
            keyframe2.setKeyframe(glm::vec3{1, 0, 8}, {0,0,1.0/2.0*M_PI}, believer1->scale);
            myAnimationHandler.addObject(believer1, keyframe1, keyframe2);
        }

        Object* believer2 = assignedScene->findObjectByName("believer2");
        if (believer2 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-1, 0, 13}, {0,0, M_PI}, believer2->scale);
            keyframe2.setKeyframe(glm::vec3{-1, 0, 8}, {0,0,3.0/2.0*M_PI}, believer2->scale);
            myAnimationHandler.addObject(believer2, keyframe1, keyframe2);
        }

        Object* believer3 = assignedScene->findObjectByName("believer3");
        if (believer3 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{1, 0, 14}, {0,0, M_PI}, believer3->scale);
            keyframe2.setKeyframe(glm::vec3{1, 0, 10}, {0,0,1.0/2.0*M_PI}, believer3->scale);
            myAnimationHandler.addObject(believer3, keyframe1, keyframe2);
        }

        Object* believer4 = assignedScene->findObjectByName("believer4");
        if (believer4 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-1, 0, 14}, {0,0, M_PI}, believer4->scale);
            keyframe2.setKeyframe(glm::vec3{-1, 0, 10}, {0,0,3.0/2.0*M_PI}, believer4->scale);
            myAnimationHandler.addObject(believer4, keyframe1, keyframe2);
        }

        animation_initialized = true;
    }

    float maxTime = 6;
    time += dt;

    if (time > maxTime) {
        myAnimationHandler.animate(1);
        animation_initialized = false;
        time = 0;

        return true;
    }

    float t = time / maxTime;
    myAnimationHandler.animate(t);

    return false;
}

bool scene2Handler::believersSitOnBenches(float dt) {
    if (!animation_initialized) {
        myAnimationHandler.init();

        objectKeyframe keyframe1;
        objectKeyframe keyframe2;

        Object* believer1 = assignedScene->findObjectByName("believer1");
        if (believer1 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{1, 0, 8}, {0,0, 1.0/2.0*M_PI}, believer1->scale);
            keyframe2.setKeyframe(glm::vec3{3, 0, 8}, {0,0,M_PI}, believer1->scale);
            myAnimationHandler.addObject(believer1, keyframe1, keyframe2);
        }

        Object* believer2 = assignedScene->findObjectByName("believer2");
        if (believer2 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-1, 0, 8}, {0,0, 3.0/2.0*M_PI}, believer2->scale);
            keyframe2.setKeyframe(glm::vec3{-3, 0, 8}, {0,0,M_PI}, believer2->scale);
            myAnimationHandler.addObject(believer2, keyframe1, keyframe2);
        }

        Object* believer3 = assignedScene->findObjectByName("believer3");
        if (believer3 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{1, 0, 10}, {0,0, 1.0/2.0*M_PI}, believer3->scale);
            keyframe2.setKeyframe(glm::vec3{3, 0, 10}, {0,0,M_PI}, believer3->scale);
            myAnimationHandler.addObject(believer3, keyframe1, keyframe2);
        }

        Object* believer4 = assignedScene->findObjectByName("believer4");
        if (believer4 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-1, 0, 10}, {0,0, 3.0/2.0*M_PI}, believer4->scale);
            keyframe2.setKeyframe(glm::vec3{-3, 0, 10}, {0,0,M_PI}, believer4->scale);
            myAnimationHandler.addObject(believer4, keyframe1, keyframe2);
        }

        animation_initialized = true;
    }

    float maxTime = 3;
    time += dt;

    if (time > maxTime) {
        myAnimationHandler.animate(1);
        animation_initialized = false;
        time = 0;

        return true;
    }

    float t = time / maxTime;
    myAnimationHandler.animate(t);

    return false;
}

bool scene2Handler::cameraMoveToAltar(float dt) {
    if (!animation_initialized) {
        myAnimationHandler.init();

        cameraKeyframe keyframe1;
        cameraKeyframe keyframe2;

        keyframe1.setKeyframe({0, 2, 15}, {0, 0, 1});
        keyframe2.setKeyframe({0, 2, 2}, {0, 0, 1});

        myAnimationHandler.addCamera(assignedScene->camera.get(), keyframe1, keyframe2);

        animation_initialized = true;
    }

    float maxTime = 10;
    time += dt;

    if (time > maxTime) {
        animation_initialized = false;
        time = 0;
        return true;
    }

    float t = time / maxTime;
    myAnimationHandler.animate(t);

    return false;
}

bool scene2Handler::staffEnterChurch(float dt) {
    if (!animation_initialized) {
        myAnimationHandler.init();

        createStaff();

        objectKeyframe keyframe1;
        objectKeyframe keyframe2;

        Object* priest = assignedScene->findObjectByName("priest");
        if (priest != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-9, 0, -13}, {-1.57,0, -1.57 + 1.0/3.0 * M_PI}, priest->scale);
            keyframe2.setKeyframe(glm::vec3{0, 0, 0}, {-1.57,0,-1.57}, priest->scale);
            myAnimationHandler.addObject(priest, keyframe1, keyframe2);
        }

        Object* ministrant1 = assignedScene->findObjectByName("ministrant1");
        if (ministrant1 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-10, 0.5, -15}, {0,0, 1.0/3.0 * M_PI}, ministrant1->scale);
            keyframe2.setKeyframe(glm::vec3{-2, 0.5, -3}, {0,0,0}, ministrant1->scale);
            myAnimationHandler.addObject(ministrant1, keyframe1, keyframe2);
        }

        Object* ministrant2 = assignedScene->findObjectByName("ministrant2");
        if (ministrant2 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-8, 0.5, -15}, {0,0, 1.0/3.0 * M_PI}, ministrant2->scale);
            keyframe2.setKeyframe(glm::vec3{2, 0.5, -3}, {0,0,0}, ministrant2->scale);
            myAnimationHandler.addObject(ministrant2, keyframe1, keyframe2);
        }

        Object* pianist = assignedScene->findObjectByName("pianist");
        if (pianist != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-6, 1.01, -15}, {0,0, 1.0/3.0 * M_PI}, pianist->scale);
            keyframe2.setKeyframe(glm::vec3{6, 1.01, -5}, {0,0,0}, pianist->scale);
            myAnimationHandler.addObject(pianist, keyframe1, keyframe2);
        }

        animation_initialized = true;
    }

    float maxTime = 6;
    time += dt;

    if (time > maxTime) {
        myAnimationHandler.animate(1);
        animation_initialized = false;
        time = 0;

        return true;
    }

    float t = time / maxTime;
    myAnimationHandler.animate(t);

    return false;
}

bool scene2Handler::cameraTurnToPeople(float dt) {
    float maxTime = 3;
    time += dt;

    if (time > maxTime) {
        assignedScene->camera->back = {0, 0, -1};
        assignedScene->camera->position = {0, 2, 2};

        animation_initialized = false;
        time = 0;
        return true;
    }

    assignedScene->camera->back = {sin(M_PI * time / maxTime), 0, cos(M_PI * time / maxTime)};
    assignedScene->camera->position = {0, 2, 2};

    return false;
}

bool scene2Handler::sermon(float dt) {
    float maxTime = 3;
    time += dt;

    if (time > maxTime) {
        animation_initialized = false;
        time = 0;
        return true;
    }

    return false;
}

bool scene2Handler::beginHostia(float dt) {
    if (!animation_initialized) {
        myAnimationHandler.init();

        objectKeyframe keyframe1;
        objectKeyframe keyframe2;

        Object* priest = assignedScene->findObjectByName("priest");
        if (priest != nullptr) {
            keyframe1.setKeyframe(glm::vec3{4, 0, 4}, {-1.57,0, -1.57}, priest->scale);
            keyframe2.setKeyframe(glm::vec3{1, 0, 5}, {-1.57,0,-1.57}, priest->scale);
            myAnimationHandler.addObject(priest, keyframe1, keyframe2);
        }

        Object* ministrant1 = assignedScene->findObjectByName("ministrant1");
        if (ministrant1 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-4, 0.5, 4}, {0,0, 0}, ministrant1->scale);
            keyframe2.setKeyframe(glm::vec3{-1, 0.5, 5}, {0,0,0}, ministrant1->scale);
            myAnimationHandler.addObject(ministrant1, keyframe1, keyframe2);
        }

        animation_initialized = true;
    }

    float maxTime = 3;
    time += dt;

    if (time > maxTime) {
        myAnimationHandler.animate(1);
        animation_initialized = false;
        time = 0;

        return true;
    }

    float t = time / maxTime;
    myAnimationHandler.animate(t);

    return false;
}

bool scene2Handler::believersEnterLine(float dt) {
    if (!animation_initialized) {
        myAnimationHandler.init();

        objectKeyframe keyframe1;
        objectKeyframe keyframe2;

        Object* believer1 = assignedScene->findObjectByName("believer1");
        if (believer1 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{1, 0, 8}, {0,0, 3.0/2.0*M_PI}, believer1->scale);
            keyframe2.setKeyframe(glm::vec3{0, 0, 6}, {0,0,M_PI}, believer1->scale);
            myAnimationHandler.addObject(believer1, keyframe1, keyframe2);
        }

        Object* believer2 = assignedScene->findObjectByName("believer2");
        if (believer2 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-1, 0, 8}, {0,0, 1.0/2.0*M_PI}, believer2->scale);
            keyframe2.setKeyframe(glm::vec3{0, 0, 7}, {0,0,M_PI}, believer2->scale);
            myAnimationHandler.addObject(believer2, keyframe1, keyframe2);
        }

        Object* believer3 = assignedScene->findObjectByName("believer3");
        if (believer3 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{1, 0, 10}, {0,0, 3.0/2.0*M_PI}, believer3->scale);
            keyframe2.setKeyframe(glm::vec3{0, 0, 8}, {0,0,M_PI}, believer3->scale);
            myAnimationHandler.addObject(believer3, keyframe1, keyframe2);
        }

        Object* believer4 = assignedScene->findObjectByName("believer4");
        if (believer4 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-1, 0, 10}, {0,0, 1.0/2.0*M_PI}, believer4->scale);
            keyframe2.setKeyframe(glm::vec3{0, 0, 9}, {0,0,M_PI}, believer4->scale);
            myAnimationHandler.addObject(believer4, keyframe1, keyframe2);
        }

        animation_initialized = true;
    }

    float maxTime = 3;
    time += dt;

    if (time > maxTime) {
        myAnimationHandler.animate(1);
        animation_initialized = false;
        time = 0;

        return true;
    }

    float t = time / maxTime;
    myAnimationHandler.animate(t);

    return false;
}

bool scene2Handler::believersLeaveLine(float dt) {
    if (!animation_initialized) {
        myAnimationHandler.init();

        objectKeyframe keyframe1;
        objectKeyframe keyframe2;

        Object* believer1 = assignedScene->findObjectByName("believer1");
        if (believer1 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{0, 0, 6}, {0,0, M_PI}, believer1->scale);
            keyframe2.setKeyframe(glm::vec3{1, 0, 8}, {0,0,1.0/2.0*M_PI}, believer1->scale);
            myAnimationHandler.addObject(believer1, keyframe1, keyframe2);
        }

        Object* believer2 = assignedScene->findObjectByName("believer2");
        if (believer2 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{0, 0, 7}, {0,0, M_PI}, believer2->scale);
            keyframe2.setKeyframe(glm::vec3{-1, 0, 8}, {0,0,3.0/2.0*M_PI}, believer2->scale);
            myAnimationHandler.addObject(believer2, keyframe1, keyframe2);
        }

        Object* believer3 = assignedScene->findObjectByName("believer3");
        if (believer3 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{0, 0, 8}, {0,0, M_PI}, believer3->scale);
            keyframe2.setKeyframe(glm::vec3{1, 0, 10}, {0,0,1.0/2.0*M_PI}, believer3->scale);
            myAnimationHandler.addObject(believer3, keyframe1, keyframe2);
        }

        Object* believer4 = assignedScene->findObjectByName("believer4");
        if (believer4 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{0, 0, 9}, {0,0, M_PI}, believer4->scale);
            keyframe2.setKeyframe(glm::vec3{-1, 0, 10}, {0,0,3.0/2.0*M_PI}, believer4->scale);
            myAnimationHandler.addObject(believer4, keyframe1, keyframe2);
        }

        animation_initialized = true;
    }

    float maxTime = 3;
    time += dt;

    if (time > maxTime) {
        myAnimationHandler.animate(1);
        animation_initialized = false;
        time = 0;

        return true;
    }

    float t = time / maxTime;
    myAnimationHandler.animate(t);

    return false;
}

bool scene2Handler::endHostia(float dt) {
    if (!animation_initialized) {
        myAnimationHandler.init();

        objectKeyframe keyframe1;
        objectKeyframe keyframe2;

        Object* priest = assignedScene->findObjectByName("priest");
        if (priest != nullptr) {
            keyframe1.setKeyframe(glm::vec3{1, 0, 5}, {-1.57,0, -1.57}, priest->scale);
            keyframe2.setKeyframe(glm::vec3{4, 0, 4}, {-1.57,0,-1.57 + M_PI}, priest->scale);
            myAnimationHandler.addObject(priest, keyframe1, keyframe2);
        }

        Object* ministrant1 = assignedScene->findObjectByName("ministrant1");
        if (ministrant1 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-1, 0.5, 5}, {0,0, 0}, ministrant1->scale);
            keyframe2.setKeyframe(glm::vec3{-4, 0.5, 4}, {0,0, M_PI}, ministrant1->scale);
            myAnimationHandler.addObject(ministrant1, keyframe1, keyframe2);
        }

        animation_initialized = true;
    }

    float maxTime = 3;
    time += dt;

    if (time > maxTime) {
        Object* priest = assignedScene->findObjectByName("priest");
        if (priest != nullptr) {
            priest->position = {0, 0, 0};
            priest->rotation = {-1.57,0,-1.57};
        }

        Object *ministrant1 = assignedScene->findObjectByName("ministrant1");
        if (ministrant1 != nullptr) {
            ministrant1->position = {-2, 0.5, -3};
            ministrant1->rotation = {0, 0, 0};
        }

        animation_initialized = false;
        time = 0;

        return true;
    }

    float t = time / maxTime;
    myAnimationHandler.animate(t);

    return false;
}

bool scene2Handler::cameraTurnToStaff(float dt) {
    float maxTime = 3;
    time += dt;

    if (time > maxTime) {
        assignedScene->camera->back = {0, 0, 1};
        assignedScene->camera->position = {0, 2, 2};

        animation_initialized = false;
        time = 0;
        return true;
    }

    assignedScene->camera->back = {sin(M_PI * time / maxTime), 0, -cos(M_PI * time / maxTime)};
    assignedScene->camera->position = {0, 2, 2};

    return false;
}

bool scene2Handler::staffLeaveChurch(float dt) {
    if (!animation_initialized) {
        myAnimationHandler.init();

        objectKeyframe keyframe1;
        objectKeyframe keyframe2;

        Object* priest = assignedScene->findObjectByName("priest");
        if (priest != nullptr) {
            keyframe1.setKeyframe(glm::vec3{0, 0, 0}, {-1.57,0, -1.57}, priest->scale);
            keyframe2.setKeyframe(glm::vec3{-9, 0, -13}, {-1.57,0,-1.57 - 1.0/3.0 * M_PI}, priest->scale);
            myAnimationHandler.addObject(priest, keyframe1, keyframe2);
        }

        Object* ministrant1 = assignedScene->findObjectByName("ministrant1");
        if (ministrant1 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-2, 0.5, -3}, {0,0, 0}, ministrant1->scale);
            keyframe2.setKeyframe(glm::vec3{-10, 0.5, -15}, {0,0,-1.0/3.0 * M_PI}, ministrant1->scale);
            myAnimationHandler.addObject(ministrant1, keyframe1, keyframe2);
        }

        Object* ministrant2 = assignedScene->findObjectByName("ministrant2");
        if (ministrant2 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{2, 0.5, -3}, {0,0, 0}, ministrant2->scale);
            keyframe2.setKeyframe(glm::vec3{-8, 0.5, -15}, {0,0,-1.0/3.0 * M_PI}, ministrant2->scale);
            myAnimationHandler.addObject(ministrant2, keyframe1, keyframe2);
        }

        Object* pianist = assignedScene->findObjectByName("pianist");
        if (pianist != nullptr) {
            keyframe1.setKeyframe(glm::vec3{6, 1.01, -5}, {0,0, 0}, pianist->scale);
            keyframe2.setKeyframe(glm::vec3{-6, 1.01, -15}, {0,0,-1.0/3.0 * M_PI}, pianist->scale);
            myAnimationHandler.addObject(pianist, keyframe1, keyframe2);
        }

        animation_initialized = true;
    }

    float maxTime = 6;
    time += dt;

    if (time > maxTime) {
        myAnimationHandler.animate(1);
        animation_initialized = false;
        time = 0;

        terminateStaff();

        return true;
    }

    float t = time / maxTime;
    myAnimationHandler.animate(t);

    return false;
}

bool scene2Handler::believersLeaveBenches(float dt) {
    if (!animation_initialized) {
        myAnimationHandler.init();

        objectKeyframe keyframe1;
        objectKeyframe keyframe2;

        Object* believer1 = assignedScene->findObjectByName("believer1");
        if (believer1 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{3, 0, 8}, {0,0, M_PI}, believer1->scale);
            keyframe2.setKeyframe(glm::vec3{1, 0, 8}, {0,0,3.0/2.0*M_PI}, believer1->scale);
            myAnimationHandler.addObject(believer1, keyframe1, keyframe2);
        }

        Object* believer2 = assignedScene->findObjectByName("believer2");
        if (believer2 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-3, 0, 8}, {0,0, M_PI}, believer2->scale);
            keyframe2.setKeyframe(glm::vec3{-1, 0, 8}, {0,0,1.0/2.0*M_PI}, believer2->scale);
            myAnimationHandler.addObject(believer2, keyframe1, keyframe2);
        }

        Object* believer3 = assignedScene->findObjectByName("believer3");
        if (believer3 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{3, 0, 10}, {0,0, M_PI}, believer3->scale);
            keyframe2.setKeyframe(glm::vec3{1, 0, 10}, {0,0,3.0/2.0*M_PI}, believer3->scale);
            myAnimationHandler.addObject(believer3, keyframe1, keyframe2);
        }

        Object* believer4 = assignedScene->findObjectByName("believer4");
        if (believer4 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-3, 0, 10}, {0,0, M_PI}, believer4->scale);
            keyframe2.setKeyframe(glm::vec3{-1, 0, 10}, {0,0,1.0/2.0*M_PI}, believer4->scale);
            myAnimationHandler.addObject(believer4, keyframe1, keyframe2);
        }

        animation_initialized = true;
    }

    float maxTime = 3;
    time += dt;

    if (time > maxTime) {
        myAnimationHandler.animate(1);
        animation_initialized = false;
        time = 0;

        return true;
    }

    float t = time / maxTime;
    myAnimationHandler.animate(t);

    return false;
}

bool scene2Handler::believersLeaveChurch(float dt) {
    if (!animation_initialized) {
        myAnimationHandler.init();

        objectKeyframe keyframe1;
        objectKeyframe keyframe2;

        Object* believer1 = assignedScene->findObjectByName("believer1");
        if (believer1 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{1, 0, 8}, {0,0, -1.0/2.0*M_PI}, believer1->scale);
            keyframe2.setKeyframe(glm::vec3{1, 0, 18}, {0,0,0}, believer1->scale);
            myAnimationHandler.addObject(believer1, keyframe1, keyframe2);
        }

        Object* believer2 = assignedScene->findObjectByName("believer2");
        if (believer2 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-1, 0, 8}, {0,0, 1.0/2.0*M_PI}, believer2->scale);
            keyframe2.setKeyframe(glm::vec3{-1, 0, 16}, {0,0,0}, believer2->scale);
            myAnimationHandler.addObject(believer2, keyframe1, keyframe2);
        }

        Object* believer3 = assignedScene->findObjectByName("believer3");
        if (believer3 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{1, 0, 10}, {0,0, -1.0/2.0*M_PI}, believer3->scale);
            keyframe2.setKeyframe(glm::vec3{1, 0, 16}, {0,0,0}, believer3->scale);
            myAnimationHandler.addObject(believer3, keyframe1, keyframe2);
        }

        Object* believer4 = assignedScene->findObjectByName("believer4");
        if (believer4 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-1, 0, 10}, {0,0, 1.0/2.0*M_PI}, believer4->scale);
            keyframe2.setKeyframe(glm::vec3{-1, 0, 14}, {0,0,0}, believer4->scale);
            myAnimationHandler.addObject(believer4, keyframe1, keyframe2);
        }

        animation_initialized = true;
    }

    float maxTime = 6;
    time += dt;

    if (time > maxTime) {
        myAnimationHandler.animate(1);
        animation_initialized = false;
        time = 0;

        terminateBelievers();

        return true;
    }

    float t = time / maxTime;
    myAnimationHandler.animate(t);

    return false;
}

bool scene2Handler::cameraLeaveChurch(float dt) {
    if (!animation_initialized) {
        myAnimationHandler.init();

        cameraKeyframe keyframe1;
        cameraKeyframe keyframe2;

        keyframe1.setKeyframe({0, 2, 2}, {0, 0, -1});
        keyframe2.setKeyframe({0, 2, 18}, {0, 0, -1});

        myAnimationHandler.addCamera(assignedScene->camera.get(), keyframe1, keyframe2);

        animation_initialized = true;
    }

    float maxTime = 10;
    time += dt;

    if (time > maxTime) {
        animation_initialized = false;
        time = 0;
        return true;
    }

    float t = time / maxTime;
    myAnimationHandler.animate(t);

    return false;
}