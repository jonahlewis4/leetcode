class Solution:
    def isValid(self, s: str) -> bool:
        map: dict[int, int] = {
            ord('('):ord(')'),
            ord('{'):ord('}'),
            ord('['):ord(']'),
        }

        stack : list[str] = []

        for char in s:
            c: int = ord(char)
            if c in map:
                stack.append(c)
            elif (len(stack) == 0 or map[stack[-1]] != c):
                return False
            else : 
                stack.pop()
        
        return len(stack) == 0
                


