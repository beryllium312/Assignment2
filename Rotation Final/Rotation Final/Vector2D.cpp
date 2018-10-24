//Vector cpp
#include "Vector2D.h"


Vector2D::Vector2D() {//constructor
	SetZero();
}

Vector2D::Vector2D(float newx, float newy) {//setting 2 parameter for construct
	Set(newx, newy);
}

Vector2D::Vector2D(const Vector2D& v) {
	x = v.x;
	y = v.y;
	
}

void Vector2D::Set(float newx, float newy) {
	x = newx;
	y = newy;
}

void Vector2D::SetZero() {
	Set(0.0, 0.0);//vectors x and y will be set to the values within the parameters respectively, when this method is called
}


void Vector2D::operator += (const Vector2D& v) {
	y += v.y;
	x += v.x;

}

void Vector2D::operator -= (const Vector2D& v) {
	y -= v.y;
	x -= v.x;
}

void Vector2D::operator *= (float a) {
	y *= a;
	x *= a;
}
