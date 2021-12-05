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
#include "lavicka.h"
#include "stol.h"
#include "luster.h"
#include "grass_plane.h"
#include "interier.h"
#include "tree.h"
#include "path.h"
#include "carpet.h"
#include "floor.h"

const unsigned int SIZE = 800;

class SceneWindow : public ppgso::Window {
private:
  Scene scene;
  float last_time = 0;
  float counter = 0;

  bool time_1_passed = false;
  bool time_2_passed = false;
  bool time_3_passed = false;
  bool time_4_passed = false;

  int active_scene = 1;

  void initScene(int scene_id) {
    scene.objects.clear();
    active_scene = scene_id;

    // Create a camera
    auto camera = std::make_unique<Camera>(90.0f, 1.0f, 0.1f, 100.0f);
    camera->position.z = -15.0f;
    scene.camera = move(camera);

    if (active_scene == 1) {
        glm::vec3 position_priest = {0,0,-15};
        auto knaz = std::make_unique<Knaz>(position_priest, "Dusan");

        auto path = std::make_unique<Path>();
        auto kostol = std::make_unique<Kostol>();
        auto skybox = std::make_unique<Skybox>();
        auto slnko = std::make_unique<Slnko>();
        auto stol = std::make_unique<Stol>();
        auto grass = std::make_unique<grass_plane>();

        glm::vec3 position_man = {1,0,-16};
        auto man = std::make_unique<Muz>(position_man, "anon1");
        position_man = {-1,0,-16};
        auto man2 = std::make_unique<Muz>(position_man, "anon2");
        position_man = {1,0,-17};
        auto man3 = std::make_unique<Muz>(position_man, "anon3");
        position_man = {-1,0,-17};
        auto man4 = std::make_unique<Muz>(position_man, "anon4");

        glm::vec3 position_tree = {-10, 0, -5};
        auto tree1 = std::make_unique<Tree>(position_tree);
        position_tree = {-10, 0, 10};
        auto tree2 = std::make_unique<Tree>(position_tree);
        position_tree = {0, 0, 20};
        auto tree3 = std::make_unique<Tree>(position_tree);
        position_tree = {10, 0, -5};
        auto tree4 = std::make_unique<Tree>(position_tree);
        position_tree = {10, 0, 10};
        auto tree5 = std::make_unique<Tree>(position_tree);

        scene.objects.push_back(std::move(path));
        scene.objects.push_back(std::move(knaz));
        scene.objects.push_back(std::move(man));
        scene.objects.push_back(std::move(man2));
        scene.objects.push_back(std::move(man3));
        scene.objects.push_back(std::move(man4));
        scene.objects.push_back(std::move(kostol));
        scene.objects.push_back(std::move(skybox));
        scene.objects.push_back(std::move(grass));
        scene.objects.push_back(std::move(slnko));
        scene.objects.push_back(std::move(tree1));
        scene.objects.push_back(std::move(tree2));
        scene.objects.push_back(std::move(tree3));
        scene.objects.push_back(std::move(tree4));
        scene.objects.push_back(std::move(tree5));
    } else if (active_scene == 2) {
        glm::vec3 position_priest = {0,0,0};
        auto knaz = std::make_unique<Knaz>(position_priest, "Dusan");

        auto stol = std::make_unique<Stol>();
        auto interier = std::make_unique<Interier>();
        auto luster = std::make_unique<Luster>();
        auto carpet = std::make_unique<Carpet>();
        auto floor = std::make_unique<Floor>();

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

        scene.objects.push_back(std::move(carpet));
        scene.objects.push_back(std::move(floor));
        scene.objects.push_back(std::move(interier));
        scene.objects.push_back(std::move(stol));

        scene.objects.push_back(std::move(lavicka));
        scene.objects.push_back(std::move(lavicka2));
        scene.objects.push_back(std::move(lavicka3));
        scene.objects.push_back(std::move(lavicka4));
        scene.objects.push_back(std::move(lavicka5));
        scene.objects.push_back(std::move(lavicka6));

        scene.objects.push_back(std::move(knaz));
        scene.objects.push_back(std::move(luster));
    }
  }

public:
  SceneWindow() : Window{"gl10_projekt", SIZE, SIZE} {

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    // Enable polygon culling
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CCW);
    glCullFace(GL_BACK);

