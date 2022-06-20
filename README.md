# imgui template

This project is a basic template to setup an imgui application based on Conan and CMake.

---

## Prerequisites
- CMake
- Python3
- Ninja
- MSVC (on Windows), GCC or Clang (on Linux/Mac)

## Setup Conan
```bash
pip install conan
```

## Configure Dependencies
```bash
./conan/run_conan.sh <Debug|Release> # Linux/Mac
conan\run_conan.bat <Debug|Release> # Windows
```

## Configure Project
```bash
cmake -G Ninja -D CMAKE_BUILD_TYPE=<Debug|Release> -B ./build/<Debug|Release> -S .
```

## Build Project
```bash
cmake --build ./build/<Debug|Release> --config <Debug|Release>
```