class Solution {
public:
    int addDigits(int num) {
        long ans=(long)num;
        while(ans>=10)
        {
            long sum=0;
            while(ans>0)
            {
                sum+=ans%10;
                ans/=10;
            }
            ans=sum;
        }
        return (int)ans;
    }
};
