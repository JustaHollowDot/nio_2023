#include <bits/stdc++.h>


struct Node {
    int id;

    int individual_approved_work = 0;
    int group_approved_work = 0;

    Node *parent = nullptr;

    int children_amount = 0;
    std::vector<Node*> children;
};

struct State {
    int id;
    int total_approved_works;

    State(int id, int total_approved_work) {
        this->id = id;
        this->total_approved_works = total_approved_work;
    }
};

int get_children_amount(Node * root) {
    if (root == nullptr) {
        return 0;
    }

    if (root->children_amount != 0) {
        return root->children_amount;
    }

    if (root->children.empty()) {
        root->children_amount = 0;
        return 1;
    }

    int children_amount = 0;

    for (auto child : root->children) {
        children_amount += get_children_amount(child);
    }

    root->children_amount = children_amount;

    return children_amount + 1;
}

void approve_sub_work(Node * root, int work_amount, int & total_approved_works, Node * prev_node = nullptr) {
    if (root == nullptr) {
        return;
    }

    for (auto child : root->children) {
        if (work_amount == total_approved_works) {
            return;
        }

        if (prev_node != nullptr && child->id == prev_node->id) {
            continue;
        }

        if (child->children_amount + 1 == work_amount - total_approved_works) {
            child->group_approved_work++;

            total_approved_works++;

            return;
        } else if (child->children_amount + 1 < work_amount - total_approved_works) {
            child->group_approved_work++;

            total_approved_works++;
        } else {
            approve_sub_work(child, work_amount, total_approved_works);

            return;
        }
    }


    // std::cout << "approved_works: " << total_approved_works << std::endl;
    // std::cout << "work_amount: " << work_amount << std::endl;
}


void approve_work(Node * start_employee, int work_amount, Node * prev_employee = nullptr) {
    if (start_employee == nullptr) {
        return;
    }

    if (start_employee->children_amount + 1 == work_amount) {
        start_employee->group_approved_work++;

        return;
    } else if (start_employee->children_amount + 1 < work_amount) {
        approve_work(start_employee->parent, work_amount, start_employee);

        return;
    } else {
        int current_approved_amount = 0;

        if (prev_employee != nullptr) {
            prev_employee->group_approved_work++;
            current_approved_amount += prev_employee->children_amount + 1;
        } else {
            start_employee->individual_approved_work++;
            current_approved_amount++;
        }


        approve_sub_work(start_employee, work_amount, current_approved_amount, prev_employee);
    }


}



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int employee_amount, work_amount;
    std::cin >> employee_amount >> work_amount;

    std::vector<Node> employees(employee_amount);for (int i = 0; i < employee_amount; ++i) {
        employees[i].id = i;
    }

    for (int i = 1; i < employee_amount; ++i) {
        int parent_id;
        std::cin >> parent_id;

        employees[i].parent = &employees[parent_id];
        employees[parent_id].children.push_back(&employees[i]);
    }

    get_children_amount(&employees[0]);



    for (int i = 0; i < work_amount; ++i) {
        int employee_id, approval_amount;
        std::cin >> employee_id >> approval_amount;

        if (approval_amount == 1) {
            employees[employee_id].individual_approved_work++;
        } else {
            approve_work(&employees[employee_id], approval_amount);
        }
    }

    for (int i = 0; i < employee_amount; ++i) {
        // std::cout << "employee " << i << ": " << employees[i].individual_approved_work << " and " << employees[i].group_approved_work << std::endl;
    }


    std::queue<State> queue;

    queue.push(State(employees[0].id, 0));

    while (!queue.empty()) {
        State current = queue.front();
        queue.pop();

        // std::cout << current.id << " " << current.total_approved_works << std::endl;

        int new_total_approved_works = current.total_approved_works + employees[current.id].group_approved_work;

        employees[current.id].individual_approved_work += new_total_approved_works;

        for (auto child: employees[current.id].children) {
            queue.push(State(child->id, new_total_approved_works));
        }
    }

    for (int i = 0; i < employee_amount; ++i) {
         std::cout << employees[i].individual_approved_work << " ";
    }

    return 0;
}



