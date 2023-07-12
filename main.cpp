#include "AMReX.H"
#include "AMReX_FArrayBox.H"
#include "AMReX_ParmParse.H"

#include <iomanip>
#include <limits>

int main(int argc, char **argv)
{
    bool return_val     = 0;
    bool use_parm_parse = true;
    amrex::Initialize(argc, argv, use_parm_parse, MPI_COMM_WORLD);
    {
        constexpr int n_grid = 8;
        amrex::Box box(amrex::IntVect(0, 0, 0),
                       amrex::IntVect(n_grid - 1, n_grid - 1, n_grid - 1));
        amrex::FArrayBox fab(box, 1, amrex::The_Managed_Arena());

        const amrex::Array4<amrex::Real> &array = fab.array();

        amrex::ParallelFor(
            box, [=] AMREX_GPU_DEVICE(int i, int j, int k)
            { array(i, j, k, 0) = static_cast<double>(i + j + k); });

        amrex::Gpu::streamSynchronize();

        amrex::FArrayBox error_fab(box, 1, amrex::The_Managed_Arena());
        const auto &error_array = error_fab.array();

        amrex::LoopOnCpu(box,
                         [=](int i, int j, int k)
                         {
                             error_array(i, j, k, 0) =
                                 std::abs(static_cast<double>(i + j + k) -
                                          array(i, j, k, 0));
                         });

        double max_error = error_fab.max<amrex::RunOn::Host>();

        amrex::Print() << std::setprecision(
                              std::numeric_limits<double>::digits10 + 1)
                       << "max error = " << max_error << std::endl;

        if (max_error > std::numeric_limits<double>::epsilon() * 10)
        {
            amrex::Print() << "Test failed" << std::endl;
            return_val = 1;
        }
        else
        {
            amrex::Print() << "Test passed" << std::endl;
        }
    }
    amrex::Finalize();
    return return_val;
}