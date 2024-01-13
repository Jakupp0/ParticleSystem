#ifndef Sphere_hpp
#define Sphere_hpp
#include <stdio.h>
#include "ofVec3f.h"

struct Sphere{
    Sphere(double, const ofVec3f&);
    void update_position(const ofVec3f&);
    bool check_collision(int particle_id,const ofVec3f& particle_pos);
    ofVec3f check_border(const ofVec3f& particle_pos);
    double radius;
    ofVec3f position;
};


#endif /* Sphere_hpp */
