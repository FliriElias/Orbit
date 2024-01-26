// Orbits.h: Includedatei für Include-Standardsystemdateien
// oder projektspezifische Includedateien.

#pragma once
#include <cstdint>
#include <vector>
#include <fstream>

using namespace std;
// TODO: Verweisen Sie hier auf zusätzliche Header, die Ihr Programm erfordert.



class Planet
{
public:

	static const uint64_t AU;
	static const long double G;
	static const uint32_t TIME_STEP;

	int64_t x;
	int64_t y;
	uint64_t radius;
	uint64_t mass;

	uint64_t distanceToCenter;
	vector<int> orbit;

	uint32_t xVel;
	uint32_t yVel;



	// Constructor
	Planet(int64_t _x, int64_t _y, uint64_t _radius, uint64_t _mass);


	void draw(void);


};