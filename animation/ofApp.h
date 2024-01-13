#pragma once

#include "ofMain.h"
#include "ParticleInfo.hpp"
#include "Generator.hpp"
#include "FlatEmiter.hpp"
#include "Sphere.hpp"
#include <vector>
#include "PointEmiter.hpp"
class ofApp : public ofBaseApp{

	public:
		void setup() override;
		void update() override;
		void draw() override;
		void exit() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
        void renderEnvironment();
        void renderEmiters();
        void renderParticles(ParticleInfo&);
        void checkCollision(ParticleInfo&,std::vector<Sphere>&);
        void updateParticles(ParticleInfo&,double);
        bool fireworks = false;
        bool cloud = true;

        

    private:
    ofVec3f cubePosition;
    ofEasyCam cam;
    ParticleInfo particles;
    ParticleInfo fireworksParticles{true};
    Generator generator{30};
    Generator fireworksGenerator{5};
    FlatEmiter emiter{{0,0,0},{300,300,300}};
    PointEmiter fireworksEmiter;
    double lastUpdateTime;
    double delta_t;
    double lastFrameTimeMillis;
    std::vector<Sphere> spheresVector;
    std::vector<PointEmiter> pointsEmiter;
     

    
    
    
    
		
};
