//
//  Vine.h
//  Testing
//
//  Created by Calvin Phung on 9/13/13.
//
//

#ifndef __Vinezors2_0__Vine__
#define __Vinezors2_0__Vine__

#include "Util.h"

// Represents the character (as a vine), currently incomplete.
struct Vine
{
    Ogre::SceneNode* parentNode;
    
    VineMeshType meshType;
    SceneNode *entireVine;
	SceneNode *tip;
    Entity* tipEntity;
	SceneNode *base;
    ParticleSystem* shockwaveEffect;
    SceneNode *boostNode;
    ParticleSystem* boostEffect;
    Vector3 forward;
    float radius;
    
    // Vine-Tunnel information
    Direction loc;
    Direction dest;
    float transition;
    int previousID;
    float previoust;
    int afterID;
    float aftert;
    
    float totalElapsed;
    float wobbleSpeed;
    bool wobbling;
    
	Vine();
	Vine(Ogre::SceneNode* parentNode, Vector3 pos, float radius);
    ~Vine();
	
    void reloadIfNecessary(VineMeshType newMeshType);
    void loadShip();
    void loadBasicShip();
    void loadRunnerShip();
    void loadFlowerShip();
    VineMeshType getMeshType() const;
    SceneNode* getEntireVine() const;
	SceneNode* getTip() const;
    SceneNode* getBase() const;
	Vector3 getPos() const;
	void setPos(Vector3 value);
    Vector3 getForward() const;
	void setForward(Vector3 value);
    float getRadius() const;
    void setQuaternion(Quaternion rot);
    void setVisible(bool value);
    void setWobble(bool value);
    void setShockwave();
    void setBoost();
    
    void updateGate(float elapsed);
    
	void move(Vector3 delta);
	
	void update(float elapsed);
    void setPowerIndication(int indication);
    
    void removeShockwave();
    void removeBoost();
	void removeFromScene();
};

#endif /* defined(__Testing__Vine__) */
