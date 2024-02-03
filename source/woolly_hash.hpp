/**
 * @file woolly_hash.hpp
 * @author Brayden Harlon
 * @brief header file for woolly hash
 * @version 0.1
 * @date 2024-01-29
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef WOOLLY_HASH_H
#define WOOLLY_HASH_H

#include <cstddef>

/**
 * @brief calculates a novel fuzzy hash based on merging bit pair via XOR in a tree like pattern
 * 
 * @param in        pointer to data to hash
 * @param in_len    length of data at `in`
 * @param out       pointer to hash output
 * @param out_len   length of desired output at `out`
 * 
 * @attention ensure memory allocated for `out` is more than or equal to `out_len`, and ensure `in_len` is more than or equal to `out_len`.
 * 
 */
void woolly_hash(const void* in, size_t in_len, void* out, size_t out_len);

#endif /* WOOLLY_HASH_H */
