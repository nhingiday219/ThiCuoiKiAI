#include <iostream>
#include <vector>

class AND {
private:
    static constexpr double tocdohoc = 0.1;
    static constexpr int bangktr = 15;
    static constexpr double bias = -0.3;

public:
    static void run() {
        double w1 = 0.4;
        double w2 = 0.2;

    
        int X[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        int Y[4] = {0, 0, 0, 1};

        for (int sobang = 0; sobang < bangktr; sobang++) {
            for (int i = 0; i < 4; i++) {
                int x1 = X[i][0];
                int x2 = X[i][1];
                int y = Y[i];

                double z = x1 * w1 + x2 * w2 + bias;
                double giatriktr = (z > 0) ? 1 : 0;

                double saiso = y - giatriktr;

                w1 += tocdohoc * saiso * x1;
                w2 += tocdohoc * saiso * x2;

                std::cout << "bangktr: " << sobang << " Input: " << x1 
                          << " " << x2 << " Output: " << giatriktr 
                          << " capnhat w1: " << w1 << " capnhat w2: " << w2 << std::endl;
            }
        }

        
        std::cout << "ket qua cuoi cung - w1: " << w1 << ", w2: " << w2 << std::endl;
    }
};

int main() {
    AND::run();
    return 0;
}