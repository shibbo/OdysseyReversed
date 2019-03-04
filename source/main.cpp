#include <arpa/inet.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>

#include "alloc.h"
#include "nn/socket.h"
#include "mem.h"
#include "str.h"
#include "svc.h"

u64 mainAddr = 0;
s32 socket_fd = -1;

void outputdebugstringf(const char* format, ...) {
    char buffer[0x1000];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, 0x1000, format, args);
    svcOutputDebugString(buffer, strlen_0(buffer));
    va_end(args);
}

void log_to_socket(const char* format, ...) {
    char buffer[0x100];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, 0x100, format, args);
    nn::socket::Send(socket_fd, buffer, strlen_0(buffer), 0);
    va_end(args);
}

void hook_init()
{
    mainAddr = (u64)__builtin_extract_return_addr(__builtin_return_address(0)) - 0x541814;

    void* socket_pool = malloc(0x600000);
    nn::socket::Initialize(socket_pool, 0x600000, 0x20000, 14);
    s32 sockfd = nn::socket::Socket(2, 1, 0);

    if (sockfd == -1)
    {
        while(1);
    }

    socket_fd = sockfd;

    struct sockaddr_in servaddr;
    memset_0(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("192.168.1.6");
    servaddr.sin_port = nn::socket::InetHtons(42069);
    nn::socket::Connect(sockfd, (sockaddr const *)&servaddr, sizeof(servaddr));
    log_to_socket("main .text start: 0x%llx\n", mainAddr);
}

int main(int argc, char **argv) 
{
    if (svcGetSystemTick() > 0) 
    {
        svcExitProcess();
    }

    hook_init();
    log_to_socket("it works?");

    return 0;
}