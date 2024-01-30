#pragma once
#include "DemoConstants.h"

struct PointXY {
	double x = 0.0;
	double y = 0.0;
};

struct Polygon {
	int num_of_points;
	PointXY points[MAX_POINTS_IN_POLYGON];
};