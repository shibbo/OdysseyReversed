/**
 * @file table.h
 * @brief Defines every class creation function in the game. Generated from createActorTable.py
 */

#pragma once

#include "al/LiveActor.h"
#include "types.h"

const u32 NUM_ACTORS = 0x23B;

namespace al
{
	class AllDeadWatcher;
	class BgmPlayObj;
	class CameraRailHolder;
	class CameraWatchPoint;
	class RippleFixMapParts;
	class FixMapParts;
	class EffectObj;
	class EffectObjCameraEmit;
	class EffectObjFollowCamera;
	class EffectObjFollowCameraLimit;
	class EffectObjInterval;
	class EntranceCameraStartObj;
	class FogRequester;
	class GraphicsObjShadowMaskSphere;
	class KeyMoveCameraObj;
	class LightningController;
	class OccludedEffectRequester;
	class OneMeshFixMapParts;
	class PrePassLineLight;
	class PrePassPointLight;
	class PrePassProjLight;
	class PrePassProjOrthoLight;
	class PrePassSpotLight;
	class RippleGeneratePoint;
	class SeBarrierObj;
	class SePlayObj;
	class SePlayRail;
	class Sky;
	class SwitchKeyMoveMapParts;
	class ThunderRenderRequester;
	class WaterAreaMoveModel;
	class AtmosScatterRequester;
	class BackHideParts;
	class ClockMapParts;
	class ConveyerMapParts;
	class FallMapParts;
	class FloaterMapParts;
	class FlowMapParts;
	class GateMapParts;
	class KeyMoveMapParts;
	class KeyMoveMapPartsGenerator;
	class RailMoveMapParts;
	class RollingCubeMapParts;
	class RotateMapParts;
	class SeesawMapParts;
	class SlideMapParts;
	class SubActorLodMapParts;
	class SurfMapParts;
	class SwingMapParts;
	class SwitchDitherMapParts;
	class SwitchKeepOnWatcher;
	class SwitchOpenMapParts;
	class VisibleSwitchMapParts;
	class WheelMapParts;
	class WobbleMapParts;
};

class AchievementNpc;
class AirBubble;
class AirBubbleGenerator;
class AirCurrent;
class AllDeadWatcherWithShine;
class AmiiboHelpNpc;
class AmiiboNpc;
class AnagramAlphabet;
class BalloonGameNpc;
class Barrel2D;
class BarrelGenerator2D;
class BarrierField;
class BazookaElectric;
class BendLeafTree;
class Bird;
class BirdCarryMeat;
class BirdPlayerGlideCtrl;
class BlockBrick;
class BlockBrick2D;
class BlockBrickBig2D;
class BlockEmpty;
class BlockEmpty2D;
class BlockHard;
class BlockQuestion;
class BlockQuestion2D;
class BlockTransparent;
class BlockTransparent2D;
class BlowObj;
class BombTail;
class BossForest;
class BossForestBlock;
class BossForestWander;
class BossKnuckle;
class BossKnuckleCounterGround;
class BossKnuckleFix;
class BossMagma;
class BossRaid;
class BossRaidNpc;
class BossRaidRivet;
class BreakablePole;
class Breeda;
class Bubble;
class Bubble2D;
class BubbleLauncher;
class Bull;
class Byugo;
class Cactus;
class CactusMini;
class CageShineWatcher;
class CageSwitch;
class BreakMapParts;
class CameraDemoGateMapParts;
class CameraDemoKeyMoveMapParts;
class CameraSub;
class Candlestand;
class CandlestandInitializer;
class CandlestandBgmDirector;
class CandlestandSaveWatcher;
class CandlestandWatcher;
class CapAccelerator;
class CapAppearMapParts;
class CapBeamer;
class CapBomb;
class CapCatapult;
class CapFlower;
class CapFlowerGroup;
class CapHanger;
class CapMessageAfterInformation;
class CapRack;
class CapRailMover;
class CapSlotBase;
class CapSwitch;
class CapSwitchTimer;
class CapThrower;
class CapTrampoline;
class Car;
class CarWatcher;
class CardboardBox;
class CatchBomb;
class Chair;
class CheckpointFlag;
class ChorobonHolder;
class ChurchDoor;
class CityBuilding;
class CityStreetlight;
class CityWorldSign;
class CityWorldUndergroundMachine;
class CitySign;
class CitySignal;
class ReactionObject;
class Closet;
class CloudStep;
class CollapseSandHill;
class CollectAnimalWatcher;
class CollectBgmSpeaker;
class CollectionList;
class Coin;
class Coin2D;
class Coin2DCityDirector;
class CoinBlow;
class CoinChameleon;
class CoinCirclePlacement;
class CoinCollect;
class CoinCollectHintObj;
class CoinCollect2D;
class CoinLead;
class CoinRail;
class CoinRing;
class CoinStackGroup;
class CrystalBreakable;
class DamageBallGenerator;
class DelaySwitch;
class DemoActorCapManHero;
class DemoActorCapManHeroine;
class DemoActorKoopaShip;
class DemoActorHack;
class DemoActorPeach;
class DemoActorShineTower;
class DemoChangeEffectObj;
class DemoWorldMoveHomeBackGround;
class DemoPeachWedding;
class DemoPlayer;
class DemoPlayerCap;
class DigPoint;
class Dokan;
class DokanKoopa;
class DokanMaze;
class DokanMazeDirector;
class DokanStageChange;
class DonkeyKong2D;
class Donsuke;
class Doshi;
class DoorAreaChange;
class DoorAreaChangeCap;
class DoorCity;
class DoorSnow;
class DoorWarp;
class DoorWarpStageChange;
class EchoBlockMapParts;
class EffectObjAlpha;
class EffectObjNpcManFar;
class EffectObjQualityChange;
class ElectricWire;
class ElectricWireKoopa;
class EventKeyMoveCameraObjNoDemo;
class EventKeyMoveCameraObjWithDemo;
class FigureWalkingNpc;
class FireBlower;
class FireBros;
class FireSwitch;
class FireHydrant;
class FireDrum2D;
class FishingFish;
class FixMapParts2D;
class FixMapPartsAppearKillAsync;
class FixMapPartsBgmChangeAction;
class FixMapPartsCapHanger;
class FixMapPartsDitherAppear;
class FixMapPartsForceSafetyPoint;
class FixMapPartsFukankunZoomCapMessage;
class FixMapPartsScenarioAction;
class FlyObject;
class ForestManSeed;
class FrailBox;
class Frog;
class Fukankun;
class FukankunZoomCapMessageSun;
class FukuwaraiWatcher;
class ForestWorldEnergyStand;
class ForestWorldFlowerCtrl;
class GabuZou;
class GabuZouGroup;
class Gamane;
class GiantWanderBoss;
class GoalMark;
class GolemClimb;
class Gotogoton;
class GotogotonGoal;
class ProjectGraphicsObjShadowMaskCube;
class GrowerBug;
class GrowerWorm;
class GrowFlowerCoin;
class GrowFlowerWatcher;
class GrowPlantGrowPlace;
class GrowPlantSeed;
class GrowPlantStartStage;
class GrowPlantWatcher;
class GunetterSpin;
class Gunetter;
class HackCar;
class HackFork;
class HammerBros;
class HammerBros2D;
class HelpNpc;
class HintNpc;
class HintPhoto;
class HintRouteGuidePoint;
class HipDropSwitch;
class HipDropSwitchTimer;
class HipDropTile;
class HipDropMoveLift;
class HipDropRepairParts;
class HipDropTransformPartsWatcher;
class HomeBed;
class HomeChair;
class HomeInside;
class HomeShip;
class Hosui;
class IcicleFall;
class Imomu;
class IndicatorDirector;
class Jango;
class Joku;
class JugemFishing;
class JumpingRopeNpc;
class Kakku;
class KaronWing;
class KickStone;
class KillerLauncher;
class KillerLauncherDot;
class KinokoUfo;
class Koopa;
class KoopaCapPlayer;
class KoopaChurch;
class KoopaLv1;
class KoopaShip;
class Kuribo2D;
class KuriboGenerator2D;
class KuriboGirl;
class KuriboHack;
class KuriboMini;
class KuriboTowerSwitch;
class KuriboWing;
class LavaFryingPan;
class LavaStewVeget;
class LavaPan;
class LavaWave;
class LifeMaxUpItem;
class LifeMaxUpItem2D;
class LifeUpItem;
class LifeUpItem2D;
class LongGenerator;
class MarchingCubeBlock;
class MapPartsRoulette;
class Megane;
class MeganeLiftExLift;
class MeganeKeyMoveMapParts;
class MeganeMapParts;
class Mirror;
class MoonBasementBreakParts;
class MoonBasementClimaxWatcher;
class MoonBasementMeteorPointObj;
class MoonBasementFinalGate;
class MoonBasementFallObjDecoration;
class MoonBasementFloor;
class MoonBasementGate;
class MoonBasementMeteorAreaObj;
class MoonBasementPillar;
class MoonBasementRock;
class MoonBasementSlideObj;
class MoonRock;
class MoonWorldBell;
class MoonWorldCaptureParadeLift;
class Mofumofu;
class MofumofuScrap;
class Motorcycle;
class MotorcycleParkingLot;
class MoveHomeNpc;
class MoviePlayerMapParts;
class MultiGateKeeperBonfire;
class MultiGateKeeperWatcher;
class Mummy;
class MummyGenerator;
class NeedleTrap;
class Nokonoko2D;
class NoteObj;
class NoteObj2D;
class NoteObjDirector;
class Objex;
class OceanWaveActor;
class OpeningStageStartDemo;
class PackunFire;
class PadRumblePoint;
class PaintObj;
class PaulineAtCeremony;
class PaulineAudience;
class PeachCastleCap;
class PeachWorldGate;
class PeachWorldMoatWater;
class PeachWorldTree;
class Pecho;
class Pen;
class PictureStageChange;
class PillarKeyMoveParts;
class PillarSwitchOpenMapParts;
class PlayerMotionObserver;
class PlayerStartObj;
class PlayerSubjectiveWatchCheckObj;
class PlayGuideBoard;
class PlayRecorder;
class PochiHintPhoto;
class Poetter;
class PoleClimbParts;
class PoleGrabCeil;
class PopnGenerator;
class ReactionObjectPoster;
class ReactionObjectSkyRhythm;
class PosterWatcher;
class PrePassCausticsLight;
class ProjectRaceCheckPoint;
class Pyramid;
class QuestObj;
class RabbitGraph;
class RaceAudienceNpc;
class RaceManGoal;
class RaceManRace;
class RaceManStart;
class RaceWatcher;
class RadiConRaceWatcher;
class RadioCassette;
class RadiconNpc;
class Radish;
class RailDrawer;
class RankingNpc;
class ReactionObjectCarBreakable;
class ReflectBombGenerator;
class RhythmSpotlight;
class RotateTarget;
class RouletteSwitch;
class RouteGuideArrow;
class RouteGuideRail;
class RunAwayNpc;
class SandGeyser;
class SandWorldHomeLift;
class SaucePan;
class SaveFlagCheckObj;
class ScenarioStartCamera;
class Senobi;
class SenobiGeneratePoint;
class SenobiMoveMapParts;
class SenobiMoveMapPartsConnector;
class SePlayObjWithSave;
class SequentialSwitch;
class SessionBgmCtrlObj;
class SessionMayorNpc;
class SessionMusicianNpc;
class Shibaken;
class Shine;
class ShineChipWatcher;
class ShineFukankunWatchObj;
class ShineTowerRocket;
class ShopBgmPlayer;
class ShopMark;
class ShoppingWatcher;
class SignBoardDanger;
class SignBoardLayoutTexture;
class SkyFukankunZoomCapMessage;
class SkyWorldCloud;
class SkyWorldKoopaFire;
class SkyWorldKoopaFrame;
class SkyWorldMiddleViewCloud;
class SignBoard;
class SnowWorldBigIcicle;
class SnowWorldSequenceFlagCheckObj;
class SmallWanderBoss;
class SneakingMan;
class SnowManRaceNpc;
class SnowVolume;
class SnowVolumeEraser;
class Souvenir;
class SouvenirDirector;
class Special2KeyMoveLift;
class Special2KeyMoveParts;
class SphinxQuiz;
class SphinxRide;
class SphinxTaxiWatcher;
class Squirrel;
class Stacker;
class StackerCapWorldCtrl;
class StageEventDemo;
class StageSwitchSelector;
class StageTalkDemoNpcCap;
class Stake;
class Statue;
class StatueSnapMark;
class SubActorLodFixPartsScenarioAction;
class SwitchAnd;
class CapMessagePlacement;
class TalkMessageInfoPointSaveObj;
class TalkNpc;
class TalkNpcFreeze;
class TalkPoint;
class Tank;
class TankReviveCtrl;
class TaxiStop;
class TextureReplaceScreen;
class Togezo;
class Togezo2D;
class TokimekiMayorNpc;
class TrampleBush;
class TrampleSwitch;
class TrampleSwitchTimer;
class TransparentWall;
class TreasureBox;
class TreasureBoxKey;
class TreasureBoxSequentialDirector;
class TRex;
class TRexScrollBreakMapParts;
class Tsukkun;
class TsukkunHole;
class TwistChainList;
class Utsubo;
class UtsuboWatcher;
class VocalMike;
class VolleyballBase;
class VolleyballNet;
class VolleyballNpc;
class Wanwan;
class WanwanHole;
class WaterfallWorldBigBreakableWall;
class WaterfallWorldFallDownBridge;
class WaterfallWorldWaterfall;
class WaterRoad;
class WeightSwitch;
class WheelWaveSurfParts;
class WindBlowPuzzle;
class WorldMapEarth;
class WorldTravelingNpc;
class WorldTravelingPeach;
class WorldWarpHole;
class Fastener;
class FastenerObj;
class CapRotateMapParts;
class HackMapParts;
class Pukupuku;
class PulseSwitch;
class RailCollision;
class RiseMapParts;
class ReactionMapParts;
class RiseMapPartsHolder;
class RocketFlower;
class WaveSurfMapParts;
class WindBlowMapParts;
class Yoshi;
class YoshiFruit;
class YoshiFruitShineHolder;
class Yukimaru;
class YukimaruRacer;
class YukimaruRacerTiago;

