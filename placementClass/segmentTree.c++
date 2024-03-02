#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

class SegmentTree {
public:
    int sizeSegmentTree;
    int sizeArr;
    vector<int> arr;
    vector<int> segmentTree;

    int calcSize() {
        int x = ceil(log2(sizeArr));
        return 2*(pow(x, 2))-1;
    }
    
    void createSegmentTree(int sl, int sr, int index) {
        if (sl == sr) {
            segmentTree[index] = arr[sl];
            return;
        }

        int mid = sl + (sr - sl) / 2;

        createSegmentTree(sl, mid, index * 2 + 1);
        createSegmentTree(mid + 1, sr, index * 2 + 2);

        segmentTree[index] = segmentTree[index * 2 + 1] + segmentTree[index * 2 + 2];
    }

    void updateUtils(int sl, int sr, int curr, int index, int changeVal) {
        segmentTree[curr]+=changeVal;

        if(sl==sr) {
            return;
        }

        int mid = sl + (sr - sl) / 2;

        if(mid>=index) {
            updateUtils(sl, mid, curr*2+1, index, changeVal);
        } else {
            updateUtils(mid+1, sr, curr*2+2, index, changeVal);
        }
    }

    int rangeUtils(int ql, int qr, int sl, int sr, int index) {
        if(qr<sl || sr<ql) {
            return 0;
        } else if(ql<=sl && sr<=qr) {
            return segmentTree[index];
        } else {
            int mid = sl + (sr - sl)/2;
            return rangeUtils(ql, qr, sl, mid, index*2+1) + rangeUtils(ql, qr, mid+1, sr, index*2+2);
        }
    }

    SegmentTree(vector<int> nums) {
        arr = nums;
        sizeArr = arr.size();
        sizeSegmentTree = calcSize();
        segmentTree.assign(sizeSegmentTree, 0);
        createSegmentTree(0, sizeArr-1, 0);
    }

    void update(int index, int val) {
        int changeVal = val-arr[index];
        arr[index] = val;
        updateUtils(0, sizeArr-1, 0, index, changeVal);
    }

    void printTree() {
        for(int i=0;i<sizeSegmentTree;i++) {
            cout<<segmentTree[i]<<" ";
        }
    }

    int sumRange(int l, int r) {
        return rangeUtils(l, r, 0, sizeArr-1, 0);
    }
};

int main() {
    int n;
    cout<<"\nEnter the number of elements:\n";
    cin>>n;
    vector<int> nums(n, 0);
    cout<<"\nEnter the elements:\n";
    for(int i=0;i<n;i++) {
        cin>>nums[i];
    }
    SegmentTree st(nums);
    char ch;
    while(true) {
        cout<<"\nEnter u for update, p for print, s for sum\n";
        cin>>ch;
        switch(ch) {
            case 'u':
                cout<<"\nEnter the number and index to update\n";
                int index, val;
                cout<<"\nEnter the index\n";
                cin>>index;
                cout<<"\nEnter the value\n";
                cin>>val;
                st.update(index, val);
                break;
            case 'p':
                st.printTree();
                break;
            case 's':
                cout<<"\nEnter the left and right index\n";
                int l, r;
                cout<<"\nEnter the left\n";
                cin>>l;
                cout<<"\nEnter the right\n";
                cin>>r;
                cout<<"\n"<<st.sumRange(l, r)<<"\n";
                break;
            default:
                cout<<"\n wrong input\n";
                break;
        }
    }
}