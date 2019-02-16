/**
 * @file PlayerHitPointData.cpp
 * @brief Keeps track on the player's health.
 */

#include "game/player/PlayerHitPointData.h"

PlayerHitPointData::PlayerHitPointData()
{
    this->mIsKidsMode = 0;
    this->mCurHealth = 0;
    this->mIsHaveMaxUpItem = 0;
}

void PlayerHitPointData::setKidsModeFlag(bool flag)
{
    this->mIsKidsMode = flag & 0x1;
}

void PlayerHitPointData::init()
{
    this->mIsHaveMaxUpItem = 0;
    this->mCurHealth = this->mIsKidsMode ? 6 : 3;
}

void PlayerHitPointData::recoverMax()
{
    if (!this->mIsForceNormalMode)
    {
        if (this->mIsHaveMaxUpItem) 
        {
            this->mCurHealth = this->mIsKidsMode ? 9 : 6;
        }
        else
        {
            this->mCurHealth = this->mIsKidsMode ? 6 : 3;
        }
    }
    else
    {
        this->mCurHealth = 3;
    }
}

s32 PlayerHitPointData::getCurrent() const
{
    return this->mCurHealth;
}

s32 PlayerHitPointData::getMaxCurrent() const
{
    if (this->mIsForceNormalMode)
    {
        return 3;
    }

    if (this->mIsHaveMaxUpItem)
    {
        return this->mIsKidsMode ? 9 : 6;
    }
    else if (this->mIsKidsMode)
    {
        return 6;
    }
    else
    {
        return 3;
    }
}

s32 PlayerHitPointData::getMaxWithItem() const
{
    if (this->mIsKidsMode && !this->mIsForceNormalMode)
    {
        return 9;
    }
    else
    {
        return 6;
    }
}

s32 PlayerHitPointData::getMaxWithoutItem() const
{
    if (this->mIsKidsMode && !this->mIsForceNormalMode)
    {
        return 6;
    }
    else
    {
        return 3;
    }
}

bool PlayerHitPointData::isMaxCurrent() const
{
    s32 curMaxHealth;

    if (this->mIsForceNormalMode)
    {
        curMaxHealth = 3;
    }
    else
    {
        s32 health = this->mIsKidsMode & 0xFF ? 6 : 3;
        s32 maxHealthWithKids = this->mIsKidsMode & 0xFF ? 9 : 6;
        
        curMaxHealth = this->mIsHaveMaxUpItem ? maxHealthWithKids : health;
    }

    return curMaxHealth == this->mCurHealth;
}

bool PlayerHitPointData::isMaxWithItem() const
{
    return (this->mIsKidsMode && !this->mIsForceNormalMode ? 9 : 6) == this->mCurHealth;
}

void PlayerHitPointData::getMaxUpItem()
{
    this->mIsHaveMaxUpItem = 1;

    if (this->mIsForceNormalMode)
    {
        this->mCurHealth = 3;
    }
    else
    {
        this->mCurHealth = this->mIsKidsMode ? 9 : 6;
    }
}

void PlayerHitPointData::recover()
{
    s32 newPossibleHealth, healthWithKids, healthWithKidsAndNoForce;

    newPossibleHealth = this->mCurHealth + 1;
    healthWithKids = 3;

    if (!this->mIsForceNormalMode)
    {
        healthWithKids = this->mIsKidsMode ? 6 : 3;
        healthWithKidsAndNoForce = this->mIsKidsMode ? 9 : 6;

        if (this->mIsHaveMaxUpItem)
        {
            healthWithKids = healthWithKidsAndNoForce;
        }
    }

    if (newPossibleHealth >= healthWithKids)
    {
        newPossibleHealth = healthWithKids;
    }

    this->mCurHealth = newPossibleHealth;
}

void PlayerHitPointData::recoverForDebug()
{
    s32 newHealth, health, v2, v3, v4, v5, v6, v7, v9, v11, v12;
    bool v8;

    newHealth = 3;
    if (this->mIsForceNormalMode)
    {
        v2 = 1;
        v3 = this->mCurHealth;
    }
    else
    {
        v4 = this->mIsHaveMaxUpItem;
        v5 = v4;
        v6 = v4 >> 8;
        v3 = this->mCurHealth;
        
        if (this->mIsKidsMode & 0xFF)
        {
            newHealth = 6;
        }
        else
        {
            newHealth = 3;
        }
    
        if (this->mIsKidsMode & 0xFF)
        {
            v7 = 9;
        }
        else
        {
            v7 = 6;
        }
        
        v8 = v5 == 0;
        v2 = v6;
        
        if (!v8)
        {
            newHealth = v7;
        }
    }

    if (this->mCurHealth >= newHealth)
    {
        v9 = this->mIsHaveMaxUpItem;
        v2 = v9 >> 8;

        if ( !v9 )
        {
            this->mIsHaveMaxUpItem = 1;
        }
    }

    health = v3 + 1;
    v11 = 3;

    if (!v2)
    {
        v11 = this->mIsKidsMode ? 6 : 3;
        v12 = this->mIsKidsMode ? 9 : 6;

        if (this->mIsHaveMaxUpItem)
        {
            v11 = v12;
        }
    }
    if (health >= v11)
    {
        health = v11;
    }

    this->mCurHealth = health;
}

void PlayerHitPointData::damage()
{
    s32 newPossibleHealth = this->mCurHealth - 1;

    if (newPossibleHealth <= 0)
    {
        newPossibleHealth = 0;
    }

    this->mCurHealth = newPossibleHealth;

    // now we see if we have to remove our max up heart
    if (!this->mIsForceNormalMode)
    {        
        if (newPossibleHealth <= this->mIsKidsMode ? 6 : 3)
        {
            this->mIsHaveMaxUpItem = 0;
        }
    }
}

void PlayerHitPointData::kill()
{
    this->mCurHealth = 0;

    if (!this->mIsForceNormalMode)
    {
        this->mIsHaveMaxUpItem = 0;
    }
}

void PlayerHitPointData::forceNormalMode()
{
    this->mIsForceNormalMode = 1;
    this->mCurHealth = 3;
}

void PlayerHitPointData::endForceNormalMode()
{
    this->mIsForceNormalMode = 0;

    if (this->mIsHaveMaxUpItem)
    {
        this->mCurHealth = this->mIsKidsMode ? 9 : 6;
    }
    else
    {
        this->mCurHealth = this->mIsKidsMode ? 3 : 6;
    }  
}

bool PlayerHitPointData::isForceNormalMode() const
{
    return this->mIsForceNormalMode;
}
