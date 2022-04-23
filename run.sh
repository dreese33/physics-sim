# this function is called when Ctrl-C is sent
function trap_ctrlc()
{
    # perform cleanup here
    echo "Ctrl-C caught...performing clean up"

    # navigate back to root directory
    cd ..

    # exit shell script with error code 2
    # if omitted, shell script will continue execution
    exit 2
}

# make files
cmake . -B build/
cd build
make

# initialise trap to call trap_ctrlc function
# when signal 2 (SIGINT) is received
trap "trap_ctrlc" 2

# run executable
./Physics_Sim

# return to root dir
cd ..
