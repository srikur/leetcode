class Solution:
    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        if image[sr][sc] == color: return image
        initialColor = image[sr][sc]
        stack = [(sr, sc)]
        while len(stack) > 0:
            x, y = stack.pop()
            image[x][y] = color
            if (x > 0) and (image[x - 1][y] == initialColor):
                stack.append((x - 1, y))
            if (x < len(image) - 1) and (image[x + 1][y] == initialColor):
                stack.append((x + 1, y))
            if (y > 0) and (image[x][y - 1] == initialColor):
                stack.append((x, y - 1))
            if (y < len(image[0]) - 1) and (image[x][y + 1] == initialColor):
                stack.append((x, y + 1))
        return image
