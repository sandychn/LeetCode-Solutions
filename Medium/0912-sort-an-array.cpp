// quick sort (44 ms, 16 MB)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        srand(time(NULL));
        quickSort(nums, 0, int(nums.size()) - 1);
        return nums;
    }
private:
    int randRange(int a, int b) {
        return 1LL * rand() * rand() % (b - a + 1) + a;
    }

    void quickSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int pos = randRange(l, r);
        swap(nums[pos], nums[r]);

        int pivot = nums[r];
        int lastSmallThanPivot = l - 1;

        for (int j = l; j < r; j++) {
            if (nums[j] <= pivot) {
                swap(nums[++lastSmallThanPivot], nums[j]);
            }
        }
        swap(nums[++lastSmallThanPivot], nums[r]);

        quickSort(nums, l, lastSmallThanPivot - 1);
        quickSort(nums, lastSmallThanPivot + 1, r);
    }
};

// merge sort (52 ms, 16.1 MB)
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, int(nums.size()) - 1);
        return nums;
    }

    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int p = l, q = mid + 1;
        for (int i = l; i <= r; i++) {
            if (q > r || (p <= mid && nums[p] <= nums[q])) tmp[i] = nums[p++];
            else tmp[i] = nums[q++];
        }
        for (int i = l; i <= r; i++) nums[i] = tmp[i];
    }

private:
    int tmp[50005];
};
