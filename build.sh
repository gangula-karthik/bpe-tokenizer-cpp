#!/bin/bash

# Build script for BPE Tokenizer with Conan and CMake
set -e

echo "Building BPE Tokenizer with Boost Regex..."

# Clean build directory if it exists
if [ -d "build" ]; then
    rm -rf build
fi

# Install dependencies with Conan
echo "Installing dependencies with Conan..."
conan install . --output-folder=build --build=missing

# Configure with CMake
echo "Configuring with CMake..."
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release

# Build
echo "Building..."
cmake --build . --config Release

echo "Build complete! Run './main' to execute the program."
