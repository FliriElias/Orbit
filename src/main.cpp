

#include <Planet.cpp>


#include <iostream>


using namespace std;

const uint32_t EARTH_RADIUS = 6378137; // in meter
const uint64_t EARTH_MASS = 5.9722E24; 



int main()
{	

	Planet Earth(0, 0, 30, 1000);
	Earth.draw();
	vector<Planet> Planets = { Earth };

	cout << Earth.mass << endl;
	return 0;
}
