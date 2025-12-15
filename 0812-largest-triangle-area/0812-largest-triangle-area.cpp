class Solution {
public:
    double distance(double x1, double y1, double x2, double y2){
        return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
    }

    double triangle_area(double x1, double y1, double x2, double y2, double x3, double y3){
        double a = distance(x1, y1, x2, y2);
        double b = distance(x1, y1, x3, y3);
        double c = distance(x2, y2, x3, y3);
        double s = 0.5 * (a + b + c);
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double largestTriangleArea(vector<vector<int>>& points) {
        double answer = 0;
        for(int i = 0; i < points.size(); i++){
            for(int j = i + 1; j < points.size(); j++){
                for(int k = j + 1; k < points.size(); k++){
                    
                        double area = triangle_area(points[i][0], points[i][1], points[j][0], points[j][1], points[k][0], points[k][1]);
                        if(area > answer){
                            answer = area;
                        }
                    
                }
            }
        }
        return answer;
    }
};