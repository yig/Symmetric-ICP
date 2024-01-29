#ifndef ICP_SINGLE_ITERATION_H
#define ICP_SINGLE_ITERATION_H
#include <Eigen/Core>

enum class ICPMethod
{
  ICP_METHOD_POINT_TO_POINT = 0,
  ICP_METHOD_POINT_TO_PLANE = 1,
  ICP_METHOD_SYMMETRIC = 2,
  NUM_ICP_METHODS = 3,
};
// Conduct a single iteration of the iterative closest point method using the symmetric
// objective to align (VP,NP) to (VQ,FQ) by finding the rigid transformation (R,t)
//
// Inputs:
//   P   #P by 3 list of vertex positions
//   NP  #P by 3 list of vertex normals
//   VQ  #VY by 3 list of mesh vertex positions
//   FQ  #FY by 3 list of triangle mesh indices into VY
//   num_samples  number of random samples to use (larger --> more accurate)
//   method  method of linearization to use
// Outputs:
//   R  3 by 3 rotation matrix
//   t  3d translation vector
void icp_single_iteration(
  const Eigen::MatrixXd & P,
  const Eigen::MatrixXd & NP,
  const Eigen::MatrixXd & VQ,
  const Eigen::MatrixXi & FQ,
  const bool is_robust,
  const ICPMethod method,
  Eigen::Matrix3d & R,
  Eigen::RowVector3d & t);

#endif
