#include "DemoLoader.h"
#include <spdlog/spdlog.h>

int main() 
{
	demo::DemoLoader::get_instance();
	spdlog::info("hi");
}