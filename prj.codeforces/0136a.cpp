#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> gifts(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> gifts[i];
    }

    std::vector<int> result(n);

    for (int i = 0; i < n; ++i){
        result[gifts[i] - 1] = i + 1;
    }

    for (int i = 0; i < n; ++i) {
        std::cout << result[i] << " ";
    }

    return 0;
}

