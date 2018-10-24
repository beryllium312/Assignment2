//Header file
//#pragma once is the default but better to use ifndef so the program is not restricted to windows, and reads staements that re repeated
#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D
{
public:
	float x;
	float y;

	Vector2D(); // Default constructor sets x and y to zero

	Vector2D(float newx, float newy); // Overloaded constructor that sets x & y values

	void Set(float newx, float newy); // Sets x & y values

	void SetZero(); // Sets vector to [0, 0]

	Vector2D(const Vector2D& v);//copy constructor


	void operator += (const Vector2D& v); // add a vector. Using pass-by-const-reference

	void operator -= (const Vector2D& v); // subtract a vector to this vector		

	void operator *= (float a); // multiply by a number “a”


};
#endif

