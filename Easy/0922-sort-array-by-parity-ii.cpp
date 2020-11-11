class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        return solver2(A);
    }

    vector<int> solver1(vector<int>& A) {
        vector<int> cnt(1005);

        int n = A.size();
        for (int i = 0; i < n; i++) ++cnt[A[i]];

        int even = 0, odd = 1;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                while (cnt[odd] == 0) odd += 2;
                --cnt[odd];
                A[i] = odd;
            } else {
                while (cnt[even] == 0) even += 2;
                --cnt[even];
                A[i] = even;
            }
        }

        return A;
    }
    
    vector<int> solver2(vector<int>& A) {
        int n = A.size();
        int p = 0, q = 1;
        
        while (p < n && q < n) {
            while (p < n && !(A[p] & 1)) p += 2;
            while (q < n && (A[q] & 1)) q += 2;
            if (p < n && q < n) {
                swap(A[p], A[q]);
                p += 2, q += 2;
            }
        }
        
        return A;
    }
};
