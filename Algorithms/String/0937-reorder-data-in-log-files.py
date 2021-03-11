class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        alphas = (log for log in logs if log[log.find(" ") + 1].islower())
        alphas = sorted(alphas, key=lambda s: chr(0).join(reversed(s.split(maxsplit=1))))
        digits = (log for log in logs if log[log.find(" ") + 1].isdigit())
        return [*alphas, *digits]
