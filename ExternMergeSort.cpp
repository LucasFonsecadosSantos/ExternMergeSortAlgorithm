#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <iostream>

struct Data {

    public:

        int key_1;
        int key_2;
        float value_1;
        char field_1[5];
        char field_2[20];
        char garbage[500];
};

bool intercalaBloco(std::ifstream auxE[2], std::ofstream auxS[2], int stage, int result) {

}