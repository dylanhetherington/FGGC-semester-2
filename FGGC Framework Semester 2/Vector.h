#pragma once
#include <math.h>
class Vector
{
private:

public:
	Vector();
	Vector(const float x, const float y, const float z);
	~Vector();
	float CalculateDotProduct(const Vector);
	Vector CalcualteCrossProdcut(const Vector);

	static Vector Normalize(const Vector);
	static float Magnitude(const Vector);

	Vector operator+(const Vector);
	Vector operator-(const Vector);
	Vector operator*(const float);
	Vector operator/(const float);
	bool operator==(const Vector);
	bool operator!=(const Vector);

	float x, y, z;
};

