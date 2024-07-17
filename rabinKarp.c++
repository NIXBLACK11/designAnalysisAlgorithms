#include <iostream>
#include <string>
#include <cmath>
#define d 256

using namespace std;

void search(string s, string pat)
{
    int q = 101;
    int m = pat.size();
    int n = s.size();
    int p = 0, t = 0, h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;
 
    for (int i = 0; i < m; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + s[i]) % q;
    }

    for (int i = 0; i <= n - m; i++) {
        if (p == t) {
            int j = 0;
            for (j = 0; j < m; j++) {
                if (s[i + j] != pat[j]) {
                    break;
                }
            }
            if (j == m) cout << "Pattern found at index:"<<i<<endl;
        }

        if (i < n - m) {
            t = (d * (t - s[i] * h) + s[i + m]) % q;
            if (t < 0) t = (t + q);
        }
    }
}
int main() {
    string s;
    cout<<"Enter the string to search in:";
    cin>>s;
    string pat;
    cout<<"Enter the pattern to search:";
    cin>>pat;
    search(s, pat);
}