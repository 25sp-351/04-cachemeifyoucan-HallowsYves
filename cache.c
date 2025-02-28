#include "rod_cut.h"
#include <stdio.h>


rod_cut_func_ptr rod_cut_provider;
long _memoization_data[ARRAY_SIZE];


rod_cut_func_ptr _original_rod_cut;



int cache_function(int rodLength, int lengths[], int values[], int peiceCount) {

    if (rodLength > MAX_MEMOIZED) {
        return (*_original_rod_cut)(rodLength, lengths, values, peiceCount);
    }

    if(_memoization_data[rodLength] == NO_VALUE_YET) {
        printf("computing value for rod length %ld\n", rodLength);
        _memoization_data[rodLength] = (*_original_rod_cut)(rodLength, lengths, values, peiceCount);
        printf("Stored max profit for rod length %d: %d\n", rodLength, _memoization_data[rodLength]);
    } else {
        printf("Returning cached value for rod length %d: %d\n", rodLength, _memoization_data[rodLength]);
    }

    return _memoization_data[rodLength];
}

rod_cut_func_ptr initialize_cache(rod_cut_func_ptr real_provider) {
    for (int index = 0; index < ARRAY_SIZE; index++) {
        _memoization_data[index] = NO_VALUE_YET;

        _original_rod_cut = real_provider;
        return cache_function;
    }
}