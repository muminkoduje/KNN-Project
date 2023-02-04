#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<unordered_map>
#include<algorithm>
#include"Structures.h"
#include "Functions.h"
using namespace std;

namespace Help {
	void noflags() {
		cout << "There is not enough flags for the program execution" << endl;
		exit(0);
	}


	void flagshelp() {
		cout << "There is an error with the given flags" << endl;
		exit(0);

	}

	void programInfo() {
		cout << "Description: \n\t  This is a program for data clustering with the k - nearest neighbours (kNN) algorithm from data points taken from txt files. \n Usage: \n\t -train <input txt with train points> -test <input txt with test points> -out <input name of the output file> -k <input number of nearst neighbours>" << endl;
		exit(0);

	}
}
void loadPoints(const string& fileName, vector<Point>& points, bool hasLabel) {
    ifstream file(fileName);
    string line;
    while (getline(file, line)) {

        if (line.empty() || line[0] == '%') continue; // skip comments and empty lines
        Point point;
        if (hasLabel) {

            point.label = line.substr(0, line.find(" "));
            line = line.substr(line.find(" ") + 1);
           // cout <<"Label Pointa: "<< point.label << endl;

        }
        /*
        while (!line.empty()) {
            size_t pos = line.find(" ");
            if (pos == string::npos) {
                break;
            }

           
            double location = stod(line.substr(0, line.find(" ")));
           
            point.attributes.first = location;
            cout << "Punkt x:   " << point.attributes.first << endl;

            line = line.substr(pos + 1);
            double location2 = stod(line.substr(0, line.find(" ")));
            
            point.attributes.second = location2;
            cout << "Punkt Y:  " << point.attributes.second << endl;
            line = line.substr(pos + 1);
            string faja = line.substr(0, line.find(" "));
            cout << faja << "xxxxxxd" << endl;
            if (line.empty() || line[0] == '%') {
                break;
            }
          

            
        }
        */
        while (!line.empty()) {
            size_t pos = line.find(" ");
            if (pos == string::npos || line.substr(0, line.find(" ")) == "%") {
                break;
            }

            double location = stod(line.substr(0, line.find(" ")));
            point.attributes.first = location;
           // cout << "Punkt x:   " << point.attributes.first << endl;

            line = line.substr(pos + 1);
            pos = line.find(" ");
            if (pos == string::npos || line.substr(0, line.find(" ")) == "%") {
                break;
            }

            double location2 = stod(line.substr(0, line.find(" ")));
            point.attributes.second = location2;
            //cout << "Punkt Y:  " << point.attributes.second << endl;
            line = line.substr(pos + 1);
        }
        points.push_back(point);

    }
}
/* double CalcDistance(const vector<Point>& mathPoint) {
    double distance = 0;
    
    

    for (const auto& math : mathPoint) {
        
        distance += pow(math.attributes.first() - math.attributes.second(), 2);
    }
    return sqrt(distance);
}
/* string kNN(const vector<double>& testPoint, const vector<Point>& trainPoints, int k) {
    vector<DistancePoint> CalcPoints;

    for (const auto& trainPoint : trainPoints) {
        double distance = CalcDistance(testPoint, trainPoints.attributes);
        CalcPoints.push_back({ trainPoint.attributes, distance });
    }
    sort(distancePoints.begin(), distancePoints.end(),
        [](const Point& dp1, const Point& dp2) {
            return dp1.distance < dp2.distance;
        });
    unordered_map < string, int> labelCount;
    for (int i = 0; i < k; i++) {
        string label;
        for (auto& trainPoint : trainPoints) {
            if (trainPoint.attributes == distancePoints[i].attributes)
                label = trainPoint.label;
        }
        labelCount[label]++;
    }
    string classifiedLabel;
    int maxCount = 0;
    for (const auto& label : labelCount) {
        if (label.second > maxCount) {
            classifiedLabel = label.first;
            maxCount = label.second;
        }
    }
    return classifiedLabel;
} */