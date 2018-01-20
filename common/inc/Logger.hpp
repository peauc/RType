//
// Created by Clément Péau on 12/01/2018.
//

#ifndef RTYPE_LOGGER_HPP
#define RTYPE_LOGGER_HPP
#include <string>

class Logger {
public:
	enum LogLevel {
		
		DEBUG = 0,
		INFO,
		MINOR,
		MAJOR,
		CRITICAL,
		FATAL
	};
	
	static void Log(LogLevel level, const std::string &message) noexcept ;
};

#endif //RTYPE_LOGGER_HPP
