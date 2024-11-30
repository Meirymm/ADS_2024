 #include <iostream>
using namespace std;

struct Node { //создали структуру
    int data;//данный(элемент,узел)
    Node* next; // связка(позволяет связывть каждый элемент )
    Node(int x) : data(x), next(nullptr) {}
};

void append(Node*& head, int value) {
    if (!head) {
        head = new Node(value);  
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(value);  }


void removeEverySecond(Node*& head) {
    if (!head || !head->next) return;  

    Node* current = head;
    while (current && current->next) {
        Node* temp = current->next;  
        current->next = current->next->next; 
        delete temp;  
        current = current->next; 
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;  

    Node* head = nullptr;  
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;  
        append(head, value);  
    }

    removeEverySecond(head);  
    printList(head);  

    return 0;
}