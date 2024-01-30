#include "woolly_hash.hpp"

#include <cstddef>
#include <cstdint>
#include <cassert>

int main() {

    /* verification */
    const uint8_t test_data[] = {10, 20, 2, 4, 1};
    const uint8_t expected_result[] = {15, 2};
    
    uint8_t result[2] = {};

    woolly_hash(test_data, sizeof(test_data), result, sizeof(result));

    assert(sizeof(expected_result) == sizeof(result));

    for (int i=0; i < sizeof(expected_result); i++) {
        assert(expected_result[i] == result[i]);
    }

    /* benchmark - 1GB in, 32 bytes out */
    const int benchmark_len = 1024 * 1024 * 1024;
    const int out_len = 32;

    uint8_t* benchmark_in = new uint8_t[benchmark_len];
    uint8_t  out[out_len] = {};

    woolly_hash(benchmark_in, benchmark_len, out, out_len);

    delete [] benchmark_in;

}