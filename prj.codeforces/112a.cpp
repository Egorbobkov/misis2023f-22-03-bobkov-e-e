#include <iostream>
#include <algorithm>

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    std::transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

    int result = s1.compare(s2);

    std::cout << result;

    return 0;
}
