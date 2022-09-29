#include <iostream>

// Includes
#include <Vector/Vector3.hpp>
#include <Matrix/Matrix4x4.hpp>
#include <Timer/Timer.hpp>
//

#define LOG(x) std::cout << "[LOG] " << x << "\n"
#define LOGFMT(fmt, ...) printf("[LOG] " fmt "\n", __VA_ARGS__)

int main(void)
{
	LOG("Playground");

	Vector3 rVec = { 10.f, 10.f, 10.f };

	std::vector<float> rMatrixVec;
	while (rMatrixVec.size() < 16)
	{
		rMatrixVec.push_back(1337.f);
	}

	//
	Timer<float, std::milli> rTimer;
	//
	float rDeltaTime = 0.f;

	while (true)
	{
		Matrix4x4 rMatrix(rMatrixVec);

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				LOG(rMatrix[i][j]);
			}
		}

		rDeltaTime = rTimer.Elapsed();
		rTimer.Reset();
	}

	return 0x0;
}