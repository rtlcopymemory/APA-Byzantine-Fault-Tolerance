//
// Created by wolfctl on 5/5/20.
//

#ifndef APA_BYZANTINE_FAULT_TOLERANCE_CLUSTER_H
#define APA_BYZANTINE_FAULT_TOLERANCE_CLUSTER_H


class cluster {
private:
    // Simulates the interprocess communication
    int *interProcessArray;
    int processes;
    int traitors;
    int coin;

    void randomizeTraitors();

    void flipCoin();

    bool checkConsensus();

    void allSameLoyal();

    void randomLoyal();

public:
    cluster(int processes, int traitors);

    ~cluster();

    // Runs the processes n times randomizing the traitors at every run
    // RETURNS: number of rounds needed
    int run(bool allLoyalSameInit);
};


#endif //APA_BYZANTINE_FAULT_TOLERANCE_CLUSTER_H
