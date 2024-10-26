/*
 * File:    inc/BloomFilter.h
 * Author:  Radu Vasiliu
 *
 * This file is licensed under the MIT License as stated below
 *
 * Copyright (c) 2024 Radu Vasiliu
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Description
 * -----------
 * The headerfile inc/BloomFilter.h contains the declaration of BloomFilter class
 * used to implement Bloom filter for strings.
 */
#ifndef BLOOM_FILTER_H__INCLUDED
#define BLOOM_FILTER_H__INCLUDED

#include <vector>
#include <string>

namespace rav
{

    class BloomFilter
    {
    public:
        BloomFilter(int filterSize);

        ~BloomFilter()  
        {
        }

        /* Insert a string in the set */
        bool insert(std::string const & str);

        /* Typedef for hash function pointer */
        typedef int (*pfnHashFn)(std::string const&, size_t bitArraySize);

        /* Add a hash function to the filter. */
        void addHash(pfnHashFn pfn)
        {
            hashes_.push_back(pfn);
            hashResults_.push_back(0);
        }

    private:
        /* Checks the bitarray_ for the bits set in hashResults_.
         * If at least one bit is not set, the string for which hashResults_ was computed is not part of the set.
         * Otherwise it may be part of the set.
         */
        bool lookup() const;
        
    private:
        /* bit array containing bits set by hash functions */
        std::vector<bool>       bitarray_;
        
        /* the hash functions used */
        std::vector<pfnHashFn>  hashes_;

        /* buffer containing the result of running hash functions on a certain input */
        std::vector<int>        hashResults_;
    };

}

#endif // BLOOM_FILTER_H__INCLUDED
