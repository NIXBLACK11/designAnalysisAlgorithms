#include <iostream>
#include <vector>

using namespace std;

class SidStack {
private:
    vector<int> stack;
    int n;
public:
    SidStack() {
        n = -1;
    }
    
    void push(int val) {
        n++;
        stack.push_back(val);
        
        int idx = n;
        for(int i=n;i>=0;i--) {
            if(stack[idx]>stack[i]) {
                swap(stack[idx], stack[i]);
                idx = i;
            }
        }
    }
    
    int pop() {
        if(n<0) {
            cout<<"Empty stack!!";
            return 0;
        }
        
        int val = stack[n];
        stack.pop_back();
        n--;
        return val;
    }
};

int main() {
    // Write C++ code here
    SidStack sidStack;
    sidStack.push(-1000);
    sidStack.push(2000);
    sidStack.push(-3);
    sidStack.push(134);
    sidStack.push(-232);
    sidStack.push(-34323);
    cout<<sidStack.pop()<<endl;
    cout<<sidStack.pop()<<endl;
    cout<<sidStack.pop()<<endl;
    cout<<sidStack.pop()<<endl;
    cout<<sidStack.pop()<<endl;
    cout<<sidStack.pop()<<endl;
    cout<<sidStack.pop()<<endl;
    return 0;
}
