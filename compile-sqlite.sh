pushd dependencies/sqlite
mkdir build
pushd build
../configure
make -j`nproc`
popd
popd