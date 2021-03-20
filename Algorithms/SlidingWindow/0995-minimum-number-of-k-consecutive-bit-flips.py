class Solution:
    def minKBitFlips(self, A: List[int], K: int) -> int:
        length = len(A)
        queue = collections.deque()
        filp = ans = 0
        for i, v in enumerate(A):
            if queue and queue[0] == i:
                filp ^= 1
                queue.popleft()
            if (v + filp) % 2 == 0:  # this value needs filp
                if i + K > length:
                    return -1
                ans += 1
                filp ^= 1
                queue.append(i + K)
        return ans
