#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;
 
typedef pair<double, double> point_t;
typedef pair<point_t, point_t> points_t;
 
double distance_between(const point_t& a, const point_t& b) {
	return sqrt(std::pow(b.first - a.first, 2)
		+ pow(b.second - a.second, 2));
}
 
pair<double, points_t> find_closest_brute(const vector<point_t>& points) {
	if (points.size() < 2) {
		return { -1, { { 0, 0 }, { 0, 0 } } };
	}
	auto minDistance = abs(distance_between(points.at(0), points.at(1)));
	points_t minPoints = { points.at(0), points.at(1) };
	for (auto i = begin(points); i != (end(points) - 1); ++i) {
		for (auto j = i + 1; j < end(points); ++j) {
			auto newDistance = abs(distance_between(*i, *j));
			if (newDistance < minDistance) {
				minDistance = newDistance;
				minPoints.first = *i;
				minPoints.second = *j;
			}
		}
	}
	return { minDistance, minPoints };
}
 
pair<double, points_t> find_closest_optimized(const vector<point_t>& xP,
	const vector<point_t>& yP) {
	if (xP.size() <= 3) {
		return find_closest_brute(xP);
	}
	auto N = xP.size();
	auto xL = vector<point_t>();
	auto xR = vector<point_t>();
	copy(begin(xP), begin(xP) + (N / 2), back_inserter(xL));
	copy(begin(xP) + (N / 2), end(xP), back_inserter(xR));
	auto xM = xP.at((N-1) / 2).first;
	auto xN = xP.at((N-1) / 2).second;
	auto yL = vector<point_t>();
	auto yR = vector<point_t>();
	copy_if(begin(yP), end(yP), back_inserter(yL), [&xM,&xN](const point_t& p) {
		 return p.first <= xM;   
	});
	copy_if(begin(yP), end(yP), back_inserter(yR), [&xM,&xN](const point_t& p) {
		 return p.first > xM;
	});
	auto p1 = find_closest_optimized(xL, yL);
	auto p2 = find_closest_optimized(xR, yR);
	auto minPair = (p1.first <= p2.first) ? p1 : p2;
	auto yS = vector<point_t>();
	copy_if(begin(yP), end(yP), back_inserter(yS), [&minPair, &xM](const point_t& p) {
		return abs(xM - p.first) < minPair.first;
	});
	auto result = minPair;
	int n1=yS.size();
	for (int i = 0; i<n1; i++) {
		for (int k = i + 1; k <n1 &&
		 ((yP[k].second - yP[i].second) < minPair.first); k++) {
			auto newDistance = abs(distance_between(yP[k], yP[i]));
			if (newDistance < result.first) {
				result = { newDistance, { yP[k], yP[i] } };
			}
		}
	}
	return result;
}
 
void print_point(const point_t& point) {
	cout << "(" << point.first
		<< ", " << point.second
		<< ")";
}
 
int main(int argc, char * argv[]) {
	int n;
    cin>>n;
    vector<point_t> points(n);
    for(int i=0;i<n;i++)
    {
        cin>>points[i].first>>points[i].second;
    }
	//auto answer = find_closest_brute(points);
	sort(begin(points), end(points), [](const point_t& a, const point_t& b) {
	    if(a.first==b.first)
	    {
	        return a.second < b.second;
	    }
	    else
	    {
	        return a.first < b.first;
	    }
	});
	auto xP = points;
	sort(begin(points), end(points), [](const point_t& a, const point_t& b) {
	    if(a.second==b.second)
	    {
	        return a.first < b.first;
	    }
	    else
	    {
	        return a.second < b.second;
	    }     
	});
	auto yP = points;
	//cout<< fixed<< setprecision(9)<< answer.first << " ";
    //print_point(answer.second.first);
	//cout << ", ";
	//print_point(answer.second.second);
	auto answer = find_closest_optimized(xP, yP);
	cout <<fixed<<setprecision(9)<< answer.first << " ";
    //print_point(answer.second.first);
	//cout << ", ";
	//print_point(answer.second.second);
	return 0;
}