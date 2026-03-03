#include <bits/stdc++.h>
using namespace std;

int main() {

    // Feature Matrix (Bias term included)
    vector<vector<double>> X = {
        {1, 0, 0},
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 1}
    };

    // Target values
    vector<double> Y = {0, 0, 0, 1};

    int n = X.size();        // number of samples
    int m = X[0].size();     // number of features

    vector<double> B(m);     // parameters

    cout << "Enter initial parameter values:\n";
    for (int i = 0; i < m; i++)
        cin >> B[i];

    double lr;
    cout << "Enter learning rate: ";
    cin >> lr;

    double prevError = 1e18;
    int iteration = 0;
    const int maxIterations = 10000;

    while (iteration < maxIterations) {

        vector<double> gradient(m, 0);
        double error = 0;

        // Compute predictions and gradient
        for (int i = 0; i < n; i++) {

            double prediction = 0;
            for (int j = 0; j < m; j++)
                prediction += X[i][j] * B[j];

            double diff = prediction - Y[i];

            error += diff * diff;  

            for (int j = 0; j < m; j++)
                gradient[j] += diff * X[i][j];
        }

        cout << "Iteration " << iteration 
             << " | Error: " << error << endl;

        // Check convergence
        if (abs(prevError - error) < 1e-6) {
            cout << "\nConvergent Case\n";
            break;
        }

        // Check divergence
        if (error > prevError) {
            cout << "\nDivergent Case (Learning rate too high)\n";
            break;
        }

        prevError = error;

        // Update parameters
        for (int j = 0; j < m; j++)
            B[j] -= lr * gradient[j];

        iteration++;
    }

    cout << "\nFinal Parameters:\n";
    for (int i = 0; i < m; i++)
        cout << "b" << i << " : " << B[i] << endl;

    return 0;
}