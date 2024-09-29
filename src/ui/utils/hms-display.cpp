

#include <string>

#include "ui/utils/hms-display.h"

std::string hms_display(int seconds) {
	int hours = seconds / 3600;
	int minutes = (seconds - (hours * 3600)) / 60;
	seconds = seconds - (hours * 3600) - (minutes * 60);

	std::string ret = "";
	if (hours > 0) {
		ret += std::to_string(hours) + ":";
	}

	int size = snprintf(NULL, 0,"%02d:%02d", minutes, seconds) + 1;
	char* fmt = (char*)malloc(sizeof(char) * size + 1);

	snprintf(fmt, size, "%02d:%02d", minutes, seconds);

	ret += fmt;
	free(fmt);

	return ret;
}

std::string hms_display(double seconds){
	return hms_display((int)seconds);
}

