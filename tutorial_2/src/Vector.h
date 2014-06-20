#ifndef __VECTOR_H__
#define __VECTOR_H__

template <typename T>
struct Vector3
{
    Vector3(void) : x(0.0f), y(0.0f), z(0.0f) { }
    Vector3(const Vector3<T>& vector) : x(vector.x), y(vector.y), z(vector.z) { }

    Vector3<T>& operator=(const Vector3<T>& vector)
    {
        x = vector.x;
        y = vector.y;
        z = vector.z;
        return *this;
    }

    T x;
    T y;
    T z;
};

typedef Vector3<float> Vector3f;

#endif
