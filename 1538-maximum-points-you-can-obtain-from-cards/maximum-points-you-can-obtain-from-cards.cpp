class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int total=0;
        for(int i=0;i<k;i++){
            total+=arr[i];
        }
        int currtotal=total;
        int i=k-1;
        int j=arr.size()-1;
        while(i>=0){
            currtotal-=arr[i];
            currtotal+=arr[j];
            i--;
            j--;
            total=max(total,currtotal);
        }
        return total;
    }
};