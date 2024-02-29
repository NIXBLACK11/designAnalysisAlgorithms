#include<iostream>
#include<string>
#include<vector>

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

    SegmentTree(vector<int> nums) {
        arr = nums;
        sizeArr = arr.size();
        sizeSegmentTree = calcSize();
        resize(segmentTree.begin(), segmentTree.end(), sizeSegmentTree);
        fill(segmentTree, begin(), segmentTree.end(), 0);
        
    }


}