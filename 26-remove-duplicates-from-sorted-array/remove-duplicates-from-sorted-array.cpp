class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int low = 0;
        int res = 1;
        int high = 1;
        while (high < n) {
            if (nums[high] == nums[high - 1]) {
                high++;
            } else if (nums[low] != nums[high]) {
                low++;
                nums[low] = nums[high];
                res++;
                high++;
            }
        }
        return res;
    }
};