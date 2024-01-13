#include "ParticleInfo.hpp"

ParticleInfo::ParticleInfo(){
    
    }

ParticleInfo::~ParticleInfo(){
    }
ParticleInfo::ParticleInfo(bool randColor) : randomColor(randColor)
{
}
ParticleInfo::ParticleInfo(ofVec3f RGBcolor){
    for(int i=0;i<particlesnumber();i++){
        color[i] = RGBcolor;
    }
}
ParticleInfo::ParticleInfo(ParticleInfo && rhs) noexcept{
    position= std::move(rhs.position);
    velocity=std::move(rhs.velocity);
    force=std::move(rhs.force);
    color=std::move(rhs.color);
    mass=std::move(rhs.mass);
    lifetime=std::move(rhs.lifetime);
    numberofparticles=rhs.numberofparticles;
    alive=rhs.alive;
    rhs.numberofparticles=0;
    rhs.alive=0;

}
ParticleInfo::ParticleInfo(const ParticleInfo& rhs){
    position= rhs.position;
    velocity=rhs.velocity;
    force=rhs.force;
    color=rhs.color;
    mass=rhs.mass;
    lifetime=rhs.lifetime;
    numberofparticles=rhs.numberofparticles;
    alive=rhs.alive;
}
ParticleInfo ParticleInfo:: operator =(ParticleInfo& rhs){
    position= rhs.position;
    velocity=rhs.velocity;
    force=rhs.force;
    color=rhs.color;
    mass=rhs.mass;
    lifetime=rhs.lifetime;
    numberofparticles=rhs.numberofparticles;
    alive=rhs.alive;
    return *this;

}
ParticleInfo ParticleInfo:: operator =(ParticleInfo&& rhs) noexcept{
    position= std::move(rhs.position);
    velocity=std::move(rhs.velocity);
    force=std::move(rhs.force);
    color=std::move(rhs.color);
    mass=std::move(rhs.mass);
    lifetime=rhs.lifetime;
    numberofparticles=rhs.numberofparticles;
    alive=rhs.alive;
    rhs.numberofparticles=0;
    rhs.alive=0;
    return *this;
}


void ParticleInfo::kill(int id) {
    position.erase(position.begin()+id);
    velocity.erase(velocity.begin()+id);
    force.erase(force.begin()+id);
    color.erase(color.begin()+id);
    mass.erase(mass.begin()+id);
    lifetime.erase(lifetime.begin()+id);
    numberofparticles--;
    alive--;
}
void ParticleInfo::addParticle(std::vector<std::vector<ofVec3f>>&& particles){
    for(int i=0;i<particles.size();i++){
        position.push_back(particles[i][0]);
        velocity.emplace_back(particles[i][1]);
        force.emplace_back(0,-0.00001,0);
        if(randomColor==true){
            color.emplace_back(createRandomColor());
        }
        else{
            color.emplace_back(particlesColor);
        }
        mass.push_back(1);
        lifetime.push_back(0);
        numberofparticles++;
    }
    
}
void ParticleInfo::collision(int id,const ofVec3f& offset){
    
    double speed = std::sqrt(std::pow(velocity[id].x,2)+std::pow(velocity[id].y,2)+std::pow(velocity[id].z,2));
    position[id].x += offset.x;
    position[id].y += offset.y;
    position[id].z += offset.z;
    
    velocity[id].x = offset.x/200;
    velocity[id].y = -offset.y/200;
    velocity[id].z = offset.z/200;
}
int ParticleInfo::particlesnumber()
{
    return numberofparticles;
}

void ParticleInfo::update_position(double delta_t) { 
    for(int i=0;i<numberofparticles;i++)
    {
        position[i].x += delta_t*velocity[i].x;
        position[i].y += delta_t*velocity[i].y;
        position[i].z += delta_t*velocity[i].z;
        
    }
}

void ParticleInfo::update_velocity(double delta_t) { 
    
    for(int i=0;i<numberofparticles;i++)
    {
        velocity[i].x += (delta_t*force[i].x)/mass[i];
        velocity[i].y += (delta_t*force[i].y)/mass[i];
        velocity[i].z += (delta_t*force[i].z)/mass[i];
        
    }
}

void ParticleInfo::update_force(double delta_t) { 
    
}

void ParticleInfo::update_color(double delta_t) { 
    
}

ofVec3f ParticleInfo::return_position(int id) const{
    return position[id];
}
void ParticleInfo::check_lifespan(double delta_t, double time){
    for(int i=0;i<numberofparticles;i++)
    {
        lifetime[i]+=delta_t;
        if(lifetime[i]>time)
        {
            kill(i);
        }
    }
    
    
}
ofVec3f ParticleInfo::return_color(int id) const {
    return color[id];
}

ofVec3f ParticleInfo::createRandomColor(){
    ofVec3f rgb;
    rgb.x = (rand()%255);
    rgb.y =(rand()%255);
    rgb.z =(rand()%255);
    return rgb;
}
