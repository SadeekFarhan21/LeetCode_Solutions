import random
class Solution:

    def __init__(self, w: List[int]):
        self.w = w
        self.denominator = sum(w)
        self.probability = [i / self.denominator for i in w]


    def pickIndex(self) -> int:
        return random.choices(range(len(self.w)), weights = self.probability, k = 1)[0]


# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()