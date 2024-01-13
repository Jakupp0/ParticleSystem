#ifndef ParticleInfo_hpp
#define ParticleInfo_hpp
#include <vector>
#include <ofVec3f.h>
class ParticleInfo{
public:
    ParticleInfo();
    ParticleInfo(ofVec3f color);
    ParticleInfo(bool randColor);
    ParticleInfo(const ParticleInfo&);
    ParticleInfo(ParticleInfo&&) noexcept;
    ~ParticleInfo();
    void kill(int id);
    void addParticle( std::vector<std::vector<ofVec3f>>&& particles);
    void update_position(double delta_t);
    void update_velocity(double delta_t);
    void update_force(double delta_t);
    void update_color(double delta_t);
    void collision(int id,const ofVec3f& offset);
    void check_lifespan(double delta_t,double time);
    int particlesnumber();
    ofVec3f return_position(int id) const;
    ofVec3f return_color(int id)    const ;
    ofVec3f createRandomColor();
    ParticleInfo operator =(ParticleInfo&);
    ParticleInfo operator =(ParticleInfo&&) noexcept;
private:
    std::vector<ofVec3f> position;
    std::vector<ofVec3f> velocity;
    std::vector<ofVec3f> force;
    std::vector<ofVec3f> color;
    std::vector<double> mass;
    std::vector<double> lifetime;
    int numberofparticles = 0;
    int alive = 0;
    bool randomColor=false;
    ofVec3f particlesColor{16,125,172};
    
};

#endif /* ParticleInfo_hpp */
