class Solution {
    public double largestTriangleArea(int[][] points) {
        // 面积 = 两个向量外积模的一半 
        // 暴力三重循环即可
        if ((points.length) == 0 || (points[0].length) == 0) return 0;
        int n = points.length, m = points[0].length;
        double res = 0, tmp = 0;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = 0; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                for (int k = 0; k < n; k++) {
                    int x3 = points[k][0], y3 = points[k][1];
                    
                    tmp = Math.abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1));
                    res = Math.max(res, tmp);
                }
            }
        }
        return res / 2;
    }
}