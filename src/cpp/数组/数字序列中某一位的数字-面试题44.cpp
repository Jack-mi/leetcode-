class Solution {
public:
    string num2str(int n) {
        char str[10];
        sprintf(str, "%d", n);
        return string(str);
    }
    int findNthDigit(long n) {
        if (n==0)
            return 0;
        int start = 1;
        int digit = 1;
        long count = 9;
        while (n > count) {
            n -= count;
            digit++;
            start *= 10;
            count = 9*start*digit;
        }
        int number = start+(n-1)/digit;
        string real = num2str(number);
        return real[(n-1)%digit] - '0';
    }
};