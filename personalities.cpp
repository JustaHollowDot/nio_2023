#include <bits/stdc++.h>


//int main() {
//    std::ios_base::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//
//    int N, M;
//    std::cin >> N >> M;
//
//    std::string employees;
//    std::cin >> employees;
//
//    std::vector<bool> is_approved(M, false);
//
//    for (int i = 0; i < M; ++i) {
//        int start, end;
//        std::cin >> start >> end;
//
//
//    }
//}




//struct State {
//    int index;
//    int groups_amount;
//    int current_group;
//
//    State(int index, int groups_amount, int current_group) {
//        this->index = index;
//        this->groups_amount = groups_amount;
//        this->current_group = current_group;
//
//    }
//};
//
//bool operator<(const State & a, const State & b) {
//    return a.groups_amount > b.groups_amount;
//}
//
//
//struct Employee {
//    char id;
//    std::vector<char> incompatible_leaders;
//    std::vector<char> compatible_leaders;
//
//    Employee(char id) {
//        this->id = id;
//    }
//
//    void add_incompatible_leader(char leader_id) {
//        incompatible_leaders.push_back(leader_id);
//    }
//
//    void add_compatible_leader(char leader_id) {
//        compatible_leaders.push_back(leader_id);
//    }
//};
//
//std::vector<char> get_compatible_leaders(std::string employees, std::map<char, Employee> & employees_map, std::set<char> & employees_set) {
//    std::vector<char> compatible_leaders;
//    std::copy(employees_set.begin(), employees_set.end(), std::back_inserter(compatible_leaders));
//
//    for (auto employee : employees) {
//        std::vector<char> new_compatible_leaders = {};
//
//        std::set_difference(
//                compatible_leaders.begin(), compatible_leaders.end(),
//                employees_map.at(employee).incompatible_leaders.begin(), employees_map.at(employee).incompatible_leaders.end(),
//                std::back_inserter(new_compatible_leaders)
//                );
//
//        compatible_leaders = new_compatible_leaders;
//    }
//
//    return compatible_leaders;
//}
//
//
//int main() {
//    std::ios_base::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//
//    int employees_amount, incompatible_pairs;
//    std::cin >> employees_amount >> incompatible_pairs;
//
//    std::string employees_string;
//    std::cin >> employees_string;
//
//    std::set<char> employee_types;
//    std::map<char, Employee> employees;
//
//    // std::cout << "employees_amount: " << employees_amount << std::endl;
//
//    for (int i = 0; i < employees_amount; ++i) {
//        int was_not_in_list = employee_types.insert(employees_string[i]).second;
//
//        if (was_not_in_list) {
//            employees.emplace(employees_string[i], Employee(employees_string[i]));
//        }
//    }
//
//    // std::cout << employee_types.size() << std::endl;
//
//    for (int i = 0; i < incompatible_pairs; ++i) {
//        char first_employee, second_employee;
//        std::cin >> first_employee >> second_employee;
//
//        if (employee_types.find(first_employee) != employee_types.end() && employee_types.find(second_employee) != employee_types.end()) {
//            employees.at(first_employee).add_incompatible_leader(second_employee);
//        }
//
//    }
//
//    for (auto & employee : employees) {
//        for (auto & employee_type : employee_types) {
//            if (employee.first != employee_type) {
//                employee.second.add_compatible_leader(employee_type);
//            }
//        }
//    }
//
//    for (auto & employee : employees) {
//        // std::cout << "employee " << employee.first << ": " << std::endl;
//
//        for (auto & incompatible_leader : employee.second.incompatible_leaders) {
//            // std::cout << incompatible_leader << " ";
//        }
//
//        // std::cout << std::endl;
//
//        for (auto & compatible_leader : employee.second.compatible_leaders) {
//            // std::cout << compatible_leader << " ";
//        }
//
//        // std::cout << std::endl;
//    }
//
//    std::vector<std::vector<int>> group_start_end(employees_amount);
//    std::vector<std::vector<int>> group_start (employees_amount);
//    std::vector<std::vector<int>> group_end (employees_amount);
//
//
//    int i = 0;
//    int employees_left = employees_amount;
//    std::string current_group = "";
//    std::vector<char> compatible_leaders;
//
//    current_group += employees_string[i];
//    employees_left--;
//    compatible_leaders = employees.at(employees_string[i]).compatible_leaders;
//
//    int group_number = 0;
//
//    group_start_end[i].push_back(group_number);
//    group_start[i].push_back(0);
//    i++;
//
//
//
//    while (employees_left) {
//        // std::cout << "employees_left: " << employees_left << std::endl;
//        // std::cout << "current_group: " << current_group << std::endl;
//
//
//        if (!compatible_leaders.empty()) {
//            Employee & current_employee = employees.at(employees_string[i]);
//
//            compatible_leaders = get_compatible_leaders(current_group + current_employee.id, employees, employee_types);
//
//
//
//            // std::cout << "compatible_leaders: " << std::endl;
//
//            for (auto & leader : compatible_leaders) {
//                // std::cout << leader << " ";
//            }
//
//            // std::cout << std::endl;
//
//            if (compatible_leaders.empty()) {
//                current_group += employees_string[i];
//                employees_left--;
//                i++;
//
//                group_start_end[i - 2].push_back(group_number);
//                group_end[i - 2].push_back(group_number);
//                group_number++;
//
//                // std::cout << "test 1" << std::endl;
//
//                compatible_leaders = get_compatible_leaders(current_group, employees, employee_types);
//
//            } else {
//                // std::cout << "test 2" << std::endl;
//
//                current_group += employees_string[i];
//                employees_left--;
//                i++;
//            }
//        } else {
//            // std::cout << "current_group_test: " << current_group << std::endl;
//            current_group.erase(0, 1);
//            // std::cout << "current_group_test_2: " << current_group << std::endl;
//
//            compatible_leaders = get_compatible_leaders(current_group, employees, employee_types);
//
//            if (!compatible_leaders.empty()) {
//                group_start_end[i - 2].push_back(group_number);
//                group_start[i - 2].push_back(group_number);
//
//                // std::cout << "test 3" << std::endl;
//            }
//        }
//
//    }
//
//    group_start_end[i - 1].push_back(group_number);
//    group_end[i - 1].push_back(group_number);
//
////    // std::cout << "group_start_end: " << std::endl;
////
////    for (auto & group : group_start_end) {
////        // std::cout << "group: " << std::endl;
////        for (auto & group_number_test : group) {
////            // std::cout << group_number_test << " ";
////        }
////
////        // std::cout << std::endl;
////    }
//
//    // std::cout << "group_start: " << std::endl;
//
//    for (auto & group : group_start) {
//        // std::cout << "group: " << std::endl;
//        for (auto & group_number_test : group) {
//            // std::cout << group_number_test << " ";
//        }
//
//        // std::cout << std::endl;
//    }
//
//    // std::cout << "group_end: " << std::endl;
//
//    for (auto & group : group_end) {
//        // std::cout << "group: " << std::endl;
//        for (auto & group_number_test : group) {
//            // std::cout << group_number_test << " ";
//        }
//
//        // std::cout << std::endl;
//    }
//
//    // std::cout << std::endl;
//
//
//    std::priority_queue<State> final_group_amounts;
//
//    final_group_amounts.push(State(0, 0, 0));
//
//    while (!final_group_amounts.empty()) {
//        State current_state = final_group_amounts.top();
//        final_group_amounts.pop();
//
//        if (current_state.index > employees_amount - 2) {
//             // std::cout << current_state.groups_amount - 1 << std::endl;
//            return 0;
//        }
//
//        if (!group_start[current_state.index].empty()) {
//
//            for (int j = 0; j < group_start[current_state.index].size(); ++j) {
//                // std::cout << "current_state.index: " << current_state.index << std::endl;
//                // std::cout << "current_state.groups_amount: " << current_state.groups_amount << std::endl;
//
//                if (current_state.index + 1 < employees_amount) {
//                    // std::cout << "group_start[current_state.index][j]: " << group_start[current_state.index][j] << std::endl;
//
//                    final_group_amounts.push(State(current_state.index + 1, current_state.groups_amount + 1, group_start[current_state.index][j]));
//                }
//
//
//            }
//        }
//
//        bool found_current_group = false;
//
//        if (!group_end[current_state.index].empty()) {
//
//            for (int j = 0; j < group_end[current_state.index].size(); ++j) {
//
//                if (group_end[current_state.index][j] == current_state.current_group) {
//                    found_current_group = true;
//
//                    if (!group_start[current_state.index + 1].empty()) {
//
//                        for (int k = 0; k < group_start[current_state.index + 1].size(); k++) {
//                            final_group_amounts.push(State(current_state.index + 1, current_state.groups_amount + 1, group_start[current_state.index][k]));
//                        }
//
//                    }
//
//                    break;
//
//                }
//
//            }
//
//        }
//
//        if (!found_current_group) {
//            final_group_amounts.push(State(current_state.index + 1, current_state.groups_amount, current_state.current_group));
//        }
//
//        // std::cout << std::endl;
//
//    }
//
//
//
//
//
//    return 0;
//}


