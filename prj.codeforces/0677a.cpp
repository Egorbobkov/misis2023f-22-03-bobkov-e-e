#include <iostream>

int main() {
    int n, h;
    std::cin >> n >> h;

    int width = 0;
    for (int i = 0; i < n; ++i) {
        int ai;
        std::cin >> ai;

        width += (ai > h) ? 2 : 1;
    }

    std::cout << width;

    return 0;
}
