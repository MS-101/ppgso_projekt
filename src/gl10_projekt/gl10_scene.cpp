// Example gl_scene
// - Introduces the concept of a dynamic scene of objects
// - Uses abstract object interface for Update and Render steps
// - Creates a simple game scene with Player, Asteroid and Space objects
// - Contains a generator object that does not render but adds Asteroids to the scene
// - Some objects use shared resources and all object deallocations are handled automatically
// - Controls: LEFT, RIGHT, "R" to reset, SPACE to fire

#include <iostream>
#include <map>
#include <list>

#include <ppgso/ppgso.h>

#include "camera.h"
#include "scene.h"
#include "lampa.h"
#include "knaz.h"
#include "kostol.h"
#include "skybox.h"
#include "muz.h"
#include "slnko.h"
#include "interier.h"

const unsigned int SIZE = 800;

/*!
 * Custom windows for our simple game
 */
class SceneWindow : public ppgso::Window {
private:
  Scene scene;
  float last_time = 0;
  float counter = 0;

  /*!
   * Reset and initialize the game scene
   * Creating unique smart pointers to objects that are stored in the scene object list
   */
  void initScene() {
    scene.objects.clear();

    // Create a camera
    auto camera = std::make_unique<Camera>(90.0f, 1.0f, 0.1f, 100.0f);
    camera->position.z = -15.0f;
    scene.camera = move(camera);

    auto lampa = std::make_unique<Lampa>();
    auto knaz = std::make_unique<Knaz>();
    auto kostol = std::make_unique<Kostol>();
    auto skybox = std::make_unique<Skybox>();
    auto slnko = std::make_unique<Slnko>();
    //auto interier = std::make_unique<Interier>();

    glm::vec3 position_man = {2,0,-10};
    auto man = std::make_unique<Muz>(position_man);

    position_man = {-2,0,-10};
    auto man2 = std::make_unique<Muz>(position_man);

    position_man = {-1,0,-12};
    auto man3 = std::make_unique<Muz>(position_man);

    position_man = {1,0,-12};
    auto man4 = std::make_unique<Muz>(position_man);

    scene.objects.push_back(std::move(knaz));

    scene.objects.push_back(std::move(man));
    scene.objects.push_back(std::move(man2));
    scene.objects.push_back(std::move(man3));
    scene.objects.push_back(std::move(man4));

    scene.objects.push_back(std::move(kostol));
    scene.objects.push_back(std::move(skybox));
    scene.objects.push_back(std::move(slnko));
    //scene.objects.push_back(std::move(lampa));
  }

public:
  /*!
   * Construct custom game window
   */
  SceneWindow() : Window{"gl10_projekt", SIZE, SIZE} {
    //hideCursor();
    glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

    // Initialize OpenGL state
    // Enable Z-buffer
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    // Enable polygon culling
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);

    initScene();
  }

  /*!
   * Window update implementation that will be called automatically from pollEvents
   */
  void onIdle() override {
      auto current_time = (float) glfwGetTime();
      float dt =  current_time - last_time;
      last_time = current_time;

      float time_1 = 8;

      float distance = 16;

      if (counter < time_1) {
          counter += dt;
          scene.camera->back = {sin(2*M_PI*counter/time_1), 0, -cos(2*M_PI*counter/time_1)};
          scene.camera->position = {distance * sin(2*M_PI*counter/time_1), 5, distance * -cos(2*M_PI*counter/time_1)};
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
