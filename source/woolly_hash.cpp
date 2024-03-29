#include "woolly_hash.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <array>

template<typename T, size_t N>
constexpr std::array<T, N> gen_lut() {

    std::array<T, N> arr = {};

    uint8_t tmp = 0;

    for (size_t i=0; i < N; i++) {
        
        tmp = (i >> 1) ^ i;

        arr[i] = (
            (tmp & 0b00000001) |
            ((tmp >> 1) & 0b00000010) |
            ((tmp >> 2) & 0b00000100) |
            ((tmp >> 3) & 0b00001000)
        );
    
    }

    return arr;

}

std::array<uint8_t, 256> merge_lut = gen_lut<uint8_t, 256>();

WoollyStatus woolly_hash(const void* in, size_t in_len, void* out, size_t out_len) {

    /* setup */
    if (in_len < out_len) {
        return WoollyStatus::ToSmallIn;
    };
    
    uint8_t* buf = new uint8_t[in_len];

    if (buf == nullptr) {
        return WoollyStatus::MemoryAllocError;
    };

    size_t buf_len = in_len;

    bool is_finished = false;

    std::memcpy(buf, in, in_len);

    /* hashing */
    while (buf_len != out_len && !is_finished) {
        
        /* check for unintended pairless byte */
        if (buf_len % 2 == 1 && (out_len % 2 != 1 || buf_len / 2 >= out_len)) {
            /* perform merge operation on second to last byte and last byte */
            buf[buf_len-2] = (merge_lut[buf[buf_len-2]] << 4) | merge_lut[buf[buf_len-1]];
            buf_len--;
        }

        for (size_t i=0; i < buf_len / 2; i++) {

            /* check if calculated bytes + remaining bytes = output length */
            if (buf_len - (i + 1) == out_len && buf_len / 2 < out_len) {
                /* concatenate remaining bytes to end of this round's calculated bytes */
                std::memcpy(&buf[i], &buf[i*2], buf_len - out_len);
                is_finished = true;
                break;
            }

            buf[i] = (merge_lut[buf[i*2]] << 4) | merge_lut[buf[i*2+1]];

        }

        buf_len = buf_len / 2;

    }

    std::memcpy(out, buf, out_len);

    delete [] buf;

    return WoollyStatus::Success;

}
