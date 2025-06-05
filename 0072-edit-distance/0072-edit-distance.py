class Solution:
    def minDistance(self, word1: str, word2: str) -> int:

        if len(word1) < len(word2):
            word1, word2 = word2, word1

        if len(word2) == 0:
            return len(word1)

        dp = [len(word2) - c for c in range(len(word2))]

        for r in range(len(word1) - 1, -1, -1):
            bottomRight = len(word1) - r - 1
            right = bottomRight + 1
            for c in range(len(word2) - 1, -1, -1):
                below = dp[c]
                if word1[r] == word2[c]:
                    dp[c] = bottomRight
                else:
                    replace = bottomRight
                    _delete = below
                    add = right

                    best = min(replace, _delete, add)
                    dp[c] = best + 1

                bottomRight = below
                right = dp[c]

        return dp[0]
