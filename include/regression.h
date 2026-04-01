#pragma once
#include <fstream>
#include <vector>
#include <string>

struct DataPoint
{
    float hours = 0;

    float grade = 0;
};

class DataSet
{
public:
    void load(const std::string &filename);

    int size()
    {
        return points.size();
    }

private:
    std::vector<DataPoint> points;
};