#pragma once

template <class T>
class Matrix4x4
{
public:
	Matrix4x4(void)
	{
		for (unsigned int i = 0; i < 4; i++)
		{
			for (unsigned int j = 0; j < 4; j++)
			{
				m_Matrix[i][j] = static_cast<T>(NULL);
			}
		}
	}

	// -- Matrix4x4[i][j] -- //
	T* operator[](unsigned int row) { return *m_Matrix; }

private:
	T m_Matrix[4][4];
};