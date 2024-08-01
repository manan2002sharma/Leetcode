class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int st=newInterval[0];
        int end=newInterval[1];
        int i=0;
        while(i<intervals.size()&&intervals[i][1]<st){    
            ans.push_back(intervals[i]);
            i++;
        }
        if(i==intervals.size()){
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<int> newinterval;
        newinterval.push_back(min(st,intervals[i][0]));
        

        while(i<intervals.size()&&end>=intervals[i][0]){
            end=max(end,intervals[i][1]);
            i++;
        }
        newinterval.push_back(end);
        ans.push_back(newinterval);
        while(i<intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
        // if(end>=intervals[i][0]){
        //     newinterval.push_back(max(end,intervals[i][1]));
        //     end=max(end,intervals[i][1]);
        // }else{
        //     newinterval.push_back(end);
        // }
        // ans.push_back(newinterval);

    }
};