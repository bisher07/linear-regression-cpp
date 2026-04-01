# Linear Regression from Scratch in C++

A simple linear regression model implemented from scratch in C++ using gradient descent.
Given a dataset of study hours and grades, the model learns the best-fit line and 
predicts grades for new inputs.

## How it works

- Loads training data from a CSV file
- Trains using gradient descent, printing the loss every 100 iterations
- Outputs the final slope, intercept, and predictions for new inputs

## Build

Clone the repository:
```
git clone https://github.com/your-username/linear-regression-cpp
```

Build with g++:
```
g++ src/main.cpp src/regression.cpp -Iinclude -o bin/main.exe
```

## Run
```
./bin/main.exe
```

## Output
```
Iteration 0:    Loss: 312.4000
Iteration 100:  Loss: 184.2300
...
Iteration 5000:  Loss: 2.1010

Slope (m):     4.8200
Intercept (b): 47.3100


Prediction for x = 3.5   64.0815
Prediction for x = 6     79.3573
Prediction for x = 11    109.909
```
