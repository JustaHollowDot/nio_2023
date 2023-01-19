#include <iostream>
#include <vector>
#include <algorithm>

bool timeline_sorter(int const& lhs, int const& rhs) {
    return lhs < rhs;
}

int main1() {
    int inhabitants, lightning_strikes;
    std::cin >> inhabitants >> lightning_strikes;

    std::vector<int> timeline_additions (inhabitants, 0);
    std::vector<int> timeline_subtractions (inhabitants, 0);

    for (int i = 0; i < lightning_strikes; ++i) {
        int start, end;
        std::cin >> start >> end;

        timeline_additions[start] += 1;
        timeline_subtractions[end] += 1;
    }

//    for (int i = 0; i < timeline_additions.size(); ++i) {
//        std::cout << timeline_additions[i] << " " << timeline_subtractions[i] << std::endl;
//    }

    std::vector<int> houses (inhabitants, 0);

    int max_test = 0;
    int strikes = 0;

    for (int i = 0; i < timeline_additions.size(); ++i) {
        int addition = timeline_additions[i];
        int subtraction = timeline_subtractions[i];

//        std::cout << "addition: " << addition << " subtraction: " << subtraction << std::endl;

        strikes += addition;

//        std::cout << "strikes: " << strikes << std::endl;

        if (strikes % 2 == 0) {
            max_test++;
        }

        strikes -= subtraction;

    }

    std::cout << max_test << std::endl;
    return 0;
}