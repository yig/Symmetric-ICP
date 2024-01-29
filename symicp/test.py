# pip install trimesh numpy scipy

import trimesh
M1 = trimesh.load('data/data1/bun000.ply')
M2 = trimesh.load('data/data1/bun090.ply')
import numpy as np
P = np.array(M1.vertices)
NP = np.array(M1.vertex_normals)
VQ = np.array(M2.vertices)
FQ = np.array(M2.faces)
import symicp
# R = np.zeros((3,3))
# t = np.zeros((1,3))
# symicp.icp_single_iteration( P, NP, VQ, FQ, False, symicp.ICPMethod.ICP_METHOD_SYMMETRIC, R, t )
R, t = symicp.icp_single_iteration( P, NP, VQ, FQ, False, symicp.ICPMethod.ICP_METHOD_SYMMETRIC )
print( R )
print( t )
