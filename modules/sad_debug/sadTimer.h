#ifndef SAD_DEBUG
#define SAD_DEBUG

#endif

#include "sadLogger.h"
#include <string>

class SADScopedTimer {
private:
	std::string Label;
	uint64_t StartTime;
	std::string File;
	int Line;

public:
	SADScopedTimer(const std::string &label, const std::string &file, int line);
	~SADScopedTimer();
};

#define SAD_SCOPED_TIMER(label) SADScopedTimer __sad_timer__##__LINE__(label, __FILE__, __LINE__)
