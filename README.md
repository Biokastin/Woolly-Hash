# Woolly Hash

Calculates a novel fuzzy hash based on merging bit pair via XOR in a tree like pattern. No dependencies other than C++20 standard library.

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
