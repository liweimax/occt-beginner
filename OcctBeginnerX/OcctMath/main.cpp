#include "stdafx.h"
#include "occtVector.h"
#include "occtMatrix.h"

int main(int argc, char** argv)
{

	OcctVector ov;
	ov.Run();
	std::cout << "--------------------" << std::endl;
	OcctMatrix om;
	om.Run();

    return 0;
}