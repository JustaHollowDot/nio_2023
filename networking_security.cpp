#include <bits/stdc++.h>

class Graph {
    int vertices;

    std::vector<std::vector<int>> adjacency_list;

public:
    Graph(int vertices) {
        this->vertices = vertices;
        adjacency_list.resize(vertices);
    }

    void add_edge(int source, int destination) {
        adjacency_list[source].push_back(destination);
        adjacency_list[destination].push_back(source);
    }

    void bfs_traversal() {
        std::vector<std::array<int, 2> > group_sizes;

        std::vector<int> node_group (vertices, -1);
        std::vector<bool> visited (vertices, false);
        std::queue<int> queue;

        // std::cout << "kake" << std::endl;

        for (int i = 0; i < vertices; ++i) {
            if (visited[i]) {
                continue;
            }



            int group_1_size = 0;
            int group_2_size = 0;

            queue.push(i);
            visited[i] = true;
            node_group[i] = 0;
            group_1_size++;

            int level = 0;

            // std::cout << "queue_1: " << i << std::endl;

            while (!queue.empty()) {
                int level_size = queue.size();

                level++;

                while (level_size--) {
                    int current_node = queue.front();
                    queue.pop();

                    for (auto neighbour : adjacency_list[current_node]) {
                        if (!visited[neighbour]) {
                            queue.push(neighbour);

                            if (level % 2 == 0) {
                                group_1_size++;
                                node_group[neighbour] = 0;
                            } else {
                                group_2_size++;
                                node_group[neighbour] = 1;
                            }

                            visited[neighbour] = true;
                        }
                    }
                }
            }

            std::queue<int> queue2;
            queue2.push(i);


            // std::cout << "queue_2: " << i << std::endl;

            int group_offset = 0;

            for (int j = 0; j < 20; j++) {
                std::vector<bool> visited2 (vertices, false);

                group_offset += 2;

                int current_node_group;

                int group_test_1 = 0;
                int group_test_2 = 0;

                bool start = true;


                while (!queue2.empty()) {
                    int current_node = queue2.front();
                    queue2.pop();



                    for (auto neighbour : adjacency_list[current_node]) {
                        if (!visited2[neighbour]) {
                            queue2.push(neighbour);

                            int test_level = 0;


                            if (node_group[neighbour] == node_group[current_node] && neighbour != current_node) {
                                if (start) {
                                    current_node_group = node_group[neighbour];
                                    group_test_1++;
                                    start = false;
                                }

                                current_node_group = node_group[current_node];
                                // std::cout << "IMPOSSIBLE" << std::endl;

                                std::queue<int> test_queue;
                                test_queue.push(current_node);


                                while (!test_queue.empty()) {
                                    int test_level_size = test_queue.size();

                                    test_level++;

                                    // std::cout << "test_level: " << test_level << std::endl;



                                    while (test_level_size--) {
                                        int test_current_node = test_queue.front();
                                        test_queue.pop();

                                        if (visited2[test_current_node]) {
                                            continue;
                                        }

                                        for (auto test_neighbour : adjacency_list[test_current_node]) {
                                            if (node_group[test_neighbour] == node_group[test_current_node]) {
                                                if (!visited2[test_neighbour]) {
                                                    test_queue.push(test_neighbour);

//                                                std::cout << "test_neighbour: " << test_neighbour << std::endl;

                                                    if (test_level % 2 == 0) {
                                                        node_group[test_current_node] = 0 + group_offset;
                                                        group_test_1++;
                                                    } else {
                                                        node_group[test_current_node] = 1 + group_offset;
                                                        group_test_2++;
                                                    }

                                                    visited2[test_neighbour] = true;
                                                }

                                            }
                                        }

                                    }
                                }
                            }
                        }
                    }

                    visited2[current_node] = true;
                }

//            std::cout << "test_1: " << group_test_1 << std::endl;
//            std::cout << "test_2: " << group_test_2 << std::endl;

                if (current_node_group == 0) {
                    group_2_size += std::min(group_test_1, group_test_2);
                } else {
                    group_1_size += std::min(group_test_1, group_test_2);
                }


            }







            group_sizes.push_back({group_1_size, group_2_size});

        }

        for (auto group : group_sizes) {
            // std::cout << group[0] << " " << group[1] << std::endl;
        }

        int min_total = 0;

        for (auto group : group_sizes) {
            min_total += std::min(group[0], group[1]);
        }

         std::cout << min_total << std::endl;
    }
};

int main4() {
    int computers, connections, wireless_computers, wireless_connections;
    std::cin >> computers >> connections >> wireless_computers >> wireless_connections;

    Graph graph2(computers);

    for (int i = 0; i < connections; ++i) {
        int source, destination;
        std::cin >> source >> destination;

        graph2.add_edge(source, destination);
    }

    for (int i = 0; i < wireless_connections; ++i) {
        int source, destination;
        std::cin >> source >> destination;

        graph2.add_edge(source, destination);
    }

    graph2.bfs_traversal();

    return 0;
}



