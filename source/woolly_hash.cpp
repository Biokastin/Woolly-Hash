#include "woolly_hash.hpp"

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cassert>

void woolly_hash(const void* in, size_t in_len, void* out, size_t out_len) {

    /* setup */
    auto calc_merge_step = [](uint16_t l, uint16_t r) {
        return (l + r) >> 1;
    };

    uint8_t* buf = new uint8_t[in_len];
    size_t buf_len = in_len;

    bool is_finished = false;

    assert(in_len >= out_len);

    std::memcpy(buf, in, in_len);

    /* hashing */
    while (buf_len > out_len && !is_finished) {

        for (size_t i=0; i < buf_len / 2; i++) {
            
            buf[i] = calc_merge_step(buf[i*2], buf[i*2+1]);

            if (buf_len - i == out_len) {
                std::memcpy(&buf[i+1], &buf[(i+1)*2], buf_len - (i * 2));
                is_finished = true;
                continue;
            }

        }

        if (buf_len % 2 == 1) {
            buf[buf_len/2-1] = calc_merge_step(buf[buf_len/2-1], buf[buf_len-1]);
        }

        buf_len = buf_len / 2;

    }

    std::memcpy(out, buf, out_len);

    delete [] buf;

}
