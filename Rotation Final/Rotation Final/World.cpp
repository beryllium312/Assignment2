#include "World.h"


World::World() {
	elapsedTime = 0;
}

World::World(Vector2D& gravityAccel_, Vector2D& windForce_) {//the constuctor, dont need a destructor
	elapsedTime = 0;
	gravityAccel = gravityAccel_;
	w_force = windForce_;
}
World::World(Vector2D& windForce_) {//the constuctor, dont need a destructor
	elapsedTime = 0;
	w_force = windForce_;
}

void World::AddTwoBodies(Body* body1, Body* body2) {//setting the bodies, is for the vector list

	bodies[0] = body1;
	bodies[1] = body2;
}

void World::AddOneBody(Body* body1) {
	body = body1;
}

void World::Update(double timeStep) {//updates the bodies.
	body->Update(timeStep);	
	elapsedTime += timeStep;

}
