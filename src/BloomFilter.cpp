/*
 * File:    inc/BloomFilter.h
 * Author:  Radu Vasiliu
 *
 * This file is licensed under the MIT License as stated in BloomFilter.h
 *
 * Copyright (c) 2024 Radu Vasiliu
 */

#include <cmath>

#include "BloomFilter.h"

namespace rav
{

BloomFilter::BloomFilter(int filterSize)
    :
    bitarray_{},
    hashes_{},
    hashResults_{}
{
    bitarray_.resize(filterSize);
}

bool BloomFilter::insert(std::string const & str)
{
    bool ret{false};

    for (size_t i = 0; i < hashes_.size(); ++i)
    {
        hashResults_[i] = (*hashes_[i])(str, bitarray_.size());
    }

    if (false == lookup())
    {
        for (size_t i = 0; i < hashes_.size(); ++i)
        {
            bitarray_[hashResults_[i]] = true;
        }
        ret = true; 
    }
    return ret;
}

bool BloomFilter::lookup()
{
    // Check if all bits are set to true
    for (size_t i = 0; i < hashResults_.size(); ++i)
    {
        if (!bitarray_[hashResults_[i]])
        {
            return false;
        }
    }

    return true;
}

}
