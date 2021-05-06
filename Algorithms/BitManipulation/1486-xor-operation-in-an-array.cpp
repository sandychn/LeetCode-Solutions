class Solution {
public:
    int xorOperation(int n, int start) {
        int x = start >> 1;
        int y = isOdd(n) && isOdd(start);
        return ((sumXor(x - 1) ^ sumXor(x + n - 1)) << 1) | y;
    }

    int sumXor(int n) {
        // return (0 xor 1 xor 2 xor ... xor n)

        // 4k xor (4k + 1) xor (4k + 2) xor (4k + 3) == 0, (k is integer)

        // let n = 4k, then
        // sumXor(4k + 0) = 4k
        // sumXor(4k + 1) = sumXor(4k + 0) xor (4k + 1) = 1
        // sumXor(4k + 2) = sumXor(4k + 1) xor (4k + 2) = 4k + 3
        // sumXor(4k + 3) = sumXor(4k + 2) xor (4k + 3) = 0

        // sumXor(n) = n         if n = 4k
        // sumXor(n) = 1         if n = 4k + 1
        // sumXor(n) = n + 1     if n = 4k + 2
        // sumXor(n) = 0         if n = 4k + 3

        if (n <= 0) return 0;
        switch (n % 4) {
            case 0:
                return n;
            case 1:
                return 1;
            case 2:
                return n + 1;
            case 3:
                return 0;
        }
        return -1;
    }

    bool isOdd(int n) {
        return n & 1;
    }
};
