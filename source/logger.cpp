#include "types.h"
#include "nn/nifm.h"
#include "nn/socket.h"
#include "str.h"

const char* socket_log_host = "10.0.0.2";
u16 socket_log_port = 1339;

enum SocketLogState
{
    SOCKET_LOG_UNINITIALIZED    = 0,
    SOCKET_LOG_CONNECTED        = 1,
    SOCKET_LOG_UNAVAILABLE      = 2
};

u8 socket_log_state = SOCKET_LOG_UNINITIALIZED;
s32 socket_log_socket = -1;
u8 socket_data_pool[0x600000+0x20000] __attribute__((aligned(0x1000)));

void socket_log(const char* str)
{
    if (socket_log_state != SOCKET_LOG_CONNECTED)
        return;

    nn::socket::Send(socket_log_socket, str, strlen(str), 0);
}

void socket_log_initialize()
{
    in_addr hostAddress = { 0 };
    sockaddr serverAddress = { 0 };

    if (socket_log_state != SOCKET_LOG_UNINITIALIZED)
        return;

    nn::nifm::Initialize();
    nn::nifm::SubmitNetworkRequest();

    while (nn::nifm::IsNetworkRequestOnHold()) { }

    if (!nn::nifm::IsNetworkAvailable())
        goto failed;

    nn::socket::Initialize(socket_data_pool, 0x600000, 0x20000, 14);

    if ((socket_log_socket = nn::socket::Socket(2, 1, 0)) < 0)
        goto failed;
    
    nn::socket::InetAton(socket_log_host, &hostAddress);

    serverAddress.address = hostAddress;
    serverAddress.port = nn::socket::InetHtons(socket_log_port);
    serverAddress.family = 2;

    if (nn::socket::Connect(socket_log_socket, &serverAddress, sizeof(serverAddress)) != 0)
        goto failed;

    socket_log_state = SOCKET_LOG_CONNECTED;

    socket_log("Connected!\n");

    return;

failed:
    socket_log_state = SOCKET_LOG_UNAVAILABLE;
    return;
}