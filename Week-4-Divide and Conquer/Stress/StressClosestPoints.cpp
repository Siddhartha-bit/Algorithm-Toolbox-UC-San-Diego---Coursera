#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <random>
#include <chrono>
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
 
std::pair<double, points_t> find_closest_brute(const std::vector<point_t>& points) {
	if (points.size() < 2) {
		return { -1, { { 0, 0 }, { 0, 0 } } };
	}
	auto minDistance = std::abs(distance_between(points.at(0), points.at(1)));
	points_t minPoints = { points.at(0), points.at(1) };
	for (auto i = std::begin(points); i != (std::end(points) - 1); ++i) {
		for (auto j = i + 1; j < std::end(points); ++j) {
			auto newDistance = std::abs(distance_between(*i, *j));
			if (newDistance < minDistance) {
				minDistance = newDistance;
				minPoints.first = *i;
				minPoints.second = *j;
			}
		}
	}
	return { minDistance, minPoints };
}
 
std::pair<double, points_t> find_closest_optimized(const std::vector<point_t>& xP,
	const std::vector<point_t>& yP) {
	if (xP.size() <= 3) {
		return find_closest_brute(xP);
	}
	auto N = xP.size();
	auto xL = std::vector<point_t>();
	auto xR = std::vector<point_t>();
	std::copy(std::begin(xP), std::begin(xP) + (N / 2), std::back_inserter(xL));
	std::copy(std::begin(xP) + (N / 2), std::end(xP), std::back_inserter(xR));
	auto xM = xP.at((N-1) / 2).first;
	auto xN = xP.at((N-1) / 2).second;
	auto yL = std::vector<point_t>();
	auto yR = std::vector<point_t>();
	std::copy_if(std::begin(yP), std::end(yP), std::back_inserter(yL), [&xM,&xN](const point_t& p) {
		if(p.first==xM)
		{
		    return p.second<xN;
		}
		else
		{
		 return p.first <= xM;   
		}
	});
	std::copy_if(std::begin(yP), std::end(yP), std::back_inserter(yR), [&xM,&xN](const point_t& p) {
		if(p.first==xM)
		{
		   return p.second>xN;
		}
		else
		{
		    return p.first > xM;
		}
	});
	auto p1 = find_closest_optimized(xL, yL);
	auto p2 = find_closest_optimized(xR, yR);
	auto minPair = (p1.first <= p2.first) ? p1 : p2;
	auto yS = std::vector<point_t>();
	std::copy_if(std::begin(yP), std::end(yP), std::back_inserter(yS), [&minPair, &xM](const point_t& p) {
		return std::abs(xM - p.first) < minPair.first;
	});
	auto result = minPair;
	for (auto i = begin(yS); i != (end(yS) - 1); ++i) {
		for (auto k = i + 1; k != end(yS) &&
		 ((k->second - i->second) < minPair.first); ++k) {
			auto newDistance = (distance_between(*i, *k));
			if (newDistance < result.first) {
			    if(k->first>i->first)
			    {
			        result = { newDistance, { *i, *k} };
			    }
			    else
			    {
			        result = { newDistance, { *k, *i}};
			    }
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

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}
 
int main(int argc, char * argv[]) {
	srand(time(0));
	while(true)
    {
        
        int n= rand() % 10 + 2; 
        cout<<n<<"\n";
        vector<point_t> points(n);
        for(int i=0;i<n;i++)
        {
            points[i].first=RandomFloat(8,8);
            points[i].second=RandomFloat(-10,2.9);
        }
        for(int i=0;i<n;i++)
        {
            cout<<"("<<points[i].first<<','<<points[i].second<<")"<<" "; 
        }
        cout<<"\n";
        auto answer = find_closest_brute(points);
       	sort(std::begin(points), std::end(points), [](const point_t& a, const point_t& b) {
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
	    sort(std::begin(points), std::end(points), [](const point_t& a, const point_t& b) {
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
	    //std::cout<< fixed<< setprecision(9)<< answer.first << " ";
        //print_point(answer.second.first);
	    //std::cout << ", ";
	    //print_point(answer.second.second);
	    auto answer1 = find_closest_optimized(xP, yP);
	    //std::cout <<fixed<<setprecision(9)<< answer.first << " ";
        //print_point(answer.second.first);
	    //std::cout << ", ";
	    //print_point(answer.second.second);
        
       if(answer.first==answer1.first)
       {
           cout<<"OK\n";
           print_point(answer.second.first);
	       std::cout << ", ";
	       print_point(answer.second.second);
	       print_point(answer1.second.first);
	       std::cout << ", ";
	       print_point(answer1.second.second);
	       std::cout << "\n";
       }
       else
       {
           cout<<"Wrong Answer"<<answer.first<<' '<<answer1.first<<"\n";
           print_point(answer.second.first);
	       std::cout << ", ";
	       print_point(answer.second.second);
	       print_point(answer1.second.first);
	       std::cout << ", ";
	       print_point(answer1.second.second);
           break;
       }
    }
}	
	
	
	/*int n;
    cin>>n;
    vector<point_t> points(n);
    for(int i=0;i<n;i++)
    {
        cin>>points[i].first>>points[i].second;
    }
	auto answer = find_closest_brute(points);
	std::sort(std::begin(points), std::end(points), [](const point_t& a, const point_t& b) {
	    if(a.first==b.first)
	    {
	        return a.second<b.second;
	    }
	    else
	    {
	        return a.first < b.first;
	    }
	});
	auto xP = points;
	std::sort(std::begin(points), std::end(points), [](const point_t& a, const point_t& b) {
	    if(a.second==b.second)
	    {
	        return a.first<b.first;
	    }
	    else
	    {
	        return a.second < b.second;
	    }     
	});
	auto yP = points;
	std::cout<< fixed<< setprecision(9)<< answer.first << " ";
    print_point(answer.second.first);
	std::cout << ", ";
	print_point(answer.second.second);
	answer = find_closest_optimized(xP, yP);
	std::cout <<fixed<<setprecision(9)<< answer.first << " ";
    print_point(answer.second.first);
	std::cout << ", ";
	print_point(answer.second.second);
	return 0;
}*/