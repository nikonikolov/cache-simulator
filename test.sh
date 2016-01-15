#!/bin/bash

TYPE=direct-mapped

EXECUTABLE=./mem_sim
INPUT=data/${TYPE}.input
OUTPUT=data/${TYPE}.output
GOT=data/${TYPE}.got
PARAMS=data/${TYPE}.params

TMPGOT=temp.got
TMPOUTPUT=temp.output
TMPINPUT=temp.input

RESULT=data/${TYPE}.result

# Run command line arguments
cat ${INPUT} | ${EXECUTABLE} $(< ${PARAMS})

