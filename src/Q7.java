public class Q7 {
    public int reverse(int x) {
        int ans = 0;
        while(x != 0) {
            int pop = x%10;
            x /= 10;
            // 1、这个比较要在最后一个等式之前放出来
            // 2、之所以要用max/10而不是ans*10，是考虑到当ans*10<max，而加上pop后又>max的情况
            if(ans>Integer.MAX_VALUE/10||ans==Integer.MAX_VALUE&&pop>Integer.MAX_VALUE%10)
                return 0;
            if(ans<Integer.MIN_VALUE/10||ans==Integer.MIN_VALUE&&pop<Integer.MIN_VALUE%10)
                return 0;
            ans = ans*10 + pop;
        }
        return ans;
    }
}
