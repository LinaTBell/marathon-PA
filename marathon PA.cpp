#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

const int NUM_RUNNERS = 5;
const int NUM_DAYS = 7;

std::string runners[NUM_RUNNERS];
int miles[NUM_RUNNERS][NUM_DAYS];

void readDataFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file." << std::endl;
        exit(1);
    }

    for (int i = 0; i < NUM_RUNNERS; ++i) {
        file >> runners[i];
        for (int j = 0; j < NUM_DAYS; ++j) {
            file >> miles[i][j];
        }
    }

    file.close();
}

void calculateTotalsAndAverage(int totals[], double averages[]) {
    for (int i = 0; i < NUM_RUNNERS; ++i) {
        int totalMiles = 0;
        for (int j = 0; j < NUM_DAYS; ++j) {
            totalMiles += miles[i][j];
        }
        totals[i] = totalMiles;
        averages[i] = static_cast<double>(totalMiles) / NUM_DAYS;
    }
}

void outputResults(const int totals[], const double averages[]) {
    std::cout << std::setw(15) << "Runner";
    for (int i = 1; i <= NUM_DAYS; ++i) {
        std::cout << std::setw(10) << "Day " << i;
    }
    std::cout << std::setw(10) << "Total" << std::setw(10) << "Average" << std::endl;

    for (int i = 0; i < NUM_RUNNERS; ++i) {
        std::cout << std::setw(15) << runners[i];
        for (int j = 0; j < NUM_DAYS; ++j) {
            std::cout << std::setw(10) << miles[i][j];
        }
        std::cout << std::setw(10) << totals[i] << std::setw(10) << std::fixed << std::setprecision(2) << averages[i] << std::endl;
    }
}

int main() {
    readDataFromFile("runners.txt");

    int totals[NUM_RUNNERS];
    double averages[NUM_RUNNERS];

    calculateTotalsAndAverage(totals, averages);

    outputResults(totals, averages);

    return 0;
}
