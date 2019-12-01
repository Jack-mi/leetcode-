package java;

public class Q27 {
    public int removeElement(int[] nums, int val) {
        int ans = 0;
        for (int j = 0; j < nums.length; j++) {
            if (nums[j] != val) {
                nums[ans++] = nums[j];
            }
        }
        return ans;
    }
}
