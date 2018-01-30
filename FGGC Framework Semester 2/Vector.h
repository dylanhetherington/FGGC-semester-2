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

	static Vector operator+(const Vector, const Vector);
	static Vector operator-(const Vector, const Vector);
	static Vector operator*(const Vector, const float);
	static Vector operator/(const Vector, const float);
	static bool operator==(const Vector, const Vector);
	static bool operator!=(const Vector, const Vector);

	float x, y, z;
};

