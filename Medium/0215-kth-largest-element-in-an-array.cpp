class Solution {
public:
    Solution() {
        srand(time(nullptr));
    }

    int partition(vector<int>& nums, int l, int r) {
        int rdPos = rand() % (r - l + 1) + l;
        int pivot = nums[rdPos];
        swap(nums[rdPos], nums[r]);
        int p = l - 1;
        for (int i = l; i < r; i++) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[++p]);
            }
        }
        swap(nums[r], nums[++p]);
        return p;
    }


    void quickSelect(vector<int>& nums, int l, int r, int k) {
        int pivotPos = partition(nums, l, r);
        while (pivotPos != k) {
            if (pivotPos < k) {
                l = pivotPos + 1;
            } else {
                r = pivotPos - 1;
            }
            pivotPos = partition(nums, l, r);
        }
        
        // 递归写法为
        // if (pivotPos < k)
        //     quickSelect(nums, pivotPos + 1, r, k);
        // else if (pivotPos > k)
        //     quickSelect(nums, l, pivotPos - 1, k);
        // 或: 
        // if (pivotPos - l > k) {
        //     quickSelect(nums, l, pivotPos - 1, k);
        // } else if (pivotPos - l < k) {
        //     quickSelect(nums, pivotPos + 1, r, k - pivotPos + l - 1);
        // }
    }

    int findKthLargest(vector<int>& nums, int k) {
        const int N = nums.size();

        quickSelect(nums, 0, N - 1, N - k);
        return nums[N - k];
    }
};
