#pragma once

/**
 * @file PlayerConst.h
 * @brief Class that holds constants for the player actor.
 */

#include "../../al/byaml/ByamlIter.h"

namespace al
{
    class PlayerConst
    {
    public:
        PlayerConst();
        PlayerConst(al::ByamlIter const &);

		f32 getGravity() const;
		f32 getFrictionAttack() const;
		f32 getPushPower() const;
		f32 getWaitPoseDegreeMax() const;
		f32 getHillPoseDegreeMax() const;
		f32 getTiltPoseDegreeMax() const;
		f32 getSlerpQuatRate() const;
		f32 getSlerpQuatRateWait() const;
		f32 getSlerpQuatGrav() const;
		s32 getPreInputFrameCapThrow() const;
		s32 getEnableActionFrameCapCatch() const;
		f32 getJumpPowerCapCatch() const;
		f32 getJumpGravityCapCatch() const;
		s32 getRunTimeContinuousThrow() const;
		f32 getRunSpeedMaxContinuousThrow() const;
		s32 getRunAccelFrameContinuousThrow() const;
		f32 getSeparateCheckHeight() const;
		f32 getSeparateOffsetLerpRate() const;
		f32 getSeparateEnableThrowHeight() const;
		f32 getTall() const;
		f32 getCollisionRadius() const;
		f32 getCollisionRadiusSquat() const;
		f32 getCollisionRadiusStand() const;
		f32 getCollisionSmallStepHeight() const;
		f32 getCollisionResetLimit() const;
		f32 getCollisionResetLimitHigh() const;
		f32 getReflectCeilingPower() const;
		f32 getReflectTossPower() const;
		f32 getReflectUpperPunchScaleH() const;
		f32 getCollisionHitDownAngleH() const;
		f32 getCollisionHitDownEscapeAngleV() const;
		f32 getShadowDropHeightScale() const;
		f32 getShadowDropNormalAdd() const;
		f32 getShadowDropLengthMin() const;
		f32 getShadowDropLengthMax() const;
		f32 getShadowDropLengthExtend() const;
		f32 getGravityDamage() const;
		f32 getHopPowerDamage() const;
		f32 getPushPowerDamage() const;
		s32 getDamageCancelFrame() const;
		s32 getDamageInvalidCount() const;
		s32 getDamageInvalidCountRecovery() const;
		s32 getDamageInvalidCountAbyss() const;
		f32 getNormalMinSpeed2D() const;
		f32 getNormalMaxSpeed2D() const;
		f32 getDashMaxSpeed2D() const;
		s32 getNormalAccelFrame2D() const;
		s32 getDashAccelFrame2D() const;
		s32 getNormalDashAnimFrame2D() const;
		s32 getNormalBrakeFrame2D() const;
		s32 getStickOnBrakeFrame2D() const;
		s32 getBrakeTurnStartFrame2D() const;
		f32 getTurnEndSpeedRate2D() const;
		f32 getJumpPowerMin2DArea() const;
		f32 getJumpPowerMax2DArea() const;
		f32 getJumpPowerMinBorder2D() const;
		f32 getJumpPowerMaxBorder2D() const;
		f32 getGravityMove() const;
		f32 getNormalMaxSpeed() const;
		f32 getNormalMinSpeed() const;
		s32 getNormalAccelFrame() const;
		f32 getRunAccelAverageScale() const;
		s32 getNormalBrakeFrame() const;
		f32 getDashJudgeSpeed() const;
		s32 getStickOnBrakeFrame() const;
		s32 getNormalDashAnimFrame() const;
		f32 getRunAfterTurnSpeedMax() const;
		f32 getRunAfterTurnScale() const;
		s32 getRunAfterTurnFrame() const;
		s32 getBrakeTurnStartFrame() const;
		f32 getBrakeOnSpeedRate() const;
		s32 getBrakeOnCounterBorder() const;
		s32 getWallPushFrame() const;
		s32 getRunDeepDownFrame() const;
		s32 getRunDeepDownMargine() const;
		s32 getQuickTurnJumpFrame() const;
		s32 getRoundAccelFrame() const;
		s32 getRoundBrakeFrame() const;
		f32 getRoundFastDegree() const;
		s32 getRoundAccelFrameFast() const;
		f32 getRoundMinDegree() const;
		s32 getRoundBrakeFrameForce() const;
		f32 getRoundFastDegreeForce() const;
		f32 getRoundLimitDegreeForce() const;
		f32 getRoundLimitDegreeForceFast() const;
		s32 getRoundAccelFrameForceFast() const;
		f32 getRoundLimitDegreeMin() const;
		f32 getRoundLimitDegree() const;
		s32 getIceAccelFrame() const;
		s32 getIceBrakeFrame() const;
		s32 getIceBrakeFrameHigh() const;
		s32 getIceBrakeFrameWall() const;
		s32 getIceRoundAccelFrame() const;
		s32 getIceRoundAccelFrameFast() const;
		s32 getIceRoundBrakeFrame() const;
		f32 getIceRoundFastDegree() const;
		f32 getIceRoundMinDegree() const;
		f32 getIceRoundLimitDegree() const;
		f32 getHillAddSpeed() const;
		f32 getHillSubSpeed() const;
		s32 getHillAccelAddFrame() const;
		s32 getHillAccelSubFrame() const;
		f32 getHillAccelSubAngleMin() const;
		f32 getHillAccelSubAngleMax() const;
		f32 getStandAngleMin() const;
		f32 getStandAngleMax() const;
		f32 getHillAngleSpeedMin() const;
		f32 getHillAngleSpeedMax() const;
		s32 getSpinCapThrowFrame() const;
		s32 getSpinCapThrowFrameAir() const;
		s32 getSpinCapThrowFrameSwim() const;
		s32 getSpinCapThrowFrameSwing() const;
		s32 getSpinCapThrowFrameContinuous() const;
		s32 getSpinAttackFrame() const;
		s32 getSpinBrakeFrame() const;
		f32 getSpinAirJumpPower() const;
		f32 getSpinAirSpeedMax() const;
		f32 getGravitySpinAir() const;
		f32 getSlerpQuatRateSpinAir() const;
		f32 getSpinBrakeRate() const;
		f32 getSpinBrakeSideAccel() const;
		f32 getSpinBrakeSideBrakeRate() const;
		f32 getSpinBrakeSideMaxSpeedRate() const;
		f32 getSpinRoundLimitDegree() const;
		f32 getDamageFireJumpPower1st() const;
		f32 getDamageFireJumpPower2nd() const;
		f32 getDamageFireJumpMoveSpeed() const;
		f32 getDamageFireCeilHitSpeed() const;
		f32 getDamageFireGravity() const;
		s32 getDamageFireNoGravityFrame() const;
		s32 getDamageFireRunTime() const;
		f32 getDamageFireRunSpeed() const;
		f32 getDamageFireRunBrakeFrame() const;
		s32 getSandSinkDeadTime() const;
		s32 getSandSinkBrakeHeightH() const;
		s32 getSandSinkBrakeHeightV() const;
		f32 getSandSinkHeight() const;
		f32 getSandSinkCapThrow() const;
		f32 getSandSinkBrakeMinH() const;
		f32 getSandSinkBrakeMaxH() const;
		f32 getSandSinkBrakeMinV() const;
		f32 getSandSinkBrakeMaxV() const;
		f32 getSlopeSlideAngleStart() const;
		f32 getSlopeSlideAngleEnd() const;
		f32 getSlopeSlideAccel() const;
		f32 getSlopeSlideBrake() const;
		f32 getSlopeSlideMaxSpeed() const;
		f32 getSlopeSlideSpeedEnd() const;
		f32 getSlopeSlideSideAccel() const;
		f32 getSlopeSlideSideBrake() const;
		f32 getSlopeSlideSideMaxSpeed() const;
		f32 getSlopeTurnDegree() const;
		s32 getSlideInvalidFrame() const;
		s32 getSlopeForceFrame() const;
		f32 getSlopeSlideForceSideAccel() const;
		f32 getSlopeSlideForceSideBrake() const;
		f32 getSlopeSlideForceSideMaxSpeed() const;
		f32 getSlopeSlideForceTurnDegree() const;
		f32 getSlopeRollingSpeedStart() const;
		f32 getSlopeRollingSpeedBoost() const;
		f32 getSlopeRollingMaxSpeed() const;
		s32 getSlopeRollingFrameMinBoost() const;
		s32 getSlopeRollingFrameMin() const;
		f32 getSlopeRollingStartJumpPower() const;
		f32 getSlopeRollingStartSlideSpeed() const;
		f32 getSlopeRollingAccel() const;
		f32 getSlopeRollingBrake() const;
		f32 getSlopeRollingAgainst() const;
		f32 getSlopeRollingAnglePowerMax() const;
		f32 getSlopeRollingSpeedEnd() const;
		f32 getSlopeRollingSideAccel() const;
		f32 getSlopeRollingSideBrake() const;
		f32 getSlopeRollingSideMaxSpeed() const;
		s32 getSlopeRollingUnRollFrame() const;
		f32 getSlopeRollingEndBrake() const;
		f32 getSlopeRollingEndBrakeEndSpeed() const;
		f32 getSlopeRollingReStartAccel() const;
		f32 getSlopeRollingReStartMaxAdd() const;
		s32 getSlopeRollingReStartInterval() const;
		s32 getSlopeRollingReStartSwing() const;
		s32 getSlopeRollingReStartCharge() const;
		s32 getSlopeRollingReStartForce() const;
		f32 getSlopeRollingAccelOnSkate() const;
		f32 getSlopeRollingSideAccelOnSkate() const;
		f32 getSlopeRollingBrakeOnSkate() const;
		s32 getExtendFrame() const;
		f32 getJumpInertiaRate() const;
		f32 getJumpPowerMin() const;
		f32 getJumpPowerMax() const;
		f32 getJumpGravity() const;
		f32 getJumpBaseSpeedMax() const;
		f32 getJumpMoveSpeedMin() const;
		f32 getJumpMoveSpeedMax() const;
		f32 getJumpAccelFront() const;
		f32 getJumpAccelBack() const;
		f32 getJumpAccelTurn() const;
		f32 getJumpTurnAngleStart() const;
		f32 getJumpTurnAngleLimit() const;
		f32 getJumpTurnAngleFast() const;
		f32 getJumpTurnAngleFastLimit() const;
		s32 getJumpTurnAccelFrame() const;
		s32 getJumpTurnAccelFrameFast() const;
		s32 getJumpTurnBrakeFrame() const;
		f32 getTrampleGravity() const;
		f32 getTrampleJumpPower() const;
		f32 getTrampleHighGravity() const;
		f32 getTrampleHighJumpPower() const;
		f32 getTrampleGravity2D() const;
		f32 getTrampleJumpPower2D() const;
		f32 getTrampleHighGravity2D() const;
		f32 getTrampleHighJumpPower2D() const;
		f32 getTrampleHipDropGravity() const;
		f32 getTrampleHipDropJumpPower() const;
		f32 getTrampleRisingBrakeVelH() const;
		f32 getTrampleJumpCodePower() const;
		f32 getTrampleJumpCodePowerSmall() const;
		f32 getCapLeapFrogJumpGravity() const;
		f32 getCapLeapFrogJumpPower() const;
		f32 getCapLeapFrogJumpPowerAir() const;
		f32 getObjLeapFrogJumpPower() const;
		f32 getObjLeapFrogJumpPowerHigh() const;
		f32 getCapHeadSpringJumpGravity() const;
		f32 getCapHeadSpringJumpPower() const;
		f32 getCapHeadSpringJumpGravityHigh() const;
		f32 getCapHeadSpringJumpPowerHigh() const;
		f32 getCapHeadSpringSpeedMax() const;
		s32 getContinuousJumpPreInputFrame() const;
		s32 getContinuousJumpCount() const;
		s32 getContinuousJumpTimer() const;
		f32 getContinuousJumpPowerMin() const;
		f32 getJumpPowerMax2nd() const;
		f32 getJumpGravity2nd() const;
		f32 getJumpPowerMax3rd() const;
		f32 getJumpGravity3rd() const;
		f32 getSpinFlowerJumpGravity() const;
		f32 getSpinFlowerJumpFallSpeedMax() const;
		f32 getSpinFlowerJumpMovePower() const;
		f32 getSpinFlowerJumpVelMax() const;
		s32 getSpinFlowerJumpStayFrame() const;
		f32 getSpinFlowerJumpStaySpeedMax() const;
		f32 getSpinFlowerJumpNoInputBrake() const;
		f32 getSpinFlowerJumpDownFallInitSpeed() const;
		f32 getSpinFlowerJumpDownFallPower() const;
		f32 getSpinFlowerJumpDownFallSpeedMax() const;
		f32 getJumpGravityForceRun() const;
		f32 getJumpPowerForceRun() const;
		f32 getCapCatchPopPower() const;
		f32 getCapCatchPopGravity() const;
		f32 getSquatJumpGravity() const;
		f32 getSquatJumpPower() const;
		f32 getSquatJumpBackPower() const;
		f32 getSquatJumpMovePowerFront() const;
		f32 getSquatJumpMovePowerSide() const;
		f32 getSquatJumpMoveSpeedMax() const;
		f32 getTurnJumpGravity() const;
		f32 getTurnJumpPower() const;
		f32 getTurnJumpVelH() const;
		f32 getTurnJumpBrake() const;
		f32 getTurnJumpAccel() const;
		f32 getTurnJumpSideAccel() const;
		f32 getLongJumpAccel() const;
		f32 getLongJumpBrake() const;
		f32 getLongJumpSideAccel() const;
		f32 getLongJumpGravity() const;
		f32 getLongJumpJumpPow() const;
		f32 getLongJumpMovePow() const;
		f32 getLongJumpInitSpeed() const;
		f32 getLongJumpSpeed() const;
		f32 getLongJumpSpeedMin() const;
		s32 getContinuousLongJumpCount() const;
		s32 getContinuousLongJumpTimer() const;
		f32 getGravityAir() const;
		f32 getFrictionAir() const;
		f32 getFallSpeedMax() const;
		f32 getLongFallDistance() const;
		f32 getFallWallScaleVelocity() const;
		s32 getDownFallFrameMin() const;
		f32 getGravityWallSlide() const;
		f32 getWallHeightLowLimit() const;
		f32 getWallKeepDegree() const;
		s32 getWallKeepFrame() const;
		f32 getWallJumpGravity() const;
		f32 getWallJumpHSpeed() const;
		f32 getWallJumpPower() const;
		s32 getWallJumpInvalidateInputFrame() const;
		s32 getWallInhibitAfterPunch() const;
		f32 getWallFollowAngleH() const;
		f32 getWallFollowAngleV() const;
		f32 getWallCatchDegree() const;
		f32 getWallCatchHeightEdgeTop() const;
		f32 getWallCatchHeightBottom() const;
		f32 getWallCatchKeepDegree() const;
		f32 getWallCatchMoveDegree() const;
		f32 getWallCatchMoveSpeed() const;
		f32 getWallCatchMoveHeightRange() const;
		s32 getWallCatchMoveInterpolate() const;
		s32 getWallCatchMoveFrame() const;
		s32 getWallCatchMoveFrameFast() const;
		s32 getWallCatchMoveFrameSwing() const;
		f32 getWallCatchInputRepeatAngle() const;
		f32 getWallClimbDegree() const;
		s32 getWallClimbJumpStartFrame() const;
		s32 getWallClimbJumpEndFrame() const;
		s32 getWallClimbStartFrame() const;
		f32 getWallClimbGravity() const;
		f32 getWallFallJumpSpeed() const;
		f32 getWallClimbJumpSpeedV() const;
		f32 getWallClimbJumpSpeedH() const;
		f32 getWallClimbJumpGravity() const;
		s32 getWallClimbJumpInvalidFrame() const;
		f32 getWallCatchHipLocalOffset() const;
		f32 getWallCatchHipStability() const;
		f32 getWallCatchHipFriction() const;
		f32 getWallCatchHipLimitDegree() const;
		f32 getWallCatchStainAreaOffset() const;
		f32 getGrabCeilRange() const;
		f32 getGrabCeilBodyRadius() const;
		f32 getGrabCeilLeaveSpeedMin() const;
		f32 getGrabCeilLeavePopPower() const;
		f32 getGrabCeilLeavePopGravity() const;
		f32 getGrabCeilSwingStartOffset() const;
		f32 getGrabCeilReverseInputBorder() const;
		f32 getGrabCeilInputPowerBorder() const;
		f32 getGrabCeilSwingWaitEnergy() const;
		f32 getGrabCeilEnableJumpEnergy() const;
		f32 getGrabCeilEnableJumpEnergyMax() const;
		f32 getGrabCeilJumpForceAngle() const;
		f32 getGrabCeilJumpPower() const;
		f32 getGrabCeilJumpMoveMin() const;
		f32 getGrabCeilJumpMoveMax() const;
		f32 getGrabCeilJumpGravity() const;
		s32 getGrabCeilJumpInvalidFrame() const;
		s32 getGrabCeilEnableNextFrame() const;
		s32 getGrabCeilEnableFallSnapFrame() const;
		s32 getPoleClimbPreInputSwing() const;
		f32 getPoleClimbInputRepeatAngle() const;
		f32 getPoleClimbInputDegreeMove() const;
		f32 getPoleClimbCatchRange() const;
		f32 getPoleClimbCatchRangeMin() const;
		f32 getPoleClimbCatchRangeMax() const;
		f32 getPoleClimbJointAngleMin() const;
		f32 getPoleClimbJointAngleMax() const;
		f32 getPoleClimbJointRangeMin() const;
		f32 getPoleClimbJointRangeMax() const;
		f32 getPoleClimbMoveWallDegree() const;
		f32 getPoleClimbUpMargine() const;
		f32 getPoleClimbUpSpeed() const;
		s32 getPoleClimbUpFrame() const;
		s32 getPoleClimbUpFrameFast() const;
		s32 getPoleClimbUpFrameSwing() const;
		f32 getPoleClimbDownSpeed() const;
		f32 getPoleClimbDownSpeedFast() const;
		f32 getPoleClimbDownSpeedSwing() const;
		s32 getPoleClimbDownFrame() const;
		s32 getPoleClimbDownKeepTime() const;
		f32 getPoleClimbTurnDist() const;
		s32 getPoleClimbTurnFrame() const;
		s32 getPoleClimbTurnStopFrame() const;
		s32 getPoleTopStartFrame() const;
		s32 getPoleTopEndFrame() const;
		f32 getPoleTopTurnSpeed() const;
		f32 getPoleTopEndUnderOffsetY() const;
		s32 getGroundSpinFrame() const;
		f32 getGroundSpinMoveSpeedMax() const;
		f32 getGroundSpinAccelRate() const;
		f32 getGroundSpinBrakeRate() const;
		f32 getSpinJumpGravity() const;
		f32 getSpinJumpPower() const;
		f32 getSpinJumpMoveSpeedMax() const;
		f32 getSpinJumpDownFallInitSpeed() const;
		f32 getSpinJumpDownFallPower() const;
		f32 getSpinJumpDownFallSpeedMax() const;
		f32 getSquatBrakeEndSpeed() const;
		f32 getSquatAccelRate() const;
		f32 getSquatBrakeRate() const;
		f32 getSquatBrakeRateOnSkate() const;
		f32 getSquatBrakeSideAccel() const;
		f32 getSquatBrakeSideRate() const;
		f32 getSquatBrakeSideAccelOnSkate() const;
		f32 getSquatBrakeSideRateOnSkate() const;
		f32 getSquatBrakeSideMaxSpeedRate() const;
		f32 getSquatWalkSpeed() const;
		f32 getSquatWalkTurnSpeed() const;
		s32 getSquatWalkTurnFrame() const;
		f32 getSquatJumpCeilSlideSpeed2D() const;
		f32 getHipDropSpeed() const;
		f32 getHipDropGravity() const;
		f32 getHipDropSpeedMax() const;
		s32 getHipDropLandCancelFrame() const;
		f32 getHipDropHeight() const;
		s32 getHipDropMsgInterval() const;
		f32 getJumpHipDropPower() const;
		s32 getJumpHipDropPermitBeginFrame() const;
		s32 getJumpHipDropPermitEndFrame() const;
		f32 getHeadSlidingSpeed() const;
		f32 getHeadSlidingSpeedMin() const;
		f32 getHeadSlidingBrake() const;
		f32 getHeadSlidingSideAccel() const;
		f32 getHeadSlidingJump() const;
		f32 getHeadSlidingGravityAir() const;
		f32 getSwimCenterOffset() const;
		f32 getSwimWallCatchOffset() const;
		f32 getSwimRisePower() const;
		f32 getSwimRiseSpeedMax() const;
		s32 getSwimRiseFrame() const;
		f32 getSwimGravity() const;
		f32 getSwimGravityWalk() const;
		f32 getSwimFallSpeedMax() const;
		f32 getSwimFloorAccelH() const;
		f32 getSwimFloorSpeedMaxH() const;
		f32 getSwimHighAccelH() const;
		f32 getSwimHighSpeedMaxH() const;
		f32 getSwimLowAccelH() const;
		f32 getSwimLowSpeedMaxH() const;
		f32 getSwimBrakeRateH() const;
		f32 getSwimWallHitSpeedMinH() const;
		s32 getSwimHighAccelPermitFrame() const;
		f32 getSwimFlowFieldBlend() const;
		f32 getSwimWalkAnimMinRate() const;
		f32 getSwimWalkAnimMaxRate() const;
		f32 getSwimWalkMaxSpeed() const;
		f32 getSwimSpinCapUpPower() const;
		f32 getSwimSpinCapUpSpeedMax() const;
		f32 getSwimRotStartAngle() const;
		f32 getSwimRotFastAngle() const;
		s32 getSwimRotAccelFrame() const;
		s32 getSwimRotAccelFrameFast() const;
		s32 getSwimRotBrakeFrame() const;
		f32 getSwimRotSpeedChangeStart() const;
		f32 getSwimRotSpeedForward() const;
		f32 getSwimRotSpeedMax() const;
		f32 getSwimSurfaceAccelH() const;
		f32 getSwimSurfaceSpeedMaxH() const;
		s32 getSwimSurfaceSpinCapFrame() const;
		f32 getSwimSurfaceSpinCapSpeedMaxH() const;
		f32 getSwimSurfaceStartDist() const;
		f32 getSwimSurfaceEndDist() const;
		f32 getSwimSurfaceGravity() const;
		f32 getSwimSurfaceBaseHeight() const;
		f32 getSwimSurfaceSpring() const;
		f32 getSwimSurfaceDamper() const;
		s32 getSwimSurfaceDamperStart() const;
		s32 getSwimSurfaceDamperFrame() const;
		f32 getSwimSurfaceEnableJumpHeight() const;
		s32 getSwimSurfacePreInputJumpFrame() const;
		f32 getSwimSurfaceMoveSpring() const;
		f32 getSwimSurfaceMoveDamper() const;
		f32 getSwimSurfaceMoveBaseHeight() const;
		f32 getSwimRunSurfaceBaseHeight() const;
		f32 getSwimRunSurfaceApproachRate() const;
		f32 getSwimRunSurfaceApproachLimit() const;
		f32 getSwimRunSurfaceBrakeBorder() const;
		f32 getSwimRunSurfaceBrakeH() const;
		f32 getSwimRunSurfaceApproachBorderMax() const;
		f32 getSwimRunSurfaceApproachBorderMin() const;
		f32 getSwimRunSurfaceApproachRateMin() const;
		f32 getSwimFallInSpeed() const;
		f32 getSwimFallInBrakeH() const;
		f32 getSwimFallInBrakeV() const;
		f32 getSwimHeadInBrakeH() const;
		f32 getSwimHeadInBrakeV() const;
		f32 getSwimHeadInRisePower() const;
		f32 getSwimHeadInRiseSpeedMax() const;
		f32 getSwimHeadInSurfaceHeight() const;
		s32 getSwimFallInForceSurfaceFrame() const;
		s32 getSwimFallInvalidJumpFrame() const;
		f32 getSwimDiveStartSpeed() const;
		f32 getSwimDiveBrake() const;
		f32 getSwimDiveEndSpeed() const;
		s32 getSwimDiveLandCount() const;
		s32 getSwimDiveLandCancelFrame() const;
		s32 getSwimDiveNoBrakeFrame() const;
		s32 getSwimDiveButtonValidFrame() const;
		s32 getSwimDiveEndFrame() const;
		f32 getSwimDiveInBrakeH() const;
		f32 getSwimDiveInBrakeV() const;
		f32 getSwimDiveInRisePower() const;
		f32 getSwimDiveInRiseSpeedMax() const;
		f32 getSwimDiveInSurfaceHeight() const;
		s32 getSwimDiveInKeepFrame() const;
		s32 getSwimHeadSlidingFrame() const;
		s32 getSwimHeadSlidingBrakeFrame() const;
		f32 getSwimHeadSlidingSpeed() const;
		f32 getSwimHeadSlidingSpeedEnd() const;
		f32 getSwimHeadSlidingBrake() const;
		f32 getSwimHeadSlidingSideAccel() const;
		f32 getSwimHeadSlidingJump() const;
		f32 getSwimHeadSlidingGravity() const;
		s32 getSwimHeadSlidingEndBrakeFrame() const;
		s32 getSwimHeadSlidingEndSpeedMin() const;
		f32 getSwimJumpHipDropSpeed() const;
		f32 getSwimJumpHipDropBrakeV() const;
		f32 getSwimJumpHipDropBrakeVCeiling() const;
		f32 getSwimJumpHipDropGravity() const;
		f32 getSwimJumpHipDropCancelSpeed() const;
		f32 getSwimJumpHipDropAccelH() const;
		f32 getSwimJumpHipDropMoveSpeedH() const;
		f32 getSwimJumpHipDropPopSpeed() const;
		f32 getSwimJumpHipDropPopJumpAdd() const;
		f32 getSwimTramplePower() const;
		f32 getDiveTramplePower() const;
		s32 getDiveTrampleCancelFrame() const;
		f32 getDamageSwimPushPower() const;
		f32 getDamageSwimGravity() const;
		s32 getDamageSwimCancelFrame() const;
		f32 getDamageSwimSurfaceGravity() const;
		f32 getDamageSwimSurfaceHopPower() const;
		f32 getDamageSwimSurfacePushPower() const;
		f32 getDamageSwimSurfaceLandSpeed() const;
		f32 getDamageSwimSurfaceLandBrake() const;
		f32 getDamageSwimSurfaceLandEndSpeed() const;
		s32 getDamageSwimSurfaceCancelFrame() const;
		f32 getDamageSwimBrakeRateGround() const;
		s32 getOxygenReduceFrame() const;
		s32 getOxygenNoReduceFrame() const;
		s32 getOxygenRecoveryFrame() const;
		s32 getOxygenDamageInterval() const;
		s32 getIceWaterDamageInterval() const;
		s32 getIceWaterRecoveryFrame() const;
		f32 getMoveAnimSpeedMax() const;
		f32 getAnimFrameRateSpeedMin() const;
		f32 getRunBorderSpeed() const;
		f32 getRunBlendRange() const;
		f32 getDashBorderSpeed() const;
		f32 getDashBlendRange() const;
		f32 getDashFastBorderSpeed() const;
		f32 getDashFastBlendRange() const;
		f32 getAnimFrameRateSpeedMax() const;
		f32 getAnimFrameRateRunStart() const;
		f32 getAnimFrameRateMinRun() const;
		f32 getAnimFrameRateMaxRun() const;
		f32 getAnimFrameRateMaxDash() const;
		f32 getAnimFrameRateMaxDashFast() const;
		f32 getRunStartPlayFrameScale() const;
		s32 getRunStartBlendFrame() const;
		f32 getDamageFireRunAnimRate() const;
		f32 getRunSkateAnimSpeedOffset() const;
		f32 getAnimFrameRateRange2D() const;
		f32 getAnimFrameRateMinRun2D() const;
		f32 getAnimFrameRateMaxRun2D() const;
		s32 getIKBlendFrameRun() const;
		f32 getIKBlendRateRunMin() const;
		f32 getIKBlendRateRunMax() const;
		f32 getRollingAnimBorderSpeedMin() const;
		f32 getRollingAnimBorderSpeedMax() const;
		f32 getRollingAnimFrameRateMin() const;
		f32 getRollingAnimFrameRateMax() const;
		s32 getSwimPaddleAnimInterval() const;
		s32 getSwimPaddleAnimRateIntervalMax() const;
		s32 getSwimPaddleAnimRateIntervalMin() const;
		f32 getSwimPaddleAnimMaxRate() const;
		f32 getSwimBentForwardMax() const;
		f32 getSwimBentForwardBlendRate() const;
		f32 getSwimBentSideMax() const;
		f32 getSwimBentSpineMax() const;
		f32 getSwimBentSideBlendRate() const;
		f32 getSwimBentFrontMax() const;
		f32 getSwimBentFrontBlendRate() const;
		f32 getSwimWalkAnimSpeedMax() const;
		f32 getSwimWalkAnimSpeedMin() const;
		f32 getSwimWalkAnimFrameRateMax() const;
		f32 getSwimWalkAnimFrameRateMin() const;
		f32 getSandSinkBorderMin() const;
		f32 getSandSinkBorderMax() const;
		f32 getSandSinkBorderRateMin() const;
		f32 getSandSinkBorderRateMax() const;
		f32 getSandSinkFrameRateMin() const;
		f32 getSandSinkFrameRateMax() const;
		s32 getLookAtEyeKeepFrame() const;
		s32 getLookAtEyeKeepFrameInSight() const;
		s32 getLookAtEyeKeepFrameWait() const;
		f32 getLookAtEyeDistance() const;
		f32 getLookAtEyeAngleMinH() const;
		f32 getLookAtEyeAngleMinInSightH() const;
		f32 getLookAtEyeAngleMaxH() const;
		f32 getLookAtEyeAngleMinV() const;
		f32 getLookAtEyeAngleMinInSightV() const;
		f32 getLookAtEyeAngleMaxV() const;
		f32 getTiltEyeBorderStart() const;
		f32 getTiltEyeBorderEnd() const;
		f32 getTiltEyeAngleScale() const;
		f32 getCenterTiltRateMax() const;
		f32 getNoseChildLocalOffset() const;
		f32 getNoseStability() const;
		f32 getNoseFriction() const;
		f32 getNoseLimitDegree() const;
		f32 getMustacheChildLocalOffset() const;
		f32 getMustacheStability() const;
		f32 getMustacheFriction() const;
		f32 getMustacheLimitDegree() const;
		s32 getCapInterpolateFrame() const;
		f32 getCapChildLocalOffset() const;
		f32 getCapStability() const;
		f32 getCapFriction() const;
		f32 getCapLimitDegree() const;
		f32 getCapTransStability() const;
		f32 getCapTransFriction() const;
		f32 getCapTransLimit() const;
		s32 getCapManHeroEyesWaitAppearFrame() const;
		s32 getDeadWipeStartDamage() const;
		s32 getDeadWipeWaitDamage() const;
		s32 getDeadWipeStartAbyss() const;
		s32 getDeadWipeWaitAbyss() const;
		s32 getDeadWipeStartAbyssWithCapMsg() const;
		s32 getDeadWipeWaitAbyssWithCapMsg() const;
		s32 getDeadWipeStartPress() const;
		s32 getDeadWipeWaitPress() const;
		s32 getDeadWipeStartSandSink() const;
		s32 getDeadWipeWaitSandSink() const;
		s32 getDeadWipeStartNoOxygen() const;
		s32 getDeadWipeWaitNoOxygen() const;
		s32 getDeadWipeStartIceWater() const;
		s32 getDeadWipeWaitIceWater() const;
		f32 getCoinDashSpeed() const;
		f32 getCoinDashSpeedLimit() const;
		f32 getAdditionalSpeedLimit() const;

