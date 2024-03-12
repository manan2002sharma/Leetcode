class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=nums[0];
        int second=INT_MIN;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=first) first=nums[i];
            else if(nums[i]<=second||second==INT_MIN) second=nums[i];
            else return true; 
        }
        return false;
    }
};