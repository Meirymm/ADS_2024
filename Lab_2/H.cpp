#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    Node* insert(int x, int p) {
        Node* newNode = new Node(x);
        if (p == 0) {
            newNode->next = head;
            head = newNode;
            return head;
        }

        Node* current = head;
        for (int i = 0; i < p - 1 && current; i++) {
            current = current->next;
        }
        if (current) {
            newNode->next = current->next;
            current->next = newNode;
        }
        return head;
    }

    Node* remove(int p) {
        if (!head) return head;

        if (p == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        Node* current = head;
        for (int i = 0; i < p - 1 && current; i++) {
            current = current->next;
        }
        if (current && current->next) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        return head;
    }

    void print() {
        if (!head) {
            cout << -1 << endl;
            return;
        }
        for (Node* current = head; current; current = current->next) {
            cout << current->data << " ";
        }
        cout << endl;
    }

    Node* replace(int p1, int p2) {
        if (!head || p1 == p2) return head;

        Node *nodeToMove = head, *prevNode1 = nullptr;
        for (int i = 0; i < p1; i++) {
            prevNode1 = nodeToMove;
            nodeToMove = nodeToMove->next;
        }

        if (!nodeToMove) return head;

        if (prevNode1) {
            prevNode1->next = nodeToMove->next;
        } else {
            head = nodeToMove->next;
        }

        Node *target = head, *prevNode2 = nullptr;
        for (int i = 0; i < p2; i++) {
            prevNode2 = target;
            target = target->next;
        }

        nodeToMove->next = target;

        if (prevNode2) {
            prevNode2->next = nodeToMove;
        } else {
            head = nodeToMove;
        }

        return head;
    }

Node* reverse() {
        Node *prev = nullptr, *current = head;

        while (current) {
            Node* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }

    Node* cyclic_shift(int x, bool left) {
        if (!head || !head->next || x <= 0) return head;

        Node* current = head;
        int length = 1;
        while (current->next) {
            current = current->next;
            length++;
        }

        x %= length;
        if (x == 0) return head;

        current->next = head;

        int breakPoint = left ? x : length - x;
        current = head;
        for (int i = 0; i < breakPoint - 1; i++) {
            current = current->next;
        }

        head = current->next;
        current->next = nullptr;
        return head;
    }

    Node* cyclic_left(int x) {
        return cyclic_shift(x, true);
    }

    Node* cyclic_right(int x) {
        return cyclic_shift(x, false);
    }
};

int main() {
    LinkedList list;
    int command, x, p, p1, p2;

    while (true) {
        cin >> command;
        if (command == 0) break;

        switch (command) {
            case 1:
                cin >> x >> p;
                list.insert(x, p);
                break;
            case 2:
                cin >> p;
                list.remove(p);
                break;
            case 3:
                list.print();
                break;
            case 4:
                cin >> p1 >> p2;
                list.replace(p1, p2);
                break;
            case 5:
                list.reverse();
                break;
            case 6:
                cin >> x;
                list.cyclic_left(x);
                break;
            case 7:
                cin >> x;
                list.cyclic_right(x);
                break;
        }
    }
    return 0;
}