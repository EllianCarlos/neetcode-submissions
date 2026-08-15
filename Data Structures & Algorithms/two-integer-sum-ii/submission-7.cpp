class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 1; i < numbers.size(); ++i) {
            int index = lb(numbers, target - numbers[i], 0, i);

            if (index != i && numbers[index] + numbers[i] == target) {
               return {index + 1, i + 1};
            }
        }

        return {};
    }
private:
    int lb(const vector<int>& arr, const int& target, int l, int r) {
        while (l < r) {
            int mid = l + ((r-l)/2);
            if (arr[mid] > target) {
                r = mid;
            } else if (arr[mid] < target) {
                l = mid + 1;
            } else {
                return mid;
            }
        }

        return l;
    }
};
