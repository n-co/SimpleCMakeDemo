#pragma once
#include <string>
#include <string_view>

namespace demo {

class DemoLoader final
{
public:
	static DemoLoader& get_instance();

	~DemoLoader() {};

	DemoLoader(const DemoLoader&) = delete;
	DemoLoader& operator=(const DemoLoader&) = delete;

	std::string& get_data() const;

private:
	DemoLoader();
	void set_logger(std::string_view config_path) const;

	std::string data;
};
}