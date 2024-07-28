class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int bigsum=0;
        int smallsum=0;
        for(auto i: nums){
            if(i<10) smallsum+=i;
            else bigsum+=i;
        }
        if(bigsum==smallsum) return false;
        return true;
    }
};