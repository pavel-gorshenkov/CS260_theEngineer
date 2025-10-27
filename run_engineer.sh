#!/bin/bash
set -e  # Stop if any command fails

# 🧹 Clean and rebuild the project
echo "🧹 Cleaning build directory..."
rm -rf build
mkdir -p build
cd build

# ⚙️ Configure with CMake
echo "⚙️  Configuring project with CMake..."
cmake ..

# �� Build with Make (using all CPU cores)
echo "🔨 Building project..."
make -j"$(nproc)"

# 🚀 Run the executable
echo "🚀 Running CS260_theEngineer..."
./CS260_theEngineer

