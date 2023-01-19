#include <iostream>
#include <vector>
#include <queue>

int main2() {
    int days;
    std::cin >> days;
    // std::cout << "days: " << days << std::endl;

    std::vector<int> queue_bergen (7, -1);
    std::vector<int> queue_oslo (7, -1);

    std::vector<int> bergen_costs;
    std::vector<int> oslo_costs;

    for (int i = 0; i < days; ++i) {
        int bergen_cost, oslo_cost;
        std::cin >> bergen_cost >> oslo_cost;

        bergen_costs.push_back(bergen_cost);
        oslo_costs.push_back(oslo_cost);
    }

    for (int i = 0; i < days; ++i) {
        // std::cout << "bergen: " << bergen_costs[i] << " oslo: " << oslo_costs[i] << std::endl;
    }

    queue_bergen[3] = 0;
    queue_oslo[2] = 0;

    int max = 0;

    for (int i = 1; i < days; ++i) {
        // std::cout << "day: " << i << std::endl;
        // std::cout << "cost bergen: " << bergen_costs[i] << " cost oslo: " << oslo_costs[i] << std::endl;

        for (int j = 0; j < 6; ++j) {
            queue_bergen[j] = queue_bergen[j + 1];
            queue_oslo[j] = queue_oslo[j + 1];
        }

        queue_bergen[6] = -1;
        queue_oslo[6] = -1;

        if (queue_bergen[0] != -1) {
            int current = queue_bergen[0];

            queue_bergen[1] = std::max(queue_bergen[1], current);

            current += bergen_costs[i];

            max = std::max(max, current);

            queue_bergen[6] = std::max(queue_bergen[6], current);
            queue_oslo[5] = std::max(queue_oslo[5], current);
        }

        if (queue_oslo[0] != -1) {
            int current = queue_oslo[0];

            queue_oslo[1] = std::max(queue_oslo[1], current);

            current += oslo_costs[i];

            max = std::max(max, current);

            queue_oslo[4] = std::max(queue_oslo[4], current);
            queue_bergen[5] = std::max(queue_bergen[5], current);
        }



        // std::cout << std::endl;

        for (int i = 0; i < 6; ++i) {
            // std::cout << "bergen: " << queue_bergen[i] << " oslo: " << queue_oslo[i] << std::endl;
        }

        // std::cout << std::endl;
    }

     std::cout << max << std::endl;
    return 0;
}


//struct State {
//    long long int cost;
//    int current_place;
//    int current_time;
//
//    State(long long int cost, int current_place, int current_time) {
//        this->cost = cost;
//        this->current_place = current_place;
//        this->current_time = current_time;
//    }
//};
//
//struct StateComparator {
//    bool operator()(State const& lhs, State const& rhs) {
//        return lhs.current_time > rhs.current_time;
//    }
//};
//
//int main() {
//    int days;
//    std::cin >> days;
//    // // std::cout << "days: " << days << std::endl;
//
//    std::vector<int> price_oslo (days, 0);
//    std::vector<int> price_bergen (days, 0);
//
//    for (int i = 0; i < days; ++i) {
//        std::cin >> price_bergen[i] >> price_oslo[i];
//    }
//
//    for (int i = 0; i < days; ++i) {
//        // // std::cout << "day: " << i << " -> price_oslo: " << price_oslo[i] << " price_bergen: " << price_bergen[i] << std::endl;
//    }
//
//
//    long long int max_cost = 0;
//
//    std::priority_queue<State, std::vector<State>, StateComparator> queue;
//    queue.push(State(0, 0, 2));
//    queue.push(State(0, 1, 3));
//
//    while (!queue.empty()) {
//        State current_state = queue.top();
//        queue.pop();
//
//        // // std::cout << "current_state.cost: " << current_state.cost << " current_state.current_place: " << current_state.current_place << " current_state.current_time: " << current_state.current_time << std::endl;
//
//        max_cost = std::max(max_cost, current_state.cost);
//
//        if (current_state.current_place == 0) {
//            if (current_state.current_time + 1 < days) {
//                queue.push(
//                        State(
//                                current_state.cost,
//                                0,
//                                current_state.current_time + 1
//                                )
//                        );
//            } else {
//                max_cost = std::max(max_cost, current_state.cost + price_oslo[current_state.current_time]);
//            }
//
//            if (current_state.current_time + 4 < days) {
//                queue.push(
//                        State(
//                                current_state.cost + price_oslo[current_state.current_time],
//                                1,
//                                current_state.current_time + 4
//                                )
//                        );
//            } else {
//                max_cost = std::max(max_cost, current_state.cost + price_oslo[current_state.current_time]);
//            }
//
//            if (current_state.current_time + 5 < days) {
//                queue.push(
//                        State(
//                                current_state.cost + price_oslo[current_state.current_time],
//                                1,
//                                current_state.current_time + 5
//                                )
//                        );
//            } else {
//                max_cost = std::max(max_cost, current_state.cost + price_oslo[current_state.current_time]);
//            }
//        } else {
//            if (current_state.current_time + 1 < days) {
//                queue.push(
//                        State(
//                                current_state.cost,
//                                1,
//                                current_state.current_time + 1
//                                )
//                        );
//            } else {
//                max_cost = std::max(max_cost, current_state.cost + price_bergen[current_state.current_time]);
//            }
//
//            if (current_state.current_time + 5 < days) {
//                queue.push(
//                        State(
//                                current_state.cost + price_bergen[current_state.current_time],
//                                0,
//                                current_state.current_time + 5
//                                )
//                        );
//            } else {
//                max_cost = std::max(max_cost, current_state.cost + price_bergen[current_state.current_time]);
//            }
//
//            if (current_state.current_time + 6 < days) {
//                queue.push(
//                        State(
//                                current_state.cost + price_bergen[current_state.current_time],
//                                0,
//                                current_state.current_time + 6
//                                )
//                        );
//            } else {
//                max_cost = std::max(max_cost, current_state.cost + price_bergen[current_state.current_time]);
//            }
//        }
//    }
//
//    // // std::cout << "max_cost: ";
//     // std::cout << max_cost << std::endl;
//
//
//
//
//
//    return 0;
//}