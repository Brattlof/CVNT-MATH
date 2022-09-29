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