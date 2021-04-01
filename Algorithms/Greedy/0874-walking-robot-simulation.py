class Solution:

    dirs = ((0, 1), (1, 0), (0, -1), (-1, 0))

    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        ans = 0
        curDir = 0
        obstacles_set = set(map(tuple, obstacles))
        pos = (0, 0)
        for command in commands:
            if command == -2:
                curDir = (curDir + 3) % 4  # (curDir - 1 + 4) % 4
            elif command == -1:
                curDir = (curDir + 1) % 4
            else:
                nextPos = tuple(map(sum, zip(pos, Solution.dirs[curDir])))
                while command > 0 and nextPos not in obstacles_set:
                    pos = nextPos
                    nextPos = tuple(map(sum, zip(pos, Solution.dirs[curDir])))
                    ans = max(ans, pos[0] ** 2 + pos[1] ** 2)
                    command -= 1
        return ans
