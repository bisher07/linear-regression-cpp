#pragma once
#include <fstream>
#include <vector>
#include <string>

struct DataPoint
{
    double hours = 0;

    double grade = 0;
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

class LinearRegression
{
public:
    LinearRegression(double rate = 0.01) : learningRate(rate), m(0), b(0) {}

    void train();

    double predict(double x);

private:
    double learningRate, m, b;

    DataSet data;
};