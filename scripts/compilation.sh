#!/bin/bash

INPUT_FILE=""
declare -a OUTPUT_SECTIONS=()

while getopts ":i:o:" opt; do
	case $opt in
		i) INPUT_FILE=("$OPTARG") ;;
		o) OUTPUT_SECTIONS+=("$OPTARG") ;;
	esac
done

echo ${OUTPUT_SECTIONS[@]}

# Split the input file name using '.' as the delimiter
IFS='.' read -ra file_name_list <<< "$INPUT_FILE"

# execute the compile command
EXECUTABLE="${file_name_list[0]}"
compile="riscv32-unknown-elf-gcc $INPUT_FILE -o $EXECUTABLE -nostdlib -nostartfiles"
eval "$compile"

# create binary file for different sections and convert them to readable text files
for section in "${OUTPUT_SECTIONS[@]}"; do
	binary_file="$EXECUTABLE.${section:1}.bin"
	create_binary="riscv32-unknown-elf-objcopy -O binary --only-section=$section $EXECUTABLE $binary_file"
	eval "$create_binary"
	
	hex_file="$EXECUTABLE.${section:1}.hex"
	create_hex="hexdump -C $binary_file > $hex_file"
	eval "$create_hex"
	
	text_file="$EXECUTABLE.${section:1}.txt"
	process="perl process_hex.pl $hex_file $text_file"
	eval "$process"
done

# compile the c++ program
# compile_test="g++ tb_riscv.cpp -o tb_riscv"
# eval "$compile_test"

# run the c++ program with files
# run_test="./tb_riscv $EXECUTABLE.text.txt $EXECUTABLE.data.txt"
# eval "$run_test"
