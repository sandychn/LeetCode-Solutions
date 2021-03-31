class Solution:
    def clumsy(self, N: int) -> int:
        stack = [N]
        op = 0
        for i in range(N - 1, 0, -1):
            if op == 0:
                stack.append(stack.pop() * i)
            elif op == 1:
                stack.append(self.do_div(stack.pop(), i))
            elif op == 2:
                stack.append(i)
            elif op == 3:
                stack.append(-i)
            op = (op + 1) % 4
        return sum(stack)

    def do_div(self, x: int, y: int) -> int:
        if x * y < 0 and x % y != 0:
            return x // y + 1
        return x // y
