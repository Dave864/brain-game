#pragma once

#include "Polycode3DPhysics.h"
#include "Polycode.h"

using namespace Polycode;

#include "Util.h"
#include "Pod.h"
enum TunnelType { NORMAL_WITH_ONE_POD, NORMAL_WITH_THREE_PODS, NORMAL_WITH_FIVE_PODS, NORMAL_WITH_MANY_PODS, NORMAL_BLANK, CHECKPOINT };

// Contains the components of a segment of a tunnel which include the wall and pod information
class TunnelSlice
{
private:
	Vector3 center;
    Quaternion rot;
	double width;
	double depth;
	
	TunnelType type;
	ScenePrimitive *topLeftWall;
	ScenePrimitive *topWall;
	ScenePrimitive *topRightWall;
	ScenePrimitive *rightWall;
	ScenePrimitive *bottomRightWall;
	ScenePrimitive *bottomWall;
	ScenePrimitive *bottomLeftWall;
	ScenePrimitive *leftWall;
    SceneMesh *intermediateSegment;
    
	vector<Pod *> pods;
    double t;
    
public:
	TunnelSlice();
	TunnelSlice(CollisionScene *scene, TunnelType type, Vector3 center, Quaternion rot, Number width, Number depth);
	
    void initWalls();
    
    TunnelType getType();
    Quaternion getQuaternion();
	Vector3 getCenter();
	Vector3 getCenter(Number t);
	Number getT(Vector3 pos);
    Vector3 getForward();
	Vector3 getUpward();
	Vector3 getRight();
    vector<Pod *> getPods();
    
	vector<Pod *> findCollisions(CollisionScene *scene, SceneEntity *ent) const;
    Vector3 requestPosition(Vector3 path, Direction dir) const;
    
	void move(Vector3 delta);
	void changeWallTexture(String filename);
	void addPod(CollisionScene *scene, Direction loc,  PodType type);
    void connect(CollisionScene* scene, TunnelSlice* next);
    void disconnect(CollisionScene* scene);
    void clearPods(CollisionScene* scene);
    void updateGrowth(double nt);
    
    void rejuvenate(CollisionScene *scene, TunnelType type, Vector3 center, Quaternion rot, Number width, Number depth);
    
	void addToCollisionScene(CollisionScene *scene);
	void postAddToCollisionScene(CollisionScene *scene);
	void removeFromCollisionScene(CollisionScene * scene);
};
