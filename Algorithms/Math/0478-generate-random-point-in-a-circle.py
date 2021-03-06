class Solution:

    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center

    def randPoint(self) -> List[float]:
        return self.solveByDistribution()

    def solveByRejectionSampling(self) -> List[float]:
        # random.uniform(a, b) -> Get a random number in the range [a, b) or [a, b] depending on rounding.
        while True:
            x, y = random.uniform(-1, 1), random.uniform(-1, 1)
            if x * x + y * y <= 1.0:
                return [self.x_center + x * self.radius, self.y_center + y * self.radius]

    def solveByDistribution(self) -> List[float]:
        # random.random() -> x in the interval [0, 1).
        radius = math.sqrt(random.random()) * self.radius
        theta = random.random() * math.pi * 2.0
        return [self.x_center + radius * math.cos(theta), self.y_center + radius * math.sin(theta)]

# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()
