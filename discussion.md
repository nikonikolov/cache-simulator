Cache Simulator nn1144
==================================

Strucuture
------------------------

There are 5 object classes that model the behaviour of physical memory and cache:
Word, Block, Set, Cache and Memory. The first 4 contain vectors whose entries
are the lower level objects(e.g. Cache contains a vector of Sets). Memory is 
composed of a vector of Words. Note that an implementation that keeps all words in
memory and keeps only tags, dirty and valid bits in cache is also possible as we
are simply doing a simulation. This version, however, was not chosen as it
differs from the actual hardware implementation of a cache. 


Program Flow
-------------

Instruction parameters are read and parsed in the main. After that, the request
is passed on to the the lower levels of the program via the Cache object initialised
in the main. For read and write requests, an object of type RetObj is returned and
printed. 


Compilation
-------------

A makefile constructs an executable called mem_sim and stores it in the main.
Anything named with the pattern mem_sim_*.cpp gets compiled. C++11 compiler 
features are required.

Testing
-------------

A bash script shell.sh is used to pass input parameters saved in a file and
redirect stdin and stdout to specified files. The expected output and the actual
result from the program are then compared and if there are any differences 
(i.e. the program did not produce the expected result), then the input, expected output
and the result got are printed in a file stored in data directory.

Note that shell.sh has to be run from the root directory and assumes an unix environment.

