#include <iostream>

using namespace std;

void find_index(string str, string substr) {
  int n = 0;
	bool flag = false;
	for (int i = 0; i < str.length(); i++) {
		if (str.substr(i, substr.length()) == substr) {
      n++;
			flag = true;
		}
	}
  cout << n << endl; 
  for (int i = 0; i < str.length(); i++) {
		if (str.substr(i, substr.length()) == substr) {
			cout << i + 1 << " ";
			flag = true;
		}
	}
}

int main() {
	string str;
	string substr;
  cin >> str >> substr;
  find_index(str, substr);
	return 0;
}