class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> curr = nums;
        while(1)
        {
            ans.push_back(curr);
            curr = nextPermutation(curr);
            if(curr == nums)
            {
                break;
            }
        }
        return ans;
    }
    vector<int> nextPermutation(vector<int>& nums) {
        int n = nums.size(), index = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        for(int i=n-1; i>=index && index != -1; i--){
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end());
        return nums;
    }
};