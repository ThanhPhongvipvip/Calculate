# CMAKE

## 1. Cấu trúc CMake của dự án

### 1.1. Root `CMakeLists.txt` (Thư mục gốc)
- Nhiệm vụ: Thiết lập thông tin chung của toàn bộ dự án, tiêu chuẩn C++ (C++14), và tập hợp các thư mục con lại với nhau.
- Lệnh:
  - `add_subdirectory(basic_calc)` / `add_subdirectory(advance_calc)`: Báo cho CMake biết hãy vào các thư mục này và chạy các file CMakeLists.txt bên trong.
  - `add_executable(demoProj main.cpp)`: Khai báo tạo ra một file thực thi có tên là `demoProj` từ file mã nguồn `main.cpp`.
  - `target_link_libraries(demoProj PRIVATE basic_calc advance_calc)`: Liên kết (link) các thư viện toán học đã được build ở các thư mục con vào file thực thi chính.

### 1.2. Module CMake (Ví dụ: `basic_calc/CMakeLists.txt`)
- Nhiệm vụ: Hoạt động như một cầu nối. Nó không trực tiếp build mã nguồn nào mà chỉ gom các chức năng con lại thành một gói (module) duy nhất.
- Lệnh: 
  - `add_subdirectory(...)`: Tiếp tục gọi xuống các thư mục của từng phép toán cụ thể (`add`, `subtract`, `multiply`, `divide`).
  - `add_library(basic_calc INTERFACE)`: Tạo ra một thư viện "ảo" (interface). Thư viện này không có code thực sự mà chỉ đóng vai trò đại diện.
  - `target_link_libraries(basic_calc INTERFACE add subtract multiply divide)`: Gắn các thư viện con thực sự vào thư viện đại diện `basic_calc`. Khi file `main.cpp` link với `basic_calc`, nó sẽ tự động link với tất cả các phép toán con.

### 1.3. Leaf CMake (Ví dụ: `basic_calc/add/CMakeLists.txt`)
- Nhiệm vụ: Đây là nơi thực sự diễn ra quá trình biên dịch (build) từng file code `.cpp` thành thư viện tĩnh (static library).
- Lệnh:
  - `add_library(add add.cpp)`: Biên dịch `add.cpp` thành một thư viện có tên là `add` (ví dụ `libadd.a`).
  - `target_include_directories(add PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../..)`: Chỉ định đường dẫn gốc để file `.cpp` và thư viện khác có thể `#include` đường dẫn chính xác (ví dụ `#include "basic_calc/add/add.h"` mà không bị lỗi không tìm thấy file).

## 2. Cách chạy chương trình

Chạy: 

```bash
./run.sh
```

Script này sẽ tự động:
1. Tạo thư mục `build/` nếu chưa có.
2. Di chuyển vào `build/` và chạy `cmake ..` để đọc cấu trúc cấu hình.
3. Chạy lệnh `make` để bắt đầu quá trình biên dịch.
4. Tự động thực thi `./demoProj` sau khi build xong và in kết quả phép tính ra màn hình.
