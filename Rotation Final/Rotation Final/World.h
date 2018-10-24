#ifndef WORLD_H
#define WORLD_H
#include "Body.h"
#include "Vector2D.h"

class World
{
public:
	World();
	Body* bodies[2];
	Body* body;
	float elapsedTime;
	Vector2D gravityAccel;
	Vector2D w_force;

	World(Vector2D& gravityAccel_, Vector2D& windForce_);
	void AddTwoBodies(Body* body1, Body* body2);
	void AddOneBody(Body* body1);
	World(Vector2D& windForce_);
	void Update(double timeStep);
};
#endif

