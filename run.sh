#!/bin/bash

# Tạo thư mục build nếu chưa có
mkdir -p build

# Di chuyển vào thư mục build
cd build

# Chạy cmake và biên dịch
cmake ..
make

./demoProj
