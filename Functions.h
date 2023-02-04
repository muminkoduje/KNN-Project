#pragma once
#include <iostream>
#include"Structures.h"

using namespace std;

namespace Help {
	/**
	@brief Signals to the user that there is not enough flags
	*/
	void noflags();
	/**
	@brief Signals to the user that there is an error with given flags
	*/
	void flagshelp();
	/**
	* @brief Writes a short program description and using instrcution
	*
	*/
	void programInfo();
}
void loadPoints(const string& fileName, vector<Point>& points, bool hasLabel);
string kNN(const vector<double>& testPoint, const vector<Point>& trainPoints, int k);
double CalcDistance(const vector<double>& point1, const vector<double>& point2);