class Solution {

    class IntPair {
        final int x;
        final int y;
        IntPair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        if (image[sr][sc] == color) return image;
        Stack<IntPair> stack = new Stack<>();
        stack.push(new IntPair(sr, sc));
        int initialColor = image[sr][sc];
        while (!stack.empty()) {
            IntPair elem = stack.pop();
            image[elem.x][elem.y] = color;
            if (elem.x > 0 && image[elem.x - 1][elem.y] == initialColor)
                stack.push(new IntPair(elem.x - 1, elem.y));
            if (elem.x < image.length - 1 && image[elem.x + 1][elem.y] == initialColor)
                stack.push(new IntPair(elem.x + 1, elem.y));
            if (elem.y > 0 && image[elem.x][elem.y - 1] == initialColor)
                stack.push(new IntPair(elem.x, elem.y - 1));
            if (elem.y < image[0].length - 1 && image[elem.x][elem.y + 1] == initialColor)
                stack.push(new IntPair(elem.x, elem.y + 1));
        }
        return image;
    }
}