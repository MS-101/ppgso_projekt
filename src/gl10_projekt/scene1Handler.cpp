//
// Created by marti on 13. 12. 2021.
//

#include "scene1Handler.h"

#include "church.h"
#include "skybox.h"
#include "believer.h"
#include "sun.h"
#include "outdoorFloor.h"
#include "tree.h"
#include "path.h"

scene1Handler::scene1Handler(Scene *newScene) {
    assignedScene = newScene;
}

void scene1Handler::initScene(glm::vec3 cameraStartPos, glm::vec3 cameraStartBack) {
    assignedScene->objects.clear();

    // nastavenie kamery
    assignedScene->camera->position = cameraStartPos;
    assignedScene->camera->back = cameraStartBack;

    // hlavne objekty
    auto sun = std::make_unique<Sun>();
    auto church = std::make_unique<Church>();
    auto grass = std::make_unique<outdoorFloor>();
    auto path = std::make_unique<Path>();
    auto skybox = std::make_unique<Skybox>();
    assignedScene->objects.push_back(std::move(church));
    assignedScene->objects.push_back(std::move(skybox));
    assignedScene->objects.push_back(std::move(grass));
    assignedScene->objects.push_back(std::move(sun));
    assignedScene->objects.push_back(std::move(path));

    // stromy
    auto tree1 = std::make_unique<Tree>(glm::vec3{-10, 0, -5});
    auto tree2 = std::make_unique<Tree>(glm::vec3 {-10, 0, 10});
    auto tree3 = std::make_unique<Tree>(glm::vec3{0, 0, 20});
    auto tree4 = std::make_unique<Tree>(glm::vec3{10, 0, -5});
    auto tree5 = std::make_unique<Tree>(glm::vec3{10, 0, 10});
    assignedScene->objects.push_back(std::move(tree1));
    assignedScene->objects.push_back(std::move(tree2));
    assignedScene->objects.push_back(std::move(tree3));
    assignedScene->objects.push_back(std::move(tree4));
    assignedScene->objects.push_back(std::move(tree5));
}

void scene1Handler::createEnteringBelievers() {
    glm::vec3 scaleBelievers = {1.7,1.7,1.7};
    glm::vec3 rotationBelievers = {0,0,0};
    auto believer1 = std::make_unique<Believer>(glm::vec3{1,0,-16}, "believer1", scaleBelievers, rotationBelievers);
    auto believer2 = std::make_unique<Believer>(glm::vec3{-1,0,-16}, "believer2", scaleBelievers, rotationBelievers);
    auto believer3 = std::make_unique<Believer>(glm::vec3{1,0,-17}, "believer3", scaleBelievers, rotationBelievers);
    auto believer4 = std::make_unique<Believer>(glm::vec3{-1,0,-17}, "believer4", scaleBelievers, rotationBelievers);
    assignedScene->objects.push_back(std::move(believer1));
    assignedScene->objects.push_back(std::move(believer2));
    assignedScene->objects.push_back(std::move(believer3));
    assignedScene->objects.push_back(std::move(believer4));
}

void scene1Handler::createLeavingBelievers() {
    glm::vec3 scaleBelievers = {1.7,1.7,1.7};
    glm::vec3 rotationBelievers = {0,0,M_PI};
    auto believer1 = std::make_unique<Believer>(glm::vec3{1,0,-7}, "believer1", scaleBelievers, rotationBelievers);
    auto believer2 = std::make_unique<Believer>(glm::vec3{-1,0,-7}, "believer2", scaleBelievers, rotationBelievers);
    auto believer3 = std::make_unique<Believer>(glm::vec3{1,0,-8}, "believer3", scaleBelievers, rotationBelievers);
    auto believer4 = std::make_unique<Believer>(glm::vec3{-1,0,-8}, "believer4", scaleBelievers, rotationBelievers);
    assignedScene->objects.push_back(std::move(believer1));
    assignedScene->objects.push_back(std::move(believer2));
    assignedScene->objects.push_back(std::move(believer3));
    assignedScene->objects.push_back(std::move(believer4));
}

void scene1Handler::terminateBelievers() {
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

    Object* myPianist = assignedScene->findObjectByName("pianist");
    if (myPianist != nullptr) {
        myPianist->terminate();
    }
}

