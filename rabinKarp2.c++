#include <iostream>
#include <cmath>
using namespace std;

void match(string s, string p) {
    int hs = 0, hp = 0;
    int base = 26;
    int ns = s.size(), np = p.size();

    if (np > ns) {
        cout << "Pattern is longer than the text. No match possible." << endl;
        return;
    }

    int highestPow = pow(base, np - 1);

    for (int i = 0; i < np; i++) {
        hs = hs * base + (s[i] - 'a');
        hp = hp * base + (p[i] - 'a');
    }

    for (int i = np; i <= ns; i++) {
        if (hs == hp && s.substr(i - np, np) == p) {
            cout << "Pattern found at index " << (i - np) << endl;
        }

        if (i < ns) {
            hs = (hs - (s[i - np] - 'a') * highestPow) * base + (s[i] - 'a');
        }
    }
}

int main() {
    string s, p;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the pattern: ";
    cin >> p;
    match(s, p);
    return 0;
}
