#include <iostream>

#include <Planet.cpp>
#include <ttime.cpp>

using namespace std;

const string SAVE_PATH = "coordinates.txt";

const uint32_t EARTH_RADIUS = 6378137; // in meter
const long double EARTH_MASS = 5.9722E24;

const long double SUN_MASS = 1.9891E30;

int main()
{

    Planet Sun(0, 0, 30, SUN_MASS);
    Planet Earth(-1 * Planet::AU, 0, 16, EARTH_MASS);
    Earth.yVel = 29.783 * 1000;
    Sun.sun = true;

    vector<Planet> Planets = {Sun, Earth};

    // clear coordinate file
    ofstream ofs;
    ofs.open(SAVE_PATH, std::ofstream::out | std::ofstream::trunc);
    ofs.close();

    uint64_t currentTime = 0; // current time in seconds

    for (int i = 0; i < 365; i++)
    {
        for (auto &planet : Planets)
        {
            planet.updatePosition(Planets);
            if (!planet.sun)
            {
                planet.save_data(SAVE_PATH, secondsToTimeString(currentTime), true, true);
            }
        }

        currentTime += Planet::TIME_STEP;
    }

    return 0;
}
