//
// Created by egor on 29.10.2023.
//
#include <iostream>

int main()
{
    int n(0), counter(0);
    std::cin >> n;

    while(n > 0){

        if(n&1){
            counter += n & 1;

        }

        n >>= 1;
    }

    std::cout << counter;
}
