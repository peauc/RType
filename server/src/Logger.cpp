//
// Created by Clément Péau on 12/01/2018.
//

#include <iostream>
#include <string>
#include "Logger.hpp"

void Logger::Log(Logger::LogLevel level, const std::string &message) noexcept
{
	switch (level)
	{
		case (Logger::LogLevel::DEBUG) :
			std::cout << "[DEBUG] : " << message << std::endl;
			break;
		case (Logger::LogLevel::INFO) :
			std::cout << "[INFO] : " << message << std::endl;
			break;
		case (Logger::LogLevel::MINOR) :
			std::cout << "[MINOR] : " << message << std::endl;
			break;
		case (Logger::LogLevel::MAJOR) :
			std::cout << "[MAJOR] : " << message << std::endl;
			break;
		case (Logger::LogLevel::CRITICAL) :
			std::cout << "[CRITICAL] : " << message << std::endl;
			break;
		case (Logger::LogLevel::FATAL) :
			std::cout << "[FATAL] : " << message << std::endl;
			std::abort();
	}
}

