#include "DemoLoader.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace demo {
	DemoLoader& DemoLoader::get_instance()
	{
		static DemoLoader instance;
		return instance;
	}

	DemoLoader::DemoLoader()
	{
		set_logger();
	}

	void DemoLoader::set_logger() const
	{
		using spdlog::level::level_enum;
		auto logger_ptr = std::make_shared<spdlog::logger>("Demo");
		logger_ptr->set_level(level_enum::trace);
				
		spdlog::sink_ptr console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		console_sink->set_level(level_enum::debug);
		console_sink->set_pattern("%T.%f [%^%l%$]: %v");
		logger_ptr->sinks().push_back(console_sink);

		// spdlog::sink_ptr file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("./DemoLog.log");
		// file_sink->set_level(level_enum::info);
		// file_sink->set_pattern("%Y-%m-%d %T.%f (%P) [%^%l%$]: %v");
		// logger_ptr->sinks().push_back(file_sink);
		
		spdlog::register_logger(logger_ptr);
		spdlog::set_default_logger(logger_ptr);
	}
}