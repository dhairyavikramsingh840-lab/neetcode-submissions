class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int cnt = 0;
        int i = 0;
        while (i < n) {
            if (nums[i] == 0) {

                cnt = 0;
                i++;
            } else {
                cnt++;
                ans = max(ans, cnt);
                i++;
            }
        }
        return ans;
    }
};