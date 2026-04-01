
#include "regression.h"
#include <iostream>
#include <fstream>
#include <string>

void DataSet::load(const std::string &filename)
{
    std::ifstream file;
    std::string line;
    DataPoint point;
    file.open(filename);

    std::getline(file, line);

    while (std::getline(file, line))
    {
        int commaIndex = line.find(',');
        std::string hoursStr = line.substr(0, commaIndex);
        std::string gradesStr = line.substr(commaIndex + 1);

        point.hours = std::stof(hoursStr);
        point.grade = std::stof(gradesStr);

        points.push_back(point);
    }
}