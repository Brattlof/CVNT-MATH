#include "pch.hpp"

#include "Matrix4x4.hpp"
#include <Windows.h>

//
//
//

Matrix4x4::Matrix4x4(void)
{
	ZeroMemory(&m_Matrix, sizeof(m_Matrix));
}

Matrix4x4::Matrix4x4(std::vector<float> v)
{
	if (v.size() != 16)
		return;

	unsigned int rCurr = 15;

	for (unsigned int i = 4; i > 0; i--)
	{
		for (unsigned int j = 4; j > 0; j--)
		{
			m_Matrix[i - 1][j - 1] = v[rCurr];
			rCurr--;
		}
	}
}

//
//
//

Matrix4x4 Matrix4x4::Translate(Vector3 translation)
{
	Matrix4x4 rMatrix;

	rMatrix[0][3] = translation.x;
	rMatrix[1][3] = translation.y;
	rMatrix[2][3] = translation.z;
	rMatrix[0][0] = 1.0f;
	rMatrix[1][1] = 1.0f;
	rMatrix[2][2] = 1.0f;
	rMatrix[3][3] = 1.0f;

	return rMatrix;
}

//
//
//

Matrix4x4 Matrix4x4::Scale(Vector3 scale)
{
	Matrix4x4 rMatrix;

	rMatrix[0][0] = scale.x;
	rMatrix[1][1] = scale.y;
	rMatrix[2][2] = scale.z;
	rMatrix[3][3] = 1.0f;

	return rMatrix;
}

//
//
//

Matrix4x4 Matrix4x4::RotateX(float angle)
{
	Matrix4x4 rMatrix;

	rMatrix[1][1] = (float)cos(angle);
	rMatrix[1][2] = (float)-sin(angle);
	rMatrix[2][1] = (float)sin(angle);
	rMatrix[2][2] = (float)cos(angle);

	return rMatrix;
}

Matrix4x4 Matrix4x4::RotateY(float angle)
{
	Matrix4x4 rMatrix;

	rMatrix[0][0] = (float)cos(angle);
	rMatrix[0][2] = (float)sin(angle);
	rMatrix[2][0] = (float)-sin(angle);
	rMatrix[2][2] = (float)cos(angle);

	return rMatrix;
}

Matrix4x4 Matrix4x4::RotateZ(float angle)
{
	Matrix4x4 rMatrix;

	rMatrix[0][0] = (float)cos(angle);
	rMatrix[0][1] = (float)-sin(angle);
	rMatrix[1][0] = (float)sin(angle);
	rMatrix[1][1] = (float)cos(angle);

	return rMatrix;
}

//
//
//

std::vector<float> Matrix4x4::ToVector(const Matrix4x4& m)
{
	std::vector<float> rVector;
	//
	unsigned int rCurr = 0;

	for (unsigned int i = 0; i < 4; i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
			rVector.push_back(Matrix4x4::At(m, i, j));
			rCurr++;
		}
	}

	return rVector;
}

std::vector<float> Matrix4x4::ToVector()
{
	return ToVector(*this);
}