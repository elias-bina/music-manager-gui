sudo apt-get update
sudo apt-get install libglfw3-dev pkg-config libxkbcommon-dev xorg-dev
sudo snap install cmake --classic

cmake -S dependencies/glfw -B dependencies/glfw/build -D CMAKE_TOOLCHAIN_FILE=CMake/x86_64-w64-mingw32.cmake
