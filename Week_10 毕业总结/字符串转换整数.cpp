class Solution {
public:
    int myAtoi(string s) {
        int sign = 1, temp = 0, i = 0;
        
        while(s[i] == ' ') i++; // 忽略前导空格

        if (s[i] == '+' || s[i] == '-') //确定正负号
            sign = (s[i++] == '-') ? -1 : 1;

        while(s[i] >= '0' && s[i] <= '9') {
            //判断是否溢出INT_MAX = 2^31 = 2147483647
            if (temp > INT_MAX / 10 || (temp == INT_MAX / 10 && s[i] - '0' > 7)) 
                return sign == 1 ? INT_MAX : INT_MIN;
            temp = temp * 10 + (s[i++] - '0');
        }
        return temp * sign;
    }
};