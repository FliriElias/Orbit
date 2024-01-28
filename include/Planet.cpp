#pragma once
#include "Planet.h"


// Astronomical Unit in meters
const int64_t Planet::AU = 149597870700;
// Gravitational Constant in m^3 kg^-1 s^-2
const long double Planet::G = 0.000000000066743015;

const uint32_t Planet::TIME_STEP = 3600 * 24; // 1 day

// Constructor
Planet::Planet(long double _x, long double _y, long double _radius, long double _mass) {

	x = _x;
	y = _y;
	radius = _radius;
	mass = _mass;

	distanceToCenter = 0;
	orbit = {};

    sun = false;

	xVel = 0;
	yVel = 0;

}


void Planet::save_data(const std::string &path, const string &Time, bool append = false, bool add_time = true) {
    ofstream OutputFile;
    if (append) {
        OutputFile.open(path, std::ios_base::app);
    } else {
        OutputFile.open(path);
    }

    // time logic
    if (add_time) {
        OutputFile << x << ' ' << y << ' ' << Time << endl;
    } else {
        OutputFile << x << ' ' << y << endl;
    }

    OutputFile.close();
}


coordinates Planet::attraction(const Planet& other) {
    long double other_x = other.x;
    long double other_y = other.y;
    long double distance_x = other_x - x;
    long double distance_y = other_y - y;
    long double distance = std::sqrt(distance_x * distance_x + distance_y * distance_y);

    if (other.sun) {
        distanceToCenter = distance;
    }

    long double force = Planet::G * mass * other.mass / (distance * distance);
    long double theta = std::atan2(distance_y, distance_x);
    long double force_x = std::cos(theta) * force;
    long double force_y = std::sin(theta) * force;
    return {force_x, force_y};
}



void Planet::updatePosition(vector<Planet> &planets) {
    long double total_fx = 0, total_fy = 0;
    for (Planet &planet : planets) {

        // check if planet is current object
        if (this == &planet) {
            continue;
        }

        coordinates attraction_coords = Planet::attraction(planet);
        total_fx += attraction_coords.x;
        total_fy += attraction_coords.y;

    }
    xVel += total_fx / mass * TIME_STEP;
    yVel += total_fy / mass * TIME_STEP;

    x += xVel * TIME_STEP;
    y += yVel * TIME_STEP;

    coordinates position {x, y};
    orbit.push_back(position);
}

