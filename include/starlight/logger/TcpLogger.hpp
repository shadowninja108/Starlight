
#pragma once
#include <nn/socket.h>
#include <arpa/inet.h>
#include <list>
#include <vector>
#include <string>
#include <cstring>
#include <cstdarg>

#include "operator.h"

namespace starlight {
    class TcpLogger
    {
        public:
        static void Initialize();
        static void Log(const char* data, size_t size = UINT32_MAX);
        static void Log(std::string str);
        static void LogFormat(const char* format, ...);
        static void ClearQueue();
    };
};