class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {

        double res = 0.000 ;
        for (int i = 0 ; i < points.size() ; ++i) {
            for (int j = i + 1 ; j < points.size() ; ++j) {
                for (int k = j + 1 ; k < points.size() ; ++k) {
                    double x1 = points[j][0] - points[i][0] , x2 = points[k][0] - points[i][0] ;
                    double y1 = points[j][1] - points[i][1] , y2 = points[k][1] - points[i][1] ;
                    res = max(res , 0.5 * abs(x1 * y2 - x2 * y1)) ;
                }
            }
        }
        return res ;
    }
};