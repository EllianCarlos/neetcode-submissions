class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        while (l < r) {
            if (numbers[l] + numbers[r] < target) {
                l++;
            }

            if (numbers[l] + numbers[r] > target) {
                r--;
            }

            if (numbers[l] + numbers[r] == target) {
                return {l + 1, r + 1};
            }
        }

        return {l + 1, r + 1};
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
