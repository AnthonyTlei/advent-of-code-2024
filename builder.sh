#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <source_file.cpp>"
    exit 1
fi

SOURCE_FILE="$1"
if [[ ! -f "$SOURCE_FILE" ]]; then
    echo "Error: File '$SOURCE_FILE' does not exist."
    exit 1
fi

OUTPUT_DIR="builds"
mkdir -p "$OUTPUT_DIR"

BASE_NAME=$(basename "$SOURCE_FILE" .cpp)

DIR_NAME=$(dirname "$SOURCE_FILE")
DIR_BASENAME=$(basename "$DIR_NAME")

DIR_BASENAME=$(echo "$DIR_BASENAME" | tr '-' '_')
BASE_NAME=$(echo "$BASE_NAME" | tr '-' '_')

OUTPUT_NAME="${DIR_BASENAME}_${BASE_NAME}"

clang++ -std=c++20 "$SOURCE_FILE" -o "$OUTPUT_DIR/$OUTPUT_NAME"

if [ $? -eq 0 ]; then
    echo "Build successful! Output: $OUTPUT_DIR/$OUTPUT_NAME"
else
    echo "Build failed."
    exit 1
fi