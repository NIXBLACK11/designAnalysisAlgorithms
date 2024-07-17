#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

using namespace std;

/*
[['9:00', '10:30'], ['12:00', '13:00'], ['16:00', '17:00']]
['9:00', '20:00']
[['10:00', '11:30'], ['12:30', '14:30'], ['14:30', '15:00'], ['16:00', '17:00']]
['10:00', '18:30']
30
[['11:30', '12:00'], ['15:00', '16:00'], ['18:00', '18:30']]
*/

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    
    while (getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    
    return tokens;
}

void getAvailableTime(vector<vector<string>>& personA, deque<vector<string>>& A) {
    int n = personA.size();
    for(int i=0;i<n-1;i++) {
        string a = personA[i][1];
        string b = personA[i+1][0];
        if(a!=b) {
            A.push_back({a, b});
        }
    }
}

void removeOutOfRange(deque<vector<string>>& A, vector<string>& personAAvailable) {
    int n = A.size();
    vector<string> startTime = split(personAAvailable[0], ':'), endTime = split(personAAvailable[1], ':');

    for(int i=0;i<n;i++) {
        vector<string> startTimeI = split(A[i][0], ':'), endTimeI = split(A[i][1], ':');
        if(startTimeI[0]<startTime[0] && endTimeI[0]<startTime[0]) {
            A.pop_front();
        } else if()
    }
}

int main() {
    vector<vector<string>> personA = {
        {"9:00", "10:30"},
        {"12:00", "13:00"},
        {"16:00", "17:00"}
    };
    vector<string> personAAvailable = {"9:00", "20:00"};

    vector<vector<string>> personB = {
        {"10:00", "11:30"},
        {"12:30", "14:30"},
        {"14:30", "15:00"},
        {"16:00", "17:00"}
    };
    vector<string> personBAvailable = {"10:00", "18:30"};

    deque<vector<string>> A, B;
    getAvailableTime(personA, A);
    getAvailableTime(personB, B);

    // for(auto it:A) {
    //     cout<<it[0]<<":"<<it[1]<<endl;
    // }
    // cout<<"----"<<endl;
    // for(auto it:B) {
    //     cout<<it[0]<<":"<<it[1]<<endl;
    // }

    removeOutOfRange(A, personAAvailable);
    removeOutOfRange(B, personBAvailable);
}