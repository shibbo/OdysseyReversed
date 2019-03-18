/**
 * @file message.h
 * @brief Message library for parsing MSBT and MSBP.
 */

#pragma once

#include "types.h"

// STANDARD BINARY
struct MessageBinary
{
    void* srcBinary;
    u64 _8;
    u8 _10; // 0xC from binary
    u8 _11;
    u16 numSections; // _12
    u32 _14;
    void* _18; // source for sections?
    u32 lbl1Offset; // _20
    u32 txt2Offset; // _24
    u32 atr1Offset; // _28
    u32 ato1Offset; // _2C
    u32 tsy1Offset; // _30
    u32 _34;
};

#ifdef __cplusplus
extern "C" {
#endif

MessageBinary* LMS_InitMessage(void *);
// set to:
// sead::MessageSetBase::allocForLibms_(ulong)
// sead::MessageSetBase::freeForLibms_(void *)
void LMS_SetMemFuncs(void *, void *);

s32 LMS_GetTextNum(MessageBinary *);
void LMS_CloseMessage(MessageBinary *);

void* LMSi_Malloc(u32);
void LMSi_AnalyzeMessageBinary(MessageBinary *, char const *, u32);
u32 LMSi_SearchBlockByName(MessageBinary *, char const *);

// PROJECT BINARY
struct ProjectBinary
{
    void* srcBinary;
    u64 _8;
    u8 _10; // 0xC from binary
    u8 _11;
    u16 numSections; // _12
    u32 _14;
    u32 _18;
    u32 _1C;
    u32 clb1Offset; // _20
    u32 clr1Offset; // _24
    u32 alb1Offset; // _28
    u32 ati2Offset; // _2C
    u32 ali2Offset; // _30
    u32 tgg2Offset; // _34
    u32 tag2Offset; // _38
    u32 tgp2Offset; // _3C
    u32 tgl2Offset; // _40
    u32 syl3Offset; // _44
    u32 slb1Offset; // _48
    u32 cti1Offset; // _4C
};

ProjectBinary* LMS_InitProject(void *);
void CloseProject(ProjectBinary *);

#ifdef __cplusplus
}
#endif