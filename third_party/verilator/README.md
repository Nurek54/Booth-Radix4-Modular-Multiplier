# Verilator runtime

The C++ runtime of [Verilator](https://verilator.org) 5.020 (2024-01-01), only the files needed to compile
the model in `generated/` without installing Verilator: `verilated`, `verilated_threads` and `verilated_vcd_c`
with their headers, copied unchanged from `share/verilator/include`.

Copyright 2003-2024 Wilson Snyder. Verilator is free software, licensed under the GNU Lesser General Public
License version 3 (`LICENSE.LGPL-3.0`, which builds on `LICENSE.GPL-3.0`) or the Perl Artistic License
version 2.0; it is used here under LGPL-3.0. These files are not covered by the license of this repository.

The model in `generated/` must come from the same Verilator version as this runtime. To update both,
install a different Verilator, run the `regenerate_model` target and copy the files listed above from its
`share/verilator/include` directory.
