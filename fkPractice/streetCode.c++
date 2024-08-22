#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin>>s;
    int n = s.size();
    for(int i=1;i<n;i++) {
        if(s[i]==s[i-1]) {
            cout<<"Bad";
            return 0;
        }
    }
    cout<<"Good";
}