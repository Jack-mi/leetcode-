import java.util.ArrayList;
import java.util.List;

public class Q9 {
    public boolean isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
//        List<Integer> arr = new ArrayList<Integer>();
        int[] arr = new int[20];
        int index = 0;
        while (x != 0) {
            int pop = x%10;
            x /= 10;
            arr[index++] = pop;
//            arr.add(pop);
        }
//        int len = arr.size();
        int len = index;
        for (int i = 0;i < len/2;i ++) {
//            if (arr.get(i) != arr.get(len-1-i)) {
//                return false;
//            }
            if (arr[i] != arr[len-1-i]) {
                return false;
            }
        }
        return true;
    }
}
