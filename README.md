## Run test file
* make test
* LD_LIBRARY_PATH=`pwd`
* export LD_LIBRARY_PATH
* ./mallocTest

## Test on system
* export LD_PRELOAD=`pwd`/libmy_malloc.so

## Stop test on system
* unset LD_PRELOAD