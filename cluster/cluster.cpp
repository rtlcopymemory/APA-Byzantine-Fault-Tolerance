//
// Created by wolfctl on 5/5/20.
//

#include <cstdlib>
#include <ctime>
#include "cluster.h"

cluster::cluster(int processes, int traitors) {
    this->processes = processes;
    this->traitors = traitors;
    this->interProcessArray = new int[processes];
    srand(time(NULL));
}

cluster::~cluster() {
    delete[] this->interProcessArray;
}

void cluster::randomizeTraitors() {
    int startRange = this->processes - this->traitors;
    for (int i = startRange; i < this->processes; ++i) {
        this->interProcessArray[i] = rand() % 2; // 0 or 1
    }
}

bool cluster::checkConsensus() {
    int startRange = this->processes - this->traitors;
    int check = this->interProcessArray[0];
    for (int i = 1; i < startRange; ++i)
        if (check != this->interProcessArray[i])
            return false;
    return true;
}

void cluster::allSameLoyal() {
    int startRange = this->processes - this->traitors;
    for (int i = 1; i < startRange; ++i) {
        this->interProcessArray[i] = 1;
    }
}

void cluster::randomLoyal() {
    int startRange = this->processes - this->traitors;
    for (int i = 1; i < startRange; ++i) {
        this->interProcessArray[i] = rand() % 2;
    }
}

int cluster::run() {
    while (!this->checkConsensus()) {
        this->randomizeTraitors();
        this->allSameLoyal();  // Switch to test the other case: allSameLoyal(), randomLoyal()
        // TODO: Run process(this->interProcessArray, i);
    }
    return -1;
}
