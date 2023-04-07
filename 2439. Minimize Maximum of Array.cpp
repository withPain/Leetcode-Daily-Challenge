class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {

        int n = nums.size();
        long long temp = 0, ans = 0;

        for(int i = 0; i < n; i++){
            temp += nums[i];
            ans = max(ans, (long long)ceil(double(temp)/(i+1)));
        }
        return ans;

    }
};