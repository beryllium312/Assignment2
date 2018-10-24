#include <iostream>
#include <string>
#include "Vector2D.h"
#include "Body.h"
#include "World.h"
#include <stdio.h>

using namespace std;

int main() {

	Vector2D force(0.0f, 0.0f);

	World world1(force);

	Body* body = new Body(1000000.0f, 26700000000.0f);// setting the mass 1 x 10^6 and rot. intertia 2.67 x 10^10

	body->torque = 0;

	world1.AddOneBody(body);//Adding 1 body in

	world1.body->position.Set(0.0f, 0.0f);//setting postion of the body	

	cout << "Spaceships mass :" << world1.body->mass << endl;

	cout << "Time \t Torque \t Angular Acc. \t Angular Vel. \t Angle \t\t Force x \t Force y \t Accel x \t\t Accel y \t\t Vel x \t\t Vel y \t\t Pos x \t\t Pos y" << std::endl;

	while (world1.elapsedTime >= 0 && world1.elapsedTime <= 60) {

		std::cout << world1.elapsedTime << "\t"
			<< world1.body->torque << "\t"
			<< world1.body->angularAcc << "\t\t"
			<< world1.body->angularVel << "\t\t"
			<< world1.body->angle << "\t\t"
			<< world1.body->force.x << "\t\t"
			<< world1.body->force.y << "\t\t"
			<< world1.body->acceleration.x << "\t\t"
			<< world1.body->acceleration.y << "\t\t\t"
			<< world1.body->velocity.x << "\t\t"
			<< world1.body->velocity.y << "\t\t"
			<< world1.body->position.x << "\t\t"
			<< world1.body->position.y << std::endl;

		if (world1.elapsedTime >= 0.0f && world1.elapsedTime <= 30.5f) {
			//force = Vector2D(5000000.0f, 0.0f);//force
			world1.body->ApplyForce(Vector2D(5000000.0f, 0.0f)); //5 x 10^7
		}

		if (world1.elapsedTime >= 31.0f && world1.elapsedTime <= 50.5f) {
			//force = Vector2D(25000000.0f, 0.0f);
			world1.body->ApplyForce(Vector2D(25000000.0f, 0.0f));//half force
			world1.body->ApplyTorque(629100000.0f);//6 * 10 ^ 8
		}

		if (world1.elapsedTime >= 51.0f && world1.elapsedTime <= 60.0f) {
			//Vector2D force(0.0f, 0.0f);)
			world1.body->ApplyForce(Vector2D(0.0f, 0.0f));
			world1.body->ApplyTorque(0.0f);
		}

		world1.Update(1.0);
	}

	string s; //creating a string
	cin >> s; //keeps the window open

	return 0;
}


