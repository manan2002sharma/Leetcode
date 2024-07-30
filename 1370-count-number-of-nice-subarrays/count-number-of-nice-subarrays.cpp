class Solution {
public:
    int find(vector<int>& nums, int k){
        int l=0;
        int r=0;
        int ans=0;
        int oddcount=0;
        while(r<nums.size()){
            if(nums[r]%2!=0) oddcount++;
            while(oddcount>k){
                if(nums[l]%2!=0) oddcount--;
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return find(nums,k)-find(nums,k-1);
    }
};