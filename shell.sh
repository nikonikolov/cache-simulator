#!/bin/bash

function run_exec {
	TYPE=$1

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
		echo "Outputs differ:" ${TYPE} 
	else
		echo "Success:" ${TYPE} 
	fi

	grep -v "#" ${INPUT} > tmpdeb.input
	grep -v "debug" tmpdeb.input > ${TMPINPUT} && rm -f tmpdeb.input
	# Print input output and got if results differ
	paste ${TMPINPUT} ${TMPOUTPUT} ${TMPGOT} | column -s $'\t' -t > ${RESULT}

	rm -f ${TMPINPUT}
	rm -f ${TMPOUTPUT}
	rm -f ${TMPGOT}
}

run_exec fully_associative
run_exec direct-mapped
run_exec four_byte_writes
run_exec single_byte_reads
run_exec two_byte_reads
run_exec singe_word_block_lru