from glob import glob
from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension, build_ext

ext_modules = [
    Pybind11Extension(
        "symicp",
        sorted(glob("symicp/*.cpp") + glob("src/*.cpp")),
        include_dirs=["include", "libigl/include", "eigen"]
    ),
]

setup(
    name="symicp",
    cmdclass={"build_ext": build_ext},
    ext_modules=ext_modules
    )
