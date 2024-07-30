class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> st;
        int total=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            if(total==goal) ans++;
            if(total>=goal&&st.find(total-goal)!=st.end()){
                ans+=st[total-goal];
            }
            st[total]++;
        }
        return ans;

    }
};