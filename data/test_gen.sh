#!/bin/bash
# 8 bit addresses
# 2 Bytes/word, 2 words/block, 1 block/set, 2 sets/cache
# 1 cycle/hit, 2 cycles/read, 2 cycles/write

TYPE=try

ADDRESS_BITS=8
BYTESPW=2
WORDSPB=2
BLOCKSPS=1
SETSPC=2
CYCLESHIT=2
CYCLESREAD=2
CYCLESWRITE=2

# Create params file
printf ${ADDRESS_BITS}"\n"${BYTESPW}"\n"${WORDSPB}"\n"${BLOCKSPS}"\n"${SETSPC}"\n"${CYCLESHIT}"\n"${CYCLESREAD}"\n"${CYCLESWRITE}"\n" > ${TYPE}.params

MAX_ADDRESS=$((2**${ADDRESS_BITS}))

#Create input file

