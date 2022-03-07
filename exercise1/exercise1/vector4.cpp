#include "vector4.h"
#include "matrix4x4.h"
#include <math.h>            
#include <stdio.h> 

CVector::CVector()
	:Values{0.0f} //Initalisierung
{
}

CVector::CVector(float _A0, float _A1, float _A2, float _A3)
	:Values{_A0,_A1,_A2,_A3 } 
{
}

float& CVector::operator [](int _index) 
{
	return Values[_index];
}

const float& CVector::operator [](int _index) const 
{
	return Values[_index];
}

CVector  CVector::operator +(const CVector& _Other) const 
{
	CVector temp;
	for (int i = 0; i < 4; i++)
	{
		temp[i] = Values[i] + _Other[i];
	}
	return temp;
}

CVector& CVector::operator +=(const CVector& _Other) 
{
	for (int i = 0; i < 4; i++)
	{
	Values[i] += _Other[i];
	}
	return *this;
}
CVector  CVector::operator -(const CVector& _Other) const 
{
	CVector temp;
	for (int i = 0; i < 4; i++)
	{
		temp[i] = Values[i] - _Other[i];
	}
	return temp;
}
CVector& CVector::operator -=(const CVector& _Other) 
{
	for (int i = 0; i < 4; i++)
	{
		Values[i] -= _Other[i];
	}
	return *this;
}

CVector  CVector::operator *(float _Scalar) const
{
	CVector temp;
	for (int i = 0; i < 4; i++)
	{
		temp[i] = Values[i] * _Scalar;
	}
	return temp;
}

CVector& CVector::operator *=(float _Scalar) 
{
	for (int i = 0; i < 4; i++)
	{
		Values[i] *= _Scalar;
	}
	return *this;
}

float CVector::GetDotProduct2(const CVector& _Other) const
{
	return Values[0] * _Other.Values[0] + Values[1] * _Other.Values[1];
}

float CVector::GetDotProduct3(const CVector& _Other) const
{
	return Values[0] * _Other.Values[0] + Values[1] * _Other.Values[1] + Values[2] * _Other.Values[2];
}

float CVector::GetDotProduct4(const CVector& _Other) const
{
	return Values[0] * _Other.Values[0] + Values[1] * _Other.Values[1] + Values[2] * _Other.Values[2] + Values[3] * _Other.Values[3];
}

CVector CVector::GetCrossProduct(const CVector& _Other) const
{
	CVector temp;
	temp[0] = Values[1] * _Other.Values[2] - Values[2] * _Other[1];
	temp[1] = Values[2] * _Other.Values[0] - Values[0] * _Other[2];
	temp[2] = Values[0] * _Other.Values[1] - Values[1] * _Other[0];
	temp[3] = 0.0f;
	return temp;
}

float CVector::GetLength2() const 
{
	return sqrtf(GetDotProduct2(*this));
}

float CVector::GetLength3() const 
{
	return sqrtf(GetDotProduct3(*this));
}

float CVector::GetLength4() const 
{
	return sqrtf(GetDotProduct4(*this));
}

CVector& CVector::Normalize2() 
{
	float Length = GetLength2();
	return (*this) *= (1.0f / Length);
}

CVector& CVector::Normalize3() 
{
	float Length = GetLength3();
	return (*this) *= (1.0f / Length);
}

CVector& CVector::Normalize4() 
{
	float Length = GetLength4();
	return (*this) *= (1.0f / Length);
}

CVector CVector::GetNormalized2() const
{
	float Length = GetLength2();
	return (*this) * (1.0f / Length);
}
CVector CVector::GetNormalized3() const
{
	float Length = GetLength3();
	return (*this) * (1.0f / Length);
}
CVector CVector::GetNormalized4() const
{
	float Length = GetLength4();
	return (*this) * (1.0f / Length);
}

CVector CVector::operator * (const CMatrix& _Other) const
{
	return CVector(
		GetDotProduct4(_Other.GetColumn(0)),
		GetDotProduct4(_Other.GetColumn(1)),
		GetDotProduct4(_Other.GetColumn(2)),
		GetDotProduct4(_Other.GetColumn(3)));
}

void CVector::Debug() const
{
	printf("%+10.2f\n", Values[0]);
	printf("%+10.2f\n", Values[1]);
	printf("%+10.2f\n", Values[2]);
	printf("%+10.2f\n", Values[3]);
	printf("\n");
}