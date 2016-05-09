#include <arm_neon.h>

float sqrtSingle(float a, bool useHW);
void magnitude_simd( const float* a, const float* b, float* result , bool doSqrt = true );
void magnitude     ( const float* a, const float* b, float* result , bool doSqrt = true );