		f32 mGravity; // _8
		f32 mFrictionAttack; // _C
		f32 mPushPower; // _10
		f32 mWaitPoseDegreeMax; // _14
		f32 mHillPoseDegreeMax; // _18
		f32 mTiltPoseDegreeMax; // _1C
		f32 mSlerpQuatRate; // _20
		f32 mSlerpQuatRateWait; // _24
		f32 mSlerpQuatGrav; // _28
		s32 mPreInputFrameCapThrow; // _2C
		s32 mEnableActionFrameCapCatch; // _30
		f32 mJumpPowerCapCatch; // _34
		f32 mJumpGravityCapCatch; // _38
		s32 mRunTimeContinuousThrow; // _3C
		f32 mRunSpeedMaxContinuousThrow; // _40
		s32 mRunAccelFrameContinuousThrow; // _44
		f32 mSeparateCheckHeight; // _48
		f32 mSeparateOffsetLerpRate; // _4C
		f32 mSeparateEnableThrowHeight; // _50
		f32 mTall; // _54
		f32 mCollisionRadius; // _58
		f32 mCollisionRadiusSquat; // _5C
		f32 mCollisionRadiusStand; // _60
		f32 mCollisionSmallStepHeight; // _64
		f32 mCollisionResetLimit; // _68
		f32 mCollisionResetLimitHigh; // _6C
		f32 mReflectCeilingPower; // _70
		f32 mReflectTossPower; // _74
		f32 mReflectUpperPunchScaleH; // _78
		f32 mCollisionHitDownAngleH; // _7C
		f32 mCollisionHitDownEscapeAngleV; // _80
		f32 mShadowDropHeightScale; // _84
		f32 mShadowDropNormalAdd; // _88
		f32 mShadowDropLengthMin; // _8C
		f32 mShadowDropLengthMax; // _90
		f32 mShadowDropLengthExtend; // _94
		f32 mGravityDamage; // _98
		f32 mHopPowerDamage; // _9C
		f32 mPushPowerDamage; // _A0
		s32 mDamageCancelFrame; // _A4
		s32 mDamageInvalidCount; // _A8
		s32 mDamageInvalidCountRecovery; // _AC
		s32 mDamageInvalidCountAbyss; // _B0
		f32 mNormalMinSpeed2D; // _B4
		f32 mNormalMaxSpeed2D; // _B8
		f32 mDashMaxSpeed2D; // _BC
		s32 mNormalAccelFrame2D; // _C0
		s32 mDashAccelFrame2D; // _C4
		s32 mNormalDashAnimFrame2D; // _C8
		s32 mNormalBrakeFrame2D; // _CC
		s32 mStickOnBrakeFrame2D; // _D0
		s32 mBrakeTurnStartFrame2D; // _D4
		f32 mTurnEndSpeedRate2D; // _D8
		f32 mJumpPowerMin2DArea; // _DC
		f32 mJumpPowerMax2DArea; // _E0
		f32 mJumpPowerMinBorder2D; // _E4
		f32 mJumpPowerMaxBorder2D; // _E8
		f32 mGravityMove; // _EC
		f32 mNormalMaxSpeed; // _F0
		f32 mNormalMinSpeed; // _F4
		s32 mNormalAccelFrame; // _F8
		f32 mRunAccelAverageScale; // _FC
		s32 mNormalBrakeFrame; // _100
		f32 mDashJudgeSpeed; // _104
		s32 mStickOnBrakeFrame; // _108
		s32 mNormalDashAnimFrame; // _10C
		f32 mRunAfterTurnSpeedMax; // _110
		f32 mRunAfterTurnScale; // _114
		s32 mRunAfterTurnFrame; // _118
		s32 mBrakeTurnStartFrame; // _11C
		f32 mBrakeOnSpeedRate; // _120
		s32 mBrakeOnCounterBorder; // _124
		s32 mWallPushFrame; // _128
		s32 mRunDeepDownFrame; // _12C
		s32 mRunDeepDownMargine; // _130
		s32 mQuickTurnJumpFrame; // _134
		s32 mRoundAccelFrame; // _138
		s32 mRoundBrakeFrame; // _13C
		f32 mRoundFastDegree; // _140
		s32 mRoundAccelFrameFast; // _144
		f32 mRoundMinDegree; // _148
		s32 mRoundBrakeFrameForce; // _14C
		f32 mRoundFastDegreeForce; // _150
		f32 mRoundLimitDegreeForce; // _154
		f32 mRoundLimitDegreeForceFast; // _158
		s32 mRoundAccelFrameForceFast; // _15C
		f32 mRoundLimitDegreeMin; // _160
		f32 mRoundLimitDegree; // _164
		s32 mIceAccelFrame; // _168
		s32 mIceBrakeFrame; // _16C
		s32 mIceBrakeFrameHigh; // _170
		s32 mIceBrakeFrameWall; // _174
		s32 mIceRoundAccelFrame; // _178
		s32 mIceRoundAccelFrameFast; // _17C
		s32 mIceRoundBrakeFrame; // _180
		f32 mIceRoundFastDegree; // _184
		f32 mIceRoundMinDegree; // _188
		f32 mIceRoundLimitDegree; // _18C
		f32 mHillAddSpeed; // _190
		f32 mHillSubSpeed; // _194
		s32 mHillAccelAddFrame; // _198
		s32 mHillAccelSubFrame; // _19C
		f32 mHillAccelSubAngleMin; // _1A0
		f32 mHillAccelSubAngleMax; // _1A4
		f32 mStandAngleMin; // _1A8
		f32 mStandAngleMax; // _1AC
		f32 mHillAngleSpeedMin; // _1B0
		f32 mHillAngleSpeedMax; // _1B4
		s32 mSpinCapThrowFrame; // _1B8
		s32 mSpinCapThrowFrameAir; // _1BC
		s32 mSpinCapThrowFrameSwim; // _1C0
		s32 mSpinCapThrowFrameSwing; // _1C4
		s32 mSpinCapThrowFrameContinuous; // _1C8
		s32 mSpinAttackFrame; // _1CC
		s32 mSpinBrakeFrame; // _1D0
		f32 mSpinAirJumpPower; // _1D4
		f32 mSpinAirSpeedMax; // _1D8
		f32 mGravitySpinAir; // _1DC
		f32 mSlerpQuatRateSpinAir; // _1E0
		f32 mSpinBrakeRate; // _1E4
		f32 mSpinBrakeSideAccel; // _1E8
		f32 mSpinBrakeSideBrakeRate; // _1EC
		f32 mSpinBrakeSideMaxSpeedRate; // _1F0
		f32 mSpinRoundLimitDegree; // _1F4
		f32 mDamageFireJumpPower1st; // _1F8
		f32 mDamageFireJumpPower2nd; // _1FC
		f32 mDamageFireJumpMoveSpeed; // _200
		f32 mDamageFireCeilHitSpeed; // _204
		f32 mDamageFireGravity; // _208
		s32 mDamageFireNoGravityFrame; // _20C
		s32 mDamageFireRunTime; // _210
		f32 mDamageFireRunSpeed; // _214
		f32 mDamageFireRunBrakeFrame; // _218
		s32 mSandSinkDeadTime; // _21C
		s32 mSandSinkBrakeHeightH; // _220
		s32 mSandSinkBrakeHeightV; // _224
		f32 mSandSinkHeight; // _228
		f32 mSandSinkCapThrow; // _22C
		f32 mSandSinkBrakeMinH; // _230
		f32 mSandSinkBrakeMaxH; // _234
		f32 mSandSinkBrakeMinV; // _238
		f32 mSandSinkBrakeMaxV; // _23C
		f32 mSlopeSlideAngleStart; // _240
		f32 mSlopeSlideAngleEnd; // _244
		f32 mSlopeSlideAccel; // _248
		f32 mSlopeSlideBrake; // _24C
		f32 mSlopeSlideMaxSpeed; // _250
		f32 mSlopeSlideSpeedEnd; // _254
		f32 mSlopeSlideSideAccel; // _258
		f32 mSlopeSlideSideBrake; // _25C
		f32 mSlopeSlideSideMaxSpeed; // _260
		f32 mSlopeTurnDegree; // _264
		s32 mSlideInvalidFrame; // _268
		s32 mSlopeForceFrame; // _26C
		f32 mSlopeSlideForceSideAccel; // _270
		f32 mSlopeSlideForceSideBrake; // _274
		f32 mSlopeSlideForceSideMaxSpeed; // _278
		f32 mSlopeSlideForceTurnDegree; // _27C
		f32 mSlopeRollingSpeedStart; // _280
		f32 mSlopeRollingSpeedBoost; // _284
		f32 mSlopeRollingMaxSpeed; // _288
		s32 mSlopeRollingFrameMinBoost; // _28C
		s32 mSlopeRollingFrameMin; // _290
		f32 mSlopeRollingStartJumpPower; // _294
		f32 mSlopeRollingStartSlideSpeed; // _298
		f32 mSlopeRollingAccel; // _29C
		f32 mSlopeRollingBrake; // _2A0
		f32 mSlopeRollingAgainst; // _2A4
		f32 mSlopeRollingAnglePowerMax; // _2A8
		f32 mSlopeRollingSpeedEnd; // _2AC
		f32 mSlopeRollingSideAccel; // _2B0
		f32 mSlopeRollingSideBrake; // _2B4
		f32 mSlopeRollingSideMaxSpeed; // _2B8
		s32 mSlopeRollingUnRollFrame; // _2BC
		f32 mSlopeRollingEndBrake; // _2C0
		f32 mSlopeRollingEndBrakeEndSpeed; // _2C4
		f32 mSlopeRollingReStartAccel; // _2C8
		f32 mSlopeRollingReStartMaxAdd; // _2CC
		s32 mSlopeRollingReStartInterval; // _2D0
		s32 mSlopeRollingReStartSwing; // _2D4
		s32 mSlopeRollingReStartCharge; // _2D8
		s32 mSlopeRollingReStartForce; // _2DC
		f32 mSlopeRollingAccelOnSkate; // _2E0
		f32 mSlopeRollingSideAccelOnSkate; // _2E4
		f32 mSlopeRollingBrakeOnSkate; // _2E8
		s32 mExtendFrame; // _2EC
		f32 mJumpInertiaRate; // _2F0
		f32 mJumpPowerMin; // _2F4
		f32 mJumpPowerMax; // _2F8
		f32 mJumpGravity; // _2FC
		f32 mJumpBaseSpeedMax; // _300
		f32 mJumpMoveSpeedMin; // _304
		f32 mJumpMoveSpeedMax; // _308
		f32 mJumpAccelFront; // _30C
		f32 mJumpAccelBack; // _310
		f32 mJumpAccelTurn; // _314
		f32 mJumpTurnAngleStart; // _318
		f32 mJumpTurnAngleLimit; // _31C
		f32 mJumpTurnAngleFast; // _320
		f32 mJumpTurnAngleFastLimit; // _324
		s32 mJumpTurnAccelFrame; // _328
		s32 mJumpTurnAccelFrameFast; // _32C
		s32 mJumpTurnBrakeFrame; // _330
		f32 mTrampleGravity; // _334
		f32 mTrampleJumpPower; // _338
		f32 mTrampleHighGravity; // _33C
		f32 mTrampleHighJumpPower; // _340
		f32 mTrampleGravity2D; // _344
		f32 mTrampleJumpPower2D; // _348
		f32 mTrampleHighGravity2D; // _34C
		f32 mTrampleHighJumpPower2D; // _350
		f32 mTrampleHipDropGravity; // _354
		f32 mTrampleHipDropJumpPower; // _358
		f32 mTrampleRisingBrakeVelH; // _35C
		f32 mTrampleJumpCodePower; // _360
		f32 mTrampleJumpCodePowerSmall; // _364
		f32 mCapLeapFrogJumpGravity; // _368
		f32 mCapLeapFrogJumpPower; // _36C
		f32 mCapLeapFrogJumpPowerAir; // _370
		f32 mObjLeapFrogJumpPower; // _374
		f32 mObjLeapFrogJumpPowerHigh; // _378
		f32 mCapHeadSpringJumpGravity; // _37C
		f32 mCapHeadSpringJumpPower; // _380
		f32 mCapHeadSpringJumpGravityHigh; // _384
		f32 mCapHeadSpringJumpPowerHigh; // _388
		f32 mCapHeadSpringSpeedMax; // _38C
		s32 mContinuousJumpPreInputFrame; // _390
		s32 mContinuousJumpCount; // _394
		s32 mContinuousJumpTimer; // _398
		f32 mContinuousJumpPowerMin; // _39C
		f32 mJumpPowerMax2nd; // _3A0
		f32 mJumpGravity2nd; // _3A4
		f32 mJumpPowerMax3rd; // _3A8
		f32 mJumpGravity3rd; // _3AC
		f32 mSpinFlowerJumpGravity; // _3B0
		f32 mSpinFlowerJumpFallSpeedMax; // _3B4
		f32 mSpinFlowerJumpMovePower; // _3B8
		f32 mSpinFlowerJumpVelMax; // _3BC
		s32 mSpinFlowerJumpStayFrame; // _3C0
		f32 mSpinFlowerJumpStaySpeedMax; // _3C4
		f32 mSpinFlowerJumpNoInputBrake; // _3C8
		f32 mSpinFlowerJumpDownFallInitSpeed; // _3CC
		f32 mSpinFlowerJumpDownFallPower; // _3D0
		f32 mSpinFlowerJumpDownFallSpeedMax; // _3D4
		f32 mJumpGravityForceRun; // _3D8
		f32 mJumpPowerForceRun; // _3DC
		f32 mCapCatchPopPower; // _3E0
		f32 mCapCatchPopGravity; // _3E4
		f32 mSquatJumpGravity; // _3E8
		f32 mSquatJumpPower; // _3EC
		f32 mSquatJumpBackPower; // _3F0
		f32 mSquatJumpMovePowerFront; // _3F4
		f32 mSquatJumpMovePowerSide; // _3F8
		f32 mSquatJumpMoveSpeedMax; // _3FC
		f32 mTurnJumpGravity; // _400
		f32 mTurnJumpPower; // _404
		f32 mTurnJumpVelH; // _408
		f32 mTurnJumpBrake; // _40C
		f32 mTurnJumpAccel; // _410
		f32 mTurnJumpSideAccel; // _414
		f32 mLongJumpAccel; // _418
		f32 mLongJumpBrake; // _41C
		f32 mLongJumpSideAccel; // _420
		f32 mLongJumpGravity; // _424
		f32 mLongJumpJumpPow; // _428
		f32 mLongJumpMovePow; // _42C
		f32 mLongJumpInitSpeed; // _430
		f32 mLongJumpSpeed; // _434
		f32 mLongJumpSpeedMin; // _438
		s32 mContinuousLongJumpCount; // _43C
		s32 mContinuousLongJumpTimer; // _440
		f32 mGravityAir; // _444
		f32 mFrictionAir; // _448
		f32 mFallSpeedMax; // _44C
		f32 mLongFallDistance; // _450
		f32 mFallWallScaleVelocity; // _454
		s32 mDownFallFrameMin; // _458
		f32 mGravityWallSlide; // _45C
		f32 mWallHeightLowLimit; // _460
		f32 mWallKeepDegree; // _464
		s32 mWallKeepFrame; // _468
		f32 mWallJumpGravity; // _46C
		f32 mWallJumpHSpeed; // _470
		f32 mWallJumpPower; // _474
		s32 mWallJumpInvalidateInputFrame; // _478
		s32 mWallInhibitAfterPunch; // _47C
		f32 mWallFollowAngleH; // _480
		f32 mWallFollowAngleV; // _484
		f32 mWallCatchDegree; // _488
		f32 mWallCatchHeightEdgeTop; // _48C
		f32 mWallCatchHeightBottom; // _490
		f32 mWallCatchKeepDegree; // _494
		f32 mWallCatchMoveDegree; // _498
		f32 mWallCatchMoveSpeed; // _49C
		f32 mWallCatchMoveHeightRange; // _4A0
		s32 mWallCatchMoveInterpolate; // _4A4
		s32 mWallCatchMoveFrame; // _4A8
		s32 mWallCatchMoveFrameFast; // _4AC
		s32 mWallCatchMoveFrameSwing; // _4B0
		f32 mWallCatchInputRepeatAngle; // _4B4
		f32 mWallClimbDegree; // _4B8
		s32 mWallClimbJumpStartFrame; // _4BC
		s32 mWallClimbJumpEndFrame; // _4C0
		s32 mWallClimbStartFrame; // _4C4
		f32 mWallClimbGravity; // _4C8
		f32 mWallFallJumpSpeed; // _4CC
		f32 mWallClimbJumpSpeedV; // _4D0
		f32 mWallClimbJumpSpeedH; // _4D4
		f32 mWallClimbJumpGravity; // _4D8
		s32 mWallClimbJumpInvalidFrame; // _4DC
		f32 mWallCatchHipLocalOffset; // _4E0
		f32 mWallCatchHipStability; // _4E4
		f32 mWallCatchHipFriction; // _4E8
		f32 mWallCatchHipLimitDegree; // _4EC
		f32 mWallCatchStainAreaOffset; // _4F0
		f32 mGrabCeilRange; // _4F4
		f32 mGrabCeilBodyRadius; // _4F8
		f32 mGrabCeilLeaveSpeedMin; // _4FC
		f32 mGrabCeilLeavePopPower; // _500
		f32 mGrabCeilLeavePopGravity; // _504
		f32 mGrabCeilSwingStartOffset; // _508
		f32 mGrabCeilReverseInputBorder; // _50C
		f32 mGrabCeilInputPowerBorder; // _510
		f32 mGrabCeilSwingWaitEnergy; // _514
		f32 mGrabCeilEnableJumpEnergy; // _518
		f32 mGrabCeilEnableJumpEnergyMax; // _51C
		f32 mGrabCeilJumpForceAngle; // _520
		f32 mGrabCeilJumpPower; // _524
		f32 mGrabCeilJumpMoveMin; // _528
		f32 mGrabCeilJumpMoveMax; // _52C
		f32 mGrabCeilJumpGravity; // _530
		s32 mGrabCeilJumpInvalidFrame; // _534
		s32 mGrabCeilEnableNextFrame; // _538
		s32 mGrabCeilEnableFallSnapFrame; // _53C
		s32 mPoleClimbPreInputSwing; // _540
		f32 mPoleClimbInputRepeatAngle; // _544
		f32 mPoleClimbInputDegreeMove; // _548
		f32 mPoleClimbCatchRange; // _54C
		f32 mPoleClimbCatchRangeMin; // _550
		f32 mPoleClimbCatchRangeMax; // _554
		f32 mPoleClimbJointAngleMin; // _558
		f32 mPoleClimbJointAngleMax; // _55C
		f32 mPoleClimbJointRangeMin; // _560
		f32 mPoleClimbJointRangeMax; // _564
		f32 mPoleClimbMoveWallDegree; // _568
		f32 mPoleClimbUpMargine; // _56C
		f32 mPoleClimbUpSpeed; // _570
		s32 mPoleClimbUpFrame; // _574
		s32 mPoleClimbUpFrameFast; // _578
		s32 mPoleClimbUpFrameSwing; // _57C
		f32 mPoleClimbDownSpeed; // _580
		f32 mPoleClimbDownSpeedFast; // _584
		f32 mPoleClimbDownSpeedSwing; // _588
		s32 mPoleClimbDownFrame; // _58C
		s32 mPoleClimbDownKeepTime; // _590
		f32 mPoleClimbTurnDist; // _594
		s32 mPoleClimbTurnFrame; // _598
		s32 mPoleClimbTurnStopFrame; // _59C
		s32 mPoleTopStartFrame; // _5A0
		s32 mPoleTopEndFrame; // _5A4
		f32 mPoleTopTurnSpeed; // _5A8
		f32 mPoleTopEndUnderOffsetY; // _5AC
		s32 mGroundSpinFrame; // _5B0
		f32 mGroundSpinMoveSpeedMax; // _5B4
		f32 mGroundSpinAccelRate; // _5B8
		f32 mGroundSpinBrakeRate; // _5BC
		f32 mSpinJumpGravity; // _5C0
		f32 mSpinJumpPower; // _5C4
		f32 mSpinJumpMoveSpeedMax; // _5C8
		f32 mSpinJumpDownFallInitSpeed; // _5CC
		f32 mSpinJumpDownFallPower; // _5D0
		f32 mSpinJumpDownFallSpeedMax; // _5D4
		f32 mSquatBrakeEndSpeed; // _5D8
		f32 mSquatAccelRate; // _5DC
		f32 mSquatBrakeRate; // _5E0
		f32 mSquatBrakeRateOnSkate; // _5E4
		f32 mSquatBrakeSideAccel; // _5E8
		f32 mSquatBrakeSideRate; // _5EC
		f32 mSquatBrakeSideAccelOnSkate; // _5F0
		f32 mSquatBrakeSideRateOnSkate; // _5F4
		f32 mSquatBrakeSideMaxSpeedRate; // _5F8
		f32 mSquatWalkSpeed; // _5FC
		f32 mSquatWalkTurnSpeed; // _600
		s32 mSquatWalkTurnFrame; // _604
		f32 mSquatJumpCeilSlideSpeed2D; // _608
		f32 mHipDropSpeed; // _60C
		f32 mHipDropGravity; // _610
		f32 mHipDropSpeedMax; // _614
		s32 mHipDropLandCancelFrame; // _618
		f32 mHipDropHeight; // _61C
		s32 mHipDropMsgInterval; // _620
		f32 mJumpHipDropPower; // _624
		s32 mJumpHipDropPermitBeginFrame; // _628
		s32 mJumpHipDropPermitEndFrame; // _62C
		f32 mHeadSlidingSpeed; // _630
		f32 mHeadSlidingSpeedMin; // _634
		f32 mHeadSlidingBrake; // _638
		f32 mHeadSlidingSideAccel; // _63C
		f32 mHeadSlidingJump; // _640
		f32 mHeadSlidingGravityAir; // _644
		f32 mSwimCenterOffset; // _648
		f32 mSwimWallCatchOffset; // _64C
		f32 mSwimRisePower; // _650
		f32 mSwimRiseSpeedMax; // _654
		s32 mSwimRiseFrame; // _658
		f32 mSwimGravity; // _65C
		f32 mSwimGravityWalk; // _660
		f32 mSwimFallSpeedMax; // _664
		f32 mSwimFloorAccelH; // _668
		f32 mSwimFloorSpeedMaxH; // _66C
		f32 mSwimHighAccelH; // _670
		f32 mSwimHighSpeedMaxH; // _674
		f32 mSwimLowAccelH; // _678
		f32 mSwimLowSpeedMaxH; // _67C
		f32 mSwimBrakeRateH; // _680
		f32 mSwimWallHitSpeedMinH; // _684
		s32 mSwimHighAccelPermitFrame; // _688
		f32 mSwimFlowFieldBlend; // _68C
		f32 mSwimWalkAnimMinRate; // _690
		f32 mSwimWalkAnimMaxRate; // _694
		f32 mSwimWalkMaxSpeed; // _698
		f32 mSwimSpinCapUpPower; // _69C
		f32 mSwimSpinCapUpSpeedMax; // _6A0
		f32 mSwimRotStartAngle; // _6A4
		f32 mSwimRotFastAngle; // _6A8
		s32 mSwimRotAccelFrame; // _6AC
		s32 mSwimRotAccelFrameFast; // _6B0
		s32 mSwimRotBrakeFrame; // _6B4
		f32 mSwimRotSpeedChangeStart; // _6B8
		f32 mSwimRotSpeedForward; // _6BC
		f32 mSwimRotSpeedMax; // _6C0
		f32 mSwimSurfaceAccelH; // _6C4
		f32 mSwimSurfaceSpeedMaxH; // _6C8
		s32 mSwimSurfaceSpinCapFrame; // _6CC
		f32 mSwimSurfaceSpinCapSpeedMaxH; // _6D0
		f32 mSwimSurfaceStartDist; // _6D4
		f32 mSwimSurfaceEndDist; // _6D8
		f32 mSwimSurfaceGravity; // _6DC
		f32 mSwimSurfaceBaseHeight; // _6E0
		f32 mSwimSurfaceSpring; // _6E4
		f32 mSwimSurfaceDamper; // _6E8
		s32 mSwimSurfaceDamperStart; // _6EC
		s32 mSwimSurfaceDamperFrame; // _6F0
		f32 mSwimSurfaceEnableJumpHeight; // _6F4
		s32 mSwimSurfacePreInputJumpFrame; // _6F8
		f32 mSwimSurfaceMoveSpring; // _6FC
		f32 mSwimSurfaceMoveDamper; // _700
		f32 mSwimSurfaceMoveBaseHeight; // _704
		f32 mSwimRunSurfaceBaseHeight; // _708
		f32 mSwimRunSurfaceApproachRate; // _70C
		f32 mSwimRunSurfaceApproachLimit; // _710
		f32 mSwimRunSurfaceBrakeBorder; // _714
		f32 mSwimRunSurfaceBrakeH; // _718
		f32 mSwimRunSurfaceApproachBorderMax; // _71C
		f32 mSwimRunSurfaceApproachBorderMin; // _720
		f32 mSwimRunSurfaceApproachRateMin; // _724
		f32 mSwimFallInSpeed; // _728
		f32 mSwimFallInBrakeH; // _72C
		f32 mSwimFallInBrakeV; // _730
		f32 mSwimHeadInBrakeH; // _734
		f32 mSwimHeadInBrakeV; // _738
		f32 mSwimHeadInRisePower; // _73C
		f32 mSwimHeadInRiseSpeedMax; // _740
		f32 mSwimHeadInSurfaceHeight; // _744
		s32 mSwimFallInForceSurfaceFrame; // _748
		s32 mSwimFallInvalidJumpFrame; // _74C
		f32 mSwimDiveStartSpeed; // _750
		f32 mSwimDiveBrake; // _754
		f32 mSwimDiveEndSpeed; // _758
		s32 mSwimDiveLandCount; // _75C
		s32 mSwimDiveLandCancelFrame; // _760
		s32 mSwimDiveNoBrakeFrame; // _764
		s32 mSwimDiveButtonValidFrame; // _768
		s32 mSwimDiveEndFrame; // _76C
		f32 mSwimDiveInBrakeH; // _770
		f32 mSwimDiveInBrakeV; // _774
		f32 mSwimDiveInRisePower; // _778
		f32 mSwimDiveInRiseSpeedMax; // _77C
		f32 mSwimDiveInSurfaceHeight; // _780
		s32 mSwimDiveInKeepFrame; // _784
		s32 mSwimHeadSlidingFrame; // _788
		s32 mSwimHeadSlidingBrakeFrame; // _78C
		f32 mSwimHeadSlidingSpeed; // _790
		f32 mSwimHeadSlidingSpeedEnd; // _794
		f32 mSwimHeadSlidingBrake; // _798
		f32 mSwimHeadSlidingSideAccel; // _79C
		f32 mSwimHeadSlidingJump; // _7A0
		f32 mSwimHeadSlidingGravity; // _7A4
		s32 mSwimHeadSlidingEndBrakeFrame; // _7A8
		s32 mSwimHeadSlidingEndSpeedMin; // _7AC
		f32 mSwimJumpHipDropSpeed; // _7B0
		f32 mSwimJumpHipDropBrakeV; // _7B4
		f32 mSwimJumpHipDropBrakeVCeiling; // _7B8
		f32 mSwimJumpHipDropGravity; // _7BC
		f32 mSwimJumpHipDropCancelSpeed; // _7C0
		f32 mSwimJumpHipDropAccelH; // _7C4
		f32 mSwimJumpHipDropMoveSpeedH; // _7C8
		f32 mSwimJumpHipDropPopSpeed; // _7CC
		f32 mSwimJumpHipDropPopJumpAdd; // _7D0
		f32 mSwimTramplePower; // _7D4
		f32 mDiveTramplePower; // _7D8
		s32 mDiveTrampleCancelFrame; // _7DC
		f32 mDamageSwimPushPower; // _7E0
		f32 mDamageSwimGravity; // _7E4
		s32 mDamageSwimCancelFrame; // _7E8
		f32 mDamageSwimSurfaceGravity; // _7EC
		f32 mDamageSwimSurfaceHopPower; // _7F0
		f32 mDamageSwimSurfacePushPower; // _7F4
		f32 mDamageSwimSurfaceLandSpeed; // _7F8
		f32 mDamageSwimSurfaceLandBrake; // _7FC
		f32 mDamageSwimSurfaceLandEndSpeed; // _800
		s32 mDamageSwimSurfaceCancelFrame; // _804
		f32 mDamageSwimBrakeRateGround; // _808
		s32 mOxygenReduceFrame; // _80C
		s32 mOxygenNoReduceFrame; // _810
		s32 mOxygenRecoveryFrame; // _814
		s32 mOxygenDamageInterval; // _818
		s32 mIceWaterDamageInterval; // _81C
		s32 mIceWaterRecoveryFrame; // _820
		f32 mMoveAnimSpeedMax; // _824
		f32 mAnimFrameRateSpeedMin; // _828
		f32 mRunBorderSpeed; // _82C
		f32 mRunBlendRange; // _830
		f32 mDashBorderSpeed; // _834
		f32 mDashBlendRange; // _838
		f32 mDashFastBorderSpeed; // _83C
		f32 mDashFastBlendRange; // _840
		f32 mAnimFrameRateSpeedMax; // _844
		f32 mAnimFrameRateRunStart; // _848
		f32 mAnimFrameRateMinRun; // _84C
		f32 mAnimFrameRateMaxRun; // _850
		f32 mAnimFrameRateMaxDash; // _854
		f32 mAnimFrameRateMaxDashFast; // _858
		f32 mRunStartPlayFrameScale; // _85C
		s32 mRunStartBlendFrame; // _860
		f32 mDamageFireRunAnimRate; // _864
		f32 mRunSkateAnimSpeedOffset; // _868
		f32 mAnimFrameRateRange2D; // _86C
		f32 mAnimFrameRateMinRun2D; // _870
		f32 mAnimFrameRateMaxRun2D; // _874
		s32 mIKBlendFrameRun; // _878
		f32 mIKBlendRateRunMin; // _87C
		f32 mIKBlendRateRunMax; // _880
		f32 mRollingAnimBorderSpeedMin; // _884
		f32 mRollingAnimBorderSpeedMax; // _888
		f32 mRollingAnimFrameRateMin; // _88C
		f32 mRollingAnimFrameRateMax; // _890
		s32 mSwimPaddleAnimInterval; // _894
		s32 mSwimPaddleAnimRateIntervalMax; // _898
		s32 mSwimPaddleAnimRateIntervalMin; // _89C
		f32 mSwimPaddleAnimMaxRate; // _8A0
		f32 mSwimBentForwardMax; // _8A4
		f32 mSwimBentForwardBlendRate; // _8A8
		f32 mSwimBentSideMax; // _8AC
		f32 mSwimBentSpineMax; // _8B0
		f32 mSwimBentSideBlendRate; // _8B4
		f32 mSwimBentFrontMax; // _8B8
		f32 mSwimBentFrontBlendRate; // _8BC
		f32 mSwimWalkAnimSpeedMax; // _8C0
		f32 mSwimWalkAnimSpeedMin; // _8C4
		f32 mSwimWalkAnimFrameRateMax; // _8C8
		f32 mSwimWalkAnimFrameRateMin; // _8CC
		f32 mSandSinkBorderMin; // _8D0
		f32 mSandSinkBorderMax; // _8D4
		f32 mSandSinkBorderRateMin; // _8D8
		f32 mSandSinkBorderRateMax; // _8DC
		f32 mSandSinkFrameRateMin; // _8E0
		f32 mSandSinkFrameRateMax; // _8E4
		s32 mLookAtEyeKeepFrame; // _8E8
		s32 mLookAtEyeKeepFrameInSight; // _8EC
		s32 mLookAtEyeKeepFrameWait; // _8F0
		f32 mLookAtEyeDistance; // _8F4
		f32 mLookAtEyeAngleMinH; // _8F8
		f32 mLookAtEyeAngleMinInSightH; // _8FC
		f32 mLookAtEyeAngleMaxH; // _900
		f32 mLookAtEyeAngleMinV; // _904
		f32 mLookAtEyeAngleMinInSightV; // _908
		f32 mLookAtEyeAngleMaxV; // _90C
		f32 mTiltEyeBorderStart; // _910
		f32 mTiltEyeBorderEnd; // _914
		f32 mTiltEyeAngleScale; // _918
		f32 mCenterTiltRateMax; // _91C
		f32 mNoseChildLocalOffset; // _920
		f32 mNoseStability; // _924
		f32 mNoseFriction; // _928
		f32 mNoseLimitDegree; // _92C
		f32 mMustacheChildLocalOffset; // _930
		f32 mMustacheStability; // _934
		f32 mMustacheFriction; // _938
		f32 mMustacheLimitDegree; // _93C
		s32 mCapInterpolateFrame; // _940
		f32 mCapChildLocalOffset; // _944
		f32 mCapStability; // _948
		f32 mCapFriction; // _94C
		f32 mCapLimitDegree; // _950
		f32 mCapTransStability; // _954
		f32 mCapTransFriction; // _958
		f32 mCapTransLimit; // _95C
		s32 mCapManHeroEyesWaitAppearFrame; // _960
		s32 mDeadWipeStartDamage; // _964
		s32 mDeadWipeWaitDamage; // _968
		s32 mDeadWipeStartAbyss; // _96C
		s32 mDeadWipeWaitAbyss; // _970
		s32 mDeadWipeStartAbyssWithCapMsg; // _974
		s32 mDeadWipeWaitAbyssWithCapMsg; // _978
		s32 mDeadWipeStartPress; // _97C
		s32 mDeadWipeWaitPress; // _980
		s32 mDeadWipeStartSandSink; // _984
		s32 mDeadWipeWaitSandSink; // _988
		s32 mDeadWipeStartNoOxygen; // _98C
		s32 mDeadWipeWaitNoOxygen; // _990
		s32 mDeadWipeStartIceWater; // _994
		s32 mDeadWipeWaitIceWater; // _998
		f32 mCoinDashSpeed; // _99C
		f32 mCoinDashSpeedLimit; // _9A0
		f32 mAdditionalSpeedLimit; // _9A4
    };
};