//    std::queue<State> states;
//    states.push(State(1, 0, 0));
//
//    while (!states.empty()) {
//        State current_state = states.front();
//        states.pop();
//
//        int current_index = current_state.index;
//        int current_group_number = current_state.current_group;
//
//        if (current_index == employees_amount) {
//            // std::cout << current_state.groups_amount + 1 << std::endl;
//        } else {
//            if (!group_start[current_index].empty()) {
//                for (auto & group_number : group_start[current_index]) {
//                    if (group_number > current_group_number) {
//                        states.push(State(current_state.groups_amount + 1, current_index + 1, group_number));
//                    }
//                }
//            }
//
//            bool end_of_group = false;
//
//            if (!group_end[current_index].empty()) {
//                for (auto & group_number : group_end[current_index]) {
//                    if (group_number == current_group_number) {
//                        end_of_group = true;
//                    }
//                }
//            }
//
//            if (!end_of_group) {
//                states.push(State(current_index + 1, current_state.groups_amount, current_group_number));
//            }
//        }
//    }


struct Employee {
    char id;
    std::vector<char> incompatible_leaders;

    Employee(char id) {
        this->id = id;
        this->incompatible_leaders = {};
    }

    void add_incompatible_leader(char leader) {
        incompatible_leaders.push_back(leader);
    }
};

