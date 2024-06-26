#pragma once

#include "vector4.h"

class Matrix4 {
public:
    Vector4 data[4];

    Matrix4() = default;
    ~Matrix4() = default;

    Matrix4(const Vector4& arg1, const Vector4& arg2, const Vector4& arg3, const Vector4& arg4);

    Matrix4& operator+ (const Matrix4& rhs);
    Matrix4& operator* (const Matrix4& rhs);
    Matrix4& operator* (const double   rhs);
    bool     operator==(const Matrix4& rhs) const;
    
    friend std::ostream& operator<<(std::ostream& stream, const Matrix4& mtx); //print Matrix4 

};
