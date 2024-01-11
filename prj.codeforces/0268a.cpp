#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> teams(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> teams[i].first >> teams[i].second;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && teams[i].first == teams[j].second) {
                // Команда i играет на своем стадионе, а цвет ее домашней формы совпадает с цветом формы команды j
                count++;
            }
        }
    }

    std::cout << count;

    return 0;
}

