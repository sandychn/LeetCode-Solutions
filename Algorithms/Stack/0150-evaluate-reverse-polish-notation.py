class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        num_stack = []
        for token in tokens:
            if token in "+-*/":
                num2, num1 = num_stack.pop(), num_stack.pop()
                if token == "+":
                    num_stack.append(num1 + num2)
                elif token == "-":
                    num_stack.append(num1 - num2)
                elif token == "*":
                    num_stack.append(num1 * num2)
                elif token == "/":
                    if num1 % num2 != 0 and num1 * num2 < 0:
                        num_stack.append(num1 // num2 + 1)
                    else:
                        num_stack.append(num1 // num2)
            else:
                num_stack.append(int(token))
        return num_stack.pop()
