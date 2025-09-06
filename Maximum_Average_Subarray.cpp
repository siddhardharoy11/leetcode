class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long long sum=0;
        for(int i=0;i<k;i++)
        {
           sum+=nums[i]; 
        }
        long long maxsum=sum;
        for(int i=k;i<nums.size();i++)
        {
            sum+=nums[i]-nums[i-k];
            maxsum=max(sum,maxsum);
        }
        return (double)maxsum/k;
    }
};
