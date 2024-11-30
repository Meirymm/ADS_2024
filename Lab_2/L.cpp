#include <iostream> 
#include <climits> 
 
using namespace std; 
 
 
struct node { 
 int x; // data 
 node* nxt = NULL; // next element 
 node() {} 
 node(int x) { 
  this->x = x; 
 } 
 node(int x, node* nxt) { 
  this->x = x; 
  this->nxt = nxt; 
 } 
}; 
struct linked_list { 
 node* head = NULL; 
 node* tail = NULL; 
 
 void add_to_end(int x) { 
  node* new_node = new node(x); 
  if (tail == nullptr) { 
   head = tail = new_node; 
  } 
  else { 
   tail->nxt = new_node; 
   tail = new_node; 
  } 
 } 
 void solve() { 
  int prevSum = head->x; 
  node* curr = head->nxt; 
  int mx = INT_MIN; 
  while (curr != NULL) 
  { 
   if (prevSum < 0) { 
    if (prevSum > mx) 
     mx = prevSum; 
    prevSum = curr->x; 
   } 
   else { 
    if (prevSum > mx) 
     mx = prevSum; 
    prevSum += curr->x; 
   } 
   curr = curr->nxt; 
  } 
  if (prevSum > mx) cout << prevSum; 
  else cout << mx; 
 } 
}; 
 
int main() { 
 linked_list LL; 
 int n; cin >> n; 
 int temp; 
 for (int i = 0; i < n; i++) 
 { 
  cin >> temp; 
  LL.add_to_end(temp); 
 } 
 LL.solve(); 
 
 return 0; 
}
