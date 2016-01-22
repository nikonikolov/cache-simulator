#!/bin/bash

TYPE=fully_associative

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
cat ${INPUT} | ${EXECUTABLE} $(< ${PARAMS}) > ${GOT}

# Remove comments from output and from got
grep -v "#" ${GOT} > tmpdeb.got
grep -v "#" ${OUTPUT} > ${TMPOUTPUT}
#grep -v "#" ${OUTPUT} > temp && mv temp ${OUTPUT}

# Remove debug messages
sed '/debug-ack-begin/,/debug-ack-end/d' tmpdeb.got > ${TMPGOT} && rm -f tmpdeb.got

# Look at the differences (this assumes no comments)
DIFF=$(diff -q ${TMPGOT} ${TMPOUTPUT}) 


if [ "$DIFF" != "" ]; then
	echo "Outputs differ"
	
else
	echo "Success"
fi

grep -v "#" ${INPUT} > tmpdeb.input
grep -v "debug" tmpdeb.input > ${TMPINPUT} && rm -f tmpdeb.input
# Print input output and got if results differ
#pr -m -t -W 150 ${TMPINPUT} ${TMPOUTPUT} ${TMPGOT} > ${RESULT}
#paste "Input" "Reference" "Ouptut" | column -s $'\t' -t > ${RESULT}
paste ${TMPINPUT} ${TMPOUTPUT} ${TMPGOT} | column -s $'\t' -t > ${RESULT}

rm -f ${TMPINPUT}
rm -f ${TMPOUTPUT}
rm -f ${TMPGOT}

#pr && pr EOF