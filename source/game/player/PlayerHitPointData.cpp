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
    s32 health;

    this->mIsHaveMaxUpItem = 0;

    if (this->mIsKidsMode)
    {
        health = 6;
    }
    else
    {
        health = 3;
    }
    
    this->mCurHealth = health;
}

void PlayerHitPointData::recoverMax()
{
    s32 health = 3;
    s32 healthWithMax;

    if (!this->mIsForceNormalMode)
    {
        if (this->mIsKidsMode)
        {
            health = 6;
        }
        else
        {
            health = 3;
        }

        if (this->mIsKidsMode)
        {
            healthWithMax = 9;
        }
        else
        {
            healthWithMax = 6;
        }

        if (this->mIsHaveMaxUpItem)
        {
            health = healthWithMax;
        }
    }

    this->mCurHealth = health;
}

s32 PlayerHitPointData::getCurrent() const
{
    return this->mCurHealth;
}

s32 PlayerHitPointData::getMaxCurrent() const
{
    s32 health;

    if (this->mIsForceNormalMode)
    {
        return 3;
    }

    if (this->mIsHaveMaxUpItem)
    {
        if (this->mIsKidsMode)
        {
            health = 9;
        }
        else
        {
            health = 6;
        }
    }
    else if (this->mIsKidsMode)
    {
        health = 6;
    }
    else
    {
        health = 3;
    }

    return health;
}

s32 PlayerHitPointData::getMaxWithItem() const
{
    s32 health;

    if (this->mIsKidsMode && !this->mIsForceNormalMode)
    {
        health = 9;
    }
    else
    {
        health = 6;
    }
    
    return health;
}

s32 PlayerHitPointData::getMaxWithoutItem() const
{
    s32 health;

    if (this->mIsKidsMode && !this->mIsForceNormalMode)
    {
        health = 6;
    }
    else
    {
        health = 3;
    }
    
    return health;
}

bool PlayerHitPointData::isMaxCurrent() const
{
    s32 curHealth, curMaxHealth, health, maxHealthWithKids;

    if (this->mIsForceNormalMode)
    {
        curHealth = this->mCurHealth;
        curMaxHealth = 3;
    }
    else
    {
        curHealth = this->mCurHealth;

        if (this->mIsKidsMode & 0xFF)
        {
            health = 6;
        }
        else
        {
            health = 3;
        }

        if (this->mIsKidsMode & 0xFF)
        {
            maxHealthWithKids = 9;
        }
        else
        {
            maxHealthWithKids = 6;
        }
        
        if (this->mIsHaveMaxUpItem)
        {
            curMaxHealth = maxHealthWithKids;
        }
        else
        {
            curMaxHealth = health;
        }
    }

    return curMaxHealth == curHealth;
}

bool PlayerHitPointData::isMaxWithItem() const
{
    s32 maxHealth;

    if (this->mIsKidsMode && !this->mIsForceNormalMode)
    {
        maxHealth = 9;
    }
    else
    {
        maxHealth = 6;
    }

    return maxHealth == this->mCurHealth;
}

void PlayerHitPointData::getMaxUpItem()
{
    s32 newHealth;

    this->mIsHaveMaxUpItem = 1;

    if (this->mIsForceNormalMode)
    {
        this->mCurHealth = 3;
    }
    else
    {
        if (this->mIsKidsMode)
        {
            newHealth = 9;
        }
        else
        {
            newHealth = 6;
        }
        
        this->mCurHealth = newHealth;
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
    s32 newPossibleHealth, healthWithKids;

    newPossibleHealth = this->mCurHealth - 1;

    if (newPossibleHealth <= 0)
    {
        newPossibleHealth = 0;
    }

    this->mCurHealth = newPossibleHealth;

    // now we see if we have to remove our max up heart
    if (!this->mIsForceNormalMode)
    {
        if (this->mIsKidsMode)
        {
            healthWithKids = 6;
        }
        else
        {
            healthWithKids = 3;
        }
        
        if (newPossibleHealth <= healthWithKids)
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
    s32 healthWithKids, healthWithKidsAndNoForce, newHealth;
    this->mIsForceNormalMode = 0;

    if (this->mIsKidsMode)
    {
        healthWithKids = 9;
    }
    else
    {
        healthWithKids = 6;
    }

    if (this->mIsKidsMode)
    {
        healthWithKidsAndNoForce = 3;
    }
    else
    {
        healthWithKidsAndNoForce = 6;
    }
    
    if (this->mIsHaveMaxUpItem)
    {
        newHealth = healthWithKids;
    }
    else
    {
        newHealth = healthWithKidsAndNoForce;
    }
    
    this->mCurHealth = newHealth;
}

bool PlayerHitPointData::isForceNormalMode() const
{
    return this->mIsForceNormalMode;
}