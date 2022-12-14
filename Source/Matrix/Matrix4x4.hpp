#pragma once

#include <vector>
#include <Vector/Vector3.hpp>

class Matrix4x4
{
public:
	Matrix4x4(void);
	Matrix4x4(const Matrix4x4& m) { *this = m; }
	Matrix4x4(std::vector<float> v);

	static Matrix4x4 Translate(Vector3 translation);

	static Matrix4x4 Scale(Vector3 scale);

	static Matrix4x4 RotateX(float angle);
	static Matrix4x4 RotateY(float angle);
	static Matrix4x4 RotateZ(float angle);

	static std::vector<float> ToVector(const Matrix4x4& m);
	std::vector<float> ToVector();

	static float& At(Matrix4x4 m, unsigned int row, unsigned int col) { return m.At(row, col); }
	float& At(unsigned int row, unsigned int col) { return m_Matrix[row][col]; }

	// -- Matrix4x4[i][j] -- //
	float* operator[](unsigned int row) { return m_Matrix[row]; }

	void operator*=(Matrix4x4& m)
	{
		for (unsigned int i = 0; i < 4; i++)
		{
			for (unsigned int j = 0; j < 4; j++)
			{
				m_Matrix[i][j] *= m.At(i, j);
			}
		}
	}

private:
	float m_Matrix[4][4];
};