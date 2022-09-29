#pragma once

class Matrix4x4
{
public:
	Matrix4x4(void);

	static Matrix4x4 RotateX(float angle);
	static Matrix4x4 RotateY(float angle);
	static Matrix4x4 RotateZ(float angle);

	// -- Matrix4x4[i][j] -- //
	float* operator[](unsigned int row) { return *m_Matrix; }

private:
	float m_Matrix[4][4];
};