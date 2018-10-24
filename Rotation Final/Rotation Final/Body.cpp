#include "Body.h"

Body::Body() {

	mass = 0;//Vectors2D's. SetZero is a function	
	position.SetZero();
	velocity.SetZero();
	acceleration.SetZero();
	force.SetZero();
}

Body::Body(float mass_) {

	mass = mass_;//set in main
	position.SetZero();
	velocity.SetZero();
	acceleration.SetZero();
}

Body::Body(float newMass, Vector2D& newPosition, Vector2D& newVelocity, Vector2D& newAcceleration) {

	mass = newMass;//sets up variables for the class using the 4 parameters
	position = newPosition;
	velocity = newVelocity;
	acceleration = newAcceleration;
}

Body::Body(Vector2D& newPosition, Vector2D& newVelocity, Vector2D& newAcceleration, Vector2D& newforce) {

	position = newPosition;
	velocity = newVelocity;
	acceleration = newAcceleration;
	
}

Body::Body(float mass_, float rotationalInertia_) {

	mass = mass_;
	rotationalInertia = rotationalInertia_;
	angle = 0;
	angularVel = 0;
	angularAcc = 0;
	force.SetZero();
	position.SetZero();
	velocity.SetZero();
	acceleration.SetZero();
}

void Body::Update(float timeStep) {	
	
	angularVel += angularVel + angularAcc * timeStep;//vel.f=vel.i + angacc * time

	angle += angle + (angularVel * timeStep) + 0.5 * (angularAcc*(timeStep * timeStep));// Af=Ai+angvel*time+0.5*angacc(time*time)
    
	force.x += (acceleration.x * cos(angle)) + (acceleration.x * sin(angle) * -1);//force
	force.y += (acceleration.x * sin(angle)) + (acceleration.x * cos(angle));
	
	velocity.x += acceleration.x * timeStep;//velf=veli+acc*time
	velocity.y += acceleration.y * timeStep;

	position.x += (velocity.x * timeStep) + (0.5 * acceleration.x * (timeStep * timeStep));//posf = posi + vel*time+acc/2 * time^2
	position.y += (velocity.y * timeStep) + (0.5 * acceleration.y * (timeStep * timeStep));
}

void Body::ApplyForce(Vector2D& force_) {

	acceleration.x = (force_.x / mass);//5*10^7//
	acceleration.y = (force_.y / mass);//linear vec
}

void Body::ApplyTorque(float torque) {
	
	angularAcc = torque / mass * rotationalInertia;//angAcc=torque/mass*rot^2
}
