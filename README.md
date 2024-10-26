# BloomFilter
Bloom filter for strings demo implementation

https://en.wikipedia.org/wiki/Bloom_filter <br />
A Bloom filter is a space-efficient probabilistic data structure, conceived by Burton Howard Bloom in 1970,<br />
 that is used to test whether an element is a member of a set.<br />
 False positive matches are possible, but false negatives are not<br />
 – in other words, a query returns either "possibly in set" or "definitely not in set".<br />
 Elements can be added to the set, but not removed (though this can be addressed with the counting Bloom filter variant);<br />
 the more items added, the larger the probability of false positives.<br /><br />
 
## Probability of False positivity: 
Let m be the size of bit array, k be the number of hash functions and n be the number of expected elements to be inserted in the filter, then the probability of false positive p can be calculated as:<br />
```math
    P = \left (1 - \left [1 - \frac{1}{m}\right ]^{kn}\right )^k
```
Size of Bit Array: If expected number of elements n is known and desired false positive probability is p then the size of bit array m can be calculated as:<br />
```math
    m = − \frac {n\ln P}{(ln 2)^2}
```
Optimum number of hash functions: The number of hash functions k must be a positive integer.<br />
If m is size of bit array and n is number of elements to be inserted, then k can be calculated as : <br />
```math
    k = \frac{m}{n}ln 2
```
## Space Efficiency

Bloom filters do not store the data items at all.<br />
 They use bit array which allow hash collision, otherwise it would not be compact. 
    
## Choice of Hash Function

The hash function used in bloom filters should be independent and uniformly distributed.<br />
They should be fast as possible.

# Get the source code

git clone git@github.com:Radu-Vasiliu/BloomFilter.git

# Build:
## Windows: 
```
    cd BloomFilter
    mkdir build-win
    cd build-win
    cmake ..
```
The above steps generate Visual Studio solution and project files. You can then open the solution in Visual Studio and build from there.
Alternatively you can build from command line, for example:
```
    cmake --build . --config Release
```

## Linux (WSL):
```
    cd BloomFilter
    mkdir build-linux
    cd build-linux
    cmake ..
```
Alternatively, open BloomFilter from Visual Studio Code (Windows).<br />
In VS Code CMakeTools extensions settiongs, Cmake: Build directory set to ${workspaceFolder}/build-linux.<br />
Build and run/debug from VS Code.<br />
To debug, create launch.json and add a new configuration c/c++ (gdb) launch. Edit the name of the executable.<br />

# Usage
BloomFilter blf(array_size);<br />
<br />
blf.addHash(hash_fn_1);<br />
blf.addhash(hash_fn_2);<br />
...<br />
<br />
bool inserted{false};<br />
<br />
inserted = blf.insert(my_string_1);<br />
inserted = blf.insert(my_string_2);<br />
...<br />

