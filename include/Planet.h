// Orbits.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;
// TODO: Verweisen Sie hier auf zusätzliche Header, die Ihr Programm erfordert.


struct coordinates {
    long double x;
    long double y;
};

struct force_coordinates {
    long double force_x;
    long double force_y;
};


class Planet
{
public:

	static const int64_t AU;
	static const long double G;
	static const uint32_t TIME_STEP;

    long double x;
    long double y;
    long double radius;
	long double mass;

    long double distanceToCenter;
	vector<coordinates> orbit;

    bool sun;

    long double xVel;
	long double yVel;



	// Constructor
	Planet(long double _x, long double _y, long double _radius, long double _mass);


    void save_data(const string &path, const string &Time, bool append, bool add_time);


    coordinates attraction(const Planet &other);

    void updatePosition(vector<Planet> &planets);


};