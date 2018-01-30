#include "Vector.h"

Vector::Vector()
{
	x, y, x = 0.0f;
}

Vector::Vector(const float X, const float Y, const float Z)
{
	x = X;
	y = Y;
	z = Z;
}
Vector::~Vector()
{
}
float Vector::CalculateDotProduct(const Vector dotVector)
{
	float dotX, dotY, dotZ = 0.0f;
	dotX = x * dotVector.x; dotY = y * dotVector.y; dotZ = z * dotVector.z;
	return dotX + dotY + dotZ;
}
Vector Vector::CalcualteCrossProdcut(const Vector crossVector)
{
	float crossX, crossY, crossZ = 0.0f;
	crossX = y * crossVector.z - z * crossVector.y; crossY = x * crossVector.z - z * crossVector.x; crossZ = x * crossVector.y - y * crossVector.x;
	Vector crossProduct = Vector(crossX, crossY, crossZ);
	return crossProduct;
}
Vector Vector::Normalize(const Vector vector)
{
	float magnitude = sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
	Vector normalVector(vector.x / 2, vector.y / 2, vector.z / 2);
	return normalVector;
}
float Vector::Magnitude(const Vector vector)
{
	return sqrt(pow(vector.x, 2) + pow(vector.y, 2) + pow(vector.z, 2));
}
Vector Vector::operator+(const Vector b)
{
	float addX, addY, addZ;
	addX = this->x + b.x;
	addY = this->y + b.y;
	addZ = this->z + b.z;
	Vector additionVector(addX, addY, addZ);
	return additionVector;
}
Vector Vector::operator-(const Vector b)
{
	float subX, subY, subZ;
	subX = this->x - b.x;
	subY = this->y - b.y;
	subZ = this->z - b.z;
	Vector subVector(subX, subY, subZ);
	return subVector;
}
Vector Vector::operator*(const float b)
{
	float multiX, multiY, multiZ;
	multiX = this->x * b;
	multiY = this->y * b;
	multiZ = this->z * b;
	Vector multiVector(multiX, multiY, multiZ);
	return multiVector;
}
Vector Vector::operator/(const float b)
{
	float divX, divY, divZ;
	divX = this->x / b;
	divY = this->y / b;
	divZ = this->z / b;
	Vector divVector(divX, divY, divZ);
	return divVector;
}
bool Vector::operator==(const Vector b)
{
	if (this->x == b.x && this->y == b.y && this->z == b.z)
	{
		return true;
	}
	return false;
}
bool Vector::operator!=(const Vector b)
{
	if (this->x != b.x && this->y != b.y && this->z != b.z)
	{
		return true;
	}
	return false;
}
