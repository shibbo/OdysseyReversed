#pragma once

#include "CameraTicket.h"

class alCameraFunction
{
public:
    static void initPriorityDemo2(al::CameraTicket *);
    static void validateKeepPreSelfPoseNextCamera(al::CameraTicket *);
    static void validateCameraInterpoleEaseOut(al::CameraTicket *);
};