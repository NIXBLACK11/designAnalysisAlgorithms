#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

unordered_map<char, char> pad = {
    {'a', '2'}, {'b', '2'}, {'c', '2'},
    {'d', '3'}, {'e', '3'}, {'f', '3'},
    {'g', '4'}, {'h', '4'}, {'i', '4'},
    {'j', '5'}, {'k', '5'}, {'l', '5'},
    {'m', '6'}, {'n', '6'}, {'o', '6'},
    {'p', '7'}, {'q', '7'}, {'r', '7'}, {'s', '7'},
    {'t', '8'}, {'u', '8'}, {'v', '8'},
    {'w', '9'}, {'x', '9'}, {'y', '9'}, {'z', '9'}
};

bool search(string pat, string text) {
    int n = text.size(), m = pat.size();
    int t = 0, p = 0, h = 1;
    int d = 256, q = 101;

    if(m>n) return false;

    for(int i=0;i<m-1;i++) {
        h = (h * d) % q;
    }

    for(int i=0;i<m;i++) {
        p = (p * d + pat[i]) % q;
        t = (t * d + text[i]) % q;
    }

    for(int i=0;i<=n-m;i++) {
        if(p==t) {
            bool found = true;
            for(int j=0;j<m;j++) {
                if(text[i+j]==pat[j]) {
                    found = true;
                    break;
                }
            }

            if(found) return true;
        }

        t = (d * (t - text[i] * h) + text[i+m]) % q;
        if(t<0) t = t+q;
    }

    return false;
}

void convert(vector<string>& words, vector<string>& nums, int n) {
    for(int i=0;i<n;i++) {
        for(auto ch: words[i]) {
            nums[i]+=pad[ch];
        } 
    }
}

int main() {
    string phNum;
    cout<<"Enter the phone number:";
    cin>>phNum;
    int n;
    cout<<"\nEnter the no of words:";
    cin>>n;
    vector<string> words(n);
    cout<<"\nEnter the words:";
    for(int i=0;i<n;i++) {
        cin>>words[i];
    }

    // "foo" -> "366"
    vector<string> nums(n);
    convert(words, nums, n);

    vector<string> ans;
    for(int i=0;i<n;i++) {
        string num = nums[i];
        if(search(num, phNum)) {
            ans.push_back(words[i]);
        }
    }

    sort(ans.begin(), ans.end());
    
    for(auto it: ans) {
        cout<<it<<", ";
    }
}