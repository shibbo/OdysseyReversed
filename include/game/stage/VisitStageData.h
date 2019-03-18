/**
 * @file VisitStageData.h
 * @brief Information on visited stages.
 */

#pragma once

#include "al/byaml/BYamlIter.h"
#include "al/byaml/ByamlWriter.h"
#include "types.h"

class VisitStageData
{
public:
    VisitStageData();

    virtual void write(al::ByamlWriter *);
    virtual void read(al::ByamlIter const &);

    bool checkAlreadyVisit(char const *) const;
    void visit(char const *);

    u64* _8; // array of structures of size 0x98
    s32 mNumStages; // _10
};