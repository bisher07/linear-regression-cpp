#include "regression.h"
#include <iostream>
using namespace std;
int main()
{
    DataSet set1;

    set1.load("data.csv");

    cout << set1.size();
}