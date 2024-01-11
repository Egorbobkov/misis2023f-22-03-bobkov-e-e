#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    int x = 0; // Начальное значение переменной x

    for (int i = 0; i < n; ++i) {
        std::string statement;
        std::cin >> statement;

        if (statement.find("++") != std::string::npos) {
            ++x;
        } else {
            --x;
        }
    }

    std::cout << x << std::endl;

    return 0;
}
