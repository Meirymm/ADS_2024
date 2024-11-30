#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int main(){
  int A, B;
  cin >> A >> B;
  vector <int> vis;
  vis.resize(2 * max(A, B) + 1, -1);

  queue <int> checking;
  vis[A] = 0;
  checking.push(A);
  while(!checking.empty()){
    int s = checking.front();
    checking.pop();
    if(s == B) break;
    if(s < B){
      if(vis[2 * s] == -1 || vis[2 * s] > vis[s] + 1){
        vis[2 * s] = vis[s] + 1;
        checking.push(2 * s);
      }
    }
    if(s !=0 && (vis[s - 1] == -1 || vis[s - 1] > vis[s] + 1)){
      vis[s - 1] = vis[s] + 1;
      checking.push(s - 1);
    }
  }
  stack <int> answer;
  answer.push(B);
  while(answer.top() != A){
    if(vis[answer.top() + 1] + 1 == vis[answer.top()]) answer.push(answer.top() + 1);
    else if(answer.top() % 2 == 0) answer.push(answer.top() / 2);
  }

  if(answer.size() == 0){
    cout << 0;
    return 0;
  }
  answer.pop();
  cout << answer.size() << endl;
  while(!answer.empty()){
    cout << answer.top() << ' ';
    answer.pop();
  }
  return 0;
}