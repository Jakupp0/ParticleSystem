#include "PointEmiter.hpp"
PointEmiter::PointEmiter(){};
PointEmiter::PointEmiter(const ofVec3f& position){
    this->position = position;
    
}


std::vector<std::vector<ofVec3f>> PointEmiter::emit(int num){
    return createParticles(num);
}
void PointEmiter::set_position(const ofVec3f& pos) {
    this->position = pos;}

void PointEmiter::update_position(const double& x,const double& y,const double& z){
    position.x+=x;
    position.y+=y;
    position.z+=z;
}

std::vector<std::vector<ofVec3f>> PointEmiter::createParticles(int num){
    std::vector<std::vector<ofVec3f>> newParticlesinfo;
    for(int i=0;i<num;i++)
    {
        std::vector<ofVec3f> temp;
        temp.push_back(setRandomParticlePosition());
        temp.push_back(randomParticleVelocity());
        newParticlesinfo.push_back(std::move(temp));
    }
    return newParticlesinfo;
}
ofVec3f PointEmiter::setRandomParticlePosition(){
    ofVec3f vector;
    vector.x = this->position.x;
    vector.y = this->position.y;
    vector.z = this->position.z;
    return vector;
}
ofVec3f PointEmiter::randomParticleVelocity(){
    ofVec3f vector;
    vector.x = (double)((std::rand()%1000)-500)/10000;
    vector.y = (double)((std::rand()%1000)-500)/10000;
    vector.z = (double)((std::rand()%1000)-500)/10000;
    return vector;
}

