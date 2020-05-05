//
// Created by wolfctl on 5/5/20.
//

#include <cstdlib>
#include <cstdio>
#include "cluster/cluster.h"

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Error: Missing argument\nUsage: %s <runs> <total number of processes> <traitor processes>\n", argv[0]);
        exit(1);
    }

    int processes = (int) strtol(argv[1], nullptr, 10);
    int traitors = (int) strtol(argv[2], nullptr, 10);
    int runs = (int) strtol(argv[3], nullptr, 10);
    if (processes < (3 * traitors + 1)) {
        printf("It is impossible for the reliable processes to reach a consensus\n");
        exit(0);
    }

    if (processes < 0 || traitors < 0) {
        printf("Invalid number of processes or traitors\n");
        exit(1);
    }

    if (runs < 1) {
        printf("Runs must be a positive number");
        exit(1);
    }

    // Checks passed
    auto simulation = new cluster(processes, traitors);
    return 0;
}
