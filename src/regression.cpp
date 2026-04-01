#include "regression.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

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

        point.hours = std::stod(hoursStr);
        point.grade = std::stod(gradesStr);

        points.push_back(point);
    }
}

void LinearRegression::train(const DataSet &data)
{
    double gradient_m, gradient_b, loss, predicted;

    for (int i = 0; i < 1000; i++)
    {
        loss = 0;
        gradient_m = 0;
        gradient_b = 0;

        for (int point = 0; point < data.size(); point++)
        {
            predicted = m * data.getPoint(point).hours + b;
            gradient_m += (predicted - data.getPoint(point).grade) * data.getPoint(point).hours;
            gradient_b += (predicted - data.getPoint(point).grade);
            loss += pow((predicted - data.getPoint(point).grade), 2);
        }

        gradient_m /= data.size();
        gradient_b /= data.size();
        loss /= data.size();

        m -= (learningRate * gradient_m);
        b -= (learningRate * gradient_b);

        if (i % 100 == 0)
        {
            std::cout << "Iteration " << i << ":\t" << "Loss: " << loss << std::endl;
        }
    }

    std::cout << "Iteration 1000:\t" << "Loss: " << loss << std::endl;
}

double LinearRegression::predict(double x)
{
    return m * x + b;
}