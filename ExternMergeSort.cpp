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

    bool intercalou = false;
    Data data[2];
    int position[2] = {0,0};
    bool validation[2] = {false,false};

    while((position[0] < stage) && (2 * stage)) {
        if((position[0] < stage) && !validation[0]) {
            if(auxE[0].read((char*) &data[0], sizeof(Data))) {
                validation[0] = true;
            }else {
                position[0] = stage;
            }
        }
        if((position[1] < stage) && !validation[1]) {
            if(auxE[1].read((char*) &data[1], sizeof(Data))) {
                validation[1] = true;
            }else {
                position[1] = stage;
            }
        }
    }

    if(validation[0] && validation[1]) {
        intercalou = true;
        if(data[0].key_1 <= data[1].key_1) {
            auxS[result].write((const char*)(&data[0]), sizeof(Data));
            validation[0] = false;
            position[0]++;
        }else {
            auxS[result].write((const char*)(&data[1]), sizeof(Data)));
            validation[1] = false;
            position[1]++;
        }
    }else if(validation[0]){
        intercalou = true;
        auxS[result].write((const char*)(&data[0]), sizeof(Data));
        validation[0] = false;
        position[0]++;
    }else if(validation[1]) {
        intercalou = true;
        auxS[result].write((const char*))
    }
}