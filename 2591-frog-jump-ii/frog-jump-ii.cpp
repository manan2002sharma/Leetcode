class Solution {
public:

    int maxJump(vector<int>& stones) {
        int n=stones.size();
        int jump=stones[0]-stones[1];
        for(int i=0;i<n-2;i++){
            jump=max(jump,stones[i+2]-stones[i]);
        }
        jump=max(jump,stones[n-1]-stones[n-2]);
        return jump;
    }
};