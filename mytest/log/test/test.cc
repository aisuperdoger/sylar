#include "util.h"
#include "log.h"
#include <sys/syscall.h>
#include<iostream>

namespace sylar
{
    pid_t GetThreadId() { return syscall(SYS_gettid); }
    uint32_t GetFiberId() { return 0; }
}
sylar::Logger g_logger_ins = sylar::Logger();
static sylar::Logger::ptr g_logger = SYLAR_LOG_ROOT()();

int main(int argc, char** argv) {
    // 使用流式风格写日志
    SYLAR_LOG_INFO(g_logger) << "hello logger stream";
    // 使用格式化写日志
    SYLAR_LOG_FMT_INFO(g_logger, "%s", "hello logger format");
    return 0;
}