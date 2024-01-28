//
// Created by elias on 27.01.2024.
//
#pragma once
#include "ttime.h"

using namespace std;


string secondsToTimeString(uint64_t seconds) {

    int minutes = (seconds % 3600) / 60;
    int hours = (seconds / 3600) % 24;


    int year = seconds / 31536000;
    int day = (seconds / 86400) % 365;

    seconds = seconds % 60;

    


    string sstm = to_string(seconds) + "s " + to_string(minutes) + "m " + to_string(hours) + "h " + to_string(day) + "d " + to_string(year) + 'y';
    return sstm;
}