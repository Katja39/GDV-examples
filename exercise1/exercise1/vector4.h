#pragma once
//Matrix = 16 float Werte
//Vector = 4 float Werte

/*Spaltenvektor
|X'|				|a11 a12 a13 a14|
|Y'|  = |X Y Z W| * |a21 a22 a23 a24|
|Z'|				|a31 a32 a33 a34|
|W'|				|a41 a42 a43 a44|
*/

//row major order:    zeileSpalte
//column major order: spalteZeile

/*
X'=X*a11+Y*a21+Z*a31+W*a41
Y'=X*a12+Y*a22+Z*a32+W*a42
Z'=X*a13+Y*a23+Z*a33+W*a43
W'=X*a14+Y*a24+Z*a34+W*a44
*/
class CMatrix;

class CVector {

	public:
		CVector();
		CVector(float _A0, float _A1, float _A2, float _A3);
		//Add(CVector* Other);				        //Adresse uebergeben, nullptr moegl.
		//CVector Add(const CVector& _Other);       //+ Adresse uebergeben, kein nullptr moegl., _ = Argument, const = Wert wird nicht veraendert
		//CVector& AddAndSet(const CVector& _Other);//+=

		float& operator [](int _index);				//Get Value float& Value = A[0]
		const float& operator [](int _index) const; //const float& Value = A[0]

		CVector  operator +(const CVector& _Other) const; //Readonly
		CVector& operator +=(const CVector& _Other);

		CVector  operator -(const CVector& _Other) const; //Sub
		CVector& operator -=(const CVector& _Other);      //SubAndSet

		CVector  operator *(float _Scalar) const; //Mul
		CVector& operator *=(float _Scalar);			  //MulAndSet

		float GetDotProduct2(const CVector& _Other) const; //Dot2
		float GetDotProduct3(const CVector& _Other) const; //Dot3
		float GetDotProduct4(const CVector& _Other) const; //Dot4
		CVector GetCrossProduct(const CVector& _Other) const;//Cross

		float GetLength2() const;
		float GetLength3() const; 
		float GetLength4() const;

		CVector& Normalize2();
		CVector& Normalize3();
		CVector& Normalize4();

		CVector GetNormalized2() const;
		CVector GetNormalized3() const;
		CVector GetNormalized4() const;

		CVector operator * (const CMatrix& _Other) const;

		void Debug() const;
	private:
		float Values[4];
};

//Add:       float Value2 = Value+8.0f;
//Add & Set: Value += 3.0f;

//Switch Case schneller als if