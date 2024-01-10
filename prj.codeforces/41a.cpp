#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string s, t;
    std::cin >> s >> t;

    // Используем функцию reverse для обращения строки s
    std::reverse(s.begin(), s.end());

    // Сравниваем обращенную строку s с t
    if (s == t) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
