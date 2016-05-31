run the test
LD_LIBRARY_PATH=`pwd`
export LD_LIBRARY_PATH
./mallocTest

test on system
export LD_PRELOAD=`pwd`/libmy_malloc.so

to stop
unset LD_PRELOAD