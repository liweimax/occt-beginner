
#pragma once

class math_Vector;

class OcctVector
{
public:
	OcctVector();

	void Run();

	static void Print(const char* name, const math_Vector& v);
};