#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-msc30-c"
#pragma ide diagnostic ignored "cert-msc32-c"
//
// Created by wolfctl on 5/5/20.
//

#include <cstdlib>
#include <ctime>
#include <cstdio>
#include "cluster.h"
#include "../process/process.h"

cluster::cluster(int processes, int traitors) {
    this->processes = processes;
    this->traitors = traitors;
    this->interProcessArray = new int[processes];
    this->coin = 0;
    srand(time(NULL));
}

cluster::~cluster() {
    delete[] this->interProcessArray;
}

void cluster::randomizeTraitors() {
    int startRange = this->processes - this->traitors;
    for (int i = startRange; i < this->processes; ++i)
        this->interProcessArray[i] = rand() % 2; // 0 or 1
}

void cluster::flipCoin() {
    this->coin = rand() % 2;
    // fprintf(stderr, "Coin: %d\n", this->coin);
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
    for (int i = 1; i < startRange; ++i)
        this->interProcessArray[i] = 1;
}

void cluster::randomLoyal() {
    int startRange = this->processes - this->traitors;
    for (int i = 1; i < startRange; ++i)
        this->interProcessArray[i] = rand() % 2;
}

void cluster::forceWorstScenario() {
    static int count = 0;
    int startRange = this->processes - this->traitors;
    for (int i = startRange; i < this->processes; ++i)
        this->interProcessArray[i] = count % 2;
    count++;
}

int cluster::run(bool allLoyalSameInit = false, bool forceBadScenario = false) {
    if (allLoyalSameInit)
        this->allSameLoyal();
    else
        this->randomLoyal();
    int rounds = 0;
    while (!this->checkConsensus()) {
        rounds++;
        this->flipCoin();
        // Run process::run(int *replies, int size, int index, int traitors, int coin); this->loyal times
        for (int i = 0; i < this->processes - this->traitors; ++i) {
            this->randomizeTraitors();
            if (forceBadScenario)
                this->forceWorstScenario();
            process::run(this->interProcessArray, this->processes, i, this->traitors, this->coin);
        }
    }
    return rounds;
}

#pragma clang diagnostic pop