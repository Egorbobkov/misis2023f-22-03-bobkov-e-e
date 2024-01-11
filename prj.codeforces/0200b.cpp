#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
//
    std::vector<int> percentages(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> percentages[i];
    }

    int totalPercentage = 0;
    for (int i = 0; i < n; ++i) {
        totalPercentage += percentages[i];
    }

    double result = static_cast<double>(totalPercentage) / n;

    std::cout << result << std::endl;

    return 0;
}
