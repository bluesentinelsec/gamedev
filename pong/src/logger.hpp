#pragma once

#include <iostream>
#include <string>
#include <cstdarg>
#include <mutex>
#include <ctime>
#include <cstring>
#include <cstdlib> // for exit()

namespace logger {

// Log levels
enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL
};

// Logger class
class Logger {
  public:
    // Singleton instance of the Logger
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    // Set the log level (default is INFO)
    void setLogLevel(LogLevel level) {
        logLevel = level;
    }

    // Log a message with the specified level, source file, and line number
    void log(LogLevel level, const char* file, int line, const char* format, ...) {
        if (level >= logLevel) {
            std::lock_guard<std::mutex> guard(logMutex);

            // Get the filename from the full path
            const char* filename = std::strrchr(file, '/');
            filename = filename ? filename + 1 : file;

            // Print the log level, source file, and line number
            std::cout << "" << getTimestamp() << ""
                      << " [" << logLevelToString(level) << "]("
                      << filename << ":" << line << ") - ";

            // Handle variable arguments
            va_list args;
            va_start(args, format);
            vprintf(format, args);
            va_end(args);

            std::cout << std::endl;

            if (level == LogLevel::FATAL) {
                std::exit(1);
            }
        }
    }

  private:
    LogLevel logLevel = LogLevel::INFO;
    std::mutex logMutex;

    // Private constructor to enforce singleton pattern
    Logger() = default;

    // Convert log level to string
    const char* logLevelToString(LogLevel level) {
        switch (level) {
        case LogLevel::DEBUG:   return "DEBUG";
        case LogLevel::INFO:    return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR:   return "ERROR";
        case LogLevel::FATAL:   return "FATAL";
        default:                return "UNKNOWN";
        }
    }

    std::string getTimestamp() {
        std::time_t now = std::time(nullptr);
        char buf[20];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
        return buf;
    }
};

// Macro for convenient logging with source file and line number
#define LOG(level, ...) \
    logger::Logger::getInstance().log(level, __FILE__, __LINE__, __VA_ARGS__)

// Convenience macros for each log level
#define LOG_DEBUG(...)    LOG(logger::LogLevel::DEBUG, __VA_ARGS__)
#define LOG_INFO(...)     LOG(logger::LogLevel::INFO, __VA_ARGS__)
#define LOG_WARNING(...)  LOG(logger::LogLevel::WARNING, __VA_ARGS__)
#define LOG_ERROR(...)    LOG(logger::LogLevel::ERROR, __VA_ARGS__)
#define LOG_FATAL(...)    LOG(logger::LogLevel::FATAL, __VA_ARGS__)

} // namespace logger

