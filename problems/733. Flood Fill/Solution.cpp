class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        stack<pair<int, int>> toFill;
        // Check if the origin is already color and add its neighbors if not
        if (image[sr][sc] == color) return image;
        toFill.push(make_pair(sr, sc));
        int initialColor = image[sr][sc];
        while (!toFill.empty()) {
            auto top = toFill.top();
            toFill.pop();
            image[top.first][top.second] = color;
            // Add its neighbors
            if (top.first > 0 && image[top.first - 1][top.second] == initialColor)
                toFill.push(make_pair(top.first - 1, top.second));
            if (top.first < image.size() - 1 && image[top.first + 1][top.second] == initialColor)
                toFill.push(make_pair(top.first + 1, top.second));
            if (top.second > 0 && image[top.first][top.second - 1] == initialColor)
                toFill.push(make_pair(top.first, top.second - 1));
            if (top.second < image[0].size() - 1 && image[top.first][top.second + 1] == initialColor)
                toFill.push(make_pair(top.first, top.second + 1));
        }
        return image;
    }
};