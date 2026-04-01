#include "regression.h"
#include <iostream>
using namespace std;
int main()
{
    LinearRegression model1;
    DataSet set1;
    set1.load("data.csv");

    model1.train(set1);

    cout << "\n\n";
    cout << "Prediction for x = 3.5\t" << model1.predict(3.5) << endl;
    cout << "Prediction for x = 6\t" << model1.predict(6) << endl;
    cout << "Prediction for x = 11\t" << model1.predict(11) << endl;
}