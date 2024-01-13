#ifndef AbstractEmiter_hpp
#define AbstractEmiter_hpp
#include <vector>
#include "ofVec3f.h"
class AbstractEmiter
{
public:
    virtual std::vector<std::vector<ofVec3f>> emit(int num) = 0;
    virtual void set_position(const ofVec3f&) = 0;
    virtual void update_position(const double& x,const double& y,const double& z) = 0;
private:
    virtual std::vector<std::vector<ofVec3f>> createParticles(int num) = 0;
    virtual ofVec3f setRandomParticlePosition() = 0;
};

#endif /* AbstractEmiter_hpp */
