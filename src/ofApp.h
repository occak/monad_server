#pragma once

#include "ofMain.h"
#include "Disc.h"
#include "Player.h"
#include "ofxNetwork.h"



class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void newUDPsender(const char *IP);
    
    //ui
    void exit();
  
    //game
    float   costRadius,
    costTexture,
    costDensity,
    costRotation,
    costMute,
    costMove,
    costSpike,
    costCreate,
    reward;
    
    //TCP
    ofxTCPServer server;
    vector<string> received;
    string title;
    
    //UDP
    vector<ofxUDPManager> udpSend;
    ofxUDPManager udpReceive;
    vector<string> udpReceived;
    string udpTitle;
    
    
    vector<vector<string> > eventList;
    
private:
    
    void eventMatch(string IP, string parameter, string change);
    void eventAdd(string time, string IP, string parameter, string change);
    void eventRemoveSame(string time, string IP, string parameter, string change);
    
    bool fullScreen;
    int playerNum;
    
//    Groove groove;
    Disc disc;
    vector<Player *> players;
    
    


};

