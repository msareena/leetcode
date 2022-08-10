# Leetcode Solutions

A collection of solutions to [leetcode problems].

# Running The Solutions

## Building the solutions

```
[ leetcode ]$ mkdir build && cd build
[ leetcode/build ]$ cmake ..
[ leetcode/build ]$ make
```

## Running the solutions

```
[ leetcode/build ]$ cd test
[ leetcode/build/test ] ctest
```

## Running a specific solution

```
[ leetcode/build ]$ cd test/<problem#>
[ leetcode/build/test/<problem#> ] ctest
```

For example, to run the solution for problem number 273:

```
[ leetcode/build ]$ cd test/273
[ leetcode/build/test/273 ] ctest
```


[leetcode problems]: https://leetcode.com/problemset/all/