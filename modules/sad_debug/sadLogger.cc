#include "sadLogger.h"
#include "core/io/file_access.h"
#include "core/os/os.h"
#include "core/string/ustring.h"
#include <cstdio>

void SADLogger::Log(const std::string &message) {
	printf("%s\n", message.c_str());

	String godotMsg = String(message.c_str());
	Ref<FileAccess> file = FileAccess::open("user://sad_log.txt", FileAccess::WRITE);
	if (file.is_valid()) {
		file->store_line(godotMsg);
	}
}

void SADLogger::LogCSV(const std::string &label, uint64_t elapsedTime, const std::string &file, int line) {
	std::string csvLine = label + "," + std::to_string(elapsedTime) + "," + file + "," + std::to_string(line);
	Log(csvLine);
}
