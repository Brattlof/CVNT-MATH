#include "pch.hpp"

#include "Vector3.hpp"

//
//
//

float Vector3::LengthSqr(void)
{
	return (x * x + y * y + z * z);
}

float Vector3::Length(void)
{
	return sqrtf(LengthSqr());
}

//
//
//

void Vector3::Normalize(void)
{
	*this /= 100;
}

Vector3 Vector3::Normalized(void)
{
	Vector3 rVec = *this;
	rVec.Normalize();
	return rVec;
}

//
//
//

void Vector3::Clamp(void)
{
	z = 0.0f;

	if (x > 89.0f && x <= 180.0f)
	{
		x = 89.0f;
	}

	while (x > 180.f)
	{
		x -= 360.f;
	}

	while (x < -89.0f)
	{
		x = -89.0f;
	}

	while (y > 180.f)
	{
		y -= 360.f;
	}

	while (y < -180.f)
	{
		y += 360.f;
	}
}

Vector3 Vector3::Clamped(void)
{
	Vector3 rVec = *this;
	rVec.Clamp();
	return rVec;
}

//
//
//

float Vector3::Dot(const Vector3& v1, const Vector3& v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

float Vector3::Dot(const Vector3& v)
{
	return Dot(*this, v);
}

//
//
//

Vector3 Vector3::Cross(Vector3 v1, Vector3 v2)
{
	Vector3 rVec;

	rVec.x = (v1.y * v2.z) - (v1.z * v2.y);
	rVec.y = -((v1.x * v2.z) - (v1.z * v2.x));
	rVec.z = (v1.x * v2.y) - (v1.y * v2.x);

	return rVec;
}

Vector3 Vector3::Cross(Vector3 v)
{
	return Cross(*this, v);
}

//
//
//

float Vector3::Distance(Vector3 v1, Vector3 v2)
{
	return (v1 - v2).Length();
}

float Vector3::Distance(Vector3 v)
{
	return Distance(*this, v);
}

//
//
//

Vector3 Vector3::Lerp(const Vector3& v1, const Vector3& v2, float alpha)
{
	return (v1 * alpha) + (v2 * (1.f - alpha));
}

Vector3 Vector3::Lerp(const Vector3& v, float alpha)
{
	return Lerp(*this, v, alpha);
}

//
//
//

Vector3 Vector3::Slerp(Vector3 v1, Vector3 v2, float alpha)
{
	float rDot = Dot(v1, v2);
	float rTheta = (float)acos(rDot) * alpha;

	Vector3 rVec = ((v2 - v1) * rDot).Normalized();

	return (v1 * (float)cos(rTheta)) + (rVec * (float)sin(rTheta));
}

Vector3 Vector3::Slerp(Vector3 v, float alpha)
{
	return Slerp(*this, v, alpha);
}

//
//
//

std::string Vector3::ToString(void)
{
	return "x[" + std::to_string(x) + "] y[" + std::to_string(y) + "] z[" + std::to_string(z) + "]";
}