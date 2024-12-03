#include <iostream>
#include <cmath>

// Ham kich hoat
double sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x));
}

// dao ham cua sigmoid
double sigmoidDerivative(double x) {
    return sigmoid(x) * (1 - sigmoid(x));
}

int main() {
    // Trong so va bias 
    double w1 = 0.5, w2 = 0.6, b1 = -0.7;
    double w3 = 0.7, w4 = 0.8, b2 = -0.8;
    double w5 = 1.0, w6 = 1.0, b3 = 1.0;

    
    double tocDoHoc = 0.2;

    // XOR input
    double x1 = 0.0, x2 = 1.0;

    
    double y = 1.0;

    
    int thuTuBang = 1000;

    for (int epoch = 1; epoch <= thuTuBang; ++epoch) {
        
        double h1 = sigmoid(w1 * x1 + w2 * x2 + b1);
        double h2 = sigmoid(w3 * x1 + w4 * x2 + b2);
        double output = sigmoid(w5 * h1 + w6 * h2 + b3);

        // sai so
        double error = 0.5 * (y - output) * (y - output);

        // lan truyen nguoc
        double delta_output = (y - output) * sigmoidDerivative(w5 * h1 + w6 * h2 + b3);
        double delta_h1 = delta_output * w5 * sigmoidDerivative(w1 * x1 + w2 * x2 + b1);
        double delta_h2 = delta_output * w6 * sigmoidDerivative(w3 * x1 + w4 * x2 + b2);

        // cap nhat trong so va bias
        w1 += tocDoHoc * delta_h1 * x1;
        w2 += tocDoHoc * delta_h1 * x2;
        b1 += tocDoHoc * delta_h1;

        w3 += tocDoHoc * delta_h2 * x1;
        w4 += tocDoHoc * delta_h2 * x2;
        b2 += tocDoHoc * delta_h2;

        w5 += tocDoHoc * delta_output * h1;
        w6 += tocDoHoc * delta_output * h2;
        b3 += tocDoHoc * delta_output;

        // Print information for each epoch
        if (epoch % 100 == 0) {
            std::cout << "Bang " << epoch << " | Sai So " << error << std::endl;
            std::cout << "Cap nhat trong so va bias" << std::endl;
            std::cout << "w1: " << w1 << ", w2: " << w2 << ", b1: " << b1 << std::endl;
            std::cout << "w3: " << w3 << ", w4: " << w4 << ", b2: " << b2 << std::endl;
            std::cout << "w5: " << w5 << ", w6: " << w6 << ", b3: " << b3 << std::endl;
            std::cout << "-----------------------------------------" << std::endl;
        }
    }

    return 0;
}