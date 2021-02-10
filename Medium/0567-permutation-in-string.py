class Solution:
    def getId(self, s: str) -> int:
        return ord(s) - ord("a")


    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
        s1_counter = [0] * 26
        s2_counter = [0] * 26
        for ch in s1:
            s1_counter[self.getId(ch)] += 1
        i = j = 0
        same_freq_count = sum(not bool(x) for x in s1_counter)
        while j < len(s2):
            j_ch_id = self.getId(s2[j])
            same_freq_count -= int(s1_counter[j_ch_id] == s2_counter[j_ch_id])
            s2_counter[j_ch_id] += 1
            same_freq_count += int(s1_counter[j_ch_id] == s2_counter[j_ch_id])
            while i <= j and s1_counter[j_ch_id] < s2_counter[j_ch_id]:
                i_ch_id = self.getId(s2[i])
                same_freq_count -= int(s1_counter[i_ch_id] == s2_counter[i_ch_id])
                s2_counter[i_ch_id] -= 1
                same_freq_count += int(s1_counter[i_ch_id] == s2_counter[i_ch_id])
                i += 1
            if same_freq_count == 26 and j - i + 1 == len(s1):
                return True
            j += 1
        return False
