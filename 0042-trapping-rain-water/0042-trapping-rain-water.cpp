class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> rightMaxHeight(height.size());
        for(int i=height.size()-1,maxHeight=0;i>=0;i--){
            rightMaxHeight[i]=maxHeight;
            maxHeight=max(height[i],maxHeight);
        }
        int ans=0;
        for(int i=0,maxHeight=0;i<height.size();i++){
            int trappedWaterAtCurrentPosition=max(0, min(maxHeight,rightMaxHeight[i])-height[i]);
            ans+=trappedWaterAtCurrentPosition;
            maxHeight=max(height[i],maxHeight);
        }
        return ans;
    }
};