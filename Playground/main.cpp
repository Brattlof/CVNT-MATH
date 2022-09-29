#include <iostream>

// Includes
#include <Vector/Vector3.hpp>
#include <Matrix/Matrix4x4.hpp>
//

#define LOG(x) std::cout << "[LOG] " << x << "\n"
#define LOGFMT(fmt, ...) printf("[LOG] " fmt "\n", __VA_ARGS__)

int main(void)
{
	LOG("Playground");

	Vector3 rVec = { 10.f, 10.f, 10.f };

	LOG(rVec.ToString());

	return 0x0;
}