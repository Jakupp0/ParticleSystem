#ifndef PointEmiter_hpp
#define PointEmiter_hpp
#include "AbstractEmiter.hpp"
class PointEmiter : public AbstractEmiter {
public:
    PointEmiter(const ofVec3f&);
    PointEmiter();
    std::vector<std::vector<ofVec3f>> emit(int num) override;
    void set_position(const ofVec3f&) override;
    void update_position(const double& x,const double& y,const double& z) override;
private:
    std::vector<std::vector<ofVec3f>> createParticles(int num) override;
    ofVec3f setRandomParticlePosition() override;
    ofVec3f randomParticleVelocity();
    ofVec3f position;
    ofVec3f velocity;
    
};


#endif /* PointEmiter_hpp */
