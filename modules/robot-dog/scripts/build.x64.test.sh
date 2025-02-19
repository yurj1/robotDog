cp make/CMakeLists.txt.x64.test CMakeLists.txt
mkdir build
cd build
cmake -DG_TEST=ON -DROS_ENABLE=ON -DROS2_ENABLE=OFF -DLCM_ENABLE=OFF -DDDS_ENABLE=OFF -DGLOG_ENABLE=ON  -DCMAKE_BUILD_TYPE=Release ../
make -j$(nproc)
