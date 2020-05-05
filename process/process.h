//
// Created by wolfctl on 5/5/20.
//

#ifndef APA_BYZANTINE_FAULT_TOLERANCE_PROCESS_H
#define APA_BYZANTINE_FAULT_TOLERANCE_PROCESS_H


namespace process {
    static int maj(const int *replies, int size, int &tally);

    void run(int *replies, int size, int index, int traitors, int coin);
};


#endif //APA_BYZANTINE_FAULT_TOLERANCE_PROCESS_H
