class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        result_list = []
        counter = collections.Counter(candidates)
        value_count = list(counter.items())
        value_count.sort(key=lambda tup : -tup[0])
        n = len(value_count)

        selected_list = []
        
        def dfs(pos, now_sum):
            if now_sum == target:
                result_list.append(selected_list[::])
            elif pos < n:
                value, occurred_times = value_count[pos]
                times = 0
                while times <= occurred_times and now_sum + times * value <= target:
                    dfs(pos + 1, now_sum + times * value)
                    selected_list.append(value)
                    times += 1
                while times > 0:
                    selected_list.pop()
                    times -= 1
        

        dfs(0, 0)
        return result_list
