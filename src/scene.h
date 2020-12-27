#ifndef _SCENE_H
#define _SCENE_H
#include <string>

#include "glm/glm.hpp"

struct alignas(16) Primitive {
  int id;                                 // 4
  int type;                               // 8
  alignas(16) glm::vec3 center;           // 24
  float radius;                           // 28
  alignas(16) glm::vec3 leftCornerPoint;  // 44
  alignas(16) glm::vec3 up;               // 60
  alignas(16) glm::vec3 right;            // 76
  int material_id;                        // 80
};

struct alignas(16) Material {
  int brdf_type;             // 4
  alignas(16) glm::vec3 kd;  // 20
  alignas(16) glm::vec3 le;  // 36
};

struct alignas(16) Light {
  int primID;
  alignas(16) glm::vec3 le;
};

class Scene {
 private:
  void setupCornellBoxOriginal() {
    // setup material
    const Material white = createDiffuse(glm::vec3(0.8));
    addMaterial(white);
    const Material red = createDiffuse(glm::vec3(0.8, 0.05, 0.05));
    addMaterial(red);
    const Material green = createDiffuse(glm::vec3(0.05, 0.8, 0.05));
    addMaterial(green);
    const Material lightm = createLight(glm::vec3(34, 19, 10));
    addMaterial(lightm);

    // setup primitives
    Primitive floor =
        createPlane(glm::vec3(0), glm::vec3(0, 0, 559.2), glm::vec3(556, 0, 0));
    floor.material_id = 0;
    addPrimitive(floor);

    Primitive rightWall = createPlane(glm::vec3(0), glm::vec3(0, 548.8, 0),
                                      glm::vec3(0, 0, 559.2));
    rightWall.material_id = 1;
    addPrimitive(rightWall);

    Primitive leftWall = createPlane(
        glm::vec3(556, 0, 0), glm::vec3(0, 0, 559.2), glm::vec3(0, 548.8, 0));
    leftWall.material_id = 2;
    addPrimitive(leftWall);

    Primitive ceil = createPlane(glm::vec3(0, 548.8, 0), glm::vec3(556, 0, 0),
                                 glm::vec3(0, 0, 559.2));
    ceil.material_id = 0;
    addPrimitive(ceil);

    Primitive backWall = createPlane(
        glm::vec3(0, 0, 559.2), glm::vec3(0, 548.8, 0), glm::vec3(556, 0, 0));
    backWall.material_id = 0;
    addPrimitive(backWall);

    Primitive shortBox1 = createPlane(
        glm::vec3(130, 165, 65), glm::vec3(-48, 0, 160), glm::vec3(160, 0, 49));
    shortBox1.material_id = 0;
    addPrimitive(shortBox1);

    Primitive shortBox2 = createPlane(
        glm::vec3(290, 0, 114), glm::vec3(0, 165, 0), glm::vec3(-50, 0, 158));
    shortBox2.material_id = 0;
    addPrimitive(shortBox2);

    Primitive shortBox3 = createPlane(
        glm::vec3(130, 0, 65), glm::vec3(0, 165, 0), glm::vec3(160, 0, 49));
    shortBox3.material_id = 0;
    addPrimitive(shortBox3);

    Primitive shortBox4 = createPlane(
        glm::vec3(82, 0, 225), glm::vec3(0, 165, 0), glm::vec3(48, 0, -160));
    shortBox4.material_id = 0;
    addPrimitive(shortBox4);

    Primitive shortBox5 = createPlane(
        glm::vec3(240, 0, 272), glm::vec3(0, 165, 0), glm::vec3(-158, 0, -47));
    shortBox5.material_id = 0;
    addPrimitive(shortBox5);

    Primitive tallBox1 =
        createPlane(glm::vec3(423, 330, 247), glm::vec3(-158, 0, 49),
                    glm::vec3(49, 0, 159));
    tallBox1.material_id = 0;
    addPrimitive(tallBox1);

    Primitive tallBox2 = createPlane(
        glm::vec3(423, 0, 247), glm::vec3(0, 330, 0), glm::vec3(49, 0, 159));
    tallBox2.material_id = 0;
    addPrimitive(tallBox2);

    Primitive tallBox3 = createPlane(
        glm::vec3(472, 0, 406), glm::vec3(0, 330, 0), glm::vec3(-158, 0, 50));
    tallBox3.material_id = 0;
    addPrimitive(tallBox3);

    Primitive tallBox4 = createPlane(
        glm::vec3(314, 0, 456), glm::vec3(0, 330, 0), glm::vec3(-49, 0, -160));
    tallBox4.material_id = 0;
    addPrimitive(tallBox4);

    Primitive tallBox5 = createPlane(
        glm::vec3(265, 0, 296), glm::vec3(0, 330, 0), glm::vec3(158, 0, -49));
    tallBox5.material_id = 0;
    addPrimitive(tallBox5);

    Primitive light = createPlane(glm::vec3(343, 548.6, 227),
                                  glm::vec3(-130, 0, 0), glm::vec3(0, 0, 105));
    light.material_id = 3;
    addPrimitive(light);
  }

