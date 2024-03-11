class Solution {
public:
    static bool comp(pair<int,int> p1,pair<int,int> p2){
        return p1.first<p2.first;
    }

    int candy(vector<int>& ratings) {
        int candies=0;
        vector<pair<int,int>> sorted_arr;
        for(int i=0;i<ratings.size();i++){
            sorted_arr.push_back({ratings[i],i});
        }
        sort(sorted_arr.begin(),sorted_arr.end(),comp);
        vector<int> candies_given(ratings.size(),0);

        for(int i=0;i<sorted_arr.size();i++){
            int ind=sorted_arr[i].second;
            int candies_to_give=1;
            if(ind>0){
                if(ratings[ind-1]<ratings[ind]){
                    candies_to_give=max(candies_given[ind-1]+1,candies_to_give);
                }
                
            }
            if(ind<candies_given.size()-1){
                if(ratings[ind+1]<ratings[ind]){
                    candies_to_give=max(candies_given[ind+1]+1,candies_to_give);
                }
                
            }
            candies_given[ind]=candies_to_give;
            candies+=candies_to_give;

        }
        return candies;
    }
};