#include<iostream>
#include<vector>
#include<utility>
#include<cmath>

using namespace std;

double max_distance(vector<pair<double, double> > points, double dist) {
    double max = 0;
    for (int i = 0; i < points.size(); i++) {
        double distance = sqrt(pow((dist - points[i].first), 2) + pow((0 - points[i].second), 2));
        if (distance > max) {
            max = distance;
        }
    }
    return max;
}

int main() {

    int num_points;
    while (cin >> num_points) {
        if (num_points == 0) {
            break;
        }

        int i;
        vector<pair<double, double> > pts;
        double precision = 1e-5;
        double right = 200001;
        double left = -200001;

        for (i = 0; i < num_points; i++) {
            double x, y;
            cin >> x >> y;
            pts.push_back(make_pair(x, y));

            if (x > right) {
                right = x;
            } else if (x < left) {
                left = x;
            }
        }
        
        double mid1; 
        double mid2;
        double m1_dist;
        double m2_dist;

        while (right - left > precision) {
            mid1 = left + ((right - left) / 3);
            mid2 = left + (((right - left) * 2) / 3);

            m1_dist = max_distance(pts, mid1);
            m2_dist = max_distance(pts, mid2);

            if (m1_dist > m2_dist) {
                left = mid1;
            } else {
                right = mid2;
            }
        }

        double final_time = max_distance(pts, right);
        cout.precision(20);
        cout << fixed << right << " " << final_time << endl;
    }
    return 0;
}