//
// Created by wolfctl on 5/5/20.
//

#include "process.h"

int process::maj(const int *replies, int size, int &tally) {
    int numberOfOnes = 0;
    for (int i = 0; i < size; ++i) {
        if (replies[i])
            ++numberOfOnes;
    }
    return numberOfOnes > (size / 2) ? 1 : 0;
}

void process::run(int *replies, const int size, const int index, const int traitors, const int coin) {
    int tally = 0;
    int majority = process::maj(replies, size, tally);
    replies[index] = (tally >= (2 * traitors + 1)) ? majority : coin;
}