//#include <bits/stdc++.h>
//
//
//
//struct Node {
//    int key;
//
//    int current_approved_work = -1;
//    int approved_works = 0;
//
//    Node * parent;
//
//    int children_amount;
//    std::vector<Node*> children;
//};
//
//Node *newNode(int key) {
//    Node *temp = new Node;
//    temp->key = key;
//    return temp;
//}
//
//void LevelOrderTraversal(Node * root) {
//    if (root == nullptr) {
//        return;
//    }
//
//    std::queue<Node*> queue;
//    queue.push(root);
//
//    while (!queue.empty()) {
//        int level_size = queue.size();
//
//        while (level_size--) {
//            Node *current = queue.front();
//            queue.pop();
//
//            // std::cout << current->key << " ";
//
//            for (auto child : current->children) {
//                queue.push(child);
//            }
//        }
//
//        // std::cout << std::endl;
//    }
//}
//
//int get_children_amount(Node * root) {
//    if (root == nullptr) {
//        return 0;
//    }
//
//    if (root->children_amount != 0) {
//        return root->children_amount;
//    }
//
//    if (root->children.empty()) {
//        root->children_amount = 0;
//        return 1;
//    }
//
//    int children_amount = 0;
//
//    for (auto child : root->children) {
//        children_amount += get_children_amount(child);
//    }
//
//    root->children_amount = children_amount;
//
//    return children_amount + 1;
//}
//
//void get_work_approved(Node * root, int work, int &approved_works_amount, int required_work_approvals) {
//    if (root == nullptr) {
//        return;
//    }
//
//    if (root->current_approved_work == work) {
//        return;
//    }
//
//    root->current_approved_work = work;
//
//    for (auto child: root->children) {
//        get_work_approved(child, work, approved_works_amount, required_work_approvals);
//    }
//
//    if ( approved_works_amount >= required_work_approvals ) {
//        return;
//    }
//
//    root->approved_works++;
//    approved_works_amount++;
//
//
//    if (root->parent != nullptr) {
//        get_work_approved(root->parent, work, approved_works_amount, required_work_approvals);
//    }
//}
//
//int main() {
//    std::ios_base::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//
//    int employees, work_amount;
//
//    std::cin >> employees >> work_amount;
//
//    std::vector<Node> nodes(employees);
//
//    for (int i = 0; i < employees; i++) {
//        nodes[i].key = i;
//    }
//
//    Node *root = &nodes[0];
//
//    for (int i = 1; i < employees; i++) {
//        int parent;
//        std::cin >> parent;
//
//        nodes[parent].children.push_back(&nodes[i]);
//        nodes[i].parent = &nodes[parent];
//    }
//
////    LevelOrderTraversal(root);
////    get_children_amount(root);
//
////    for (const auto& node : nodes) {
////        // std::cout << node.key << " " << node.children_amount << std::endl;
////    }
//
//    for (int i = 0; i < work_amount; i++) {
//        int employee, required_work_approvals;
//        std::cin >> employee >> required_work_approvals;
//
//        // std::cout << "employee: " << employee << " required_work_approvals: " << required_work_approvals << std::endl;
//
//        int approved_works_amount = 1;
//        nodes[employee].approved_works++;
//        nodes[employee].current_approved_work = i;
//
//        for (auto child : nodes[employee].children) {
//            get_work_approved(child, i, approved_works_amount, required_work_approvals);
//        }
//
//        get_work_approved(nodes[employee].parent, i, approved_works_amount, required_work_approvals);
//
//
//        // std::cout << "approved_works_amount: " << approved_works_amount << std::endl;
//    }
//
////    for (const auto& node : nodes) {
////        // std::cout << node.key << " " << node.approved_works << std::endl;
////    }
//
//
//    for (const auto& node : nodes) {
//          std::cout << node.approved_works << " ";
//    }
//
//
//
//
//
//    return 0;
//}