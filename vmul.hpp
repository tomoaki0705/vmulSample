#include <arm_neon.h>

struct v_float32x4
{
    typedef float lane_type;
    enum { nlanes = 4 };

    v_float32x4() {}
    explicit v_float32x4(float32x4_t v) : val(v) {}
    v_float32x4(float v0, float v1, float v2, float v3)
    {
        float v[] = {v0, v1, v2, v3};
        val = vld1q_f32(v);
    }
    float get0() const
    {
        return vgetq_lane_f32(val, 0);
    }
    float32x4_t val;
};

v_float32x4_t magnitude(const v_float32x4& a, const v_float32x4& b);
