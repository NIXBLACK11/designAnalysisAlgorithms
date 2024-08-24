#include <iostream>
#include <stack>
// https://leetcode.com/discuss/interview-experience/4923739/Flipkart-SDE-1-or-Interview-Experience-or-Off-Campus-2024/

using namespace std;

int main() {
    string s;
    cin>>s;
    stack<char> st;
    int ans = 0;

    for (char ch : s) {
        if (!st.empty() && st.top() == '0' && ch == '1') {
            st.pop();
            ans++;
        } else {
            st.push(ch);
        }
    }

    cout<<ans/2;
}