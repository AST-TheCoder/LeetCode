class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        for(int i=0, j=height.size()-1, mx=0; i<j;){
            if(height[i]<mx){
                i++;
                continue;
            }
            mx=height[i];
            if(height[j]<mx){
                j--;
                continue;
            }
            ans=max(ans,(j-i)*height[i]);
            i++;
        }
        for(int i=0, j=height.size()-1, mx=0; i<j;){
            if(height[j]<mx){
                j--;
                continue;
            }
            mx=height[j];
            if(height[i]<mx){
                i++;
                continue;
            }
            ans=max(ans,(j-i)*height[j]);
            j--;
        }
        return ans;
    }
};