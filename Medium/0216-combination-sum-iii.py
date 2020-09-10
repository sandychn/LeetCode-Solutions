class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = []
        selected_list = []
        
        def dfs(number_need, now_sum, max_number_used):
            if number_need == 0:
                if now_sum == n:
                    res.append(selected_list.copy())
                return
            
            for i in range(max_number_used + 1, min(10, n - now_sum + 1)):
                selected_list.append(i)
                dfs(number_need - 1, now_sum + i, i)
                selected_list.pop()
        
        dfs(k, 0, 0)
        return res
