#include <iostream>

int main() {
    int n;
    std::cin >> n;

    bool isHard = false;
    for (int i = 0; i < n; ++i) {
        int answer;
        std::cin >> answer;

        if (answer == 1) {
            isHard = true;
            break;
        }
    }

    if (isHard) {
        std::cout << "HARD";
    } else {
        std::cout << "EASY";
    }

    return 0;
}
