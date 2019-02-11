/**
 * @file PlacementId.cpp
 * @brief Storage container for an actors' placement identification.
 */

#include "al/PlacementId.h"
#include "al/byaml/ByamlIter.h"
#include "al/Scene.h"
#include "util.h"

namespace al
{
    PlacementId::PlacementId()
    {
        this->mZoneId = 0;
        this->mCommonId = 0;
        this->mStageId = 0;
        this->mUnitConfigName = 0;
    }

    PlacementId::PlacementId(char const *stageId, char const *unitConfigName, char const *zoneId)
    {
        this->mStageId = (char*)stageId;
        this->mUnitConfigName = (char*)unitConfigName;
        this->mZoneId = (char*)zoneId;
        this->mCommonId = 0;
    }

    void PlacementId::init(PlacementInfo const &info)
    {
        this->mStageId = 0;
        this->mZoneId = 0;
        this->mUnitConfigName = 0;
        this->mCommonId = 0;

        info.mStageIterator.tryGetStringByKey(&this->mCommonId, "CommonId");
        info.mZoneIterator.tryGetStringByKey(&this->mUnitConfigName, "UnitConfigName");
        info.mZoneIterator.tryGetStringByKey(&this->mZoneId, "Id");
        info.mStageIterator.tryGetStringByKey(&this->mStageId, "Id");
    }

    bool PlacementId::isEqual(PlacementId const &id) const
    {
        if (this->mCommonId)
        {
            if (!id.mCommonId)
            {
                return false;
            }

            return al::isEqualString(this->mCommonId, id.mCommonId);
        }

        if (!id.mCommonId)
        {
            if (this->mUnitConfigName)
            {
                if ( !id.mUnitConfigName || !(al::isEqualString(this->mUnitConfigName, id.mUnitConfigName) & 1) || !(al::isEqualString(this->mZoneId, id.mZoneId) & 1))
                {
                    return false;
                }

                if (!this->mStageId)
                {
                    return false;
                }

                if (!id.mStageId)
                {
                    return false;
                }

                return al::isEqualString(this->mStageId, id.mStageId);
            }

            if (!id.mUnitConfigName)
            {
                if (!this->mStageId)
                {
                    return false;
                }

                if (!id.mStageId)
                {
                    return false;
                }

                return al::isEqualString(this->mStageId, id.mStageId);
            }
        }

        return false;
    }

    bool PlacementId::isEqual(PlacementId const &id1, PlacementId const &id2)
    {
        if (id1.mCommonId)
        {
            if (!id2.mCommonId)
            {
                return false;
            }

            return al::isEqualString(id1.mCommonId, id2.mCommonId);
        }

        if (!id2.mCommonId)
        {
            if (id1.mUnitConfigName)
            {
                if (!id2.mUnitConfigName || !(al::isEqualString(id1.mUnitConfigName, id2.mUnitConfigName) & 1) || 
                    !(al::isEqualString(id1.mZoneId, id2.mZoneId) & 1))
                {
                    return false;
                }

                if (!id1.mStageId)
                {
                    return false;
                }

                if (!id2.mStageId)
                {
                    return false;
                }

                return al::isEqualString(id1.mCommonId, id2.mCommonId);
            }

            if (!id2.mUnitConfigName)
            {
                if (!id1.mStageId)
                {
                    return false;
                }

                if (!id2.mStageId)
                {
                    return false;
                }

                return al::isEqualString(id1.mCommonId, id2.mCommonId);
            }
        }
    }

    bool PlacementId::isValid() const
    {
        if (this->mCommonId)
        {
            return true;
        }
        else
        {
            return this->mStageId != 0;
        }
    }

    s32 PlacementId::makeString(sead::BufferedSafeStringBase<char> *strBase)
    {
        char* temp;
        temp = this->mCommonId;

        if (!temp)
        {
            if (this->mUnitConfigName)
            {
                return strBase->format("%s(%s[%s])", this->mStageId, this->mUnitConfigName, this->mZoneId);
            }

            if (this->mStageId)
            {
                return strBase->format(this->mStageId);
            }

            temp = sceneObjectName;
        }

        return strBase->format(temp);
    }
};