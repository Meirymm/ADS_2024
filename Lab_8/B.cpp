#include <iostream>
#include<cmath>
#include<unordered_map>
#include<string>
using namespace std;
unordered_map<int, int> map1;
int counter = 0;
void count(string text, string sub)
{
    int n = text.size();
    int m = sub.size();
    long long h[n];
    long long p[n];
    long long q = 2147483647;
    p[0] = 1;
    for (int i = 1; i < max(n, m); ++i)
    {
        p[i] = (p[i - 1] * 31) % q;
    }
    for (int i = 0; i < n; ++i)
    {
        h[i] = ((text[i] - int('a') + 1) * p[i]) % q;
        if (i > 0)
        {
            h[i] = (h[i] + h[i - 1]) % q;
        }
    }
    long long h_s = 0;
    for (int i = 0; i < m; ++i)
    {
        h_s = (h_s + ((sub[i] - int('a') + 1) * p[i]) % q) % q;
    }
    for (int i = 0; i + m - 1 < n; i++)
    {
        long long d = h[i + m - 1];
        if (i > 0)
        {
            d = (d - h[i - 1] + q) % q;
        }
        if (d == (h_s * p[i]) % q)
        {
            map1[i]++;
            if (map1[i] > 1)
                counter++;
        }
    }
}
int main()
{
    string firsttext, secondtext, pattern;
    getline(cin, firsttext);
    getline(cin, secondtext);
    getline(cin, pattern);
    count(firsttext, pattern);
    count(secondtext, pattern);
    cout << counter;
}