#include <bits/stdc++.h>

int main6() {
    int A, B;

    std::cin >> A >> B;

    std::string test;
    std::cin >> test;

    auto kake = std::unique(test.begin(), test.end());

    test.erase(kake, test.end());

//    std::cout << test << std::endl;
    std::cout << test.size() << std::endl;


    return 0;
}