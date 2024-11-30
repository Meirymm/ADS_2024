#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};
Node* insertNode(Node* head, int data, int position) {
    Node* newNode = new Node(data);  
    if (position == 0) {
        newNode->next = head;
        return newNode;  
    }

    Node* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; ++i) {
        current = current->next;
    }
    if (current != nullptr) {
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;  
}
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;  

    Node* head = nullptr;  
    Node* tail = nullptr; 
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        Node* newNode = new Node(value);  
        if (head == nullptr) {
            head = newNode;  
            tail = head;
        } else {
            tail->next = newNode; 
            tail = newNode;
        }
    }

    int data, position;
    cin >> data;   
    cin >> position;  
    head = insertNode(head, data, position);  
    printList(head);  
    return 0;
}
