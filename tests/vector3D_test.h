#include "../src/math/vector3D.h"

#include <stdexcept>

constexpr void assert_that(bool statement, const char* message) {
    if (!statement) throw std::runtime_error{ message }; 
}

namespace vec_normal_ops {

    void add() {
        Vector3D u(1.0, 2.0, 3.0);
        Vector3D v(3.0, 2.0, 1.0);

        Vector3D res = u + v;
        Vector3D expt(4.0, 4.0, 4.0);

        assert_that(res == expt, "Addition Failed!");
    }

    void sub() {

        Vector3D v(1.0, 2.0, 3.0);
        Vector3D t(5.0, 6.0, 7.0);
        Vector3D res = v - t;
        Vector3D expt(-4.0, -4.0, -4.0);
        
        assert_that(res == expt, "Subtration Failed!");
    }
    
    void mul() {
        Vector3D v(1.0, 2.0, 3.0);

        Vector3D res = v * 10.0;
        Vector3D expt(10.0, 20.0, 30.0);
        
        assert_that(res == expt, "Multiplication Failed!");
    }

    void dot_product() {
        Vector3D u(1.0, 2.0, 3.0);
        Vector3D v(2.0, 3.0, 4.0);
        
        double res = dot(u, v);
        double expt = 20.0;

        assert_that(res == expt, "Dot Product Failed!");

    }

    void cross_prod() {
        Vector3D u(1.0, 2.0, 3.0);
        Vector3D v(2.0, 3.0, 4.0);
        
        Vector3D res = cross(u, v);
        Vector3D expt(-1.0, 2.0, -1.0);

        assert_that(res == expt, "Cross Product Failed!");
    }
}


namespace vec_scalar_ops {
    void mul() {
        Vector3D v(1.1, 2.2, 3.3);

        Vector3D res = v * 10.0;
        Vector3D expt(11.0, 22.0, 33.0);
        
        assert_that(res == expt, "Scalar Multiplication Failed!");
    }

    void div() {
        Vector3D v(10.0, 20.0, 30.0);

        Vector3D res = v / 10.0;
        Vector3D expt(1.0, 2.0, 3.0);
        
        assert_that(res == expt, "Scalar Division Failed!");
    }
}