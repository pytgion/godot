// sadTimer.cpp
#include "sadTimer.h"
#include "core/os/os.h"

SADScopedTimer::SADScopedTimer(const std::string &pLabel, const std::string &pFile, int pLine) :
		Label(pLabel), File(pFile), Line(pLine) {
	StartTime = OS::get_singleton()->get_ticks_usec();
}

SADScopedTimer::~SADScopedTimer() {
	uint64_t endTime = OS::get_singleton()->get_ticks_usec();
	uint64_t elapsed = endTime - StartTime;

	std::string msg = "SADScopedTimer: " + Label + " took " + std::to_string(elapsed) +
			"us at " + File + ":" + std::to_string(Line);

	SADLogger::Log(msg);
	SADLogger::LogCSV(Label, elapsed, File, Line);
}
