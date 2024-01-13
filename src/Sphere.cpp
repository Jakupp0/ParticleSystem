#include "Sphere.hpp"

Sphere::Sphere(double radius, const ofVec3f& position):
radius(radius),position(position){}


void Sphere::update_position(const ofVec3f& newPosition){
    position.x += newPosition.x;
    position.y += newPosition.y;
    position.z += newPosition.z;
}
bool Sphere::check_collision(int particle_id,const ofVec3f& particle_pos){
    
    double distance = std::sqrt(
            std::pow(particle_pos.x - this->position.x, 2) +
            std::pow(particle_pos.y - this->position.y, 2) +
            std::pow(particle_pos.z - this->position.z, 2)
        );
    if(distance < 5+this->radius)
        return true;
    else
        return false;
        
    
}
ofVec3f Sphere::check_border(const ofVec3f& particle_pos){
        ofVec3f offset{0,0,0};
    double distance = std::sqrt(
            std::pow(particle_pos.x - this->position.x, 2) +
            std::pow(particle_pos.y - this->position.y, 2) +
            std::pow(particle_pos.z - this->position.z, 2)
        );
    double overlapDistance = 5+radius - distance;
        ofVec3f direction;
        direction.x =(particle_pos.x - position.x)/distance;
        direction.y =(particle_pos.y - position.x)/distance;
        direction.z =(particle_pos.z - position.z)/distance;
        
        offset.x = direction.x*overlapDistance;
        offset.y = direction.y*overlapDistance;
        offset.z = direction.z*overlapDistance;
    
    return offset;
}

