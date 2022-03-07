#include "matrix4x4.h";
#include <math.h>            
#include <stdio.h> 

CMatrix::CMatrix()
	: Rows{ CVector(1.0f, 0.0f, 0.0f, 0.0f)
		  , CVector(0.0f, 1.0f, 0.0f, 0.0f),
		    CVector(0.0f, 0.0f, 1.0f, 0.0f),
		    CVector(0.0f, 0.0f, 0.0f, 1.0f) } 
{
}

CMatrix::CMatrix(const CMatrix& _Matrix)
	:Rows{ _Matrix.Rows[0], _Matrix.Rows[1],_Matrix.Rows[2],_Matrix.Rows[3]}
{
}

CMatrix::CMatrix(const CVector& _Row0, const CVector& _Row1, const CVector& _Row2,
	const CVector& _Row3) 
	:Rows{_Row0,_Row1,_Row2,_Row3}
{
}

CVector& CMatrix::GetRow(int _index)
{
	return Rows[_index];
}
const CVector& CMatrix::GetRow(int _index) const
{
	return Rows[_index];
}
CVector CMatrix::GetColumn(int _index) const
{
	return CVector(Rows[0][_index], Rows[1][_index], Rows[2][_index], Rows[3][_index]);
}
CVector& CMatrix::operator [] (int _index)
{
	return GetRow(_index);
}
const CVector& CMatrix::operator[](int _index)const
{
	return GetRow(_index);
}

CMatrix CMatrix::operator +(const CMatrix& _Matrix) const 
{
	CMatrix temp;

	temp.Rows[0] = Rows[0] + _Matrix.Rows[0];
	temp.Rows[1] = Rows[1] + _Matrix.Rows[1];
	temp.Rows[2] = Rows[2] + _Matrix.Rows[2];
	temp.Rows[3] = Rows[3] + _Matrix.Rows[3];

	return temp;
}

CMatrix& CMatrix::operator +=(const CMatrix& _Matrix) 
{
	Rows[0] += _Matrix.Rows[0];
	Rows[1] += _Matrix.Rows[1];
	Rows[2] += _Matrix.Rows[2];
	Rows[3] += _Matrix.Rows[3];
	
	return *this;
}



CMatrix CMatrix::operator *(const CMatrix& _Matrix) const
{
	return CMatrix(
		  CVector(Rows[0].GetDotProduct4(_Matrix.GetColumn(0)), Rows[0].GetDotProduct4(_Matrix.GetColumn(1)), Rows[0].GetDotProduct4(_Matrix.GetColumn(3)), Rows[0].GetDotProduct4(_Matrix.GetColumn(4))),
		  CVector(Rows[1].GetDotProduct4(_Matrix.GetColumn(0)), Rows[1].GetDotProduct4(_Matrix.GetColumn(1)), Rows[1].GetDotProduct4(_Matrix.GetColumn(3)), Rows[1].GetDotProduct4(_Matrix.GetColumn(4))),
		  CVector(Rows[2].GetDotProduct4(_Matrix.GetColumn(0)), Rows[2].GetDotProduct4(_Matrix.GetColumn(1)), Rows[2].GetDotProduct4(_Matrix.GetColumn(3)), Rows[2].GetDotProduct4(_Matrix.GetColumn(4))),
		  CVector(Rows[3].GetDotProduct4(_Matrix.GetColumn(0)), Rows[3].GetDotProduct4(_Matrix.GetColumn(1)), Rows[3].GetDotProduct4(_Matrix.GetColumn(3)), Rows[3].GetDotProduct4(_Matrix.GetColumn(4)))
				);
}

CMatrix& CMatrix::operator *=(const CMatrix& _Matrix) 
{
	(*this) = (*this) * _Matrix;
	return *this;
}

void CMatrix::Debug() const 
{
	printf("%+10.3f %+10.3f %+10.3f %+10.3f\n", Rows[0][0], Rows[0][1], Rows[0][2], Rows[0][3]);
	printf("%+10.3f %+10.3f %+10.3f %+10.3f\n", Rows[1][0], Rows[1][1], Rows[1][2], Rows[1][3]);
	printf("%+10.3f %+10.3f %+10.3f %+10.3f\n", Rows[2][0], Rows[2][1], Rows[2][2], Rows[2][3]);
	printf("%+10.3f %+10.3f %+10.3f %+10.3f\n", Rows[3][0], Rows[3][1], Rows[3][2], Rows[3][3]);
}

