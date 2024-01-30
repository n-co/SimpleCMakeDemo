#include "geometry.h"
#include <numbers>

double demo::utils::math::rad_to_deg(double theta)
{
	constexpr double ratio = 180.0 / std::numbers::pi_v<double>;
	return theta * ratio;
}

double demo::utils::math::deg_to_rad(double alpha)
{
	constexpr double ratio = std::numbers::pi_v<double> / 180.0;
	return alpha * ratio;
}