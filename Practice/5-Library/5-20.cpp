#include <iostream>
#include <random>
#include <vector>
#include <iomanip>
#include <algorithm>

int main() {
    const int num_samples = 1000000;
    const int num_bins = 20;
    const int max_line_length = 80;

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_real_distribution<> dis(-10, 10);
    double mean = dis(gen);

    std::normal_distribution<> d(mean, 1);

    std::vector<int> histogram(num_bins, 0);
    for (int n = 0; n < num_samples; ++n) {
        double number = d(gen);
        if (number >= -10 && number <= 10) {
            int index = (number + 10) / 20 * num_bins;
            ++histogram[index];
        }
    }

    int max_bin_count = *std::max_element(histogram.begin(), histogram.end());
    double scale = static_cast<double>(max_line_length - 10) / max_bin_count;

    for (int i = 0; i < num_bins; ++i) {
        double bin_center = (static_cast<double>(i) / num_bins) * 20 - 10;
        std::cout << std::fixed << std::setprecision(2) << std::setw(5) << bin_center << ' ';
        int num_asterisks = histogram[i] * scale;
        for (int j = 0; j < num_asterisks; ++j) {
            std::cout << '*';
        }
        std::cout << '\n';
    }

    return 0;
}