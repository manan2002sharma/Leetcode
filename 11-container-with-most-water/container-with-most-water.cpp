class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int maxArea=min(height[l],height[r])*(r-l);
        while(l<r){
            
            if(maxArea<min(height[l],height[r])*(r-l)) maxArea=min(height[l],height[r])*(r-l);
        
            if(height[l]<height[r]){
                l++;
            }
            else if(height[l]>height[r]){
                r--;
            }else l++;
            
        }
        return maxArea;

    }
};