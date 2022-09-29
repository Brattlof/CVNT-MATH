#pragma once

#include <vector>

class Matrix4x4
{
public:
	Matrix4x4(void);

	static Matrix4x4 RotateX(float angle);
	static Matrix4x4 RotateY(float angle);
	static Matrix4x4 RotateZ(float angle);

	static std::vector<float> ToVector(const Matrix4x4& m);
	std::vector<float> ToVector();

	static float& At(Matrix4x4 m, unsigned int row, unsigned int col) { return m.At(row, col); }
	float& At(unsigned int row, unsigned int col) { return m_Matrix[row][col]; }

	// -- Matrix4x4[i][j] -- //
	float* operator[](unsigned int row) { return m_Matrix[row]; }

private:
	float m_Matrix[4][4];
};