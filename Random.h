//Copyright 2021
#ifndef RANDOM_H_
#define RANDOM_H_

#include <cstdlib>
#include <ctime>

/** Class to encapsulate the standard random number generator. */
class Random {

public:

    /** Initializes the random number generator using the time
        as the seed.
    */
    Random() {
        srand(std::time(0));
    }

    /** Initializes the randon mumber generator using a
        supplied seed.
    */
    explicit Random(int seed) {
        srand(seed);
    }

    /** Returns a random integer in the range 0 to n. */
    int next_int(int n) {
        return int(next_double() * n);
    }

    /** Return a random double in the range 0 to 1. */
    double next_double() {
        return double(rand()) / RAND_MAX;
    }

};

#endif
