#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>

namespace py = pybind11;

#include "icp_single_iteration.h"
#include "symmetric_rigid_matching.h"

PYBIND11_MODULE(symicp, m) {
    m.doc() = "ICP module"; // optional module docstring

    // The simplest wrapper doesn't work because `R` and `t` are output parameters.
    // m.def("icp_single_iteration", &icp_single_iteration, "A function that computes a single ICP iteration");
    // We fixed this by returning `R` and `t`.
    // We could also have fixed this by changing their type to `Eigen::Ref<...>`,
    // which would be a good idea for large amounts of data:
    //     https://stackoverflow.com/questions/52979815/how-to-use-eigenref-with-pybind11
    m.def("icp_single_iteration", []( const Eigen::MatrixXd & P,
        const Eigen::MatrixXd & NP,
        const Eigen::MatrixXd & VQ,
        const Eigen::MatrixXi & FQ,
        const bool is_robust,
        const ICPMethod method ) {
            Eigen::Matrix3d R;
            Eigen::RowVector3d t;
            icp_single_iteration( P, NP, VQ, FQ, is_robust, method, R, t );
            return std::make_tuple( R, t );
        },
        "A function that computes symmetric ICP");
    
    // The simplest wrapper for `symmetric_rigid_matching()` also won't work
    // because `R` and `t` are output parameters.
    // m.def("symmetric_rigid_matching", &symmetric_rigid_matching, "A function that computes symmetric ICP");

    py::enum_<ICPMethod>(m, "ICPMethod")
        .value("ICP_METHOD_POINT_TO_POINT", ICPMethod::ICP_METHOD_POINT_TO_POINT)
        .value("ICP_METHOD_POINT_TO_PLANE", ICPMethod::ICP_METHOD_POINT_TO_PLANE)
        .value("ICP_METHOD_SYMMETRIC", ICPMethod::ICP_METHOD_SYMMETRIC);
}
