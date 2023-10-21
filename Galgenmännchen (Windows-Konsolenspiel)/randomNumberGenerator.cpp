#include<iostream>
#include<random>
#include<time.h>


using namespace std;


int random(int low, int high)
{
    typedef mt19937 rng_type;
    uniform_int_distribution<rng_type::result_type> udist(low, high);

    rng_type rng;


    // seed rng first:
    rng_type::result_type const seedval = time(0); // get this from somewhere
    rng.seed(seedval);

    rng_type::result_type random_number = udist(rng);

    return random_number;
}
