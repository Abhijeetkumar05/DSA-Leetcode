class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;

        if(costBoth < cost1 + cost2){
            long long ans1 = 1LL*max(need1,need2)*costBoth;  
            long long ans2 = 1LL*min(need1,need2)*costBoth;  

            if(need1 > need2) ans2 += 1LL*(need1 - need2)*cost1;
            else ans2 += 1LL*(need2 - need1)*cost2;

            ans = min(ans1,ans2);
                    
        }
        else{
            ans += 1LL*need1*cost1;
            ans += 1LL*need2*cost2;
        }
        return ans;
    }
};