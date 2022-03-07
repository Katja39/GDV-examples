#include <iostream>
#include "vector4.h"
#include "matrix4x4.h"


#include <stdio.h>
int main()
{
    CVector V0(5.76f, 4.21f, -5.2f, -1.649);
    CVector Other(2.0f, 2.0f, 1.2f, 1.0f);

    std::cout << "Vector: \n";
    V0.Debug();
    std::cout << "Other Vector: \n";
    Other.Debug();

    std::cout << "Dot Product: ";
    std::cout<<V0.GetDotProduct3(Other);
    std::cout << "\nCross Product\n";
    V0.GetCrossProduct(Other).Debug();

    std::cout << "Matrix: \n";
    CMatrix M0;
    M0.Debug();
    std::cout << "Matrix+Matrix\n";
    CMatrix M1 = M0 + M0;
    M1.Debug();
    std::cout << "\n";

    std::cout << "Vector 1:\n";
    CVector V1(1.0f, 2.0f, 3.0f, 4.0f);
    V1.Debug();
    std::cout << "Vector 1 * Matrix\n";
    CVector V2 = V1 * M0;
    V2.Debug();

}
