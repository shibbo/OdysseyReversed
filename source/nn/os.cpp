#include "nn/os.h"

namespace nn
{
    namespace os
    {
        namespace detail
        {
            s32 nn::os::detail::g_CommandLineParameter = 1;
        };

        void SetHostArgc(s32 arg)
        {
            detail::g_CommandLineParameter = arg;
        }

        s32 GetHostArgc()
        {
            return detail::g_CommandLineParameter;
        }

        void SetHostArgv(char** arg)
        {
            detail::g_CommandLineParameterArgv = arg;
        }

        char** GetHostArgv()
        {
            return detail::g_CommandLineParameterArgv;
        }
    };
};