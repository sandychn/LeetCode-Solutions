"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""
from typing import List


class Solution:
    def getImportance(self, employees: List['Employee'], eid: int) -> int:
        emps = {employee.id: employee for employee in employees}

        def dfs(eid: int) -> int:
            employee = emps[eid]
            total = 0
            for subordinate in employee.subordinates:
                total += dfs(subordinate)
            total += employee.importance
            return total

        return dfs(eid)
