#include<iostream>
#include<string>
#include<vector>
#include"Functions.h"
#include"Structures.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 9) Help::noflags();
    if (argc == 0) Help::programInfo();
	string TestData, TrainData, Output;
	int k=1;
    for (int i = 1; i < argc; i++) {
        string arg = argv[i];
        if (arg == "-train") {
            TrainData = argv[i + 1];
            i++;
        }
        else if (arg == "-test") {
            TestData = argv[i + 1];
            i++;
        }
        else if (arg == "-out") {
            Output = argv[i + 1];
            i++;
        }
        else if (arg == "-k") {
            k = stoi(argv[i + 1]);
            i++;
        }
    }
   // if (TrainData="" ||  TestData= "" || k="" || Output="")  Help::flagshelp(); //
    vector<Point>TrainPoints;
    vector<Point>TestPoints;
    loadPoints(TrainData,TrainPoints, 1);
    for (const auto& point : TrainPoints) {
        std::cout << "Labelek: " << point.label << std::endl;
        std::cout << "Attribute 1: " << point.attributes.first << std::endl;
        std::cout << "Attribute 2: " << point.attributes.second << std::endl;
    }
    loadPoints(TestData,TestPoints, 0);
    cout << endl << endl << endl;
    for (const auto& point : TestPoints) {
        
        std::cout << "Attribute 1: " << point.attributes.first << std::endl;
        std::cout << "Attribute 2: " << point.attributes.second << std::endl;
    }
  //  CalcDistance(TrainPoints.attributes);

    return 0;
}