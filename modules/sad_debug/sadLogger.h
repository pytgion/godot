// this is gonna be fun
#ifndef SAD_LOGGER_H
#define SAD_LOGGER_H

#include <string>

class SADLogger {
public:
	static void Log(const std::string &message);
	static void LogCSV(const std::string &label, uint64_t elapsedTime, const std::string &file, int line);
};

#endif 
