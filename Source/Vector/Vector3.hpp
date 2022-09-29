#pragma once

#include <string>

class Vector3
{
public:
	Vector3(float _x = 0.f, float _y = 0.f, float _z = 0.f) : x(_x), y(_y), z(_z) { }
	Vector3(Vector3& v) { *this = v; }
	~Vector3() = default;

	float LengthSqr(void);
	float Length(void);

	void Normalize(void);
	Vector3 Normalized(void);

	void Clamp(void);
	Vector3 Clamped(void);

	static float Dot(const Vector3& v1, const Vector3& v2);
	float Dot(const Vector3& v);

	static Vector3 Cross(Vector3 v1, Vector3 v2);
	Vector3 Cross(Vector3 v);

	static float Distance(Vector3 v1, Vector3 v2);
	float Distance(Vector3 v);

	static Vector3 Lerp(Vector3 v1, Vector3 v2, float alpha);
	Vector3 Lerp(Vector3 v, float alpha);

	static Vector3 Slerp(Vector3 v1, Vector3 v2, float alpha);
	Vector3 Slerp(Vector3 v, float alpha);

	std::string ToString(void);

	//

	Vector3 operator+(const Vector3& v)
	{
		Vector3 rVec;

		rVec.x = x + v.x;
		rVec.y = y + v.y;
		rVec.z = z + v.y;

		return rVec;
	}

	//

	Vector3 operator-(const Vector3& v)
	{
		Vector3 rVec;

		rVec.x = x - v.x;
		rVec.y = y - v.y;
		rVec.z = z - v.z;

		return rVec;
	}

	void operator-=(const Vector3& v) { x -= v.x; y -= v.y; z -= v.z; }

	//

	Vector3 operator*(float v)
	{
		Vector3 rVec;

		rVec.x = x * v;
		rVec.y = y * v;
		rVec.z = z * v;

		return rVec;
	}

	float operator*(const Vector3& v) { return Dot(*this, v); }

	//

	Vector3 operator/(float v)
	{
		Vector3 rVec;

		rVec.x = x / v;
		rVec.y = y / v;
		rVec.z = z / v;

		return rVec;
	}

	void operator/=(float v) { x /= v; y /= v; z /= v; }

	//

public:
	float x, y, z;
};