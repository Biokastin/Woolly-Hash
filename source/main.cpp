#include "woolly_hash.hpp"

#include <cstddef>
#include <cstdint>
#include <cassert>
#include <iostream>
#include <chrono>

int main() {

    /* verification */
    {
        const uint8_t test_data[] = {0xAA, 0x55, 0xFF, 0x01, 0xAA};
        const uint8_t expected_result[] = {0xFF, 0x04};
        
        uint8_t result[2] = {};

        woolly_hash(test_data, sizeof(test_data), result, sizeof(result));

        assert(sizeof(expected_result) == sizeof(result));

        for (size_t i=0; i < sizeof(expected_result); i++) {
            assert(expected_result[i] == result[i]);
        }
    }

    /* benchmark - 1GB in, 32 bytes out */
    {
        const int benchmark_len = 1024 * 1024 * 1024;
        const int out_len = 32;

        uint8_t* benchmark_in = new uint8_t[benchmark_len];
        uint8_t  out[out_len] = {};

        auto start_time = std::chrono::high_resolution_clock::now();
        
        woolly_hash(benchmark_in, benchmark_len, out, out_len);

        auto end_time = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time);

        std::cout << "benchmark duration: " << duration.count() * 0.000000001f << " seconds" << std::endl;

        delete [] benchmark_in;
    }

    /* interactable - user defined string, user defined out_len */
    {
        const int out_len = 5;

        uint8_t benchmark_in[] = "Hello world, and all who inhabit it!";
        uint8_t out[out_len] = {};

        woolly_hash(benchmark_in, sizeof(benchmark_in), out, out_len);

        for (size_t i=0; i < out_len; i++) {
            printf("%02x ", out[i]);
        }

        printf("\n");
    }

}
