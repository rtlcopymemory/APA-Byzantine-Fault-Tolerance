project("APA Byzantine Fault Tolerance")

add_executable(byzantine main.cpp cluster/cluster.cpp cluster/cluster.h process/process.cpp process/process.h)
