pushd ./dependencies/vlc
./bootstrap
./configure --disable-swscale --disable-xcb --disable-qt
make -j`nproc`
sudo make install
popd