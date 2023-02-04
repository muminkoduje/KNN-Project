#pragma once
#include <iostream>

using namespace std;

struct Point {
	string label;
	pair<double, double> attributes;
};
struct DistancePoint {
	vector<double> attributes;
	double distance;
};