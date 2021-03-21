class Solution {
public:
    int climbStairs(int n) {
        /*
        int last=0,ans=1,temp;
        for (int i = 1;i<n+1;i++)
        {
            temp = ans;
            ans = ans +last;
            last = temp;
        }
        return ans;
        */
        /*
        int a = 1, b = 1;
        while (--n) //n--,会报溢出
            a = (b += a) - a; 
        return b;   //n--，如果不报错则返回a
        */
        int a = 1, b = 0;
        digui(n, a, b);
        return a;
    }

    void digui(int& n, int& cur, int& last) {
        if (n == 0) return;
        n -- ;
        int a = cur;
        cur += last;
        last = a;
        return digui(n,  cur, last);
    }
};