    initScene(1);
  }

  void onIdle() override {
      auto current_time = (float) glfwGetTime();
      float dt =  current_time - last_time;
      last_time = current_time;

      // scena 1 je v exterieri kostola
      if (active_scene == 1) {
          float time_1 = 20;
          float time_2 = 5;
          float time_3 = 5;

          // otacanie kamery okolo kostola
          if (!time_1_passed && counter < time_1) {
              float distance = 15;
              counter += dt;

              scene.camera->back = {sin(2 * M_PI * counter / time_1), 0, -cos(2 * M_PI * counter / time_1)};
              scene.camera->position = {distance * sin(2 * M_PI * counter / time_1), 2,
                                        distance * -cos(2 * M_PI * counter / time_1)};
          } else if (!time_1_passed) {
              counter = 0;
              time_1_passed = true;
          // knaz a veriaci vstupuju do kostola
          } else if (!time_2_passed && counter < time_2) {
              counter += dt;

              scene.camera->back = {0, 0, -1};
              scene.camera->position = {0, 2, -15};

              for (auto& picked_object: scene.objects) {
                  if (strcmp(picked_object->name.c_str(), "Dusan") == 0) {
                      picked_object->position.z = -15 + 9 * counter / time_2;
                  } else if (strcmp(picked_object->name.c_str(), "anon1") == 0) {
                      picked_object->position.z = -16 + 9 * counter / time_2;
                  } else if (strcmp(picked_object->name.c_str(), "anon2") == 0) {
                      picked_object->position.z = -16 + 9 * counter / time_2;
                  } else if (strcmp(picked_object->name.c_str(), "anon3") == 0) {
                      picked_object->position.z = -17 + 9 * counter / time_2;
                  } else if (strcmp(picked_object->name.c_str(), "anon4") == 0) {
                      picked_object->position.z = -17 + 9 * counter / time_2;
                  }
              }
          } else if (!time_2_passed) {
              counter = 0;
              time_2_passed = true;

              for (auto& picked_object: scene.objects) {
                  if (strcmp(picked_object->name.c_str(), "Dusan") == 0) {
                      picked_object->is_alive = false;
                  }
              }
          // priblizovanie ku dveram kostola
          } else if (!time_3_passed && counter < time_3) {
              counter += dt;

              scene.camera->back = {0, 0, -1};
              scene.camera->position = {0, 2, -15 + 8 * counter / time_3};
          } else if (!time_3_passed) {
              counter = 0;
              time_3_passed = true;

              time_1_passed = false;
              time_2_passed = false;
              time_3_passed = false;
              initScene(2);
          }
      // scena 2 je v interieri kostola
      } else if (active_scene == 2) {
          /*
          scene.camera->back = {0, 0, 1};
          scene.camera->position = {0, 2, 15};
          */

          float time_1 = 5;
          float time_2 = 5;
          float time_3 = 5;
          float time_4 = 5;

          // priblizovanie kamery ku oltaru
          if (!time_1_passed && counter < time_1) {
              counter += dt;

              scene.camera->back = {0, 0, 1};
              scene.camera->position = {0, 2, 15 - 13*counter/time_1};
          } else if (!time_1_passed) {
              counter = 0;
              time_1_passed = true;
          // otocenie kamery na veriacich
          } else if (!time_2_passed && counter < time_2) {
              counter += dt;

              scene.camera->back = {sin(M_PI * counter / time_1), 0, cos(M_PI * counter / time_1)};
              scene.camera->position = {0, 2, 2};
          } else if (!time_2_passed) {
              counter = 0;
              time_2_passed = true;
          // bohosluzba
          } else if (!time_3_passed && counter < time_3) {
              counter += dt;
          } else if (!time_3_passed) {
              counter = 0;
              time_3_passed = true;
          // odchod z kostola
          } else if (!time_4_passed && counter < time_4) {
              counter += dt;

              scene.camera->back = {0, 0, -1};
              scene.camera->position = {0, 2, 2 + 13 * counter / time_4};
          } else if (!time_4_passed) {
              counter = 0;
              time_4_passed = true;
          }
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
