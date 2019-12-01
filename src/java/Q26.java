package java;

class Q26 {
    public int removeDuplicates(int[] nums) {
        int i = 0;
        int ans = 1;
        for (int j = 1;j < nums.length; j++) {
            if (nums[i] != nums[j]) {
                nums[ans++] = nums[j];
                i = j;
            }
        }
        return ans;
    }
}