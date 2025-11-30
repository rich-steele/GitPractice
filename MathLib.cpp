#include "MathLib.h"

int MathLib::AddInts(int A, int B)
{
    return 0;
}

int MathLib::SubtractInt(int A, int B)
{
    if (B < 0) return AddInts(A, B * -1);

    int Result = A;

    while (true)
    {
        if (Result == A - B) {
            return Result;;
        }
        
        Result--;
    }
}