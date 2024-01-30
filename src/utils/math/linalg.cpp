#include "linalg.h"
#include <math.h>

double demo::utils::math::magnitude(double x, double y)
{
	return sqrt(x * x + y * y);
}

double demo::utils::math::magnitude(double x, double y, double z)
{
	return sqrt(x * x + y * y + z * z);
}

double demo::utils::math::distance(double p1x, double p1y, double p2x, double p2y)
{
	return magnitude(p1x - p2x, p1y - p2y);
}

double demo::utils::math::distance(double p1x, double p1y, double p1z, double p2x, double p2y, double p2z)
{
	return magnitude(p1x - p2x, p1y - p2y, p1z - p2z);
}
