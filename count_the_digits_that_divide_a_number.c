class Solution {
public:
    int countDigits(int num) {
        int count=0;
        int div=num;
        int temp=num;
            int digit;
        while(temp>0)
        {
            digit=temp%10;
            temp/=10;
            if(div % digit==0){
                count++;
            }
        }
        return count;

    }
};
