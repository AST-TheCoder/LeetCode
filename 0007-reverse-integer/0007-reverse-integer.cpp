class Solution {
public:
    int reverse(int x) {
        bool sign = (x<0);
        int ans=0;
        
        if(sign){
            while(x){
                if(ans>=-214748364) ans*=10;
                else return 0;
                int digit=x%10;
                if(ans>=-2147483648-digit) ans+=digit;
                else return 0;
                x/=10;
            }
        }
        else{
            while(x){
                if(ans<=214748364) ans*=10;
                else return 0;
                int digit=x%10;
                if(ans<=2147483647-digit) ans+=digit;
                else return 0;
                x/=10;
            }    
        }
        return ans;
    }
};