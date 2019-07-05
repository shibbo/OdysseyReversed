/**
 * @file socket.h
 * @brief Functions for opening sockets for wireless communication.
 */

#pragma once

#include "types.h"

// both of these are a part of nn::socket but whatever
struct in_addr
{
    u32 data;           // 0
};

struct sockaddr
{
    u8 addrLen;
    u8 family;
    u16 port;
    in_addr address;
    u8 _8[8];
};


namespace nn
{
    namespace socket
    {
        Result Initialize(void* memoryPool, u64, u64, s32);

        s32 Socket(s32, s32, s32);
        s32 Connect(s32 socket,	const sockaddr* address, u32 addressLen);

        s32 Send(s32 socket, const void* data, u64 dataLen, s32 unk);
        s32 Recv(s32 socket, void* out, u64 outLen, s32 unk);

        u16 InetHtons(u16 val);
        s32 InetAton(const char* addressStr, in_addr* addressOut);

    };
};