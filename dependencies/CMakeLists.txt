cmake_minimum_required(VERSION 3.22)

CPMAddPackage(
	GIT_REPOSITORY https://github.com/gabime/spdlog.git
	GIT_TAG v1.13.0
)

CPMAddPackage(
	GIT_REPOSITORY https://github.com/nlohmann/json.git
	GIT_TAG v3.11.3
)

CPMAddPackage(
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.14.0
)