#include <iostream>
#include <string>

int main() {
    std::string word;
    std::cin >> word;

    word[0] = toupper(word[0]);
// вывод
    std::cout << word;

    return 0;
}