//class Graph {
//    int vertices;
//
//    std::vector<std::list<int>> adjacency_list;
//
//public:
//    Graph(int vertices) {
//        this->vertices = vertices;
//        adjacency_list.resize(vertices);
//    }
//
//    void add_edge(int source, int destination) {
//        adjacency_list[source].push_back(destination);
//        adjacency_list[destination].push_back(source);
//    }
//
//    void bfs_traversal() {
//        int min_group_size = 0;
//
//        std::vector<int> node_group (vertices, -1);
//        std::vector<bool> visited (vertices, false);
//        std::vector<bool> visited2 (vertices, false);
//        std::queue<int> queue;
//
//        for (int i = 0; i < vertices; ++i) {
//            int group_0 = 0;
//            int group_1 = 0;
//
//            if (!visited[i]) {
//                queue.push(i);
//                visited[i] = true;
//                group_0++;
//                node_group[i] = 0;
//
//                int level = 0;
//
//                while (!queue.empty()) {
//                    int level_size = queue.size();
//
//                    level++;
//                    // // std::cout << "level_size: " << level_size << std::endl;
//
//                    while (level_size--) {
//                        int current = queue.front();
//                        queue.pop();
//
//                        // // std::cout << current << " ";
//
//                        for (auto neighbour : adjacency_list[current]) {
//                            if (!visited[neighbour]) {
//                                visited[neighbour] = true;
//                                queue.push(neighbour);
//
//                                if (level % 2 == 0) {
//                                    group_0++;
//                                    node_group[neighbour] = 0;
//                                } else {
//                                    group_1++;
//                                    node_group[neighbour] = 1;
//                                }
//                            } else {
//                                if (node_group[current] == node_group[neighbour]) {
//                                    // // std::cout << "IMPOSSIBLE" << std::endl;
//                                    // // std::cout << "current: " << current << " neighbour: " << neighbour << std::endl;
//
//                                    int current_node_group = node_group[current];
//
//                                    std::queue<int> queue_2;
//                                    queue_2.push(current);
//                                    visited2[current] = true;
//
//                                    int node_group_0_2 = 0;
//                                    int node_group_1_2 = 0;
//
//                                    int level_2 = 0;
//
//                                    while (!queue_2.empty()) {
//                                        int level_size_2 = queue_2.size();
//
//                                        level_2++;
//                                        // // std::cout << "level_size_2: " << level_size_2 << std::endl;
//
//                                        while (level_size_2--) {
//                                            int current_2 = queue_2.front();
//                                            queue_2.pop();
//
//                                            // // std::cout << current_2 << " ";
//
//                                            for (auto neighbour_2 : adjacency_list[current_2]) {
//                                                if (!visited2[neighbour_2]) {
//                                                    if (node_group[neighbour_2] == current_node_group) {
//                                                        // // std::cout << neighbour_2 << " ";
//                                                        queue_2.push(neighbour_2);
//                                                        visited2[neighbour_2] = true;
//
//                                                        if (level_2 % 2 == 0) {
//                                                            node_group_0_2++;
//                                                        } else {
//                                                            node_group_1_2++;
//                                                        }
//
//                                                        if (level_2 % 2 == 0) {
//                                                            // // std::cout << "group_0: " << group_0 << " group_1: " << group_1 << std::endl;
//                                                            group_0++;
//                                                        } else {
//                                                            // // std::cout << "group_0: " << group_0 << " group_1: " << group_1 << std::endl;
//                                                            group_1++;
//                                                        }
//                                                    }
//                                                }
//                                            }
//                                        }
//                                        // // std::cout << std::endl;
//                                    }
//
//                                    int min_node_group = std::min(node_group_0_2, node_group_1_2);
//
//                                    if (current_node_group == 0) {
//                                        group_0 += min_node_group;
//                                    } else {
//                                        group_1 += min_node_group;
//                                    }
//                                }
//                            }
//                        }
//                    }
//                    // // std::cout << std::endl;
//                }
//
//                // // std::cout << "group_0: " << group_0 << " group_1: " << group_1 << std::endl;
//                min_group_size += std::min(group_0, group_1);
//            }
//        }
//
//
//        for (int i = 0; i < vertices; ++i) {
//            for (auto neighbour: adjacency_list[i]) {
//                if (node_group[i] == node_group[neighbour]) {
//                    // // std::cout << "node_group[i]: " << node_group[i] << " node_group[neighbour]: " << node_group[neighbour] << std::endl;
//                    // // std::cout << "i: " << i << " neighbour: " << neighbour << std::endl;
//                    // // std::cout << "min_group_size: " << min_group_size << std::endl;
//
//                    queue.push(i);
//                }
//            }
//        }
//
//
//        for (int i = 0; i < node_group.size(); ++i) {
//            // // std::cout << "node: " << i << " group: " << node_group[i] << std::endl;
//        }
//
//        // // std::cout << std::endl;
//
//         // std::cout << min_group_size << std::endl;
//
//    }
//
//    void print_graph() {
//        for (int i = 0; i < adjacency_list.size(); ++i) {
//            // // std::cout << i << " -> ";
//            for (auto j : adjacency_list[i]) {
//                // // std::cout << j << " ";
//            }
//            // // std::cout << std::endl;
//        }
//    }
//};
//
//
//int main4() {
//    int computers, connections, wireless_computers, wireless_connections;
//    std::cin >> computers >> connections >> wireless_computers >> wireless_connections;
//
//    Graph graph2(computers);
//
//    for (int i = 0; i < connections; ++i) {
//        int source, destination;
//        std::cin >> source >> destination;
//
//        graph2.add_edge(source, destination);
//    }
//
//    for (int i = 0; i < wireless_connections; ++i) {
//        int source, destination;
//        std::cin >> source >> destination;
//
//        graph2.add_edge(source, destination);
//    }
//
//    graph2.print_graph();
//
//    graph2.bfs_traversal();
//
//    return 0;
//}