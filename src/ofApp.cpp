#include "ofApp.h"

/*
 texture patterns can be randomized
 
 colors for users:
 161,24,87 - purple
 255,153,0 - orange
 50,153,187 - blue
 
 */


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetVerticalSync(true);
    
    //set up network
    server.setup(10002);
    server.setMessageDelimiter("vnet");
    
//    ofxUDPManager
    udpReceive.Create();
    udpReceive.Bind(10003);
    udpReceive.SetNonBlocking(true);
    
    
    // set up values of objects
    disc.setup();
    
    
    //    sound.setup(&disc);
    
    // set up game costs
//    costRadius = -2;
//    costDensity = -2;
//    costRotation = -2;
//    costTexture = -2;
//    costMute = -1;
//    costMove = -1;
//    costSpike = -2;
//    costCreate = -20;
//    reward = 3;


    costRadius = 0;
    costDensity = 0;
    costRotation = 0;
    costTexture = 0;
    costMute = 0;
    costMove = 0;
    costSpike = 0;
    costCreate = 0;
    reward = 0;
}

//--------------------------------------------------------------
void ofApp::exit(){
    
    for(int i = 0; i < players.size(); i++){
        delete players[i];
    }
    
}
//--------------------------------------------------------------

void ofApp::update(){
    
    
    
    disc.update();
    
    char udpMessage[1000];
    udpReceive.Receive(udpMessage,1000);
    string message = udpMessage;
    if(message.length()>0){
        
        udpReceived = ofSplitString(message, "//");
        udpTitle = received[0];
        
        
        /* these will be udp messages
         rot
         rad
         den
         tex
         spk
         mut
         mov
         movR
         movA
         stpA
         rstA
         z
         zA
         cnt - counter
         lfe
         opi - other players index
         */
        
        if (udpTitle == "rot"){
            vector<string> nameValue;
            nameValue = ofSplitString(received[1], ": ");
            int index = ofToInt(nameValue[0]);
            
            disc.setRotationSpeed(index, ofToFloat(nameValue[1]));
        }
        
        if (udpTitle == "rad"){
            vector<string> nameValue;
            nameValue = ofSplitString(received[1], ": ");
            int index = ofToInt(nameValue[0]);
            float newValue = ofToFloat(nameValue[1]);
            float oldValue = disc.getThickness(index);
            
            // prepare event record
//            string time = ofToString(ofGetElapsedTimeMillis());
//            string IP = received[2];
//            string parameter = udpTitle;
//            string change;
//            if (newValue > oldValue) change = "inc";
//            else if (newValue < oldValue) change = "dec";
//            
//            if(newValue != oldValue){
//                // set change
//                disc.setThickness(index, newValue);
//                
//                //add to eventList
//                eventAdd(time, IP, parameter, change);
//                
//                //check and remove similar
//                eventRemoveSame(time, IP, parameter, change);
//                
//                //reward if match with others
//                eventMatch(IP, parameter, change);
//                
//            }
        }
        
        
        if (udpTitle == "den"){
            vector<string> nameValue;
            nameValue = ofSplitString(received[1], ": ");
            int index = ofToInt(nameValue[0]);
            int newValue = ofToFloat(nameValue[1]);
            int oldValue = disc.getDensity(index);
            
            // prepare event record
//            string time = ofToString(ofGetElapsedTimeMillis());
//            string IP = received[2];
//            string parameter = title;
//            string change;
//            if (newValue > oldValue) change = "inc";
//            else if (newValue < oldValue) change = "dec";
//            
//            if(newValue != oldValue){
//                // set change
//                disc.setDensity(index, newValue);
//                
//                //add to eventList
//                eventAdd(time, IP, parameter, change);
//                
//                //check and remove similar
//                eventRemoveSame(time, IP, parameter, change);
//                
//                //reward if match with others
//                eventMatch(IP, parameter, change);
//            }
        }
        
        if (udpTitle == "tex"){
            vector<string> nameValue;
            nameValue = ofSplitString(received[1], ": ");
            int index = ofToInt(nameValue[0]);
            int newValue = ofToInt(nameValue[1]);
            int oldValue = disc.getTexture(index);
            
            // prepare event record
//            string time = ofToString(ofGetElapsedTimeMillis());
//            string IP = received[2];
//            string parameter = title;
//            string change = ofToString(newValue);
//            
//            if(newValue != oldValue){
//                // set change
//                disc.setTexture(index, newValue);
//                
//                //add to eventList
//                eventAdd(time, IP, parameter, change);
//                
//                //check and remove similar
//                eventRemoveSame(time, IP, parameter, change);
//                
//                //reward if match with others
//                eventMatch(IP, parameter, change);
//            }
            
            
            
        }
        
        if (udpTitle == "spk"){
            
            vector<string> nameValue;
            nameValue = ofSplitString(received[1], ": ");
            int index = ofToInt(nameValue[0]);
            int newValue = ofToFloat(nameValue[1]);
            int oldValue = disc.getSpikeDistance(index);
            
            // prepare event record
//            string time = ofToString(ofGetElapsedTimeMillis());
//            string IP = received[2];
//            string parameter = title;
//            string change;
//            if (newValue > oldValue) change = "inc";
//            else if (newValue < oldValue) change = "dec";
//            
//            if(newValue != oldValue){
//                
//                // set change
//                disc.setSpikeDistance(index, newValue);
//                
//                //add to eventList
//                eventAdd(time, IP, parameter, change);
//                
//                //check and remove similar
//                eventRemoveSame(time, IP, parameter, change);
//                
//                //reward if match with others
//                eventMatch(IP, parameter, change);
//            }
            
            
            
        }
        
        if (udpTitle == "mut"){
            vector<string> nameValue;
            nameValue = ofSplitString(received[1], ": ");
            int index = ofToInt(nameValue[0]);
            int newValue = ofToInt(nameValue[1]);
            int oldValue = disc.isMute(index);
            
            // prepare event record
//            string time = ofToString(ofGetElapsedTimeMillis());
//            string IP = received[2];
//            string parameter = title;
//            string change;
//            if (newValue > oldValue) change = "inc";
//            else if (newValue < oldValue) change = "dec";
//            
//            if(newValue != oldValue){
//                // set change
//                disc.setMute(index, newValue);
//                
//                //add to eventList
//                eventAdd(time, IP, parameter, change);
//                
//                //check and remove similar
//                eventRemoveSame(time, IP, parameter, change);
//                
//                //reward if match with others
//                eventMatch(IP, parameter, change);
//            }
        }
        
        if (udpTitle == "mov"){
            vector<string> nameValue;
            nameValue = ofSplitString(received[1], ": ");
            int index = ofToInt(nameValue[0]);
            int newValue = ofToInt(nameValue[1]);
            int oldValue = disc.isMoving(index);
            
            
            // prepare event record
//            string time = ofToString(ofGetElapsedTimeMillis());
//            string IP = received[2];
//            string parameter = title;
//            string change;
//            if (newValue > oldValue) change = "inc";
//            else if (newValue < oldValue) change = "dec";
//            
//            if(newValue != oldValue){
//                // set change
//                disc.setMoving(index, newValue);
//                
//                //add to eventList
//                eventAdd(time, IP, parameter, change);
//                
//                //check and remove similar
//                eventRemoveSame(time, IP, parameter, change);
//                
//                //reward if match with others
//                eventMatch(IP, parameter, change);
//            }
            
        }
        
        if (udpTitle == "movR"){
            int index = ofToInt(received[1]);
            
            // prepare event record
//            string time = ofToString(ofGetElapsedTimeMillis());
//            string IP = received[2];
//            string parameter = title;
//            string change = "reset";
//            
//            // set change
//            disc.resetPerlin[index] = 1;
//            
//            //add to eventList
//            eventAdd(time, IP, parameter, change);
//            
//            //check and remove similar
//            eventRemoveSame(time, IP, parameter, change);
//            
//            //reward if match with others
//            eventMatch(IP, parameter, change);
//        }

            if (udpTitle == "movA"){
                for(int i = 0; i<disc.getDiscIndex(); i++){
                    disc.setMoving(i, 1);
                }
            }
            
            if (udpTitle == "stpA"){
                for(int i = 0; i<disc.getDiscIndex(); i++){
                    disc.setMoving(i, 0);
                }
            }
            
            if (udpTitle == "rstA"){
                for(int i = 0; i<disc.getDiscIndex(); i++){
                    disc.resetPerlin[i] = 1;
                }
            }
            
            if (udpTitle == "z"){
                vector<string> nameValue;
                nameValue = ofSplitString(received[1], ": ");
                disc.setPosition(ofToInt(nameValue[0]), ofToFloat(nameValue[1]));
            }
            
            if (udpTitle == "zA"){
                for (int i = 1; i < received.size()-1; i++) {
                    vector<string> nameValue;
                    nameValue = ofSplitString(received[i], ": ");
                    disc.setPosition(ofToInt(nameValue[0]), ofToFloat(nameValue[1]));
                }
            }
            
            if (udpTitle == "ctr"){
                vector<string> nameValue;
                nameValue = ofSplitString(received[1], ": ");
                disc.setCounter(ofToInt(nameValue[0]), ofToInt(nameValue[1]));
            }
            
            if (udpTitle == "lfe"){
                Player *_player = NULL;
                for(int j = 1; j < received.size(); j++ ){
                    vector<string> playerData = ofSplitString(received[j], ": ");
                    if (playerData[0] == "IP"){
                        for (int k = 0; k < players.size(); k++) {
                            if(playerData[1] == players[k]->getIP()) {
                                _player = players[k];
                                break;
                            }
                        }
                    }
                    if (playerData[0] == "lifeChange" && _player != NULL) _player->changeLife(ofToFloat(playerData[1]));
                }
            }
            
            if (udpTitle == "opi"){
                for(int i = 1; i < received.size(); i++ ){
                    vector<string> playerData = ofSplitString(received[i], ": ");
                    int thisPlayer;
                    if (playerData[0] == "IP"){
                        for (int j = 0; j < players.size(); j++) {
                            if(playerData[1] == players[j]->getIP()) {
                                thisPlayer = j;
                                break;
                            }
                        }
                    }
                    if (playerData[0] == "index") players[thisPlayer]->setDiscIndex(ofToInt(playerData[1]));
                }
            }
            
            if (udpTitle == "bye"){
                for (int j = 0; j < players.size(); j++) {
                    if(received[1] == players[j]->getNick()) {
                        players[j]->setConnection(false);
                        players[j]->setDiscIndex(-1);
                    }
                }
            }

        
        //send UDP message to others
        string thisIP = received[2];
        for(int i = 0; i < players.size(); i++){
            
            if(players[i]->getIP() != thisIP){
                udpSend[i].Send(udpMessage, sizeof(udpMessage));
            }
            
        }
        
        
    }
    
    
    for ( int i = 0; i < server.getLastID(); i++ ) {
        if(server.isClientConnected(i)) {
            string str = server.receive(i);
            if(str.length()>0){
                received = ofSplitString(str, "//");
                title = received[0];
                
                ////////////send to all other clients////////
                for (int j = 0; j < server.getLastID(); j++) {
                    if(j != i && title != "hello") server.send(j, str);
                }
                
                /////////////// initialize /////////////////
                if (title == "hello") {
                    
                    Player* _player = new Player();
                    string thisIP = server.getClientIP(i);
                    _player->setIP(thisIP);
                    bool rejoin = false;
                    for(int j = 0; j < players.size(); j++){
                        if(_player->getIP() == players[j]->getIP()) {
                            _player = players[j];   // if the IP matches do not create new player
                            rejoin = true;
                            break;
                        }
                    }
                    if(rejoin == false) {           // make new player
                        players.push_back(_player);
                        _player->setLife(100);
                        _player->setDiscIndex(-1);
                        _player->setColorByIndex(players.size());
                        _player->setNick(received[1]);
                        
                        //create udp sender
                        ofxUDPManager udpSender;
                        udpSender.Create();
                        udpSender.Connect(_player->getIP().c_str(), 10003);
                        udpSender.SetNonBlocking(true);
                        udpSend.push_back(udpSender);
                        
                    }
                    _player->setConnection(true);
                    
                    // send player status
                    string playerInfo;
                    playerInfo += "playerInfo//";
                    playerInfo += "IP: " + ofToString(_player->getIP()) + "//";
                    playerInfo += "color: " + ofToString(_player->getColor()) + "//";
                    playerInfo += "life: " + ofToString(_player->getLife()) + "//";
                    playerInfo += "index: " + ofToString(_player->getDiscIndex()) + "//";
                    if(rejoin == true) playerInfo += "nick: " + _player->getNick() + "//";
                    server.send(i, playerInfo);
                    
                    
                    
                    
                    //if there are other players, also send their info
                    if(players.size() > 1){
                        for(int j = 0; j < players.size(); j++){
                            if( players[j] != _player && players[j]->isConnected()){
                                string otherPlayers = "otherPlayers//";
                                otherPlayers += "IP: " + ofToString(players[j]->getIP()) + "//";
                                otherPlayers += "color: " + ofToString(players[j]->getColor()) + "//";
                                otherPlayers += "life: " + ofToString(players[j]->getLife()) + "//";
                                otherPlayers += "index: " + ofToString(players[j]->getDiscIndex()) + "//";
                                otherPlayers += "nick: " + players[j]->getNick() + "//";
                                server.send(i, otherPlayers);
                            }
                        }
                    }
                    
                    
                    //send player information to all other clients
                    string newPlayerInfo;
                    newPlayerInfo += "otherPlayers//";
                    newPlayerInfo += "IP: " + ofToString(_player->getIP()) + "//";
                    newPlayerInfo += "color: " + ofToString(_player->getColor()) + "//";
                    newPlayerInfo += "life: " + ofToString(_player->getLife()) + "//";
                    newPlayerInfo += "index: " + ofToString(_player->getDiscIndex()) + "//";
                    newPlayerInfo += "nick: " + _player->getNick() + "//";
                    for (int j = 0; j < server.getLastID(); j++) {
                        if(j != i) server.send(j, newPlayerInfo);
                    }
                    
                    //send game costs
                    string costs = "costs//";
                    costs += "costRadius: " + ofToString(costRadius) + "//";
                    costs += "costDensity: " + ofToString(costDensity) + "//";
                    costs += "costRotation: " + ofToString(costRotation) + "//";
                    costs += "costTexture: " + ofToString(costTexture) + "//";
                    costs += "costMute: " + ofToString(costMute) + "//";
                    costs += "costMove: " + ofToString(costMove) + "//";
                    costs += "costSpike: " + ofToString(costSpike) + "//";
                    costs += "costCreate: " + ofToString(costCreate) + "//";
                    costs += "reward: " + ofToString(reward) + "//";
                    server.send(i, costs);
                    
                    //prepare to send the current state of the server
                    string state;
                    state += "state//";
                    state += "discIndex: " + ofToString(disc.getDiscIndex()) + "//";
                    for(int j = 0; j < disc.getDiscIndex(); j++){
                        state += "radius"+ofToString(j) + ": " + ofToString(disc.getRadius(j)) + "//";
                        state += "rotation"+ofToString(j) + ": " + ofToString(disc.getRotation(j)) + "//";
                        state += "rotationSpeed"+ofToString(j) + ": " + ofToString(disc.getNetRotationSpeed(j)) + "//";
                        state += "density"+ofToString(j) + ": " + ofToString(disc.getDensity(j)) + "//";
                        state += "texture"+ofToString(j) + ": " + ofToString(disc.getTexture(j)) + "//";
                        state += "zPosition"+ofToString(j) + ": " + ofToString(disc.getPosition(j)) + "//";
                        state += "spike"+ofToString(j) + ": " + ofToString(disc.getSpikeDistance(j)) + "//";
                        state += "seed"+ofToString(j) + ": " + ofToString(disc.getSeed(j)) + "//";
                        state += "counter"+ofToString(j) + ": "+ ofToString(disc.getCounter(j)) + "//";
                        state += "mute"+ofToString(j) + ": " + ofToString(disc.isMute(j)) + "//";
                        state += "move"+ofToString(j) + ": " + ofToString(disc.isMoving(j)) + "//";
                    }
                    server.send(i, state);  //send current state to new client
                    
                    
                    cout<< "initialize " + ofToString(server.getClientIP(i)) <<endl;
                    
                }
                /////////////////////////////////////////////
                
                /////////////newDisc////////////////////////
                if ( title == "newDisc" ){
                    
                    Player* _player = new Player();
                    
                    //match IP
                    string thisIP = server.getClientIP(i);
                    _player->setIP(thisIP);
                    for(int j = 0; j < players.size(); j++){
                        if(_player->getIP() == players[j]->getIP()) {
                            _player = players[j];
                            break;
                        }
                    }
                    
                    if(_player != NULL){
                        
                        int total = disc.getDiscIndex();
                        
                        
                        //check if we reach maximum disc number
                        if(total != 9){
                            
                            disc.addDisc();
                            
                            string addDisc = "addDisc//IP: " + _player->getIP() +
                            "//" + "total: " + ofToString(disc.getDiscIndex()) +
                            "//" + "index: " + ofToString(disc.getDiscIndex()-1) +
                            "//" + "seed: " + ofToString(disc.getSeed(disc.getDiscIndex()-1));
                            
                            server.sendToAll(addDisc);
                            
                            //update life
                            _player->changeLife(costCreate);
                            
                            string lifeUpdate = "life//";
                            lifeUpdate += "IP: "+ofToString(_player->getIP()) + "//";
                            lifeUpdate += "lifeChange: "+ofToString(costCreate) + "//";
                            server.sendToAll(lifeUpdate);
                            
                        }
                    }
                    
                    
                }
                /////////////single changes//////////////////
                
                
                if (title == "rotationSpeed"){
                    vector<string> nameValue;
                    nameValue = ofSplitString(received[1], ": ");
                    int index = ofToInt(nameValue[0]);
                    
                    disc.setRotationSpeed(index, ofToFloat(nameValue[1]));
                    
                    cout << str << endl;
                }
                
                if (title == "radius"){
                    vector<string> nameValue;
                    nameValue = ofSplitString(received[1], ": ");
                    int index = ofToInt(nameValue[0]);
                    float newValue = ofToFloat(nameValue[1]);
                    float oldValue = disc.getThickness(index);
                    
                    // prepare event record
                    string time = ofToString(ofGetElapsedTimeMillis());
                    string IP = server.getClientIP(i);
                    string parameter = title;
                    string change;
                    if (newValue > oldValue) change = "increase";
                    else if (newValue < oldValue) change = "decrease";
                    
                    if(newValue != oldValue){
                        // set change
                        disc.setThickness(index, newValue);
                        
                        //add to eventList
                        eventAdd(time, IP, parameter, change);
                        
                        //check and remove similar
                        eventRemoveSame(time, IP, parameter, change);
                        
                        //reward if match with others
                        eventMatch(IP, parameter, change);
                        
                    }
                }
                
                if (title == "density"){
                    vector<string> nameValue;
                    nameValue = ofSplitString(received[1], ": ");
                    int index = ofToInt(nameValue[0]);
                    int newValue = ofToFloat(nameValue[1]);
                    int oldValue = disc.getDensity(index);
                    
                    // prepare event record
                    string time = ofToString(ofGetElapsedTimeMillis());
                    string IP = server.getClientIP(i);
                    string parameter = title;
                    string change;
                    if (newValue > oldValue) change = "increase";
                    else if (newValue < oldValue) change = "decrease";
                    
                    if(newValue != oldValue){
                        // set change
                        disc.setDensity(index, newValue);
                        
                        //add to eventList
                        eventAdd(time, IP, parameter, change);
                        
                        //check and remove similar
                        eventRemoveSame(time, IP, parameter, change);
                        
                        //reward if match with others
                        eventMatch(IP, parameter, change);
                    }
                }
                
                if (title == "texture"){
                    vector<string> nameValue;
                    nameValue = ofSplitString(received[1], ": ");
                    int index = ofToInt(nameValue[0]);
                    int newValue = ofToInt(nameValue[1]);
                    int oldValue = disc.getTexture(index);
                    
                    // prepare event record
                    string time = ofToString(ofGetElapsedTimeMillis());
                    string IP = server.getClientIP(i);
                    string parameter = title;
                    string change = ofToString(newValue);
                    
                    if(newValue != oldValue){
                        // set change
                        disc.setTexture(index, newValue);
                        
                        //add to eventList
                        eventAdd(time, IP, parameter, change);
                        
                        //check and remove similar
                        eventRemoveSame(time, IP, parameter, change);
                        
                        //reward if match with others
                        eventMatch(IP, parameter, change);
                    }
                    
                    
                    
                }
                
                if (title == "spike"){
                    
                    vector<string> nameValue;
                    nameValue = ofSplitString(received[1], ": ");
                    int index = ofToInt(nameValue[0]);
                    int newValue = ofToFloat(nameValue[1]);
                    int oldValue = disc.getSpikeDistance(index);
                    
                    // prepare event record
                    string time = ofToString(ofGetElapsedTimeMillis());
                    string IP = server.getClientIP(i);
                    string parameter = title;
                    string change;
                    if (newValue > oldValue) change = "increase";
                    else if (newValue < oldValue) change = "decrease";
                    
                    if(newValue != oldValue){
                        
                        // set change
                        disc.setSpikeDistance(index, newValue);
                        
                        //add to eventList
                        eventAdd(time, IP, parameter, change);
                        
                        //check and remove similar
                        eventRemoveSame(time, IP, parameter, change);
                        
                        //reward if match with others
                        eventMatch(IP, parameter, change);
                    }
                    
                    
                    
                }
                
                if (title == "mute"){
                    vector<string> nameValue;
                    nameValue = ofSplitString(received[1], ": ");
                    int index = ofToInt(nameValue[0]);
                    int newValue = ofToInt(nameValue[1]);
                    int oldValue = disc.isMute(index);
                    
                    // prepare event record
                    string time = ofToString(ofGetElapsedTimeMillis());
                    string IP = server.getClientIP(i);
                    string parameter = title;
                    string change;
                    if (newValue > oldValue) change = "increase";
                    else if (newValue < oldValue) change = "decrease";
                    
                    if(newValue != oldValue){
                        // set change
                        disc.setMute(index, newValue);
                        
                        //add to eventList
                        eventAdd(time, IP, parameter, change);
                        
                        //check and remove similar
                        eventRemoveSame(time, IP, parameter, change);
                        
                        //reward if match with others
                        eventMatch(IP, parameter, change);
                    }
                }
                
                if (title == "move"){
                    vector<string> nameValue;
                    nameValue = ofSplitString(received[1], ": ");
                    int index = ofToInt(nameValue[0]);
                    int newValue = ofToInt(nameValue[1]);
                    int oldValue = disc.isMoving(index);
                    
                    
                    // prepare event record
                    string time = ofToString(ofGetElapsedTimeMillis());
                    string IP = server.getClientIP(i);
                    string parameter = title;
                    string change;
                    if (newValue > oldValue) change = "increase";
                    else if (newValue < oldValue) change = "decrease";
                    
                    if(newValue != oldValue){
                        // set change
                        disc.setMoving(index, newValue);
                        
                        //add to eventList
                        eventAdd(time, IP, parameter, change);
                        
                        //check and remove similar
                        eventRemoveSame(time, IP, parameter, change);
                        
                        //reward if match with others
                        eventMatch(IP, parameter, change);
                    }
                    
                }
                
                if (title == "moveReset"){
                    int index = ofToInt(received[1]);
                    
                    // prepare event record
                    string time = ofToString(ofGetElapsedTimeMillis());
                    string IP = server.getClientIP(i);
                    string parameter = title;
                    string change = "reset";
                    
                    // set change
                    disc.resetPerlin[index] = 1;
                    
                    //add to eventList
                    eventAdd(time, IP, parameter, change);
                    
                    //check and remove similar
                    eventRemoveSame(time, IP, parameter, change);
                    
                    //reward if match with others
                    eventMatch(IP, parameter, change);
                }
                
                
                if (title == "moveAll"){
                    for(int i = 0; i<disc.getDiscIndex(); i++){
                        disc.setMoving(i, 1);
                    }
                }
                
                if (title == "stopAll"){
                    for(int i = 0; i<disc.getDiscIndex(); i++){
                        disc.setMoving(i, 0);
                    }
                }
                
                if (title == "resetAll"){
                    for(int i = 0; i<disc.getDiscIndex(); i++){
                        disc.resetPerlin[i] = 1;
                    }
                }
                
                if (title == "zPosition"){
                    vector<string> nameValue;
                    nameValue = ofSplitString(received[1], ": ");
                    disc.setPosition(ofToInt(nameValue[0]), ofToFloat(nameValue[1]));
                }
                
                if (title == "zPositionAll"){
                    for (int i = 1; i < received.size()-1; i++) {
                        vector<string> nameValue;
                        nameValue = ofSplitString(received[i], ": ");
                        disc.setPosition(ofToInt(nameValue[0]), ofToFloat(nameValue[1]));
                    }
                }
                
                if (title == "counter"){
                    vector<string> nameValue;
                    nameValue = ofSplitString(received[1], ": ");
                    disc.setCounter(ofToInt(nameValue[0]), ofToInt(nameValue[1]));
                }
                
                if (title == "life"){
                    Player *_player = NULL;
                    for(int j = 1; j < received.size(); j++ ){
                        vector<string> playerData = ofSplitString(received[j], ": ");
                        if (playerData[0] == "IP"){
                            for (int k = 0; k < players.size(); k++) {
                                if(playerData[1] == players[k]->getIP()) {
                                    _player = players[k];
                                    break;
                                }
                            }
                        }
                        if (playerData[0] == "lifeChange" && _player != NULL) _player->changeLife(ofToFloat(playerData[1]));
                    }
                }
                
                if (title == "otherPlayersIndex"){
                    for(int i = 1; i < received.size(); i++ ){
                        vector<string> playerData = ofSplitString(received[i], ": ");
                        int thisPlayer;
                        if (playerData[0] == "IP"){
                            for (int j = 0; j < players.size(); j++) {
                                if(playerData[1] == players[j]->getIP()) {
                                    thisPlayer = j;
                                    break;
                                }
                            }
                        }
                        if (playerData[0] == "index") players[thisPlayer]->setDiscIndex(ofToInt(playerData[1]));
                    }
                }
                
                if (title == "goodbye"){
                    cout<< str << endl;
                    for (int j = 0; j < players.size(); j++) {
                        if(server.getClientIP(i) == players[j]->getIP()) {
                            players[j]->setConnection(false);
                            players[j]->setDiscIndex(-1);
                        }
                    }
                }
                /////////////////////////////////////////////
            }
            
        }
        else{
            for(int j = 0; j < players.size(); j++){
                if(server.getClientIP(i) == players[j]->getIP() && players[j]->isConnected()) {
                    players[j]->setConnection(false);
                    server.sendToAll("goodbye//"+players[j]->getNick());
                }
            }
            
        }
    }
    
    //check first list member and remove if older than 10 seconds
    if( eventList.size() > 0){
        int now = ofGetElapsedTimeMillis();
        int oldest = ofToInt(eventList[0][0]);
        if(now - oldest > 5000) eventList.erase(eventList.begin());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(255, 233);
    
    ofSetColor(0);
    ofDrawBitmapString("Server Running", 10, 20);
    int online = 0;
    for(int i = 0; i < players.size(); i++){
        if(players[i]->isConnected()) online++;
    }
    ofDrawBitmapString("Number of Players: "+ofToString(online), 10, 40);
    
    
    //Add names of online players//
    for(int i = 0; i < players.size(); i++){
        
        if(players[i]->isConnected()) ofDrawBitmapString(players[i]->getNick(), 10, 60+i*20);
        
    }
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

//--------------------------------------------------------------
void ofApp::eventMatch(string IP, string parameter, string change){
    
    for (int i = 0; i < eventList.size(); i++) {
        
        //check if other players recently changed the same parameter the same way
        if(IP != eventList[i][1] && parameter == eventList[i][2] && change == eventList[i][3]){
            
            //check which players did and give them points
            for(int j = 0; j < players.size(); j++){
                
                if(players[j]->getIP() == IP || players[j]->getIP() == eventList[i][1])
                {
                    players[j]->changeLife(reward);
                    
                    //send to clients
                    string lifeUpdate = "reward//";
                    lifeUpdate += "IP: "+ players[j]->getIP() + "//";
                    lifeUpdate += "lifeChange: "+ofToString(reward) + "//";
                    
                    server.sendToAll(lifeUpdate);
                    
                }
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::eventAdd(string time, string IP, string parameter, string change){
    
    // form event
    vector<string> newEvent;
    newEvent.push_back(time);
    newEvent.push_back(IP);
    newEvent.push_back(parameter);
    newEvent.push_back(change);
    
    //add to eventList
    eventList.push_back(newEvent);
    
}

//--------------------------------------------------------------
void ofApp::eventRemoveSame(string time, string IP, string parameter, string change){
    
    for (int i = 0; i < eventList.size(); i++) {
        if (eventList[i][0] != time &&      //different time
            eventList[i][1] == IP &&        //same player
            eventList[i][2] == parameter && //same parameter
            eventList[i][3] == change       //same change
            ) {
            //remove that event
            eventList.erase(eventList.begin()+i);
        }
    }
}

//--------------------------------------------------------------
void ofApp::newUDPsender(const char *IP){
    
    ofxUDPManager newUDP;
    newUDP.Create();
    newUDP.Connect(IP, 10003);
    
    
    
}
