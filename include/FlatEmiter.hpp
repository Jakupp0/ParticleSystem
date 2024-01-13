
#ifndef FlatEmiter_hpp
#define FlatEmiter_hpp
#include "AbstractEmiter.hpp"
#include "ofVec3f.h"
#include <vector>
#include <iostream>
#include <random>
class FlatEmiter : public AbstractEmiter{
public:
    FlatEmiter();
    std::vector<std::vector<ofVec3f>> emit(int) override;
    void set_position(const ofVec3f&) override;
    void update_position(const double& x,const double& y,const double& z) override;
    ofVec3f return_velocity();
    FlatEmiter(ofVec3f,ofVec3f);
private:
    ofVec3f emiter_dimensions={300,300,300};
    ofVec3f position;
    ofVec3f velocity;
    std::vector<std::vector<ofVec3f>> createParticles(int) override;
    ofVec3f setRandomParticlePosition() override;
    
};

#endif /* FlatEmiter_hpp */
