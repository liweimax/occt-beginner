#include "stdafx.h"
#include "occtVector.h"

#include <math_Vector.hxx>
#include <math_BullardGenerator.hxx>

OcctVector::OcctVector()
{

}

void OcctVector::Print(const char* name, const math_Vector& v)
{
	std::cout << name << " = (";
	for (int ii = v.Lower(); ii <= v.Upper(); ++ii)
	{
		std::cout << v(ii) << " ";
	}
	std::cout << ")" << std::endl;
}

void OcctVector::Run()
{
	math_Vector a(1, 10);
	math_BullardGenerator randomGenerator;
	for (int ii = a.Lower(); ii <= a.Upper(); ++ii)
	{
		a(ii) = randomGenerator.NextReal();
	}
	Print("a", a);

	std::cout << "|a| = " << a.Norm() << std::endl;
	std::cout << "Max Value Index = " << a.Max() << std::endl;
	std::cout << "Min Value Index = " << a.Min() << std::endl;

	math_Vector b = a.Normalized();
	Print("Normalized a => b", b);
	std::cout << "|b| = " << b.Norm() << std::endl;

	math_Vector c = a.Inverse();
	Print("Inverse a => c", c);
	std::cout << "|c| = " << c.Norm() << std::endl;

	math_Vector o = a.Opposite();
	Print("Opposite a => o", o);
	std::cout << "|o| = " << o.Norm() << std::endl;

	math_Vector d = a.Multiplied(10);
	Print("a * 10 => d", d);
	std::cout << "|d| = " << d.Norm() << std::endl;

	math_Vector e = d.Divided(10);
	Print("d / 10 => e", e);
	std::cout << "|e| = " << e.Norm() << std::endl;

	math_Vector f = d.Added(e);
	Print("d + e => f", f);
	std::cout << "|f| = " << f.Norm() << std::endl;

	math_Vector g = f.Subtracted(e);
	Print("f - e => g", g);
	std::cout << "|g| = " << g.Norm() << std::endl;
}