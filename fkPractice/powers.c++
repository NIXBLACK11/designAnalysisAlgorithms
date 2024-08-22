#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Function to calculate the sum of all possible values with + inserted between numbers
int calculateMaxPower(const string &S) {
    int n = S.size();
    int totalSum = 0;

    // There are 2^(n-1) possible combinations of inserting '+' between the digits
    int combinations = 1 << (n - 1);

    for (int i = 0; i < combinations; ++i) {
        int currentValue = 0;
        int sum = 0;

        for (int j = 0; j < n; ++j) {
            // Add the current digit to the current value
            currentValue = currentValue * 10 + (S[j] - '0');

            // If the j-th bit in i is set or j is the last digit, add currentValue to sum
            if ((i & (1 << j)) || j == n - 1) {
                sum += currentValue;
                currentValue = 0;
            }
        }

        // Add the calculated sum for this combination
        totalSum += sum;
    }

    return totalSum;
}

int main() {
    string S;
    cout << "Enter the string representing the mystical river: ";
    cin >> S;

    int result = calculateMaxPower(S);
    cout << "The greatest power the river can possess is: " << result << endl;

    return 0;
}
