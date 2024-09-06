#include <iostream>

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int _val) : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp  = head;
        while (temp != nullptr) {
            Node* a = temp->next;
            if (temp->child != nullptr) {
                Node* c = temp->child;
                temp->child = nullptr;
                c = flatten(c);
                temp->next = c;
                c->prev = temp;
                while (c->next != nullptr) {
                    c = c->next;
                }
                c->next = a;
                if (a) a->prev = c;
            }
            temp = a;
        }
        return head;
    }
};

// Helper function to print the list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage:
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    // Adding child nodes
    head->next->child = new Node(7);
    head->next->child->next = new Node(8);
    head->next->child->next->prev = head->next->child;

    Solution sol;
    head = sol.flatten(head);

    // Print flattened list
    printList(head);

    return 0;
}
