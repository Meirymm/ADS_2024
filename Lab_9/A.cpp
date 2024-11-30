#include <iostream>
#include <string>

using namespace std;


bool kmp_searching(string s2, string r1)
{
	int m = s2.length();
	int n = r1.length();

	for (int i = 0; i <= n - m; i++) {
		int j;

		for (j = 0; j < m; j++)
			if (r1[i + j] != s2[j]) break;

		if (j == m) return true;
	}

	return false; 
}

int min_repetation(string s1, string s2) {
	int answer = 1;
	
	string S = s1;
	
	while(S.size() < s2.size()) {
		S += s1;
		answer++;
	}

	if (kmp_searching(s2, S)) return answer;
	
	if (kmp_searching(s2, S+s1)) return answer + 1;

	return -1;
}

int main() {
	string A, B;
	cin >> A >> B;
	
	cout << min_repetation(A, B);
	
	return 0;
}