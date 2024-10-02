#pragma once

#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <stdexcept>
#include <chrono>
#include "Percolation.hpp"

class PercolationStats {
private:
    std::vector<double> thresholds;
    int n;
    int trials;

public:
    // perform independent trials on an n-by-n grid
    PercolationStats(int n, int trials) : n(n), trials(trials) {
        if (n <= 0 || trials <= 0) {
            throw std::invalid_argument("n and trials must be greater than 0");
        }

        thresholds.resize(trials);
        std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<int> dis(0, n - 1);

        for (int t = 0; t < trials; ++t) {
            Percolation perc(n);
            int openSites = 0;

            while (!perc.percolates()) {
                int row = dis(gen);
                int col = dis(gen);
                if (!perc.isOpen(row, col)) {
                    perc.open(row, col);
                    ++openSites;
                }
            }

            thresholds[t] = static_cast<double>(openSites) / (n * n);
        }
    }

    // sample mean of percolation threshold
    double mean() {
        double sum = 0.0;
        for (double threshold : thresholds) {
            sum += threshold;
        }
        return sum / trials;
    }

    // sample standard deviation of percolation threshold
    double stddev() {
        double m = mean();
        double sum = 0.0;
        for (double threshold : thresholds) {
            sum += (threshold - m) * (threshold - m);
        }
        return std::sqrt(sum / (trials - 1));
    }

    // low endpoint of 95% confidence interval
    double confidenceLow() {
        double m = mean();
        double s = stddev();
        return m - (1.96 * s / std::sqrt(trials));
    }

    // high endpoint of 95% confidence interval
    double confidenceHigh() {
        double m = mean();
        double s = stddev();
        return m + (1.96 * s / std::sqrt(trials));
    }

    // test client
    static void test(int n, int trials) {
        time_t start = clock();
        PercolationStats stats(n, trials);
        time_t end = clock();
        double elapsed = static_cast<double>(end - start) / static_cast<double>(CLOCKS_PER_SEC);

        std::cout << "mean() = " << stats.mean() << std::endl;
        std::cout << "stddev() = " << stats.stddev() << std::endl;
        std::cout << "confidenceLow() = " << stats.confidenceLow() << std::endl;
        std::cout << "confidenceHigh() = " << stats.confidenceHigh() << std::endl;
        std::cout << "elapsed time = " << elapsed << std::endl;
    }
};
