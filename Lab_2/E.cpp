#include <iostream>
#include <list>
using namespace std;  
  
struct Node{  
    string val;  
    Node * prev;  
    Node * next;  
    int cnt;  
    Node(string val) {  
        this->val=val;  
        prev=nullptr;  
        next=nullptr;  
        cnt=0;  
    }  
};  
  
class Database{  
public:  
    Node * head;  
    Node * tail;  
    int sz;  
    Database() {  
        head=tail=nullptr;  
        sz=0;  
    }  
  
    void push(string val) {  
        Node * newNode = new Node(val);  
        if(head==nullptr) {  
            head=tail=newNode;  
            sz=1;  
        }  
        else{  
            if(head->val==val) {  
                head->cnt++;  
                // break;  
            }  
            else if(head->prev==nullptr) {  
                head->prev=newNode;  
                newNode->next=head;  
                head=newNode;  
                sz++;  
            }  
        }  
    }  
    void print() {  
        Node * cur = head;  
        cout<<"All in all: "<<sz<<endl;  
        cout<<"Students:"<<endl;  
        while(cur!=nullptr) {  
            cout<<cur->val<<endl;  
            cur=cur->next;  
        }  
    }  
};  
  
int main() {  
    Database list;  
    int n;  
    cin>>n;  
    for(int i=0;i<n;i++) {  
        string s;  
        while(cin>>s) list.push(s);  
    }  
    list.print();  
}