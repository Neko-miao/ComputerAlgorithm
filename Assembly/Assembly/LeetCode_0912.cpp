#include <vector>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        return Solution3_quick(nums);
    }

private:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    /*
    
    */
    vector<int> Solution0_bubble(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j < nums.size() - i; j++) {
                if (nums[j] < nums[j - 1]) {
                    swap(nums[j], nums[j - 1]);
                }
            }
        }
        return nums;
    }

    vector<int> Solution1_select(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int maxIndex = 0;
            for (int j = 1; j < nums.size() - i; j++) {
                if (nums[j] > nums[maxIndex]) {
                    maxIndex = j;
                }
                swap(nums[nums.size() - i - 1], nums[maxIndex]);
            }
        }
        return nums;
    }

    vector<int> Solution2_insert(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            for (int j = i; j > 0; j--) {
                if (nums[j] < nums[j - 1]) {
                    swap(nums[j], nums[j - 1]);
                }
            }
        }

        return nums;
    }

    int partition(vector<int>& nums, int start, int end) {
        int pivot = nums[start];
        int i = start + 1;
        int j = end;
        while (i <= j) {
            while (i <= end && nums[i] <= pivot) i++;
            while (nums[j] > pivot) j--;
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[j], nums[start]);
        return j;
    }

    void quickSorting(vector<int>& nums, int start, int end) {
        if (start >= end)
            return;

        int j = partition(nums, start, end);
        quickSorting(nums, start, j - 1);
        quickSorting(nums, j + 1, end);
    }

    vector<int> Solution3_quick(vector<int>& nums) {
        quickSorting(nums, 0, nums.size() - 1);
        return nums;
    }

    vector<int> Solution4_shell(vector<int>& nums) {

    }

    vector<int> Solution5_merge(vector<int>& nums) {

    }

    void _setupHeapOnce0(vector<int>& nums, int start, int end) {
        if (start >= end)
            return;
        int n = end;
        int p = (n - 1) / 2;
        while (p >= 0 && nums[p] < nums[n]) {
            swap(nums[p], nums[n]);
            n = p;
            p = (n - 1) / 2;
        }
    }

    void _setupHeapOnce1(vector<int>& nums, int start, int end) {
        if (start >= end)
            return;
        int p = start;
        int l = p * 2 + 1;
        int r = p * 2 + 2;
        while ((l <= end && nums[l] > nums[p]) || (r <= end && nums[r] > nums[p])) {
            if (r > end || nums[l] > nums[r]) {
                swap(nums[p], nums[l]);
                p = l;
            }
            else {
                swap(nums[p], nums[r]);
                p = r;
            }
            l = p * 2 + 1;
            r = p * 2 + 2;
        }
    }

    void setupHeap(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            _setupHeapOnce0(nums, 0, i);
        }
    }

    vector<int> Solution6_heap(vector<int>& nums) {
        setupHeap(nums);
        for (int i = nums.size() - 1; i > 0; i--) {
            swap(nums[0], nums[i]);
            _setupHeapOnce1(nums, 0, i - 1);
        }
        return nums;
    }

    vector<int> Solution7_counting(vector<int>& nums) {
        const int LEN = 1e5 + 1;
        const int MIN = -5e4;
        int countArray[LEN];
        memset(countArray, 0, sizeof(countArray));
        for (int i = 0; i < nums.size(); i++) {
            countArray[nums[i] - MIN] += 1;
        }

        vector<int> result;
        for (int i = 0; i < LEN; i++) {
            if (countArray[i] > 0) {
                int count = countArray[i];
                while (count) {
                    result.push_back(i + MIN);
                    count--;
                }
            }
        }
        return result;
    }

    vector<int> Solution8_bucket(vector<int>& nums) {

    }
    vector<int> Solution9_radix(vector<int>& nums) {
        const int MIN = -5e4;
        const int MAX_DIGIT = 6;
        vector<queue<int>> buckets;
        for (int i = 0; i < 10; i++)
            buckets.push_back(queue<int>());

        for (int i = 0; i < MAX_DIGIT; i++) {
            int base = pow(10, i);
            
            for (int i = 0; i < nums.size(); i++) {
                buckets[((nums[i] - MIN) / base) % 10].push(nums[i]);
            }

            int k = 0;
            for (int i = 0; i < 10; i++) {
                while (!buckets[i].empty()) {
                    nums[k++] = buckets[i].front();
                    buckets[i].pop();
                }
            }
        }
        return nums;
    }
};


int main() {
    Solution solution = Solution();
    vector<int> test;
    test.push_back(5);
    test.push_back(2);
    test.push_back(3);
    test.push_back(1);

    solution.sortArray(test);

    for (int i : test) {
        cout << "  " << i;
    }
    return 0;
}