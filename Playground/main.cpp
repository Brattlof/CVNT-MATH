#include <iostream>

// Includes
#include <Matrix/Matrix4x4.hpp>
//

#define LOG(x) std::cout << x << "\n"
#define LOGFMT(fmt, ...) printf("[LOG] " fmt "\n", __VA_ARGS__)

int main(void)
{
	Matrix4x4<float> rMatrix;
	rMatrix[1][1] = 1337.f;

	for (unsigned int i = 0; i < 4; i++)
	{
		for (unsigned int j = 0; j < 4; j++)
		{
			printf("[%i][%i] : %f\n", i, j, rMatrix[i][j]);
		}
	}

	return 0x0;
}