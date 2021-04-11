class Solution:
    def nthUglyNumber(self, n: int) -> int:
        heap = [1]
        elements = {1}
        for _ in range(n - 1):
            p = heapq.heappop(heap)
            for q in (2, 3, 5):
                r = p * q
                if r not in elements:
                    elements.add(r)
                    heapq.heappush(heap, r)
        return heapq.heappop(heap)
