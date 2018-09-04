# C-string Information Exercise

An Exercism.io-like exercise to simulate a method that provides complicated information.

# The task

To return various information about a string.

The header in `include/str_t.h` declares signatures for the functions you need to implement.

Add test to `tests/test_str_t.c` to specify how the functions should behave.

Remember to ask yourself: what parts of the code should "own" and thus free any memory you allocate?

**BEWARE** there could be gotchas hidden in this starter code. It is your task to find them.

You MAY change the signatures in the header if you need to.

# Learning outcomes

Understand:

* how a method can return structure information. In this case it is random facts about a string, but the same issues may apply when returning a record from a database or an API call.
* the tricky problem of memory ownership and when/where to free allocated memory
* how easy it is to forget to free memory you have allocated
* the difference between passing a struct as a pointer versus by value.

# Usage

Build and run the tests:

```
$ make test
```

Clean build outputs:

```
$ make clean
```

Clean build outputs and remove downloaded dependencies:

```
$ make clobber
```

To run the memory error detector. Install [valgrind](http://valgrind.org/):

```sh
# First time only (Mac)
$ brew install valgrind

# First time only (Ubuntu/Debian)
$ sudo apt-get install valgrind
```

From then on ...

```
$ make memcheck
```
