#ifndef BODY_H
#define BODY_H
#include "Vector2D.h"
#include "Vector2D.h"
#include "math.h"

class Body
	
{
public:

	float mass, rotationalInertia;
	float angle, angularVel, angularAcc, torque;
	Vector2D position;
	Vector2D velocity;
	Vector2D acceleration;
	Vector2D force;
	
	Body();

	Body(float newMass); // The constructor. Sets the mass to the given value and everything else to [0, 0]

	Body(float newMass, Vector2D& newPosition, Vector2D& newVelocity, Vector2D& newAcceleration); // Overloaded constructor that sets all member variable to given values

	Body(float mass_, float rotationalInertia_);
	
	Body(Vector2D& newPosition, Vector2D& newVelocity, Vector2D& newAcceleration, Vector2D& newforce);

	void Update(float timeStep); // Updates position and velocity using equations of motion every half second

	void ApplyForce(Vector2D& force); // Updates acceleration using the equation a = F/m

	void ApplyTorque(float torque);
};

#endif