struct ActorEntry
{
    char* name;
    void* creationFuncPtr;
};

const ActorEntry entries[NUM_ACTORS] = {
		{ (char*)"AchievementNpc", (void*)al::createActorFunction<AchievementNpc> },
		{ (char*)"AirBubble", (void*)al::createActorFunction<AirBubble> },
		{ (char*)"AirBubbleGenerator", (void*)al::createActorFunction<AirBubbleGenerator> },
		{ (char*)"AirCurrent", (void*)al::createActorFunction<AirCurrent> },
		{ (char*)"AllDeadWatcher", (void*)al::createActorFunction<al::AllDeadWatcher> },
		{ (char*)"AllDeadWatcherWithShine", (void*)al::createActorFunction<AllDeadWatcherWithShine> },
		{ (char*)"AmiiboHelpNpc", (void*)al::createActorFunction<AmiiboHelpNpc> },
		{ (char*)"AmiiboNpc", (void*)al::createActorFunction<AmiiboNpc> },
		{ (char*)"AnagramAlphabet", (void*)al::createActorFunction<AnagramAlphabet> },
		{ (char*)"BalloonGameNpc", (void*)al::createActorFunction<BalloonGameNpc> },
		{ (char*)"Barrel2D", (void*)al::createActorFunction<Barrel2D> },
		{ (char*)"BarrelGenerator2D", (void*)al::createActorFunction<BarrelGenerator2D> },
		{ (char*)"BarrierField", (void*)al::createActorFunction<BarrierField> },
		{ (char*)"BazookaElectric", (void*)al::createActorFunction<BazookaElectric> },
		{ (char*)"BendLeafTree", (void*)al::createActorFunction<BendLeafTree> },
		{ (char*)"BgmPlayObj", (void*)al::createActorFunction<al::BgmPlayObj> },
		{ (char*)"Bird", (void*)al::createActorFunction<Bird> },
		{ (char*)"BirdCarryMeat", (void*)al::createActorFunction<BirdCarryMeat> },
		{ (char*)"BirdPlayerGlideCtr", (void*)al::createActorFunction<BirdPlayerGlideCtrl> },
		{ (char*)"BlockBrick", (void*)al::createActorFunction<BlockBrick> },
		{ (char*)"BlockBrick2D", (void*)al::createActorFunction<BlockBrick2D> },
		{ (char*)"BlockBrickBig2D", (void*)al::createActorFunction<BlockBrickBig2D> },
		{ (char*)"BlockEmpty", (void*)al::createActorFunction<BlockEmpty> },
		{ (char*)"BlockEmpty2D", (void*)al::createActorFunction<BlockEmpty2D> },
		{ (char*)"BlockHard", (void*)al::createActorFunction<BlockHard> },
		{ (char*)"BlockQuestion", (void*)al::createActorFunction<BlockQuestion> },
		{ (char*)"BlockQuestion2D", (void*)al::createActorFunction<BlockQuestion2D> },
		{ (char*)"BlockTransparent", (void*)al::createActorFunction<BlockTransparent> },
		{ (char*)"BlockTransparent2D", (void*)al::createActorFunction<BlockTransparent2D> },
		{ (char*)"BlowObj", (void*)al::createActorFunction<BlowObj> },
		{ (char*)"BombTai", (void*)al::createActorFunction<BombTail> },
		{ (char*)"BossForest", (void*)al::createActorFunction<BossForest> },
		{ (char*)"BossForestBlock", (void*)al::createActorFunction<BossForestBlock> },
		{ (char*)"BossForestWander", (void*)al::createActorFunction<BossForestWander> },
		{ (char*)"BossKnuckle", (void*)al::createActorFunction<BossKnuckle> },
		{ (char*)"BossKnuckleCounterGround", (void*)al::createActorFunction<BossKnuckleCounterGround> },
		{ (char*)"BossKnuckleFix", (void*)al::createActorFunction<BossKnuckleFix> },
		{ (char*)"BossMagm", (void*)al::createActorFunction<BossMagma> },
		{ (char*)"BossRaid", (void*)al::createActorFunction<BossRaid> },
		{ (char*)"BossRaidNpc", (void*)al::createActorFunction<BossRaidNpc> },
		{ (char*)"BossRaidRivet", (void*)al::createActorFunction<BossRaidRivet> },
		{ (char*)"BreakablePole", (void*)al::createActorFunction<BreakablePole> },
		{ (char*)"Breed", (void*)al::createActorFunction<Breeda> },
		{ (char*)"Bubble", (void*)al::createActorFunction<Bubble> },
		{ (char*)"Bubble2D", (void*)al::createActorFunction<Bubble2D> },
		{ (char*)"BubbleLauncher", (void*)al::createActorFunction<BubbleLauncher> },
		{ (char*)"Bu", (void*)al::createActorFunction<Bull> },
		{ (char*)"Byugo", (void*)al::createActorFunction<Byugo> },
		{ (char*)"Cactus", (void*)al::createActorFunction<Cactus> },
		{ (char*)"CactusMini", (void*)al::createActorFunction<CactusMini> },
		{ (char*)"CageShineWatcher", (void*)al::createActorFunction<CageShineWatcher> },
		{ (char*)"CageSwitch", (void*)al::createActorFunction<CageSwitch> },
		{ (char*)"BreakMapParts", (void*)al::createActorFunction<BreakMapParts> },
		{ (char*)"CameraDemoGateMapParts", (void*)al::createActorFunction<CameraDemoGateMapParts> },
		{ (char*)"CameraDemoKeyMoveMapParts", (void*)al::createActorFunction<CameraDemoKeyMoveMapParts> },
		{ (char*)"CameraRailHolder", (void*)al::createActorFunction<al::CameraRailHolder> },
		{ (char*)"CameraSub", (void*)al::createActorFunction<CameraSub> },
		{ (char*)"CameraWatchPoint", (void*)al::createActorFunction<al::CameraWatchPoint> },
		{ (char*)"Candlestand", (void*)al::createActorFunction<Candlestand> },
		{ (char*)"CandlestandInitializer", (void*)al::createActorFunction<CandlestandInitializer> },
		{ (char*)"CandlestandBgmDirector", (void*)al::createActorFunction<CandlestandBgmDirector> },
		{ (char*)"CandlestandSaveWatcher", (void*)al::createActorFunction<CandlestandSaveWatcher> },
		{ (char*)"CandlestandWatcher", (void*)al::createActorFunction<CandlestandWatcher> },
		{ (char*)"CapAccelerator", (void*)al::createActorFunction<CapAccelerator> },
		{ (char*)"CapAppearMapParts", (void*)al::createActorFunction<CapAppearMapParts> },
		{ (char*)"CapBeamer", (void*)al::createActorFunction<CapBeamer> },
		{ (char*)"CapBomb", (void*)al::createActorFunction<CapBomb> },
		{ (char*)"CapCatapult", (void*)al::createActorFunction<CapCatapult> },
		{ (char*)"CapFlower", (void*)al::createActorFunction<CapFlower> },
		{ (char*)"CapFlowerGroup", (void*)al::createActorFunction<CapFlowerGroup> },
		{ (char*)"CapHanger", (void*)al::createActorFunction<CapHanger> },
		{ (char*)"CapMessageAfterInformation", (void*)al::createActorFunction<CapMessageAfterInformation> },
		{ (char*)"CapRack", (void*)al::createActorFunction<CapRack> },
		{ (char*)"CapRailMover", (void*)al::createActorFunction<CapRailMover> },
		{ (char*)"CapSlotBase", (void*)al::createActorFunction<CapSlotBase> },
		{ (char*)"CapSwitch", (void*)al::createActorFunction<CapSwitch> },
		{ (char*)"CapSwitchTimer", (void*)al::createActorFunction<CapSwitchTimer> },
		{ (char*)"CapThrower", (void*)al::createActorFunction<CapThrower> },
		{ (char*)"CapTrampoline", (void*)al::createActorFunction<CapTrampoline> },
		{ (char*)"Car", (void*)al::createActorFunction<Car> },
		{ (char*)"CarWatcher", (void*)al::createActorFunction<CarWatcher> },
		{ (char*)"CardboardBox", (void*)al::createActorFunction<CardboardBox> },
		{ (char*)"CatchBomb", (void*)al::createActorFunction<CatchBomb> },
		{ (char*)"Chair", (void*)al::createActorFunction<Chair> },
		{ (char*)"CheckpointFlag", (void*)al::createActorFunction<CheckpointFlag> },
		{ (char*)"ChorobonHolder", (void*)al::createActorFunction<ChorobonHolder> },
		{ (char*)"ChurchDoor", (void*)al::createActorFunction<ChurchDoor> },
		{ (char*)"CityBuilding", (void*)al::createActorFunction<CityBuilding> },
		{ (char*)"CityStreetlight", (void*)al::createActorFunction<CityStreetlight> },
		{ (char*)"CityWorldSign", (void*)al::createActorFunction<CityWorldSign> },
		{ (char*)"CityWorldUndergroundMachine", (void*)al::createActorFunction<CityWorldUndergroundMachine> },
		{ (char*)"CitySign", (void*)al::createActorFunction<CitySign> },
		{ (char*)"CitySign", (void*)al::createActorFunction<CitySignal> },
		{ (char*)"ReactionObject", (void*)al::createActorFunction<ReactionObject> },
		{ (char*)"Closet", (void*)al::createActorFunction<Closet> },
		{ (char*)"CloudStep", (void*)al::createActorFunction<CloudStep> },
		{ (char*)"CollapseSandHi", (void*)al::createActorFunction<CollapseSandHill> },
		{ (char*)"CollectAnimalWatcher", (void*)al::createActorFunction<CollectAnimalWatcher> },
		{ (char*)"CollectBgmSpeaker", (void*)al::createActorFunction<CollectBgmSpeaker> },
		{ (char*)"CollectionList", (void*)al::createActorFunction<CollectionList> },
		{ (char*)"Coin", (void*)al::createActorFunction<Coin> },
		{ (char*)"Coin2D", (void*)al::createActorFunction<Coin2D> },
		{ (char*)"Coin2DCityDirector", (void*)al::createActorFunction<Coin2DCityDirector> },
		{ (char*)"CoinBlow", (void*)al::createActorFunction<CoinBlow> },
		{ (char*)"CoinChameleon", (void*)al::createActorFunction<CoinChameleon> },
		{ (char*)"CoinCirclePlacement", (void*)al::createActorFunction<CoinCirclePlacement> },
		{ (char*)"CoinCollect", (void*)al::createActorFunction<CoinCollect> },
		{ (char*)"CoinCollectHintObj", (void*)al::createActorFunction<CoinCollectHintObj> },
		{ (char*)"CoinCollect2D", (void*)al::createActorFunction<CoinCollect2D> },
		{ (char*)"CoinLead", (void*)al::createActorFunction<CoinLead> },
		{ (char*)"CoinRai", (void*)al::createActorFunction<CoinRail> },
		{ (char*)"CoinRing", (void*)al::createActorFunction<CoinRing> },
		{ (char*)"CoinStackGroup", (void*)al::createActorFunction<CoinStackGroup> },
		{ (char*)"CrystalBreakable", (void*)al::createActorFunction<CrystalBreakable> },
		{ (char*)"DamageBallGenerator", (void*)al::createActorFunction<DamageBallGenerator> },
		{ (char*)"DelaySwitch", (void*)al::createActorFunction<DelaySwitch> },
		{ (char*)"DemoActorCapManHero", (void*)al::createActorFunction<DemoActorCapManHero> },
		{ (char*)"DemoActorCapManHeroine", (void*)al::createActorFunction<DemoActorCapManHeroine> },
		{ (char*)"DemoActorKoopaShip", (void*)al::createActorFunction<DemoActorKoopaShip> },
		{ (char*)"DemoActorHack", (void*)al::createActorFunction<DemoActorHack> },
		{ (char*)"DemoActorPeach", (void*)al::createActorFunction<DemoActorPeach> },
		{ (char*)"DemoActorShineTower", (void*)al::createActorFunction<DemoActorShineTower> },
		{ (char*)"RippleFixMapParts", (void*)al::createActorFunction<al::RippleFixMapParts> },
		{ (char*)"DemoChangeEffectObj", (void*)al::createActorFunction<DemoChangeEffectObj> },
		{ (char*)"DemoWorldMoveHomeBackGround", (void*)al::createActorFunction<DemoWorldMoveHomeBackGround> },
		{ (char*)"DemoPeachWedding", (void*)al::createActorFunction<DemoPeachWedding> },
		{ (char*)"DemoPlayer", (void*)al::createActorFunction<DemoPlayer> },
		{ (char*)"DemoPlayerCap", (void*)al::createActorFunction<DemoPlayerCap> },
		{ (char*)"DigPoint", (void*)al::createActorFunction<DigPoint> },
		{ (char*)"FixMapParts", (void*)al::createActorFunction<al::FixMapParts> },
		{ (char*)"Dokan", (void*)al::createActorFunction<Dokan> },
		{ (char*)"DokanKoop", (void*)al::createActorFunction<DokanKoopa> },
		{ (char*)"DokanMaze", (void*)al::createActorFunction<DokanMaze> },
		{ (char*)"DokanMazeDirector", (void*)al::createActorFunction<DokanMazeDirector> },
		{ (char*)"DokanStageChange", (void*)al::createActorFunction<DokanStageChange> },
		{ (char*)"DonkeyKong2D", (void*)al::createActorFunction<DonkeyKong2D> },
		{ (char*)"Donsuke", (void*)al::createActorFunction<Donsuke> },
		{ (char*)"Doshi", (void*)al::createActorFunction<Doshi> },
		{ (char*)"DoorAreaChange", (void*)al::createActorFunction<DoorAreaChange> },
		{ (char*)"DoorAreaChangeCap", (void*)al::createActorFunction<DoorAreaChangeCap> },
		{ (char*)"DoorCity", (void*)al::createActorFunction<DoorCity> },
		{ (char*)"DoorSnow", (void*)al::createActorFunction<DoorSnow> },
		{ (char*)"DoorWarp", (void*)al::createActorFunction<DoorWarp> },
		{ (char*)"DoorWarpStageChange", (void*)al::createActorFunction<DoorWarpStageChange> },
		{ (char*)"EchoBlockMapParts", (void*)al::createActorFunction<EchoBlockMapParts> },
		{ (char*)"EffectObj", (void*)al::createActorFunction<al::EffectObj> },
		{ (char*)"EffectObjAlph", (void*)al::createActorFunction<EffectObjAlpha> },
		{ (char*)"EffectObjCameraEmit", (void*)al::createActorFunction<al::EffectObjCameraEmit> },
		{ (char*)"EffectObjFollowCamer", (void*)al::createActorFunction<al::EffectObjFollowCamera> },
		{ (char*)"EffectObjFollowCameraLimit", (void*)al::createActorFunction<al::EffectObjFollowCameraLimit> },
		{ (char*)"EffectObjInterv", (void*)al::createActorFunction<al::EffectObjInterval> },
		{ (char*)"EffectObjNpcManFar", (void*)al::createActorFunction<EffectObjNpcManFar> },
		{ (char*)"EffectObjQualityChange", (void*)al::createActorFunction<EffectObjQualityChange> },
		{ (char*)"ElectricWire", (void*)al::createActorFunction<ElectricWire> },
		{ (char*)"ElectricWireKoop", (void*)al::createActorFunction<ElectricWireKoopa> },
		{ (char*)"EntranceCameraStartObj", (void*)al::createActorFunction<al::EntranceCameraStartObj> },
		{ (char*)"EventKeyMoveCameraObjNoDemo", (void*)al::createActorFunction<EventKeyMoveCameraObjNoDemo> },
		{ (char*)"EventKeyMoveCameraObjWithDemo", (void*)al::createActorFunction<EventKeyMoveCameraObjWithDemo> },
		{ (char*)"FigureWalkingNpc", (void*)al::createActorFunction<FigureWalkingNpc> },
		{ (char*)"FireBlower", (void*)al::createActorFunction<FireBlower> },
		{ (char*)"FireBros", (void*)al::createActorFunction<FireBros> },
		{ (char*)"FireSwitch", (void*)al::createActorFunction<FireSwitch> },
		{ (char*)"FireHydrant", (void*)al::createActorFunction<FireHydrant> },
		{ (char*)"FireDrum2D", (void*)al::createActorFunction<FireDrum2D> },
		{ (char*)"FishingFish", (void*)al::createActorFunction<FishingFish> },
		{ (char*)"FixMapParts2D", (void*)al::createActorFunction<FixMapParts2D> },
		{ (char*)"FixMapPartsAppearKillAsync", (void*)al::createActorFunction<FixMapPartsAppearKillAsync> },
		{ (char*)"FixMapPartsBgmChangeAction", (void*)al::createActorFunction<FixMapPartsBgmChangeAction> },
		{ (char*)"FixMapPartsCapHanger", (void*)al::createActorFunction<FixMapPartsCapHanger> },
		{ (char*)"FixMapPartsDitherAppear", (void*)al::createActorFunction<FixMapPartsDitherAppear> },
		{ (char*)"FixMapPartsForceSafetyPoint", (void*)al::createActorFunction<FixMapPartsForceSafetyPoint> },
		{ (char*)"FixMapPartsFukankunZoomCapMessage", (void*)al::createActorFunction<FixMapPartsFukankunZoomCapMessage> },
		{ (char*)"FixMapPartsScenarioAction", (void*)al::createActorFunction<FixMapPartsScenarioAction> },
		{ (char*)"FlyObject", (void*)al::createActorFunction<FlyObject> },
		{ (char*)"ForestManSeed", (void*)al::createActorFunction<ForestManSeed> },
		{ (char*)"FogRequester", (void*)al::createActorFunction<al::FogRequester> },
		{ (char*)"FrailBox", (void*)al::createActorFunction<FrailBox> },
		{ (char*)"Frog", (void*)al::createActorFunction<Frog> },
		{ (char*)"Fukankun", (void*)al::createActorFunction<Fukankun> },
		{ (char*)"FukankunZoomCapMessageSun", (void*)al::createActorFunction<FukankunZoomCapMessageSun> },
		{ (char*)"FukuwaraiWatcher", (void*)al::createActorFunction<FukuwaraiWatcher> },
		{ (char*)"ForestWorldEnergyStand", (void*)al::createActorFunction<ForestWorldEnergyStand> },
		{ (char*)"ForestWorldFlowerCtr", (void*)al::createActorFunction<ForestWorldFlowerCtrl> },
		{ (char*)"GabuZou", (void*)al::createActorFunction<GabuZou> },
		{ (char*)"GabuZouGroup", (void*)al::createActorFunction<GabuZouGroup> },
		{ (char*)"Gamane", (void*)al::createActorFunction<Gamane> },
		{ (char*)"GiantWanderBoss", (void*)al::createActorFunction<GiantWanderBoss> },
		{ (char*)"GoalMark", (void*)al::createActorFunction<GoalMark> },
		{ (char*)"GolemClimb", (void*)al::createActorFunction<GolemClimb> },
		{ (char*)"Gotogoton", (void*)al::createActorFunction<Gotogoton> },
		{ (char*)"GotogotonGo", (void*)al::createActorFunction<GotogotonGoal> },
		{ (char*)"ProjectGraphicsObjShadowMaskCube", (void*)al::createActorFunction<ProjectGraphicsObjShadowMaskCube> },
		{ (char*)"GraphicsObjShadowMaskSphere", (void*)al::createActorFunction<al::GraphicsObjShadowMaskSphere> },
		{ (char*)"GrowerBug", (void*)al::createActorFunction<GrowerBug> },
		{ (char*)"GrowerWorm", (void*)al::createActorFunction<GrowerWorm> },
		{ (char*)"GrowFlowerCoin", (void*)al::createActorFunction<GrowFlowerCoin> },
		{ (char*)"GrowFlowerWatcher", (void*)al::createActorFunction<GrowFlowerWatcher> },
		{ (char*)"GrowPlantGrowPlace", (void*)al::createActorFunction<GrowPlantGrowPlace> },
		{ (char*)"GrowPlantSeed", (void*)al::createActorFunction<GrowPlantSeed> },
		{ (char*)"GrowPlantStartStage", (void*)al::createActorFunction<GrowPlantStartStage> },
		{ (char*)"GrowPlantWatcher", (void*)al::createActorFunction<GrowPlantWatcher> },
		{ (char*)"GunetterSpin", (void*)al::createActorFunction<GunetterSpin> },
		{ (char*)"Gunetter", (void*)al::createActorFunction<Gunetter> },
		{ (char*)"HackCar", (void*)al::createActorFunction<HackCar> },
		{ (char*)"HackFork", (void*)al::createActorFunction<HackFork> },
		{ (char*)"HammerBros", (void*)al::createActorFunction<HammerBros> },
		{ (char*)"HammerBros2D", (void*)al::createActorFunction<HammerBros2D> },
		{ (char*)"HelpNpc", (void*)al::createActorFunction<HelpNpc> },
		{ (char*)"HintNpc", (void*)al::createActorFunction<HintNpc> },
		{ (char*)"HintPhoto", (void*)al::createActorFunction<HintPhoto> },
		{ (char*)"HintRouteGuidePoint", (void*)al::createActorFunction<HintRouteGuidePoint> },
		{ (char*)"HipDropSwitch", (void*)al::createActorFunction<HipDropSwitch> },
		{ (char*)"HipDropSwitchTimer", (void*)al::createActorFunction<HipDropSwitchTimer> },
		{ (char*)"HipDropTile", (void*)al::createActorFunction<HipDropTile> },
		{ (char*)"HipDropMoveLift", (void*)al::createActorFunction<HipDropMoveLift> },
		{ (char*)"HipDropRepairParts", (void*)al::createActorFunction<HipDropRepairParts> },
		{ (char*)"HipDropTransformPartsWatcher", (void*)al::createActorFunction<HipDropTransformPartsWatcher> },
		{ (char*)"HomeBed", (void*)al::createActorFunction<HomeBed> },
		{ (char*)"HomeChair", (void*)al::createActorFunction<HomeChair> },
		{ (char*)"HomeInside", (void*)al::createActorFunction<HomeInside> },
		{ (char*)"HomeShip", (void*)al::createActorFunction<HomeShip> },
		{ (char*)"Hosui", (void*)al::createActorFunction<Hosui> },
		{ (char*)"IcicleF", (void*)al::createActorFunction<IcicleFall> },
		{ (char*)"Imomu", (void*)al::createActorFunction<Imomu> },
		{ (char*)"IndicatorDirector", (void*)al::createActorFunction<IndicatorDirector> },
		{ (char*)"Jango", (void*)al::createActorFunction<Jango> },
		{ (char*)"Joku", (void*)al::createActorFunction<Joku> },
		{ (char*)"JugemFishing", (void*)al::createActorFunction<JugemFishing> },
		{ (char*)"JumpingRopeNpc", (void*)al::createActorFunction<JumpingRopeNpc> },
		{ (char*)"Kakku", (void*)al::createActorFunction<Kakku> },
		{ (char*)"KaronWing", (void*)al::createActorFunction<KaronWing> },
		{ (char*)"KeyMoveCameraObj", (void*)al::createActorFunction<al::KeyMoveCameraObj> },
		{ (char*)"KickStone", (void*)al::createActorFunction<KickStone> },
		{ (char*)"KillerLauncher", (void*)al::createActorFunction<KillerLauncher> },
		{ (char*)"KillerLauncherDot", (void*)al::createActorFunction<KillerLauncherDot> },
		{ (char*)"KinokoUfo", (void*)al::createActorFunction<KinokoUfo> },
		{ (char*)"Koop", (void*)al::createActorFunction<Koopa> },
		{ (char*)"KoopaCapPlayer", (void*)al::createActorFunction<KoopaCapPlayer> },
		{ (char*)"KoopaChurch", (void*)al::createActorFunction<KoopaChurch> },
		{ (char*)"KoopaLv1", (void*)al::createActorFunction<KoopaLv1> },
		{ (char*)"KoopaShip", (void*)al::createActorFunction<KoopaShip> },
		{ (char*)"Kuribo2D", (void*)al::createActorFunction<Kuribo2D> },
		{ (char*)"KuriboGenerator2D", (void*)al::createActorFunction<KuriboGenerator2D> },
		{ (char*)"KuriboGir", (void*)al::createActorFunction<KuriboGirl> },
		{ (char*)"KuriboHack", (void*)al::createActorFunction<KuriboHack> },
		{ (char*)"KuriboMini", (void*)al::createActorFunction<KuriboMini> },
		{ (char*)"KuriboTowerSwitch", (void*)al::createActorFunction<KuriboTowerSwitch> },
		{ (char*)"KuriboWing", (void*)al::createActorFunction<KuriboWing> },
		{ (char*)"LavaFryingPan", (void*)al::createActorFunction<LavaFryingPan> },
		{ (char*)"LavaStewVeget", (void*)al::createActorFunction<LavaStewVeget> },
		{ (char*)"LavaPan", (void*)al::createActorFunction<LavaPan> },
		{ (char*)"LavaWave", (void*)al::createActorFunction<LavaWave> },
		{ (char*)"LifeMaxUpItem", (void*)al::createActorFunction<LifeMaxUpItem> },
		{ (char*)"LifeMaxUpItem2D", (void*)al::createActorFunction<LifeMaxUpItem2D> },
		{ (char*)"LifeUpItem", (void*)al::createActorFunction<LifeUpItem> },
		{ (char*)"LifeUpItem2D", (void*)al::createActorFunction<LifeUpItem2D> },
		{ (char*)"LightningController", (void*)al::createActorFunction<al::LightningController> },
		{ (char*)"LongGenerator", (void*)al::createActorFunction<LongGenerator> },
		{ (char*)"MarchingCubeBlock", (void*)al::createActorFunction<MarchingCubeBlock> },
		{ (char*)"MapPartsRoulette", (void*)al::createActorFunction<MapPartsRoulette> },
		{ (char*)"Megane", (void*)al::createActorFunction<Megane> },
		{ (char*)"MeganeLiftExLift", (void*)al::createActorFunction<MeganeLiftExLift> },
		{ (char*)"MeganeKeyMoveMapParts", (void*)al::createActorFunction<MeganeKeyMoveMapParts> },
		{ (char*)"MeganeMapParts", (void*)al::createActorFunction<MeganeMapParts> },
		{ (char*)"Mirror", (void*)al::createActorFunction<Mirror> },
		{ (char*)"MoonBasementBreakParts", (void*)al::createActorFunction<MoonBasementBreakParts> },
		{ (char*)"MoonBasementClimaxWatcher", (void*)al::createActorFunction<MoonBasementClimaxWatcher> },
		{ (char*)"MoonBasementMeteorPointObj", (void*)al::createActorFunction<MoonBasementMeteorPointObj> },
		{ (char*)"MoonBasementFinalGate", (void*)al::createActorFunction<MoonBasementFinalGate> },
		{ (char*)"MoonBasementFallObjDecoration", (void*)al::createActorFunction<MoonBasementFallObjDecoration> },
		{ (char*)"MoonBasementFloor", (void*)al::createActorFunction<MoonBasementFloor> },
		{ (char*)"MoonBasementGate", (void*)al::createActorFunction<MoonBasementGate> },
		{ (char*)"MoonBasementMeteorAreaObj", (void*)al::createActorFunction<MoonBasementMeteorAreaObj> },
		{ (char*)"MoonBasementPillar", (void*)al::createActorFunction<MoonBasementPillar> },
		{ (char*)"MoonBasementRock", (void*)al::createActorFunction<MoonBasementRock> },
		{ (char*)"MoonBasementSlideObj", (void*)al::createActorFunction<MoonBasementSlideObj> },
		{ (char*)"MoonRock", (void*)al::createActorFunction<MoonRock> },
		{ (char*)"MoonWorldBe", (void*)al::createActorFunction<MoonWorldBell> },
		{ (char*)"MoonWorldCaptureParadeLift", (void*)al::createActorFunction<MoonWorldCaptureParadeLift> },
		{ (char*)"Mofumofu", (void*)al::createActorFunction<Mofumofu> },
		{ (char*)"MofumofuScrap", (void*)al::createActorFunction<MofumofuScrap> },
		{ (char*)"Motorcycle", (void*)al::createActorFunction<Motorcycle> },
		{ (char*)"MotorcycleParkingLot", (void*)al::createActorFunction<MotorcycleParkingLot> },
		{ (char*)"MoveHomeNpc", (void*)al::createActorFunction<MoveHomeNpc> },
		{ (char*)"MoviePlayerMapParts", (void*)al::createActorFunction<MoviePlayerMapParts> },
		{ (char*)"MultiGateKeeperBonfire", (void*)al::createActorFunction<MultiGateKeeperBonfire> },
		{ (char*)"MultiGateKeeperWatcher", (void*)al::createActorFunction<MultiGateKeeperWatcher> },
		{ (char*)"Mummy", (void*)al::createActorFunction<Mummy> },
		{ (char*)"MummyGenerator", (void*)al::createActorFunction<MummyGenerator> },
		{ (char*)"NeedleTrap", (void*)al::createActorFunction<NeedleTrap> },
		{ (char*)"Nokonoko2D", (void*)al::createActorFunction<Nokonoko2D> },
		{ (char*)"NoteObj", (void*)al::createActorFunction<NoteObj> },
		{ (char*)"NoteObj2D", (void*)al::createActorFunction<NoteObj2D> },
		{ (char*)"NoteObjDirector", (void*)al::createActorFunction<NoteObjDirector> },
		{ (char*)"Objex", (void*)al::createActorFunction<Objex> },
		{ (char*)"OccludedEffectRequester", (void*)al::createActorFunction<al::OccludedEffectRequester> },
		{ (char*)"OceanWaveActor", (void*)al::createActorFunction<OceanWaveActor> },
		{ (char*)"OneMeshFixMapParts", (void*)al::createActorFunction<al::OneMeshFixMapParts> },
		{ (char*)"OpeningStageStartDemo", (void*)al::createActorFunction<OpeningStageStartDemo> },
		{ (char*)"PackunFire", (void*)al::createActorFunction<PackunFire> },
		{ (char*)"PadRumblePoint", (void*)al::createActorFunction<PadRumblePoint> },
		{ (char*)"PaintObj", (void*)al::createActorFunction<PaintObj> },
		{ (char*)"PaulineAtCeremony", (void*)al::createActorFunction<PaulineAtCeremony> },
		{ (char*)"PaulineAudience", (void*)al::createActorFunction<PaulineAudience> },
		{ (char*)"PeachCastleCap", (void*)al::createActorFunction<PeachCastleCap> },
		{ (char*)"PeachWorldGate", (void*)al::createActorFunction<PeachWorldGate> },
		{ (char*)"PeachWorldMoatWater", (void*)al::createActorFunction<PeachWorldMoatWater> },
		{ (char*)"PeachWorldTree", (void*)al::createActorFunction<PeachWorldTree> },
		{ (char*)"Pecho", (void*)al::createActorFunction<Pecho> },
		{ (char*)"Pen", (void*)al::createActorFunction<Pen> },
		{ (char*)"PictureStageChange", (void*)al::createActorFunction<PictureStageChange> },
		{ (char*)"PillarKeyMoveParts", (void*)al::createActorFunction<PillarKeyMoveParts> },
		{ (char*)"PillarSwitchOpenMapParts", (void*)al::createActorFunction<PillarSwitchOpenMapParts> },
		{ (char*)"PlayerMotionObserver", (void*)al::createActorFunction<PlayerMotionObserver> },
		{ (char*)"PlayerStartObj", (void*)al::createActorFunction<PlayerStartObj> },
		{ (char*)"PlayerSubjectiveWatchCheckObj", (void*)al::createActorFunction<PlayerSubjectiveWatchCheckObj> },
		{ (char*)"PlayGuideBoard", (void*)al::createActorFunction<PlayGuideBoard> },
		{ (char*)"PlayRecorder", (void*)al::createActorFunction<PlayRecorder> },
		{ (char*)"PochiHintPhoto", (void*)al::createActorFunction<PochiHintPhoto> },
		{ (char*)"Poetter", (void*)al::createActorFunction<Poetter> },
		{ (char*)"PoleClimbParts", (void*)al::createActorFunction<PoleClimbParts> },
		{ (char*)"PoleGrabCei", (void*)al::createActorFunction<PoleGrabCeil> },
		{ (char*)"PopnGenerator", (void*)al::createActorFunction<PopnGenerator> },
		{ (char*)"ReactionObjectPoster", (void*)al::createActorFunction<ReactionObjectPoster> },
		{ (char*)"ReactionObjectSkyRhythm", (void*)al::createActorFunction<ReactionObjectSkyRhythm> },
		{ (char*)"PosterWatcher", (void*)al::createActorFunction<PosterWatcher> },
		{ (char*)"PrePassCausticsLight", (void*)al::createActorFunction<PrePassCausticsLight> },
		{ (char*)"PrePassLineLight", (void*)al::createActorFunction<al::PrePassLineLight> },
		{ (char*)"PrePassPointLight", (void*)al::createActorFunction<al::PrePassPointLight> },
		{ (char*)"PrePassProjLight", (void*)al::createActorFunction<al::PrePassProjLight> },
		{ (char*)"PrePassProjOrthoLight", (void*)al::createActorFunction<al::PrePassProjOrthoLight> },
		{ (char*)"PrePassSpotLight", (void*)al::createActorFunction<al::PrePassSpotLight> },
		{ (char*)"ProjectRaceCheckPoint", (void*)al::createActorFunction<ProjectRaceCheckPoint> },
		{ (char*)"Pyramid", (void*)al::createActorFunction<Pyramid> },
		{ (char*)"QuestObj", (void*)al::createActorFunction<QuestObj> },
		{ (char*)"RabbitGraph", (void*)al::createActorFunction<RabbitGraph> },
		{ (char*)"RaceAudienceNpc", (void*)al::createActorFunction<RaceAudienceNpc> },
		{ (char*)"RaceManGo", (void*)al::createActorFunction<RaceManGoal> },
		{ (char*)"RaceManRace", (void*)al::createActorFunction<RaceManRace> },
		{ (char*)"RaceManStart", (void*)al::createActorFunction<RaceManStart> },
		{ (char*)"RaceWatcher", (void*)al::createActorFunction<RaceWatcher> },
		{ (char*)"RadiConRaceWatcher", (void*)al::createActorFunction<RadiConRaceWatcher> },
		{ (char*)"RadioCassette", (void*)al::createActorFunction<RadioCassette> },
		{ (char*)"RadiconNpc", (void*)al::createActorFunction<RadiconNpc> },
		{ (char*)"Radish", (void*)al::createActorFunction<Radish> },
		{ (char*)"RailDrawer", (void*)al::createActorFunction<RailDrawer> },
		{ (char*)"RankingNpc", (void*)al::createActorFunction<RankingNpc> },
		{ (char*)"ReactionObjectCarBreakable", (void*)al::createActorFunction<ReactionObjectCarBreakable> },
		{ (char*)"ReflectBombGenerator", (void*)al::createActorFunction<ReflectBombGenerator> },
		{ (char*)"RhythmSpotlight", (void*)al::createActorFunction<RhythmSpotlight> },
		{ (char*)"RippleGeneratePoint", (void*)al::createActorFunction<al::RippleGeneratePoint> },
		{ (char*)"RotateTarget", (void*)al::createActorFunction<RotateTarget> },
		{ (char*)"RouletteSwitch", (void*)al::createActorFunction<RouletteSwitch> },
		{ (char*)"RouteGuideArrow", (void*)al::createActorFunction<RouteGuideArrow> },
		{ (char*)"RouteGuideRai", (void*)al::createActorFunction<RouteGuideRail> },
		{ (char*)"RunAwayNpc", (void*)al::createActorFunction<RunAwayNpc> },
		{ (char*)"SandGeyser", (void*)al::createActorFunction<SandGeyser> },
		{ (char*)"SandWorldHomeLift", (void*)al::createActorFunction<SandWorldHomeLift> },
		{ (char*)"SaucePan", (void*)al::createActorFunction<SaucePan> },
		{ (char*)"SaveFlagCheckObj", (void*)al::createActorFunction<SaveFlagCheckObj> },
		{ (char*)"ScenarioStartCamer", (void*)al::createActorFunction<ScenarioStartCamera> },
		{ (char*)"Senobi", (void*)al::createActorFunction<Senobi> },
		{ (char*)"SenobiGeneratePoint", (void*)al::createActorFunction<SenobiGeneratePoint> },
		{ (char*)"SenobiMoveMapParts", (void*)al::createActorFunction<SenobiMoveMapParts> },
		{ (char*)"SenobiMoveMapPartsConnector", (void*)al::createActorFunction<SenobiMoveMapPartsConnector> },
		{ (char*)"SeBarrierObj", (void*)al::createActorFunction<al::SeBarrierObj> },
		{ (char*)"SePlayObj", (void*)al::createActorFunction<al::SePlayObj> },
		{ (char*)"SePlayObjWithSave", (void*)al::createActorFunction<SePlayObjWithSave> },
		{ (char*)"SePlayRai", (void*)al::createActorFunction<al::SePlayRail> },
		{ (char*)"SequentialSwitch", (void*)al::createActorFunction<SequentialSwitch> },
		{ (char*)"SessionBgmCtrlObj", (void*)al::createActorFunction<SessionBgmCtrlObj> },
		{ (char*)"SessionMayorNpc", (void*)al::createActorFunction<SessionMayorNpc> },
		{ (char*)"SessionMusicianNpc", (void*)al::createActorFunction<SessionMusicianNpc> },
		{ (char*)"Shibaken", (void*)al::createActorFunction<Shibaken> },
		{ (char*)"Shine", (void*)al::createActorFunction<Shine> },
		{ (char*)"ShineChipWatcher", (void*)al::createActorFunction<ShineChipWatcher> },
		{ (char*)"ShineFukankunWatchObj", (void*)al::createActorFunction<ShineFukankunWatchObj> },
		{ (char*)"ShineTowerRocket", (void*)al::createActorFunction<ShineTowerRocket> },
		{ (char*)"ShopBgmPlayer", (void*)al::createActorFunction<ShopBgmPlayer> },
		{ (char*)"ShopMark", (void*)al::createActorFunction<ShopMark> },
		{ (char*)"ShoppingWatcher", (void*)al::createActorFunction<ShoppingWatcher> },
		{ (char*)"SignBoardDanger", (void*)al::createActorFunction<SignBoardDanger> },
		{ (char*)"SignBoardLayoutTexture", (void*)al::createActorFunction<SignBoardLayoutTexture> },
		{ (char*)"SkyFukankunZoomCapMessage", (void*)al::createActorFunction<SkyFukankunZoomCapMessage> },
		{ (char*)"SkyWorldCloud", (void*)al::createActorFunction<SkyWorldCloud> },
		{ (char*)"SkyWorldKoopaFire", (void*)al::createActorFunction<SkyWorldKoopaFire> },
		{ (char*)"SkyWorldKoopaFrame", (void*)al::createActorFunction<SkyWorldKoopaFrame> },
		{ (char*)"SkyWorldMiddleViewCloud", (void*)al::createActorFunction<SkyWorldMiddleViewCloud> },
		{ (char*)"SignBoard", (void*)al::createActorFunction<SignBoard> },
		{ (char*)"SnowWorldBigIcicle", (void*)al::createActorFunction<SnowWorldBigIcicle> },
		{ (char*)"SnowWorldSequenceFlagCheckObj", (void*)al::createActorFunction<SnowWorldSequenceFlagCheckObj> },
		{ (char*)"Sky", (void*)al::createActorFunction<al::Sky> },
		{ (char*)"SmallWanderBoss", (void*)al::createActorFunction<SmallWanderBoss> },
		{ (char*)"SneakingMan", (void*)al::createActorFunction<SneakingMan> },
		{ (char*)"SnowManRaceNpc", (void*)al::createActorFunction<SnowManRaceNpc> },
		{ (char*)"SnowVolume", (void*)al::createActorFunction<SnowVolume> },
		{ (char*)"SnowVolumeEraser", (void*)al::createActorFunction<SnowVolumeEraser> },
		{ (char*)"Souvenir", (void*)al::createActorFunction<Souvenir> },
		{ (char*)"SouvenirDirector", (void*)al::createActorFunction<SouvenirDirector> },
		{ (char*)"Special2KeyMoveLift", (void*)al::createActorFunction<Special2KeyMoveLift> },
		{ (char*)"Special2KeyMoveParts", (void*)al::createActorFunction<Special2KeyMoveParts> },
		{ (char*)"SphinxQuiz", (void*)al::createActorFunction<SphinxQuiz> },
		{ (char*)"SphinxRide", (void*)al::createActorFunction<SphinxRide> },
		{ (char*)"SphinxTaxiWatcher", (void*)al::createActorFunction<SphinxTaxiWatcher> },
		{ (char*)"Squirre", (void*)al::createActorFunction<Squirrel> },
		{ (char*)"Stacker", (void*)al::createActorFunction<Stacker> },
		{ (char*)"StackerCapWorldCtr", (void*)al::createActorFunction<StackerCapWorldCtrl> },
		{ (char*)"StageEventDemo", (void*)al::createActorFunction<StageEventDemo> },
		{ (char*)"StageSwitchSelector", (void*)al::createActorFunction<StageSwitchSelector> },
		{ (char*)"StageTalkDemoNpcCap", (void*)al::createActorFunction<StageTalkDemoNpcCap> },
		{ (char*)"Stake", (void*)al::createActorFunction<Stake> },
		{ (char*)"Statue", (void*)al::createActorFunction<Statue> },
		{ (char*)"StatueSnapMark", (void*)al::createActorFunction<StatueSnapMark> },
		{ (char*)"SubActorLodFixPartsScenarioAction", (void*)al::createActorFunction<SubActorLodFixPartsScenarioAction> },
		{ (char*)"SwitchAnd", (void*)al::createActorFunction<SwitchAnd> },
		{ (char*)"SwitchKeyMoveMapParts", (void*)al::createActorFunction<al::SwitchKeyMoveMapParts> },
		{ (char*)"CapMessagePlacement", (void*)al::createActorFunction<CapMessagePlacement> },
		{ (char*)"TalkMessageInfoPointSaveObj", (void*)al::createActorFunction<TalkMessageInfoPointSaveObj> },
		{ (char*)"TalkNpc", (void*)al::createActorFunction<TalkNpc> },
		{ (char*)"TalkNpcFreeze", (void*)al::createActorFunction<TalkNpcFreeze> },
		{ (char*)"TalkPoint", (void*)al::createActorFunction<TalkPoint> },
		{ (char*)"Tank", (void*)al::createActorFunction<Tank> },
		{ (char*)"TankReviveCtr", (void*)al::createActorFunction<TankReviveCtrl> },
		{ (char*)"TaxiStop", (void*)al::createActorFunction<TaxiStop> },
		{ (char*)"TextureReplaceScreen", (void*)al::createActorFunction<TextureReplaceScreen> },
		{ (char*)"ThunderRenderRequester", (void*)al::createActorFunction<al::ThunderRenderRequester> },
		{ (char*)"Togezo", (void*)al::createActorFunction<Togezo> },
		{ (char*)"Togezo2D", (void*)al::createActorFunction<Togezo2D> },
		{ (char*)"TokimekiMayorNpc", (void*)al::createActorFunction<TokimekiMayorNpc> },
		{ (char*)"TrampleBush", (void*)al::createActorFunction<TrampleBush> },
		{ (char*)"TrampleSwitch", (void*)al::createActorFunction<TrampleSwitch> },
		{ (char*)"TrampleSwitchTimer", (void*)al::createActorFunction<TrampleSwitchTimer> },
		{ (char*)"TransparentW", (void*)al::createActorFunction<TransparentWall> },
		{ (char*)"TreasureBox", (void*)al::createActorFunction<TreasureBox> },
		{ (char*)"TreasureBoxKey", (void*)al::createActorFunction<TreasureBoxKey> },
		{ (char*)"TreasureBoxSequentialDirector", (void*)al::createActorFunction<TreasureBoxSequentialDirector> },
		{ (char*)"TRex", (void*)al::createActorFunction<TRex> },
		{ (char*)"TRexScrollBreakMapParts", (void*)al::createActorFunction<TRexScrollBreakMapParts> },
		{ (char*)"Tsukkun", (void*)al::createActorFunction<Tsukkun> },
		{ (char*)"TsukkunHole", (void*)al::createActorFunction<TsukkunHole> },
		{ (char*)"TwistChainList", (void*)al::createActorFunction<TwistChainList> },
		{ (char*)"Utsubo", (void*)al::createActorFunction<Utsubo> },
		{ (char*)"UtsuboWatcher", (void*)al::createActorFunction<UtsuboWatcher> },
		{ (char*)"VocalMike", (void*)al::createActorFunction<VocalMike> },
		{ (char*)"VolleyballBase", (void*)al::createActorFunction<VolleyballBase> },
		{ (char*)"VolleyballNet", (void*)al::createActorFunction<VolleyballNet> },
		{ (char*)"VolleyballNpc", (void*)al::createActorFunction<VolleyballNpc> },
		{ (char*)"Wanwan", (void*)al::createActorFunction<Wanwan> },
		{ (char*)"WanwanHole", (void*)al::createActorFunction<WanwanHole> },
		{ (char*)"WaterAreaMoveMode", (void*)al::createActorFunction<al::WaterAreaMoveModel> },
		{ (char*)"WaterfallWorldBigBreakableW", (void*)al::createActorFunction<WaterfallWorldBigBreakableWall> },
		{ (char*)"WaterfallWorldFallDownBridge", (void*)al::createActorFunction<WaterfallWorldFallDownBridge> },
		{ (char*)"WaterfallWorldWaterf", (void*)al::createActorFunction<WaterfallWorldWaterfall> },
		{ (char*)"WaterRoad", (void*)al::createActorFunction<WaterRoad> },
		{ (char*)"WeightSwitch", (void*)al::createActorFunction<WeightSwitch> },
		{ (char*)"WheelWaveSurfParts", (void*)al::createActorFunction<WheelWaveSurfParts> },
		{ (char*)"WindBlowPuzzle", (void*)al::createActorFunction<WindBlowPuzzle> },
		{ (char*)"WorldMapEarth", (void*)al::createActorFunction<WorldMapEarth> },
		{ (char*)"WorldTravelingNpc", (void*)al::createActorFunction<WorldTravelingNpc> },
		{ (char*)"WorldTravelingPeach", (void*)al::createActorFunction<WorldTravelingPeach> },
		{ (char*)"WorldWarpHole", (void*)al::createActorFunction<WorldWarpHole> },
		{ (char*)"Fastener", (void*)al::createActorFunction<Fastener> },
		{ (char*)"FastenerObj", (void*)al::createActorFunction<FastenerObj> },
		{ (char*)"AtmosScatterRequester", (void*)al::createActorFunction<al::AtmosScatterRequester> },
		{ (char*)"BackHideParts", (void*)al::createActorFunction<al::BackHideParts> },
		{ (char*)"CapRotateMapParts", (void*)al::createActorFunction<CapRotateMapParts> },
		{ (char*)"ClockMapParts", (void*)al::createActorFunction<al::ClockMapParts> },
		{ (char*)"ConveyerMapParts", (void*)al::createActorFunction<al::ConveyerMapParts> },
		{ (char*)"FallMapParts", (void*)al::createActorFunction<al::FallMapParts> },
		{ (char*)"FloaterMapParts", (void*)al::createActorFunction<al::FloaterMapParts> },
		{ (char*)"FlowMapParts", (void*)al::createActorFunction<al::FlowMapParts> },
		{ (char*)"GateMapParts", (void*)al::createActorFunction<al::GateMapParts> },
		{ (char*)"KeyMoveMapParts", (void*)al::createActorFunction<al::KeyMoveMapParts> },
		{ (char*)"KeyMoveMapPartsGenerator", (void*)al::createActorFunction<al::KeyMoveMapPartsGenerator> },
		{ (char*)"HackMapParts", (void*)al::createActorFunction<HackMapParts> },
		{ (char*)"Pukupuku", (void*)al::createActorFunction<Pukupuku> },
		{ (char*)"PulseSwitch", (void*)al::createActorFunction<PulseSwitch> },
		{ (char*)"RailCollision", (void*)al::createActorFunction<RailCollision> },
		{ (char*)"RailMoveMapParts", (void*)al::createActorFunction<al::RailMoveMapParts> },
		{ (char*)"RiseMapParts", (void*)al::createActorFunction<RiseMapParts> },
		{ (char*)"ReactionMapParts", (void*)al::createActorFunction<ReactionMapParts> },
		{ (char*)"RiseMapPartsHolder", (void*)al::createActorFunction<RiseMapPartsHolder> },
		{ (char*)"RocketFlower", (void*)al::createActorFunction<RocketFlower> },
		{ (char*)"RollingCubeMapParts", (void*)al::createActorFunction<al::RollingCubeMapParts> },
		{ (char*)"RotateMapParts", (void*)al::createActorFunction<al::RotateMapParts> },
		{ (char*)"SeesawMapParts", (void*)al::createActorFunction<al::SeesawMapParts> },
		{ (char*)"SlideMapParts", (void*)al::createActorFunction<al::SlideMapParts> },
		{ (char*)"SubActorLodMapParts", (void*)al::createActorFunction<al::SubActorLodMapParts> },
		{ (char*)"SurfMapParts", (void*)al::createActorFunction<al::SurfMapParts> },
		{ (char*)"SwingMapParts", (void*)al::createActorFunction<al::SwingMapParts> },
		{ (char*)"SwitchDitherMapParts", (void*)al::createActorFunction<al::SwitchDitherMapParts> },
		{ (char*)"SwitchKeepOnWatcher", (void*)al::createActorFunction<al::SwitchKeepOnWatcher> },
		{ (char*)"SwitchOpenMapParts", (void*)al::createActorFunction<al::SwitchOpenMapParts> },
		{ (char*)"VisibleSwitchMapParts", (void*)al::createActorFunction<al::VisibleSwitchMapParts> },
		{ (char*)"WaveSurfMapParts", (void*)al::createActorFunction<WaveSurfMapParts> },
		{ (char*)"WheelMapParts", (void*)al::createActorFunction<al::WheelMapParts> },
		{ (char*)"WobbleMapParts", (void*)al::createActorFunction<al::WobbleMapParts> },
		{ (char*)"WindBlowMapParts", (void*)al::createActorFunction<WindBlowMapParts> },
		{ (char*)"Yoshi", (void*)al::createActorFunction<Yoshi> },
		{ (char*)"YoshiFruit", (void*)al::createActorFunction<YoshiFruit> },
		{ (char*)"YoshiFruitShineHolder", (void*)al::createActorFunction<YoshiFruitShineHolder> },
		{ (char*)"Yukimaru", (void*)al::createActorFunction<Yukimaru> },
		{ (char*)"YukimaruRacer", (void*)al::createActorFunction<YukimaruRacer> },
		{ (char*)"YukimaruRacerTiago", (void*)al::createActorFunction<YukimaruRacerTiago> }
};

static const ActorEntry* getEntries()
{
    return entries;
}