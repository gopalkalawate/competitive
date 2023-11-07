#define M 1000000007 
class Solution{
    public:
    int maxInversion(int A,int B,int C)
    {
        // code here
        ll ans = ((A%M)*(B%M))%M + ((B%M)*(C%M))%M + (((B%M)*((B-1)%M))%M)/2;
        
        return ans;
    }
};