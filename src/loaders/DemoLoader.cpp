#include "DemoLoader.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <nlohmann/json.hpp>
#include <map>
#include <fstream>

namespace demo {
	DemoLoader& DemoLoader::get_instance()
	{
		static DemoLoader instance;
		return instance;
	}

	DemoLoader::DemoLoader()
	{
		set_logger("./logger_config.json");
	}

	void DemoLoader::set_logger(std::string_view config_path) const
	{
		using spdlog::level::level_enum;
		using namespace std::string_view_literals;

		const std::map<std::string_view, level_enum> level_names{
			{"trace"sv,    level_enum::trace },
			{"debug"sv,    level_enum::debug },
			{"info"sv,     level_enum::info },
			{"warn"sv,     level_enum::warn },
			{"warninig"sv, level_enum::warn },
			{"err"sv,      level_enum::err },
			{"error"sv,    level_enum::err },
			{"critical"sv, level_enum::critical },
			{"off"sv,      level_enum::off }
		};

		using nlohmann::json;
		
		std::ifstream in_file;
		in_file.open(std::string(config_path));
		json logger_config = json::parse(in_file);

		auto logger_name   = logger_config.at("logger_name").get<std::string>();
		auto console_level = level_names.at(logger_config.at("console_level").get<std::string_view>());
		auto file_level    = level_names.at(logger_config.at("file_level").get<std::string_view>());
		auto file_name     = logger_config.at("file_name").get<std::string>();
		auto file_path     = logger_config.at("file_path").get<std::string>();

		using spdlog::level::level_enum;
		auto logger_ptr = std::make_shared<spdlog::logger>(logger_name);
		logger_ptr->set_level(std::min(console_level, file_level));
				
		if (console_level != level_enum::off) {
			spdlog::sink_ptr console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
			console_sink->set_level(console_level);
			console_sink->set_pattern("%T.%f [%^%l%$]: %v");
			logger_ptr->sinks().push_back(console_sink);
		}


		if (file_level != level_enum::off) {
			std::filesystem::path file_full_path(file_path);
			file_full_path /= file_name;

			if (std::filesystem::exists(file_full_path)) {
				std::filesystem::remove(file_full_path);
			}

			spdlog::sink_ptr file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(file_full_path.string());
			file_sink->set_level(file_level);
			file_sink->set_pattern("%Y-%m-%d %T.%f (%P) [%^%l%$]: %v");
			logger_ptr->sinks().push_back(file_sink);
		}

		spdlog::register_logger(logger_ptr);
		spdlog::set_default_logger(logger_ptr);
	}
}