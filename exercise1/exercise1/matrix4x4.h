#pragma once
#include "vector4.h"
class CMatrix {
	public:
		static const int NumberOfRows = 4;
		static const int NumberOfColumns = 4;
		static const int NumberOfComponents = NumberOfRows * NumberOfColumns;

		CMatrix();						//Standard constructor
		CMatrix(const CMatrix& _Matrix);//Copy constructor
		CMatrix(const CVector& _Row0, const CVector& _Row1, const CVector& _Row2,
				const CVector& _Row3);	//Parametrized constructor
	public:
		CVector& GetRow(int _index);
		const CVector& GetRow(int _index) const;
		CVector GetColumn(int _index) const;

		CVector& operator [] (int _index);
		const CVector& operator[](int _index)const;

	public:
		CMatrix operator +(const CMatrix& _Matrix) const;
		CMatrix& operator +=(const CMatrix& _Matrix);

		CMatrix operator *(const CMatrix& _Matrix) const;
		CMatrix& operator *=(const CMatrix& _Matrix);
	
		void Debug() const;
	private: CVector Rows[NumberOfRows];
};
