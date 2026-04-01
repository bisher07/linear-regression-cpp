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

    int size() const
    {
        return points.size();
    }

    DataPoint getPoint(int index) const
    {
        return points[index];
    }

private:
    std::vector<DataPoint> points;
};

class LinearRegression
{
public:
    LinearRegression(double rate = 0.01) : learningRate(rate), m(0), b(0) {}

    void train(const DataSet &data);

    double predict(double x);

private:
    double learningRate, m, b;
};