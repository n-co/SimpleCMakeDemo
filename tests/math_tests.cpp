#include "geometry.h"
#include "linalg.h"
#include <gtest/gtest.h>

TEST(utils_math, geometry)
{
	constexpr double pi = 3.14159265358979;
	constexpr double radian = 57.295779513082323;
	constexpr double epsilon = 1e-9;

	using namespace demo::utils::math;

	EXPECT_NEAR(rad_to_deg(pi), 180.0, epsilon);
	EXPECT_NEAR(deg_to_rad(180.0), pi, epsilon);

	EXPECT_NEAR(rad_to_deg(1.0), radian, epsilon);
	EXPECT_NEAR(deg_to_rad(radian), 1.0, epsilon);
}

TEST(utils_math, linalg)
{
	constexpr double epsilon = 1e-9;

	using namespace demo::utils::math;
	 
	EXPECT_NEAR(magnitude(3.0, 4.0), 5.0, epsilon);
	EXPECT_NEAR(magnitude(5.0, 12.0), 13.0, epsilon);
	EXPECT_NEAR(distance(1.0, 1.0, 4.0, 5.0), 5.0, epsilon);
}

