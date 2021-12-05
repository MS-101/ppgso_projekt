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
#include "lavicka.h"
#include "stol.h"
#include "luster.h"
#include "interior.h"
#include "knaz_interior.h"

const unsigned int SIZE = 800;

class SceneWindow : public ppgso::Window {
private:
  Scene scene;
  float last_time = 0;
  float counter = 0;

  bool time_1_passed = false;
  bool time_2_passed = false;

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

    glm::vec3 position_man = {2,0,-21};
    auto man = std::make_unique<Muz>(position_man);

    position_man = {-2,0,-22};
    auto man2 = std::make_unique<Muz>(position_man);

    position_man = {-1,0,-23};
    auto man3 = std::make_unique<Muz>(position_man);

    position_man = {1,0,-24};
    auto man4 = std::make_unique<Muz>(position_man);

    //scene.objects.push_back(std::move(knaz));
    //scene.objects.push_back(std::move(man));
    //scene.objects.push_back(std::move(man2));
    //scene.objects.push_back(std::move(man3));
    //scene.objects.push_back(std::move(man4));

    //scene.objects.push_back(std::move(kostol));
    //scene.objects.push_back(std::move(skybox));
    //scene.objects.push_back(std::move(slnko));

    auto stol = std::make_unique<Stol>();
    auto interier = std::make_unique<Interier>();
    auto knaz_interier = std::make_unique<Knaz_interier>();
    auto luster = std::make_unique<Luster>();

    glm::vec3 position_lavicka = {3,0,7};
    auto lavicka = std::make_unique<Lavicka>(position_lavicka);

    position_lavicka = {-3,0,7};
    auto lavicka2 = std::make_unique<Lavicka>(position_lavicka);

    position_lavicka = {3,0,9};
    auto lavicka3 = std::make_unique<Lavicka>(position_lavicka);

    position_lavicka = {-3,0,9};
    auto lavicka4 = std::make_unique<Lavicka>(position_lavicka);

    position_lavicka = {3,0,11};
    auto lavicka5 = std::make_unique<Lavicka>(position_lavicka);

    position_lavicka = {-3,0,11};
    auto lavicka6 = std::make_unique<Lavicka>(position_lavicka);

    scene.objects.push_back(std::move(interier));
    scene.objects.push_back(std::move(stol));

    scene.objects.push_back(std::move(lavicka));
    scene.objects.push_back(std::move(lavicka2));
    scene.objects.push_back(std::move(lavicka3));
    scene.objects.push_back(std::move(lavicka4));
    scene.objects.push_back(std::move(lavicka5));
    scene.objects.push_back(std::move(lavicka6));

    scene.objects.push_back(std::move(knaz_interier));
    scene.objects.push_back(std::move(luster));

  }

public:
  SceneWindow() : Window{"gl10_projekt", SIZE, SIZE} {

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

      float time_1 = 20;
      float time_2 = 5;

      // otacanie kamery okolo kostola
      if (!time_1_passed && counter < time_1) {
          float distance = 15;
          counter += dt;

          scene.camera->back = {sin(2*M_PI*counter/time_1), 0, -cos(2*M_PI*counter/time_1)};
          scene.camera->position = {distance * sin(2*M_PI*counter/time_1), 2, distance * -cos(2*M_PI*counter/time_1)};
      } else if (!time_1_passed) {
          counter = 0;
          time_1_passed = true;
          // priblizovanie ku dveram kostola
      } else if (!time_2_passed && counter < time_2) {
          counter += dt;

          scene.camera->position = {0, 2, -15 + 8*counter/time_2};
      } else if (!time_2_passed){
          counter = 0;
          time_2_passed = true;
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
