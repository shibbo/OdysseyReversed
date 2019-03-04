/**
 * @file socket.h
 * @brief Functions for opening sockets for wireless communication.
 */

#pragma once

#include <sys/socket.h>
#include "types.h"

namespace nn
{
    namespace socket
    {
        Result Initialize(void *pool, u64 poolSize, u64 allocPoolSize, s32 concurLimit);
        Result Finalize();
        s32 SetSockOpt(s32 socket, s32 socketLevel, s32 option, void const *, u64 len);
        u64 Send(s32 socket, void const *buffer, u64 bufferLength, s32 flags);
        s32 Socket(s32 domain, s32 type, s32 proto);
        u16 InetHtons(u16);
        u32 Connect(s32 socket, const sockaddr *addr, u32 addrLen);
    };
};