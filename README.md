# BloomFilter
Bloom filter for string demo implementation

# Usage
BloomFilter blf(array_size);

blf.addHash(hash_fn_1);
blf.addhash(hash_fn_2);
...

bool inserted{false};

inserted = blf.insert(my_string_1);
inserted = blf.insert(my_string_2);
...

