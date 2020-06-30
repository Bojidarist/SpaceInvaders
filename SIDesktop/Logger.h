#pragma once

namespace SI {
	void LogMessage(const char* message, bool newLine = true);
	void LogWarning(const char* warning, bool newLine = true);
	void LogError(const char* error, bool newLine = true);
}