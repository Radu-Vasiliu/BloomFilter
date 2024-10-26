# BloomFilter
Bloom filter for string demo implementation

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

