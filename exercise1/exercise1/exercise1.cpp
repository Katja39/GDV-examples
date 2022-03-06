#include <iostream>
#include "vector4.h"


#include <stdio.h>
int main()
{
    CVector V0(5.76f, 4.21f, -5.2f, -1.649);

    CVector Other(2.0f, 2.0f, 1.2f, 1.0f);

    std::cout << "Vector: \n";
    V0.Debug();
    std::cout << "Other Vector: \n";
    Other.Debug();

    std::cout << "\nDot Product: ";
    std::cout<<V0.GetDotProduct3(Other);
    std::cout << "\nCross Product\n";
    V0.GetCrossProduct(Other).Debug();
}
