#include <iostream>
#include <algorithm>

int main() {
    int n, k, l, c, d, p, nl, np;
    std::cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int totalToastFromSoda = (k * l) / nl;
    int totalToastFromLime = c * d;
    int totalToastFromSalt = p / np;

    int minToasts = std::min({totalToastFromSoda, totalToastFromLime, totalToastFromSalt});

    int result = minToasts / n; // Рассчитываем количество тостов на каждого друга

    std::cout << result << std::endl;

    return 0;
}