  void setupCornellSphere() {
    // setup material
    const Material white = createDiffuse(glm::vec3(0.8));
    addMaterial(white);
    const Material red = createDiffuse(glm::vec3(0.8, 0.05, 0.05));
    addMaterial(red);
    const Material green = createDiffuse(glm::vec3(0.05, 0.8, 0.05));
    addMaterial(green);
    const Material mirror = createMirror(glm::vec3(1.0));
    addMaterial(mirror);
    const Material glass = createGlass(glm::vec3(1.0));
    addMaterial(glass);
    const Material lightm = createLight(glm::vec3(34, 19, 10));
    addMaterial(lightm);

    // setup primitives
    Primitive floor =
        createPlane(glm::vec3(0), glm::vec3(0, 0, 559.2), glm::vec3(556, 0, 0));
    floor.material_id = 0;
    addPrimitive(floor);

    Primitive rightWall = createPlane(glm::vec3(0), glm::vec3(0, 548.8, 0),
                                      glm::vec3(0, 0, 559.2));
    rightWall.material_id = 1;
    addPrimitive(rightWall);

    Primitive leftWall = createPlane(
        glm::vec3(556, 0, 0), glm::vec3(0, 0, 559.2), glm::vec3(0, 548.8, 0));
    leftWall.material_id = 2;
    addPrimitive(leftWall);

    Primitive ceil = createPlane(glm::vec3(0, 548.8, 0), glm::vec3(556, 0, 0),
                                 glm::vec3(0, 0, 559.2));
    ceil.material_id = 0;
    addPrimitive(ceil);

    Primitive backWall = createPlane(
        glm::vec3(0, 0, 559.2), glm::vec3(0, 548.8, 0), glm::vec3(556, 0, 0));
    backWall.material_id = 0;
    addPrimitive(backWall);

    Primitive sphere1 = createSphere(glm::vec3(186, 100.0, 169.5), 100.0);
    sphere1.material_id = 3;
    addPrimitive(sphere1);

    Primitive sphere2 = createSphere(glm::vec3(393, 120.0, 351), 120.0);
    sphere2.material_id = 4;
    addPrimitive(sphere2);

    Primitive light = createPlane(glm::vec3(343, 548.6, 227),
                                  glm::vec3(-130, 0, 0), glm::vec3(0, 0, 105));
    light.material_id = 5;
    addPrimitive(light);
  }

  void init() {
    // set primitive id
    for (unsigned int i = 0; i < primitives.size(); ++i) {
      primitives[i].id = i;
    }

    // set lights
    for (const auto& primitive : primitives) {
      const Material& material = materials[primitive.material_id];
      if (material.le != glm::vec3(0)) {
        Light light;
        light.primID = primitive.id;
        light.le = material.le;
        lights.push_back(light);
      }
    }
  }

 public:
  std::vector<Primitive> primitives;

  void addPrimitive(const Primitive& primitive) {
    primitives.push_back(primitive);
  }

  std::vector<Material> materials;

  void addMaterial(const Material& material) { materials.push_back(material); }

  std::vector<Light> lights;

  static Primitive createSphere(const glm::vec3& center, float radius) {
    Primitive ret;
    ret.type = 0;
    ret.center = center;
    ret.radius = radius;
    return ret;
  }

  static Primitive createPlane(const glm::vec3& leftCornerPoint,
                               const glm::vec3& right, const glm::vec3& up) {
    Primitive ret;
    ret.type = 1;
    ret.leftCornerPoint = leftCornerPoint;
    ret.right = right;
    ret.up = up;
    return ret;
  }

  static Material createDiffuse(const glm::vec3& kd) {
    Material ret;
    ret.brdf_type = 0;
    ret.kd = kd;
    ret.le = glm::vec3(0);
    return ret;
  }

  static Material createMirror(const glm::vec3& kd) {
    Material ret;
    ret.brdf_type = 1;
    ret.kd = kd;
    ret.le = glm::vec3(0);
    return ret;
  }

  static Material createGlass(const glm::vec3& kd) {
    Material ret;
    ret.brdf_type = 2;
    ret.kd = kd;
    ret.le = glm::vec3(0);
    return ret;
  }

  static Material createLight(const glm::vec3& le) {
    Material ret;
    ret.brdf_type = 0;
    ret.kd = glm::vec3(0);
    ret.le = le;
    return ret;
  }

  Scene() {
    setupCornellBoxOriginal();
    init();
  }
};

#endif