#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* prev;
    Node* next;
    Node(string book) : data(book), prev(nullptr), next(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void add_front(string book) {
        Node* newNode = new Node(book);
        if (!head) { 
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "ok" << endl;
    }

    void add_back(string book) {
        Node* newNode = new Node(book);
        if (!tail) { 
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        cout << "ok" << endl;
    }

    void erase_front() {
        if (!head) {
            cout << "error" << endl;
        } else {
            cout << head->data << endl;
            Node* temp = head;
            if (head == tail) {  
                head = tail = nullptr;
            } else {
                head = head->next;
                head->prev = nullptr;
            }
            delete temp;
        }
    }
    void erase_back() {
        if (!tail) {
            cout << "error" << endl;
        } else {
            cout << tail->data << endl;
            Node* temp = tail;
            if (head == tail) {  
                head = tail = nullptr;
            } else {
                tail = tail->prev;
                tail->next = nullptr;
            }
            delete temp;
        }
    }
    void front() {
        if (!head) {
            cout << "error" << endl;
        } else {
            cout << head->data << endl;
        }
    }
    void back() {
        if (!tail) {
            cout << "error" << endl;
        } else {
            cout << tail->data << endl;
        }
    }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "ok" << endl;
    }
    void exit() {
        cout << "goodbye" << endl;
    }
};
int main() {
    DoublyLinkedList list;
    string command;

    while (true) {
        cin >> command;
        
        if (command == "add_front") {
            string book;
            cin >> book;
            list.add_front(book);
        } 
        else if (command == "add_back") {
            string book;
            cin >> book;
            list.add_back(book);
        } 
        else if (command == "erase_front") {
            list.erase_front();
        } 
        else if (command == "erase_back") {
            list.erase_back();
        } 
        else if (command == "front") {
            list.front();
        } 
        else if (command == "back") {
            list.back();
        } 
        else if (command == "clear") {
            list.clear();
        } 
        else if (command == "exit") {
            list.exit();
            break;
        }
    }

    return 0;
}
