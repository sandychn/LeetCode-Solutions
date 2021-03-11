class Solution:
    def calculate(self, s: str) -> int:
        priority = {"+": 1, "-": 1, "*": 2, "/": 2}
        calculators = {
            "+": lambda a, b: a + b,
            "-": lambda a, b: a - b,
            "*": lambda a, b: a * b,
            "/": lambda a, b: a // b
        }
        number_stack = []
        operator_stack = []
        idx, length = 0, len(s)
        while idx < length:
            if s[idx].isdigit():
                number = 0
                while idx < length and s[idx].isdigit():
                    number = number * 10 + int(s[idx])
                    idx += 1
                number_stack.append(number)
            elif s[idx] in calculators:
                while operator_stack and priority[operator_stack[-1]] >= priority[s[idx]]:
                    n2, n1 = number_stack.pop(), number_stack.pop()
                    op = operator_stack.pop()
                    number_stack.append(calculators[op](n1, n2))
                operator_stack.append(s[idx])
                idx += 1
            else:
                idx += 1
        while operator_stack:
            n2, n1 = number_stack.pop(), number_stack.pop()
            op = operator_stack.pop()
            number_stack.append(calculators[op](n1, n2))
        return number_stack.pop()
