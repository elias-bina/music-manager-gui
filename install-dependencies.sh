# Runtime for yt-dlp

sudo apt-get update
sudo apt-get install ffmpeg

# Compilation of vlc

sudo apt-get install \
  autoconf automake build-essential pkg-config libtool \
  gettext git python3 python3-pip yasm flex bison \
  libxcb-shm0-dev libxcb-xv0-dev libxcb-keysyms1-dev \
  libasound2-dev libpulse-dev libudev-dev libx11-dev \
  libxext-dev libxinerama-dev libgl1-mesa-dev libgles2-mesa-dev \
  qtbase5-dev qttools5-dev-tools qtwayland5 liblua5.2-dev lua5.2 \
  libavcodec-dev libavutil-dev libavformat-dev

# Windows

sudo apt-get install libglfw3-dev pkg-config libxkbcommon-dev xorg-dev
sudo snap install cmake --classic

cmake -S dependencies/glfw -B dependencies/glfw/build -D CMAKE_TOOLCHAIN_FILE=CMake/x86_64-w64-mingw32.cmake
