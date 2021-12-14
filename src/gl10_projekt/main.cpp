#include <iostream>
#include <map>
#include <list>

#include <ppgso/ppgso.h>

#include "camera.h"
#include "scene.h"
#include "animationHandler.h"
#include "scene1Handler.h"
#include "scene2Handler.h"

const unsigned int WIDTH = 1920;
const unsigned int HEIGHT = 1080;

class SceneWindow : public ppgso::Window {
private:
    Scene scene;
    float last_time = 0;

    int active_scene = 1;
    int active_animation = 0;

    scene1Handler myScene1Handler = scene1Handler(&scene);
    scene2Handler myScene2Handler = scene2Handler(&scene);

    void initScene() {
        scene.objects.clear();

        // Create a camera
        auto camera = std::make_unique<Camera>(90.0f, 1.0f, 0.1f, 100.0f);
        scene.camera = move(camera);
    }

public:
    SceneWindow() : Window{"gl10_projekt", WIDTH, HEIGHT} {

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);

        // Enable polygon culling
        glEnable(GL_CULL_FACE);
        glFrontFace(GL_CCW);
        glCullFace(GL_BACK);

        initScene();
    }

    void onIdle() override {
        auto current_time = (float) glfwGetTime();
        float dt =  current_time - last_time;
        last_time = current_time;

        switch (active_scene) {
            case 1:
                switch (active_animation) {
                    case 0:
                        myScene1Handler.initScene({0, 2, -15}, {0, 0, -1});
                        active_animation++;
                        break;
                    case 1:
                        if (myScene1Handler.cameraSpinAroundChurch(dt)) {
                            active_animation++;
                        }
                        break;
                    case 2:
                        if (myScene1Handler.believersEnterChurch(dt)) {
                            active_animation++;
                        }
                        break;
                    case 3:
                        if (myScene1Handler.cameraEnterChurch(dt)) {
                            active_scene = 2;
                            active_animation = 0;
                        }
                        break;
                }
                break;
            case 2:
                switch (active_animation) {
                    case 0:
                        myScene2Handler.initScene();
                        active_animation++;
                        break;
                    case 1:
                        if (myScene2Handler.believersEnterChurch(dt)) {
                            active_animation++;
                        }
                        break;
                    case 2:
                        if (myScene2Handler.believersSitOnBenches(dt)) {
                            active_animation++;
                        }
                        break;
                    case 3:
                        if (myScene2Handler.cameraMoveToAltar(dt)) {
                            active_animation++;
                        }
                        break;
                    case 4:
                        if (myScene2Handler.staffEnterChurch(dt)) {
                            active_animation++;
                        }
                        break;
                    case 5:
                        if (myScene2Handler.cameraTurnToPeople(dt)) {
                            active_animation++;
                        }
                        break;
                    case 6:
                        if (myScene2Handler.sermon(dt)) {
                            active_animation++;
                        }
                        break;
                    case 7:
                        if (myScene2Handler.beginHostia(dt)) {
                            active_animation++;
                        }
                        break;
                    case 8:
                        if (myScene2Handler.believersLeaveBenches(dt)) {
                            active_animation++;
                        }
                        break;
                    case 9:
                        if (myScene2Handler.believersEnterLine(dt)) {
                            active_animation++;
                        }
                        break;
                    case 10:
                        if (myScene2Handler.sermon(dt)) {
                            active_animation++;
                        }
                        break;
                    case 11:
                        if (myScene2Handler.believersLeaveLine(dt)) {
                            active_animation++;
                        }
                        break;
                    case 12:
                        if (myScene2Handler.believersSitOnBenches(dt)) {
                            active_animation++;
                        }
                        break;
                    case 13:
                        if (myScene2Handler.endHostia(dt)) {
                            active_animation++;
                        }
                        break;
                    case 14:
                        if (myScene2Handler.sermon(dt)) {
                            active_animation++;
                        }
                        break;
                    case 15:
                        if (myScene2Handler.cameraTurnToStaff(dt)) {
                            active_animation++;
                        }
                        break;
                    case 16:
                        if (myScene2Handler.staffLeaveChurch(dt)) {
                            active_animation++;
                        }
                        break;
                    case 17:
                        if (myScene2Handler.cameraTurnToPeople(dt)) {
                            active_animation++;
                        }
                        break;
                    case 18:
                        if (myScene2Handler.believersLeaveBenches(dt)) {
                            active_animation++;
                        }
                        break;
                    case 19:
                        if (myScene2Handler.believersLeaveChurch(dt)) {
                            active_animation++;
                        }
                        break;
                    case 20:
                        if (myScene2Handler.cameraLeaveChurch(dt)) {
                            active_scene = 3;
                            active_animation = 0;
                        }
                        break;
                }
                break;
            case 3:
                switch (active_animation) {
                    case 0:
                        myScene1Handler.initScene({0, 2, -7}, {0, 0, 1});
                        active_animation++;
                        break;
                    case 1:
                        if (myScene1Handler.believersLeaveChurch(dt)) {
                            active_animation++;
                        }
                        break;
                    case 2:
                        if (myScene1Handler.cameraLeaveChurch(dt)) {
                            exit(0);
                        }
                        break;
                }
                break;
        }

        // Set gray background
        glClearColor(.5f, .5f, .5f, 0);
        // Clear depth and color buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Update and render all objects

        scene.update((float)dt);
        scene.render();
    }
};

int main() {
    // Initialize our window
    SceneWindow window;

    // Main execution loop
    while (window.pollEvents()) {}

    return EXIT_SUCCESS;
}
