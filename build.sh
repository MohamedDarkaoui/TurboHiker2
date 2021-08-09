if [ -d "build" ]
then 
	rm -r build
fi

mkdir build
cd build || exit
cmake ..
make 
make install
cd ..