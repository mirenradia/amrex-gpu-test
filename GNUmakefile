DEBUG = FALSE

USE_MPI = FALSE
USE_OMP = FALSE

USE_HDF5 = FALSE

TINY_PROFILE = FALSE

TEST = FALSE
USE_ASSERTION = FALSE
BOUND_CHECK = FALSE

USE_CUDA  = FALSE
USE_HIP   = FALSE
USE_SYCL = FALSE

COMP = gnu

DIM = 3

BL_NO_FORT = TRUE
AMREX_NO_PROBINIT = TRUE

CXXSTD = c++17
AMREX_HOME ?= $(realpath ./amrex)

include $(AMREX_HOME)/Tools/GNUMake/Make.defs

include ./Make.package
include $(AMREX_HOME)/Src/Base/Make.package
include $(AMREX_HOME)/Src/Boundary/Make.package
include $(AMREX_HOME)/Src/AmrCore/Make.package
include $(AMREX_HOME)/Src/Amr/Make.package

INCLUDE_LOCATIONS += $(realpath .)

include $(AMREX_HOME)/Tools/GNUMake/Make.rules