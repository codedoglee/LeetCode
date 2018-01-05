#ifndef MAX_POINTS_ON_LINE_H_
#define MAX_POINTS_ON_LINE_H_

/**
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 */

#include <iostream>
#include <vector>
#include <map>

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

static std::string doubleToString(double d) {
	std::stringstream ss;
	ss << d;
	std::string res;
	ss >> res;
	return res;
}

class Solution {
public:
    int maxPoints(std::vector<Point> &points) {
    	if (points.size() == 0) {
    		return 0;
    	}
    	if (points.size() == 1) {
    		return 1;
    	}
    	int gmax = 1;
    	int cmax = 1;
    	std::map<std::string, int> slope;
    	int vertical = 1;
    	int repeat = 0;
    	for (int i = 0; i < points.size(); ++i) {
    		for (int j = i+1; j < points.size(); ++j) {
    			int deltX = points[j].x - points[i].x;
    			int deltY = points[j].y - points[i].y;
    			if (deltX == 0 && deltY == 0) {
    				++repeat;
    			}
    			else if (deltX == 0) {
    				++vertical;
    			}
    			else {
    				std::string key = doubleToString(((double)deltY/(double)deltX));
    				if (key == "-0.0") {
    					key = "0.0";
    				}
    				if (slope.find(key) != slope.end()) {
    					slope.insert(std::pair<std::string, int>(key, slope.at(key) + 1));
    				}
    				else {
    					slope.insert(std::pair<std::string, int>(key, 2));
    				}
    			}
    			std::map<std::string, int>::iterator it = slope.begin();
    			for (; it != slope.end(); ++it) {
    				int val = it->second;
    				if (val > cmax) {
    					cmax = val;
    				}
    			}
    			if (vertical > cmax) {
    				cmax = vertical;
    			}
    		}
    		cmax += repeat;
    		if (cmax > gmax) {
    			gmax = cmax;
    		}
    		slope.clear();
    		vertical = 1;
    		repeat = 0;
    		cmax = 1;
    	}
    	return gmax;
    }
};



#endif
