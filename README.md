# Arduino TDD Starter

This project will help you test drive the code for your Arduino project.  If you are unfamiliar with test driving, especially test driving embedded code, there are two books that are highly recommended.

* [Modern C++ Programming with Test-Driven Development](https://amzn.to/2ZrHhSn) by Jeff Langr talks about using C++ in general.  As Arduino is a C++ library, this will be directly relevant.
* [Test Driven Development for Embedded C](https://amzn.to/34U3Lg1) by James Grenning delves into the specifics of testing in an embedded space.

## Requirements

On your local workstation, you will need:

* GNU Make
* A native C++ toolchain
* CMake at least version 3.13

## Building and Running Tests

From the command shell:

    mkdir build
    cd build
    cmake ..

To build your code, from the build folder run

    make
    make test


-fin
