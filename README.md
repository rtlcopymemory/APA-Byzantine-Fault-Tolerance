# APA-Byzantine-Fault-Tolerance
Class Assignment

Implements the Byzantine Fault Tolerance algorithm in C++ using a class to simulate the interprocess communication

## How to compile
```sh
git clone https://github.com/WolfenCLI/APA-Byzantine-Fault-Tolerance.git
cd APA-Byzantine-Fault-Tolerance/build
cmake ..
make
```

## How to run
From the build folder:
```sh
./byzantine <runs> <total number of processes> <number of traitors> [-b]
```

The `-b` option enables the worst case scenario which is where the traitors make the most damage making the loyal processes disagree on the tally(i)

