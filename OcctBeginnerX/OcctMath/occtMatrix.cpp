#include "stdafx.h"
#include "OcctMatrix.h"
#include "occtVector.h"

#include <math_Matrix.hxx>
#include <math_BullardGenerator.hxx>
#include <math_Jacobi.hxx>

OcctMatrix::OcctMatrix()
{

}

void OcctMatrix::Print(const char* name, const math_Matrix& v)
{
	std::cout << name << " = [" << std::endl;
	
	for (int jj = v.LowerCol(); jj <= v.UpperCol(); ++jj)
	{
		std::cout << "\t";
		for (int ii = v.LowerRow(); ii <= v.UpperRow(); ++ii)
		{
			std::cout << v(ii, jj) << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << "\t]" << std::endl;
}

void OcctMatrix::Run()
{
	math_Matrix a(1, 5, 1, 5);
	math_BullardGenerator randomGenerator;
	for (int ii = a.LowerRow(); ii <= a.UpperRow(); ++ii)
	{
		for (int jj = a.LowerCol(); jj <= a.UpperCol(); ++jj)
		{ 
			a(ii, jj) = randomGenerator.NextReal();
		}
	}
	Print("A", a);
	std::cout << "det(A) = " << a.Determinant() << std::endl;
	

	math_Matrix t = a.Transposed();
	Print("Transposed a => t", t);

	math_Matrix i = a.Inverse();
	Print("Inverse a => i", i);

	math_Matrix b = a.Multiplied(i);
	Print("a x i => b", b);

	math_Matrix c = a.Multiplied(10);
	Print("a x 10 => c", c);

	math_Matrix d = c.Divided(10);
	Print("c / 10 => d", d);

	math_Vector v(1, 5);
	for (int ii = v.Lower(); ii <= v.Upper(); ++ii)
	{
		v(ii) = randomGenerator.NextReal();
	}
	OcctVector::Print("v", v);
	math_Vector v2 = a.Multiplied(v);
	OcctVector::Print("a * v1 => v2", v2);


	double xx[5][5] = {
		{1,0,0,0,10},
		{0,1,0,0,0},
		{0,0,1,0,0},
		{0,0,0,1,0},
		{10,0,0,0,1}
	};
	for (int jj = a.LowerCol(); jj <= a.UpperCol(); ++jj)
		for (int ii = a.LowerRow(); ii <= a.UpperRow(); ++ii)
		{
			{
				a(ii, jj) = xx[ii-1][jj-1];
			}
		}
	Print("a ", a);
	math_Jacobi jacobi(a);
	if (jacobi.IsDone())
	{
		math_Vector ev = jacobi.Values();
		OcctVector::Print("a eigenvalues", ev);

		math_Matrix evt = jacobi.Vectors();
		Print("a eigenvectors", evt);
		std::cout << "det(eigenvectors) = " << evt.Determinant() << std::endl;

		for (int ii = 1; ii <= 5; ++ii)
		{
			math_Vector j(1,5);
			jacobi.Vector(ii, j);
			OcctVector::Print("eigenvector", j);

			OcctVector::Print("R", j.Multiplied(jacobi.Value(ii)));

			OcctVector::Print("L", a.Multiplied(j));
		}
	}

}