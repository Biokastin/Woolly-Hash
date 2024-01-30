# Woolly Hash

Calculates a novel fuzzy hash based on merging byte pair averages in a tree like pattern. No dependencies other than C++ standard library.

## test & benchmark compile instructions

1. run: `$ scons` in repo's root
2. compiled binary located in `bin` named `program`

## generate doxygen documentation

1. run `$ doxygen doxy.config` in the repo's root
2. open documentation format of choice
    - open `doxy-documentation/html/index.html` in a web browser
    - `cd doxy-documentation/latex/` from repo's root, run `make`, and open `refman.pdf` in a PDF viewer

## use in projects

1. from the external directory of the repo's root folder `#include "Woolly Hash/woolly_hash.hpp"`

## notes

1. The program that compiles is bare bones. All it performs is a validation of the algorithm using asserts and allocates a gigabyte of memory and hashes it meant to be used as a benchmark.
2. I advise against using this in production as this will likely have minimal if any updates, and hasn't gone through an efficiency evaluation. If I see this project getting note worthy attention or if I think of adding something I will continue updating.
