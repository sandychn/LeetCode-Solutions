class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        version1_parts = list(map(int, version1.split(".")))
        version2_parts = list(map(int, version2.split(".")))
        version1_parts += [0] * max(0, len(version2_parts) - len(version1_parts))
        version2_parts += [0] * max(0, len(version1_parts) - len(version2_parts))
        if version1_parts > version2_parts:
            return 1
        if version1_parts < version2_parts:
            return -1
        return 0
