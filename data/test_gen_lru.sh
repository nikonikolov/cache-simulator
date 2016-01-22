#!/bin/bash

TYPE=singe_word_block_lru

ADDRESS_BITS=8
BYTESPW=1
WORDSPB=1
BLOCKSPS=4
SETSPC=2
CYCLESHIT=1
CYCLESREAD=3
CYCLESWRITE=2

# Create params file
printf ${ADDRESS_BITS}" "${BYTESPW}" "${WORDSPB}" "${BLOCKSPS}" "${SETSPC}" "${CYCLESHIT}" "${CYCLESREAD}" "${CYCLESWRITE}" " > ${TYPE}.params


#Create input file
printf "write-req 0 FF
read-req 0
write-req 2 FA
read-req 2
write-req 4 FB
read-req 4
write-req 6 FC
read-req 6
read-req 0
write-req 8 FD
read-req 8
read-req 2
read-req 4
write-req 7 FE
flush-req" > ${TYPE}.input


#Create output file
printf "write-ack 0 miss 1
read-ack 0 hit 1 FF
write-ack 0 miss 1
read-ack 0 hit 1 FA
write-ack 0 miss 1
read-ack 0 hit 1 FB
write-ack 0 miss 1
read-ack 0 hit 1 FC
read-ack 0 hit 1 FF
write-ack 0 miss 3
read-ack 0 hit 1 FD
read-ack 0 miss 6 FA
read-ack 0 miss 6 FB
write-ack 1 miss 1
flush-ack 6" > ${TYPE}.output
