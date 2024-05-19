#include <iostream>
#include <iomanip>

int main() {
    const double pound_to_kg = 0.453592;

    std::cout << std::fixed << std::setprecision(2);

    std::cout << std::setw(10) << "Pounds" << std::setw(15) << "Kilograms" << '\n';
    for (double pounds = 0; pounds <= 200; pounds += 10) {
        double kilograms = pounds * pound_to_kg;
        std::cout << std::setw(10) << pounds << std::setw(15) << kilograms << '\n';
    }

    return 0;
}