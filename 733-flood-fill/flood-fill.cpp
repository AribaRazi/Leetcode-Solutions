class Solution {
public:
    // base case
 void dfs(int i, int j, vector<vector<int>>& image,
             int original, int color, int r, int c) {

        // Base case
        if (i < 0 || j < 0 || i >= r || j >= c ||
            image[i][j] != original) {
            return;
        }

        // Recolor the current cell
        image[i][j] = color;

        // Explore all 4 directions
        dfs(i, j - 1, image, original, color, r, c); // left
        dfs(i, j + 1, image, original, color, r, c); // right
        dfs(i - 1, j, image, original, color, r, c); // top
        dfs(i + 1, j, image, original, color, r, c); // bottom
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int r=image.size();
        int c=image[0].size();
        
        int original=image[sr][sc];
        if (original == color)
            return image;
        
        dfs(sr,sc,image,original,color,r,c);
        // cout<<count;
        return image;
    }
};