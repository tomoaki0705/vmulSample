#include "vmul.hpp"
#include <iostream>
#include <iomanip>
#define ALIGNED 16

float simd[4] __attribute__ ((aligned(ALIGNED)));
float ref[4]  __attribute__ ((aligned(ALIGNED)));

void verify(const float* a, const float* b, bool doSqrt)
{
    magnitude_simd( a, b, simd , doSqrt);
    magnitude     ( a, b, ref  , doSqrt);
    for(int i = 0;i < 4;i++)
    {
        std::cout << std::fixed << std::setprecision(10) << simd[i] << "  " << std::hex << ((unsigned int*)simd)[i] << std::dec << std::endl;
        std::cout << std::fixed << std::setprecision(10) << ref[i]  << "  " << std::hex << ((unsigned int*)ref)[i]  << std::dec << std::endl;
    }
}

int main(int argc, char**argv)
{
    float inputA[4] __attribute__ ((aligned(ALIGNED)));
    float inputB[4] __attribute__ ((aligned(ALIGNED)));
    inputA[0] = 1.1;
    inputA[1] = 2.2;
    inputA[2] = 3.3;
    inputA[3] = 4.4;
    inputB[0] = 11;
    inputB[1] = 12;
    inputB[2] = 13;
    inputB[3] = 14;
	verify( inputA, inputB, false );
	verify( inputA, inputB, true  );
    return 0;
}
