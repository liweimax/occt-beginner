
#pragma once

class math_Matrix;

class OcctMatrix
{
public:
	OcctMatrix();

	void Run();

	static void Print(const char* name, const math_Matrix& v);
};