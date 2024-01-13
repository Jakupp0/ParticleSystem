#include "FlatEmiter.hpp"

FlatEmiter::FlatEmiter(ofVec3f pos,ofVec3f size) : position(pos), emiter_dimensions(size){}
FlatEmiter::FlatEmiter(){}

ofVec3f FlatEmiter::setRandomParticlePosition(){
    ofVec3f vector;
    vector.x = ((std::rand())%(int)emiter_dimensions.x)-0.5*emiter_dimensions.x+position.x;
    vector.y = position.y -0.5* emiter_dimensions.y;
    vector.z = ((std::rand())%(int)emiter_dimensions.z)-0.5*emiter_dimensions.z+position.z;
    return vector;
}


std::vector<std::vector<ofVec3f>> FlatEmiter::createParticles(int num){
    std::vector<std::vector<ofVec3f>> newParticlesinfo;
    for(int i=0;i<num;i++)
    {
        std::vector<ofVec3f> temp;
        temp.push_back(setRandomParticlePosition());
        temp.push_back(ofVec3f(0,0,0));
        newParticlesinfo.push_back(std::move(temp));
    }
    return newParticlesinfo;
}
std::vector<std::vector<ofVec3f>> FlatEmiter::emit(int num){
    return createParticles(num);
    
}
void FlatEmiter::set_position(const ofVec3f& vec){
    position.x = vec.x;
    position.y = vec.y;
    position.z = vec.z;
}
void FlatEmiter::update_position(const double& x,const double& y,const double& z){
    position.x += x;
    position.y += y;
    position.z += z;
}


ofVec3f FlatEmiter::return_velocity() { 
    return velocity;
}

