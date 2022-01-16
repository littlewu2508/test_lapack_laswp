# Test dlaswp

A strange behavior of openblas is found at https://github.com/xianyi/OpenBLAS/issues/3513 . This repo extract the data and write it into a small test program.

## Command

make -j will compile the 4 cases of input ipiv. Note that the dimension of ipiv should be ``(k1+(k2)*abs(inc))``

To compile with clang (or other compiler), run make CC=clang -j

In Gentoo we can switch different blas implementation at runtime via eselect.

## Result
```
user@machine:test$ make -j
gcc main.c -o test_1 -DCASE_1 -llapack
gcc main.c -o test_2 -DCASE_2 -llapack
gcc main.c -o test_3 -DCASE_3 -llapack
gcc main.c -o test_4 -DCASE_4 -llapack
user@machine:test$ eselect lapack list
Available LAPACK (lib) candidates:
  (none found)
Available LAPACK (lib64) candidates:
  [1]   openblas *
  [2]   reference
user@machine:test$ ./test_1
Segmentation fault
user@machine:test$ ./test_2
Program exited normally.
user@machine:test$ ./test_3
Program exited normally.
user@machine:test$ ./test_4
Segmentation fault
user@machine:test$ eselect lapack set reference
>>> Regenerating /etc/ld.so.cache...
user@machine:test$ ./test_1
Program exited normally.
user@machine:test$ ./test_2
Program exited normally.
user@machine:test$ ./test_3
Program exited normally.
user@machine:test$ ./test_4
Program exited normally.
```

Same behavior on amd64 (including Ryzen 5000 series, EYPC Rome, Intel Xeon E5) and armv8.2
