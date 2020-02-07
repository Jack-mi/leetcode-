// https://www.nowcoder.com/practice/9f3231a991af4f55b95579b44b7a01ba
class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int l = 0;
        int r = rotateArray.size()-1;
        while (l < r) {
            int mid = (l+r) /2;
            int v = rotateArray[mid];
            // 判断条件是：当前mid是最小值的前一个值
            if (v > rotateArray[mid+1])
                return rotateArray[mid+1];
            // 此时v和v前面的值都相等，都和mid比较过了不对，+1
            else if (v >= rotateArray[0])
                l = mid+1;
            // 很显然是旋转情况的后半数组，此时v可能是min，所以mid不能+1
            else
                r = mid;
        }
        return rotateArray[l];
    }
};