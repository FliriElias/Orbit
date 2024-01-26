#pragma once
#include "Planet.h"

// Astronomical Unit in meters
const uint64_t Planet::AU = 149597870700;
// Gravitational Constant in m^3 kg^-1 s^-2
const long double Planet::G = 0.000000000066743015;

const uint32_t Planet::TIME_STEP = 3600 * 24; // 1 day

// Constructor
Planet::Planet(int64_t _x, int64_t _y, uint64_t _radius, uint64_t _mass) {

	x = _x;
	y = _y;
	radius = _radius;
	mass = _mass;

	distanceToCenter = 0;
	orbit = {};

	xVel = 0;
	yVel = 0;

}



void Planet::draw(void) {
	ofstream CoordinatesFile("coordinates.txt");
	uint64_t _x = x;
	uint64_t _y = y;

	if (orbit.size() > 2) {
		vector<coordinates> updatedPoints = {};
		for (const auto point : orbit) {
			x = point.x;
			y = point.y;

			coordinates temp;
			temp.x = x;
			temp.y = y;
			
			updatedPoints.push_back(temp);
		}

		for (const auto point : updatedPoints) {
			CoordinatesFile << point.x << ' ' << point.y << '\n';
			CoordinatesFile.close();
		}
	}

	return;
}

