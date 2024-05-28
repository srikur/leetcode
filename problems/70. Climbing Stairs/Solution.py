class Solution:
    def climbStairs(self, n: int) -> int:
        steps = [0] * 2
        steps[0] = 1
        steps[1] = 1
        for i in range(2, n + 1):
            current_steps = steps[0] + steps[1]
            steps[0] = steps[1]
            steps[1] = current_steps
        return steps[-1]