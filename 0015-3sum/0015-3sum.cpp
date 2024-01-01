class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> arr, v;
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i>=2 && !nums[i] && !nums[i-2] && ans.empty()){
                vector<int> temp;
                temp.push_back(0);
                temp.push_back(0);
                temp.push_back(0);
                ans.push_back(temp);
            }
            if(i && nums[i]==nums[i-1]){
                if((v.empty() || v[v.size()-1]!=nums[i]) && nums[i]) v.push_back(nums[i]);
                continue;
            }
            arr.push_back(nums[i]);
        }
        
        for(int i=0;i<(int)arr.size();i++){
            for(int j=i+1,k=arr.size()-1;j<k;){
                int sum = arr[i] + arr[j] + arr[k];
                if(!sum){
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(arr[j]);
                    temp.push_back(arr[k]);
                    ans.push_back(temp);
                    j++,k--;
                }
                else if(sum>0) k--;
                else j++;
            }
            for(int j=0;j<v.size();j++){
                int sum = 2*v[j]+arr[i]; 
                //cout<<v[j]<<" "<<arr[i]<<" "<<sum<<endl;
                if(!sum){
                    vector<int> temp;
                    temp.push_back(arr[i]);
                    temp.push_back(v[j]);
                    temp.push_back(v[j]);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};