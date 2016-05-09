#include <arm_neon.h>

void magnitude_simd( const float* a, const float* b, float* result , bool doSqrt = true );
void magnitude     ( const float* a, const float* b, float* result , bool doSqrt = true );
