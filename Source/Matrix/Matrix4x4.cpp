#include "pch.hpp"

#include "Matrix4x4.hpp"

//
//
//

Matrix4x4::Matrix4x4(void)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
			m_Matrix[i][j] = 0.f;
		}
	}
}

//
//
//

Matrix4x4 Matrix4x4::RotateX(float angle)
{
	Matrix4x4 rResult;
	rResult[1][1] = (float)cos(angle);
	rResult[1][2] = (float)-sin(angle);
	rResult[2][1] = (float)sin(angle);
	rResult[2][2] = (float)cos(angle);
	return rResult;
}

Matrix4x4 Matrix4x4::RotateY(float angle)
{
	Matrix4x4 rResult;
	rResult[0][0] = (float)cos(angle);
	rResult[0][2] = (float)sin(angle);
	rResult[2][0] = (float)-sin(angle);
	rResult[2][2] = (float)cos(angle);
	return rResult;
}

Matrix4x4 Matrix4x4::RotateZ(float angle)
{
	Matrix4x4 rResult;
	rResult[0][0] = (float)cos(angle);
	rResult[0][1] = (float)-sin(angle);
	rResult[1][0] = (float)sin(angle);
	rResult[1][1] = (float)cos(angle);
	return rResult;
}