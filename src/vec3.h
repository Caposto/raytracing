#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

// 3D vector with basic operations (+, -, *, /) the latter two with both constants and scalars
// Also operations for cross and dot products
class vec3 {
    public:
        vec3() : e{0, 0, 0} {}
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; };

        vec3& operator+=(const vec3 &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        vec3& operator*=(const double c) {
            e[0] *= c;
            e[1] *= c;
            e[2] *= c;
            return *this;
        }

        vec3& operator/=(const double c) {
            return *this *= 1/c;
        }

        double length() const {
            return sqrt(length_squared());
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

        inline static vec3 random() {
            return vec3(random_double(), random_double(), random_double());
        }

        inline static vec3 random(double min, double max) {
            return vec3(random_double(min, max), random_double(min, max), random_double(min, max));
        }

    public:
        double e[3];
};

// Type aliases for vec3
using point3 = vec3; // 3D Point
using color = vec3;  // RGB Color

/* Utility Functions */

inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double c, const vec3 &v) {
    return vec3(c*v.e[0], c*v.e[1], c*v.e[2]);
}

inline vec3 operator*(const vec3 &v, double c) {
    return c * v;
}

inline vec3 operator/(vec3 v, double c) {
    return (1/c) * v;
}

inline double dot(const vec3 &u, const vec3 &v) {
    return u.e[0]*v.e[0] + u.e[1]*v.e[1] + u.e[2]*v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3( (u.e[1]*v.e[2] - u.e[2]*v.e[1]), (-(u.e[0]*v.e[2] - u.e[2]*v.e[0])), (u.e[0]*v.e[1] - u.e[1]*v.e[0]));
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

vec3 random_in_unit_sphere() {
    while (true) {
        auto p = vec3::random(-1, 1);
        if (p.length_squared() >= 1) continue;
        return p;
    }
}

#endif