bool operator<(const Employee& lhs, const Employee& rhs) {
    return lhs.id < rhs.id;
}

int main3() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int employees, incompatible_pairs;
    std::cin >> employees >> incompatible_pairs;

    std::string company;
    std::cin >> company;

    // std::cout << "employees: " << employees << std::endl << "incompatible_pairs: " << incompatible_pairs << std::endl;
    // std::cout << "company: " << company << std::endl;

    std::set<int> employee_types;
    std::unordered_map<char, Employee> employee_map;

    for (int i = 0; i < employees; ++i) {
        int was_not_list = employee_types.insert(company[i]).second;

        if (was_not_list) {
            employee_map.emplace(company[i], Employee(company[i]));
        }
    }

    // std::cout << "employee_types: " << employee_types.size() << std::endl;


    for (int i = 0; i < incompatible_pairs; ++i) {
        char employee_1, employee_2;
        std::cin >> employee_1 >> employee_2;

      // std::cout << "employee_1: " << employee_1 << " employee_2: " << employee_2 << std::endl;

        if (employee_map.find(employee_1) != employee_map.end()) {
            employee_map.at(employee_1).add_incompatible_leader(employee_2);
        }
    }

    // std::cout << std::endl;

    for (const auto& employee: employee_map) {
        // std::cout << "employee: " << employee.first << std::endl;
        for (auto incompatible_leader: employee.second.incompatible_leaders) {
            // std::cout << "incompatible_leader: " << incompatible_leader << std::endl;
        }

        // std::cout << std::endl;
    }

    std::vector<std::vector<char>> groups = {{}};
    std::vector<char> compatible_leaders (employee_types.size());
    std::copy(employee_types.begin(), employee_types.end(), compatible_leaders.begin());

    int i = 0;
    int group_index = 0;
    int employees_left = employees;

    while (employees_left--) {
        Employee current_employee = employee_map.at(company[i]);

        // std::cout << "current_employee: " << current_employee.id << std::endl;

        std::vector<char> incompatible_leaders_current = current_employee.incompatible_leaders;
        std::vector<char> new_compatible_leaders;

        std::set_difference(
            compatible_leaders.begin(), compatible_leaders.end(),
            incompatible_leaders_current.begin(), incompatible_leaders_current.end(),
            std::back_inserter(new_compatible_leaders)
                );

        compatible_leaders = new_compatible_leaders;

        if (compatible_leaders.empty()) {
            groups.emplace_back();
            group_index++;

            compatible_leaders.assign(employee_types.begin(), employee_types.end());

            groups[group_index].push_back(current_employee.id);

            std::vector<char> new_compatible_leaders_2;

            std::set_difference(
                    compatible_leaders.begin(), compatible_leaders.end(),
                    incompatible_leaders_current.begin(), incompatible_leaders_current.end(),
                    std::back_inserter(new_compatible_leaders_2)
            );

            compatible_leaders = new_compatible_leaders_2;
        } else {
            groups[group_index].push_back(current_employee.id);

            // std::cout << "group_index: " << group_index << std::endl;
            for (auto employee: groups[group_index]) {
                // std::cout << "employee: " << employee << std::endl;
            }
        }
        i++;
    }

    // std::cout << std::endl;
    for (const auto& group: groups) {
        // std::cout << "group: " << std::endl;
        for (auto employee: group) {
            // std::cout << employee << " ";
        }
        // std::cout << std::endl;
    }


    unsigned long long int groups_size = groups.size();

     std::cout << groups_size << std::endl;



    return 0;
}