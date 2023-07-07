# AMReX GPU Test

A small [AMReX](https://github.com/AMReX-Codes/amrex) application to try and
reproduce issues I have found with different GPU backends.

## AMReX documentation

AMReX provides extensive documentation which can be found
[here](https://amrex-codes.github.io/amrex/docs_html/).


## AMReX git submodule

Note that the AMReX repository is included as a [git
submodule](https://git-scm.com/book/en/v2/Git-Tools-Submodules) so to clone this
repository, it is easiest to pass the `--recurse-submodules` flag e.g.

```bash
git clone --recurse-submodules https://github.com/mirenradia/amrex-gpu-test.git
```

If you forget to pass this flag when cloning, you can check out the submodule
with the following two commands

```bash
git submodule init
git submodule update
```

The second command can also be used to check out the AMReX commit.

## How to build

This application uses AMReX's [GNU make build
system](https://amrex-codes.github.io/amrex/docs_html/BuildingAMReX.html#building-with-gnu-make).
To build it (in parallel on 4 threads), `cd` into this directory and run
```bash
make -j 4
```
You can configure the build options by changing the makefile variables in
[GNUmakefile](./GNUmakefile). Alternatively, you can set these variables on the
command line e.g.
```bash
make -j 4 USE_SYCL=TRUE
```
Note that when building with GPU support, it is not usually necessary to modify
the `COMP` variable as this is inferred from the selected GPU backend. For
further information about GPU build configuration, see [this part of the AMReX
documentation](https://amrex-codes.github.io/amrex/docs_html/GPU.html#building-with-gnu-make).
