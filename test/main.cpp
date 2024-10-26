
#include <iostream>
#include <string>
#include <array>
#include <cmath>

#include "BloomFilter.h"

/**
 *  Hash functions
 */
static int hashfn1(std::string const& str, size_t arrSize)
{
    int hash = 0;

    for (int i = 0; i < str.size(); i++)
    {
        hash = (hash + ((int)str[i]));
        hash = hash % arrSize;
    }
    return hash;
}

static int hashfn2(std::string const& str, size_t arrSize)
{
    int hash = 1;

    for (int i = 0; i < str.size(); i++)
    {
        hash = hash + std::pow(19, i) * str[i];
        hash = hash % arrSize;
    }
    return hash % arrSize;
}

static int hashfn3(std::string const& str, size_t arrSize)
{
    int hash = 7;

    for (int i = 0; i < str.size(); i++)
    {
        hash = (hash * 31 + str[i]) % arrSize;
    }
    return hash % arrSize;
}

static int hashfn4(std::string const& str, size_t arrSize)
{
    int hash = 3;
    int p = 7;

    for (int i = 0; i < str.size(); i++)
    {
        hash += hash * 7 + str[0] * std::pow(p, i);
        hash = hash % arrSize;
    }
    return hash;
}

static int hashfn5(std::string const& str, size_t arrSize)
{
    int hash = 3;
    int p = 11;

    for (int i = 0; i < str.size(); i++)
    {
        hash *= hash * 17 + str[0] * std::pow(p, i);
        hash = hash % (arrSize * 5);
    }
    hash = hash % arrSize;
    return hash;
}


/**
 *  main()
 */
int main(int argc, char * argv[])
{
    static constexpr int TEST_DATA_SIZE = 36;

    std::array<std::string, TEST_DATA_SIZE> testData
    { 
        "abound",   "abounds",       "abundance",
        "abundant", "accessible",    "bloom",
        "blossom",  "bolster",       "bonny",
        "bonus",    "bonuses",       "coherent",
        "cohesive", "colorful",      "comely",
        "comfort",  "gems",          "generosity",
        "generous", "generously",    "genial",
        "bluff",    "cheater",       "hate",
        "war",      "humanity",      "racism",
        "hurt",     "nuke",          "gloomy",
        "wants",    "be",            "cat",
        "facebook", "everybody",     "twitter"
    };
    

    rav::BloomFilter blf(128);
    blf.addHash(hashfn1);
    blf.addHash(hashfn2);
    //blf.addHash(hashfn3);
    //blf.addHash(hashfn4);
    //blf.addHash(hashfn5);

    for (int i = 0; i < TEST_DATA_SIZE; i++)
    {
        bool inserted { blf.insert(testData[i]) };
        if(inserted)
        {
            std::cout << "inserted " << testData[i] << std::endl;
        }
        else
        {
            std::cout << testData[i] << " probably already inserted" << std::endl;
        }
    }

    return 0;
}