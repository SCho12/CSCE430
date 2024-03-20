#include<iostream>
#include<vector>
#include<utility>
#include<cmath>

using namespace std;

int main() {
    int asc_seg;
    int des_seg;
    vector<pair<double, double> > ascending;
    vector<pair<double, double> > descending;

    cin >> asc_seg >> des_seg;

    int i, j;
    double asc_time = 0;
    double des_time = 0;
    double elevation = 0;

    for (i = 0; i < asc_seg; i++) {
        double dist, time;
        cin >> dist >> time;
        elevation += dist;
        asc_time += time;
        ascending.push_back(make_pair(dist, time));
    }

    for (j = 0; j < des_seg; j++) {
        double dist, time;
        cin >> dist >> time;
        des_time += time;
        descending.push_back(make_pair(dist, time));
    }

    double high = max(asc_time, des_time);
    double low = 0;
    double mid; 
    double asc_elevation = 0;
    double des_elevation = 0;

    while ((high - low) > 1e-5) {
        mid = (high + low) / 2;
        asc_elevation = 0;
        des_elevation = elevation;

        double asc_mid = mid;
        double des_mid = mid;

        for (i = 0; i < ascending.size(); i++) {
            double segment_duration = ascending[i].second;
            if (asc_mid >= segment_duration) {
                asc_elevation += ascending[i].first;
                asc_mid -= segment_duration;
            } else {
                if (ascending[i].first > 0) {
                    double speed = ascending[i].first / segment_duration;
                    asc_elevation += speed * asc_mid;
                }
                break;
            }
        }

        for (j = 0; j < descending.size(); j++) {
            double segment_duration = descending[j].second;
            if (des_mid >= segment_duration) {
                des_elevation -= descending[j].first;
                des_mid -= segment_duration;
            } else {
                if (descending[j].first > 0) { 
                    double speed = descending[j].first / segment_duration;
                    des_elevation -= speed * des_mid;
                }
                break;
            }
        }

        if (des_elevation == asc_elevation) {
            high = mid;
        } else if (asc_elevation > des_elevation) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout.precision(6);
    cout << fixed << mid << endl;
    return 0;
}