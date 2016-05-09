#include "simdUtils.h"
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdlib>
#include "float.h"
#include <iostream>

inline float4 v_sqrt(const float4 x)
{
    float4 x1 = vmaxq_f32(x, vdupq_n_f32(FLT_MIN));
    float4 e = vrsqrteq_f32(x1);
    float ee = get_float(e, 0);
	std::cout << ee << std::endl;
    e = vmulq_f32(vrsqrtsq_f32(vmulq_f32(x1, e), e), e);
    e = vmulq_f32(vrsqrtsq_f32(vmulq_f32(x1, e), e), e);
    return vmulq_f32(x, e);
}


void magnitude_simd(const float* a, const float* b, float* result, bool doSqrt)
{
    float4 vA = load_float4(a);
    float4 vB = load_float4(b);
    float4 x = vmlaq_f32(vmulq_f32(vA, vA), vB, vB);

    if(doSqrt)
    {
        store_float4( result, v_sqrt(x) );
    }
    else
    {
        store_float4( result, x );
    }
}

void magnitude(const float* a, const float* b, float* result, bool doSqrt)
{
    for(int i = 0;i < 4;i++)
    {
        if(doSqrt)
        {
            result[i] = std::sqrt(a[i]*a[i]+b[i]*b[i]);
        }
        else
        {
            result[i] = a[i]*a[i]+b[i]*b[i];
        }
    }
}
