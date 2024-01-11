#include <iostream>
#include <cctype>

int main() {
    std::string s;
    std::cin >> s;

    int  upperCount = 0, lowerCount = 0;

    for (char c : s) {
        if (std::isupper(c)) {
            upperCount++;
        } else {
            lowerCount++;
        }
    }

    if (upperCount > lowerCount) {
        for (char& c : s) {
            c = std::toupper(c);
        }
    } else {
        for (char& c : s) {
            c = std::tolower(c);
        }
    }

    std::cout << s;

    return 0;
}
