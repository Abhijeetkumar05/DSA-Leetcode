class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> highs(n), lows(n);
        partial_sum(nums.begin(), nums.end(), highs.begin(), ranges::max);  
        partial_sum(nums.rbegin(), nums.rend(), lows.rbegin(), ranges::min);  
        auto idx = views::iota(0, n);
        auto it = ranges::find_if(idx, [&](int i) { return highs[i] - lows[i] <= k; });
        return it == idx.end() ? -1 : *it;
    }
};