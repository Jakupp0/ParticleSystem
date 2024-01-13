#include "ofApp.h"
#include <iostream>
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    std::srand(std::time(nullptr));
    ofEnableDepthTest();
    ofSetSphereResolution(20);

            
    //initializing "cloud"
    ofVec3f pos{0,0,0};
    cubePosition.set(0, 0, 0);
    emiter.set_position(pos);
    generator.startGenerating();
    lastUpdateTime = ofGetElapsedTimeMillis();
    
    //initializing fireworks
    fireworksGenerator.stopGenerating();
    
         
    
    //initializing Spheres
        for(int j=0;j<4;j++)
        {
        spheresVector.emplace_back(300,ofVec3f(0,-800,-2000+j*1000));
        }
        for(int i=0;i<6;i++)
        spheresVector.emplace_back(300,ofVec3f(0,-1600,-2600+i*1000));
    
    

      
}

//--------------------------------------------------------------
void ofApp::update(){
    if (ofGetKeyPressed('w')) {
        cubePosition.z += 5;
       emiter.update_position(0,0,5);
    }
    if (ofGetKeyPressed('s')) {
        cubePosition.z -= 5;
      emiter.update_position(0,0,-5);
    }
    if (ofGetKeyPressed('a')) {
        cubePosition.x -= 5;
      emiter.update_position(-5,0,0);
    }
    if (ofGetKeyPressed('d')) {
        cubePosition.x += 5;
      emiter.update_position(5,0,0);
    }
    if (ofGetKeyPressed('k')) {
              cam.setPosition(cam.getPosition().x, cam.getPosition().y, cam.getPosition().z - 50);
    }
    if (ofGetKeyPressed('l')) {
              cam.setPosition(cam.getPosition().x, cam.getPosition().y, cam.getPosition().z + 50);
    }
    if(ofGetKeyPressed('f'))
    {
        generator.stopGenerating();
        fireworksGenerator.startGenerating();
        fireworks = true;
        cloud = false;
    }
    if(ofGetKeyPressed('c'))
    {
        generator.startGenerating();
        fireworksGenerator.stopGenerating();
        fireworks = false;
        cloud = true;
    }
    if(ofGetKeyPressed('g'))
    {
        ofVec3f pos;
        pos.x  = (rand()%3000)-1500;
        pos.y = rand()%2000;
        pos.z  = (rand()%3000)-1500;
        fireworksEmiter.set_position(pos);
        fireworksParticles.addParticle(fireworksEmiter.emit(fireworksGenerator.generate()));
    }


    
}

//--------------------------------------------------------------
void ofApp::draw(){
    std::cout<<"Number of particles: "<<particles.particlesnumber()<<"\n";
    
    //handling time
    delta_t = (ofGetElapsedTimeMillis() - lastFrameTimeMillis)*20;
    lastFrameTimeMillis = ofGetElapsedTimeMillis();
    
    //drawing objects
    cam.begin();
    
    if(cloud){
        particles.addParticle(emiter.emit(generator.generate()));
        renderEnvironment();
        renderEmiters();
        renderParticles(particles);
        checkCollision(particles, spheresVector);
        
    }
    if(fireworks){
        renderParticles(fireworksParticles);
        
    }
    cam.end();
    
    updateParticles(particles, delta_t);
    updateParticles(fireworksParticles, delta_t);
    
    

}

void ofApp::updateParticles(ParticleInfo& particles,double delta_t){
    particles.check_lifespan(delta_t,50000);
    particles.update_position(delta_t);
    particles.update_force(delta_t);
    particles.update_velocity(delta_t);
}
void ofApp::renderParticles(ParticleInfo& particles){
    for(int i=0;i<particles.particlesnumber();i++)
    {
        auto pos = particles.return_position(i);
        ofPushMatrix();
        ofTranslate(pos);
        ofSetColor(particles.return_color(i).x,particles.return_color(i).y,particles.return_color(i).z);
        ofDrawSphere(5);
        ofPopMatrix();
     
    }
}
void ofApp::renderEmiters(){
    ofPushMatrix();
    ofTranslate(cubePosition);
    ofSetColor(100, 100, 100);
    ofDrawBox(300);
    ofPopMatrix();
}
void ofApp::renderEnvironment()
{
    ofBackground(0);
    for(const auto& sphere : spheresVector)
    {
        
        ofPushMatrix();
        ofSetColor(255, 0, 100);
        ofDrawSphere(sphere.position.x, sphere.position.y, sphere.position.z, sphere.radius);
        ofPopMatrix();
    }
}
void ofApp::checkCollision(ParticleInfo& particles,std::vector<Sphere>& spheresVector){
    for(int i=0;i<particles.particlesnumber();i++)
    {
        for(int j=0;j<spheresVector.size();j++)
        {
            if(spheresVector[j].check_collision(i, particles.return_position(i)))
            {
              
                auto offset =  spheresVector[j].check_border(particles.return_position(i));
                particles.collision(i, offset);
            }
        }
    }

}
//--------------------------------------------------------------
void ofApp::exit(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