bool scene1Handler::cameraSpinAroundChurch(float dt) {
    float maxTime = 20;
    time += dt;

    float distance = 15;

    if (time > maxTime) {
        assignedScene->camera->back = {0, 0, -1};
        assignedScene->camera->position = {0, 2, -distance};

        animation_initialized = false;
        time = 0;
        return true;
    }

    assignedScene->camera->back = {sin(2 * M_PI * time / maxTime), 0, -cos(2 * M_PI * time / maxTime)};
    assignedScene->camera->position = {distance * sin(2 * M_PI * time / maxTime), 2, distance * -cos(2 * M_PI * time / maxTime)};

    return false;
}

bool scene1Handler::believersEnterChurch(float dt) {
    if (!animation_initialized) {
        myAnimationHandler.init();

        createEnteringBelievers();

        objectKeyframe keyframe1;
        objectKeyframe keyframe2;

        Object* believer1 = assignedScene->findObjectByName("believer1");
        if (believer1 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{1, 0, -16}, believer1->rotation, believer1->scale);
            keyframe2.setKeyframe(glm::vec3{1, 0, -7}, believer1->rotation, believer1->scale);
            myAnimationHandler.addObject(believer1, keyframe1, keyframe2);
        }

        Object* believer2 = assignedScene->findObjectByName("believer2");
        if (believer2 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-1, 0, -16}, believer2->rotation, believer2->scale);
            keyframe2.setKeyframe(glm::vec3{-1, 0, -7}, believer2->rotation, believer2->scale);
            myAnimationHandler.addObject(believer2, keyframe1, keyframe2);
        }

        Object* believer3 = assignedScene->findObjectByName("believer3");
        if (believer3 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{1, 0, -17}, believer3->rotation, believer3->scale);
            keyframe2.setKeyframe(glm::vec3{1, 0, -8}, believer3->rotation, believer3->scale);
            myAnimationHandler.addObject(believer3, keyframe1, keyframe2);
        }

        Object* believer4 = assignedScene->findObjectByName("believer4");
        if (believer4 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-1, 0, -17}, believer4->rotation, believer4->scale);
            keyframe2.setKeyframe(glm::vec3{-1, 0, -8}, believer4->rotation, believer4->scale);
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

bool scene1Handler::cameraEnterChurch(float dt) {
    if (!animation_initialized) {
        myAnimationHandler.init();

        cameraKeyframe keyframe1;
        cameraKeyframe keyframe2;

        keyframe1.setKeyframe({0, 2, -15}, {0, 0, -1});
        keyframe2.setKeyframe({0, 2, -7}, {0, 0, -1});

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

bool scene1Handler::believersLeaveChurch(float dt) {
    if (!animation_initialized) {
        myAnimationHandler.init();

        createLeavingBelievers();

        objectKeyframe keyframe1;
        objectKeyframe keyframe2;

        Object* believer1 = assignedScene->findObjectByName("believer1");
        if (believer1 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{1, 0, -7}, believer1->rotation, believer1->scale);
            keyframe2.setKeyframe(glm::vec3{1, 0, -23}, believer1->rotation, believer1->scale);
            myAnimationHandler.addObject(believer1, keyframe1, keyframe2);
        }

        Object* believer2 = assignedScene->findObjectByName("believer2");
        if (believer2 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-1, 0, -7}, believer2->rotation, believer2->scale);
            keyframe2.setKeyframe(glm::vec3{-1, 0, -23}, believer2->rotation, believer2->scale);
            myAnimationHandler.addObject(believer2, keyframe1, keyframe2);
        }

        Object* believer3 = assignedScene->findObjectByName("believer3");
        if (believer3 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{1, 0, -8}, believer3->rotation, believer3->scale);
            keyframe2.setKeyframe(glm::vec3{1, 0, -24}, believer3->rotation, believer3->scale);
            myAnimationHandler.addObject(believer3, keyframe1, keyframe2);
        }

        Object* believer4 = assignedScene->findObjectByName("believer4");
        if (believer4 != nullptr) {
            keyframe1.setKeyframe(glm::vec3{-1, 0, -8}, believer4->rotation, believer4->scale);
            keyframe2.setKeyframe(glm::vec3{-1, 0, -24}, believer4->rotation, believer4->scale);
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

bool scene1Handler::cameraLeaveChurch(float dt) {
    if (!animation_initialized) {
        myAnimationHandler.init();

        cameraKeyframe keyframe1;
        cameraKeyframe keyframe2;

        keyframe1.setKeyframe({0, 2, -7}, {0, 0, 1});
        keyframe2.setKeyframe({0, 2, -20}, {0, 0, 1});

        myAnimationHandler.addCamera(assignedScene->camera.get(), keyframe1, keyframe2);

        animation_initialized = true;
    }

    float maxTime = 6;
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