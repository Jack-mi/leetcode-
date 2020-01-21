class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i(0),j(numbers.size()-1);
        while (i <= j) {
            if (numbers[i] + numbers[j] > target) {
                j--;
                continue;
            }
            else if (numbers[i] + numbers[j] < target) {
                i++;
                continue;
            }
            else {
                return {i+1, j+1};
                break;
            }
        }
        return {-1, -1};
    }
};