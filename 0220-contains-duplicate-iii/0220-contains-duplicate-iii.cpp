class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        unordered_map<int,int> bucket;
        for(int i=0;i<nums.size();i++){
            int bucketId=nums[i]/(valueDiff+1)-(nums[i]<0);
            if(bucket[bucketId] && i-bucket[bucketId]<indexDiff) return true;
            if(bucket[bucketId-1] && i-bucket[bucketId-1]<indexDiff && abs(nums[i]-nums[bucket[bucketId-1]-1])<=valueDiff) return true;
            if(bucket[bucketId+1] && i-bucket[bucketId+1]<indexDiff && abs(nums[i]-nums[bucket[bucketId+1]-1])<=valueDiff) return true;
            bucket[bucketId]=i+1;
        }
        return false;
    }
};