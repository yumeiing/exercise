if [[ ! -d ./build/ ]];then
  cmake -B build
fi
cd ./build/
make
echo 
../bin/app
