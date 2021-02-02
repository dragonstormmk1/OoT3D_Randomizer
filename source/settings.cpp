#include "settings.hpp"
#include "setting_descriptions.hpp"
#include "random.hpp"

namespace Settings {
  std::string seed;

  //                                        Setting name,              Options,                                                Option Descriptions (assigned in setting_descriptions.cpp), default setting index
  //Open Settings
  Option Logic               = Option::U8  ("Logic",                  {"Glitchless", "No Logic"},                              {logicGlitchless, logicNoLogic});
  Option OpenForest          = Option::U8  ("Forest",                 {"Open", "Closed"},                                      {forestOpen, forestClosed});
  Option OpenKakariko        = Option::U8  ("Kakariko Gate",          {"Open", "Closed"},                                      {kakGateOpen, kakGateClosed}, 1);
  Option OpenDoorOfTime      = Option::Bool("Door of Time",           {"Closed", "Open"},                                      {doorOfTimeDesc, doorOfTimeDesc}, true);
  Option ZorasFountain       = Option::U8  ("Zora's Fountain",        {"Normal", "Open"},                                      {fountainNormal, fountainOpen});
  Option GerudoFortress      = Option::U8  ("Gerudo Fortress",        {"Normal", "Fast", "Open"},                              {gerudoNormal, gerudoFast, gerudoOpen});
  Option Bridge              = Option::U8  ("Rainbow Bridge",         {"Open", "Vanilla", "Stones", "Medallions", "Dungeons"}, {bridgeOpen, bridgeVanilla, bridgeStones, bridgeMedallions, bridgeDungeons}, 1);
  std::vector<Option *> openOptions = {
    &Logic,
    &OpenForest,
    //&OpenKakariko,
    &OpenDoorOfTime,
    &ZorasFountain,
    &GerudoFortress,
    &Bridge,
  };

  //World Settings
  Option StartingAge         = Option::U8  ("Starting Age",           {"Adult", "Child"},                                      {ageDesc, ageDesc}, 1);
  Option BombchusInLogic     = Option::Bool("Bombchus in Logic",      {"Off", "On"},                                           {bombchuLogicDesc, bombchuLogicDesc});
  Option RandomMQDungeons    = Option::Bool("Random MQ Dungeons",     {"Off", "On"},                                           {randomMQDungeonsDesc, randomMQDungeonsDesc});
  std::vector<Option *> worldOptions = {
    &StartingAge,
    &BombchusInLogic,
    //&RandomMQDungeons, TODO: Finish MQ logic before enabling this
  };

  //Shuffle Settings
  Option ShuffleSongs        = Option::U8  ("Shuffle Songs",          {"Song Locations", "Anywhere"},                          {songsSongLocations, songsAllLocations}); //TODO: Dungeon Rewards
  Option Tokensanity         = Option::U8  ("Tokensanity",            {"Vanilla", "Anywhere"},                                 {tokensVanilla, tokensAllLocations});
  Option Scrubsanity         = Option::U8  ("Scrub Shuffle",          {"Off", "Affordable", "Expensive", "Random Prices"},     {scrubsOff, scrubsAffordable, scrubsExpensive, scrubsRandomPrices});
  Option ShuffleKokiriSword  = Option::Bool("Shuffle Kokiri Sword",   {"Off", "On"},                                           {kokiriSwordDesc, kokiriSwordDesc});
  Option ShuffleOcarinas     = Option::Bool("Shuffle Ocarinas",       {"Off", "On"},                                           {ocarinasDesc, ocarinasDesc});
  Option ShuffleWeirdEgg     = Option::Bool("Shuffle Weird Egg",      {"Off", "On"},                                           {weirdEggDesc, weirdEggDesc});
  Option ShuffleGerudoToken  = Option::Bool("Shuffle Gerudo Token",   {"Off", "On"},                                           {gerudoTokenDesc, gerudoTokenDesc});
  Option ShuffleMagicBeans   = Option::Bool("Shuffle Magic Beans",    {"Off", "On"},                                           {magicBeansDesc, magicBeansDesc});
  //TODO: Medigoron and Carpet Salesman
  std::vector<Option *> shuffleOptions = {
    &ShuffleSongs,
    &Tokensanity,
    &Scrubsanity,
    &ShuffleKokiriSword,
    &ShuffleOcarinas,
    &ShuffleWeirdEgg,
    &ShuffleGerudoToken,
    &ShuffleMagicBeans,
    //TODO: Medigoron and Carpet Salesman
  };

  //Shuffle Dungeon Items
  Option Keysanity           = Option::U8  ("Small Keys",             {"Vanilla", "Own Dungeon", "Anywhere"},                  {smallKeyVanilla, smallKeyOwnDungeon, smallKeyAnywhere});
  Option BossKeysanity       = Option::U8  ("Boss Keys",              {"Vanilla", "Own Dungeon", "Anywhere"},                  {bossKeyVanilla, bossKeyOwnDungeon, bossKeyAnywhere});
  Option GanonsBossKey       = Option::U8  ("Ganon's Boss Key",       {"Vanilla", "Own Dungeon", "Anywhere", "LACS: Vanilla", "LACS: Medallions", "LACS: Stones", "LACS: Dungeons"},
                                                                      {ganonKeyVanilla, ganonKeyOwnDungeon, ganonKeyAnywhere, ganonKeyLACS, ganonKeyLACS, ganonKeyLACS, ganonKeyLACS});
  Option MapsAndCompasses    = Option::U8  ("Maps/Compasses",         {"Start With", "Vanilla", "Own Dungeon", "Anywhere"},    {mapCompassStartWith, mapCompassVanilla, mapCompassOwnDungeon, mapCompassAnywhere}, 1);
  u8 LACSCondition           = 0;
  std::vector<Option *> shuffleDungeonItemOptions = {
    &Keysanity,
    &BossKeysanity,
    &GanonsBossKey,
    &MapsAndCompasses,
  };

  //Timesaver Settings
  Option SkipChildStealth    = Option::U8  ("Skip Child Sealth",      {"Don't Skip", "Skip"},                                  {childStealthDesc, childStealthDesc});
  Option FourPoesCutscene    = Option::Bool("Four Poes Cutscene",     {"Skip", "Don't Skip"},                                  {fourPoesDesc, fourPoesDesc});
  Option BigPoeTargetCount   = Option::U8  ("Big Poe Target Count",   {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"},     {"", "", "", "", "", "", "", "", "", ""});
  std::vector<Option *> timesaverOptions = {
    &SkipChildStealth,
    &FourPoesCutscene,
    &BigPoeTargetCount,
  };

  //Misc Settings
  Option DamageMultiplier    = Option::U8  ("Damage Multiplier",      {"Half", "Default", "Double", "Quadruple", "OHKO"},      {damageMultiDesc, damageMultiDesc, damageMultiDesc, damageMultiDesc, damageMultiDesc}, 1);
  Option StartingTime        = Option::U8  ("Starting Time",          {"Day", "Night"},                                        {startingTimeDesc, startingTimeDesc});
  bool HasNightStart         = false;
  std::vector<Option *> miscOptions = {
    &DamageMultiplier,
    &StartingTime,
  };

  //Advanced Glitch Settings
  Option BoomerangAsAdult    = Option::U8  ("Enable Adult Boomerang", {"No", "Yes"},                                           {adultBoomerangDesc, adultBoomerangDesc});
  Option HammerAsChild       = Option::U8  ("Enable Child Hammer",    {"No", "Yes"},                                           {childHammerDesc, childHammerDesc});
  std::vector<Option *> advancedGlitchedOptions = {
    &BoomerangAsAdult,
    &HammerAsChild,
  };

  //Item Pool Settings
  Option ItemPoolValue       = Option::U8  ("Item Pool",              {"Plentiful", "Balanced", "Scarce", "Minimal"},          {itemPoolPlentiful, itemPoolBalanced, itemPoolScarce, itemPoolMinimal}, 1);
  //TODO: Ice Traps

  //Excluded Locations (definitions made in ItemLocation class)
  std::vector<Option *> excludeLocationsOptions = {};

  MenuItem open                     = MenuItem::SubMenu("Open Settings",              &openOptions);
  MenuItem world                    = MenuItem::SubMenu("World Settings",             &worldOptions);
  MenuItem shuffle                  = MenuItem::SubMenu("Shuffle Settings",           &shuffleOptions);
  MenuItem shuffleDungeonItems      = MenuItem::SubMenu("Shuffle Dungeon Items",      &shuffleDungeonItemOptions);
  MenuItem excludeLocations         = MenuItem::SubMenu("Exclude Locations",          &excludeLocationsOptions);
  MenuItem timesaverSettings        = MenuItem::SubMenu("Timesaver Settings",         &timesaverOptions);
  MenuItem miscSettings             = MenuItem::SubMenu("Misc Settings",              &miscOptions);
  MenuItem advancedGlitchedSettings = MenuItem::SubMenu("Advanced Glitched Settings", &advancedGlitchedOptions);
  MenuItem loadSettingsPreset       = MenuItem::Action ("Load Settings Preset",       LOAD_PRESET);
  MenuItem saveSettingsPreset       = MenuItem::Action ("Save Settings Preset",       SAVE_PRESET);
  MenuItem generateRandomizer       = MenuItem::Action ("Generate Randomizer",        GENERATE_MODE);

  //adding a menu with no options crashes, might fix later
  std::vector<MenuItem *> mainMenu = {
    &open,
    &world,
    &shuffle,
    &shuffleDungeonItems,
    &timesaverSettings,
    &excludeLocations,
    &miscSettings,
    &advancedGlitchedSettings,
    &loadSettingsPreset,
    &saveSettingsPreset,
    &generateRandomizer,
  };

  //declared here, set in fill.cpp
  u32 LinksPocketRewardBitMask = 0;

  std::array<u32, 9> rDungeonRewardOverrides{};

  //Fills a SettingsContext struct which is sent to the patch
  SettingsContext FillContext() {
    SettingsContext ctx = {};
    ctx.logic              = Logic.Value<u8>();
    ctx.openForest         = OpenForest.Value<u8>();
    ctx.openKakariko       = OpenKakariko.Value<u8>();
    ctx.openDoorOfTime     = OpenDoorOfTime.Value<bool>();
    ctx.zorasFountain      = ZorasFountain.Value<u8>();
    ctx.gerudoFortress     = GerudoFortress.Value<u8>();
    ctx.rainbowBridge      = Bridge.Value<u8>();

    ctx.startingAge        = StartingAge.Value<u8>();
    ctx.bombchusInLogic    = BombchusInLogic.Value<bool>();
    ctx.randomMQDungeons   = RandomMQDungeons.Value<bool>();

    ctx.shuffleSongs       = ShuffleSongs.Value<u8>();
    ctx.tokensanity        = Tokensanity.Value<u8>();
    ctx.scrubsanity        = Scrubsanity.Value<u8>();
    ctx.shuffleKokiriSword = ShuffleKokiriSword.Value<bool>();
    ctx.shuffleOcarinas    = ShuffleOcarinas.Value<bool>();
    ctx.shuffleWeirdEgg    = ShuffleWeirdEgg.Value<bool>();
    ctx.shuffleGerudoToken = ShuffleGerudoToken.Value<bool>();
    ctx.shuffleMagicBeans  = ShuffleMagicBeans.Value<bool>();

    ctx.keysanity          = Keysanity.Value<u8>();
    ctx.bossKeysanity      = BossKeysanity.Value<u8>();
    ctx.ganonsBossKey      = GanonsBossKey.Value<u8>();
    ctx.mapsAndCompasses   = MapsAndCompasses.Value<u8>();
    ctx.lacsCondition      = LACSCondition;

    ctx.skipChildStealth   = SkipChildStealth.Value<u8>();
    ctx.fourPoesCutscene   = FourPoesCutscene.Value<bool>();
    ctx.bigPoeTargetCount  = BigPoeTargetCount.Value<u8>() + 1;

    ctx.damageMultiplier   = DamageMultiplier.Value<u8>();
    ctx.startingTime       = StartingTime.Value<u8>();

    ctx.boomerangAsAdult   = BoomerangAsAdult.Value<u8>();
    ctx.hammerAsChild      = HammerAsChild.Value<u8>();

    ctx.itemPoolValue      = ItemPoolValue.Value<u8>();

    ctx.dekuTreeDungeonMode              = (DekuTreeDungeonMode)              ? 1 : 0;
    ctx.dodongosCavernDungeonMode        = (DodongosCavernDungeonMode)        ? 1 : 0;
    ctx.jabuJabusBellyDungeonMode        = (JabuJabusBellyDungeonMode)        ? 1 : 0;
    ctx.forestTempleDungeonMode          = (ForestTempleDungeonMode)          ? 1 : 0;
    ctx.fireTempleDungeonMode            = (FireTempleDungeonMode)            ? 1 : 0;
    ctx.waterTempleDungeonMode           = (WaterTempleDungeonMode)           ? 1 : 0;
    ctx.spiritTempleDungeonMode          = (SpiritTempleDungeonMode)          ? 1 : 0;
    ctx.shadowTempleDungeonMode          = (ShadowTempleDungeonMode)          ? 1 : 0;
    ctx.bottomOfTheWellDungeonMode       = (BottomOfTheWellDungeonMode)       ? 1 : 0;
    ctx.gerudoTrainingGroundsDungeonMode = (GerudoTrainingGroundsDungeonMode) ? 1 : 0;
    ctx.ganonsCastleDungeonMode          = (GanonsCastleDungeonMode)          ? 1 : 0;

    ctx.dungeonRewardBitMask = LinksPocketRewardBitMask;
    return ctx;
  }

  //Takes a SettingsContext to use for the current settings
  void FillSettings(SettingsContext ctx) {
    Logic.SetSelectedIndex(ctx.logic);
    OpenForest.SetSelectedIndex(ctx.openForest);
    OpenKakariko.SetSelectedIndex(ctx.openKakariko);
    OpenDoorOfTime.SetSelectedIndex(ctx.openDoorOfTime);
    ZorasFountain.SetSelectedIndex(ctx.zorasFountain);
    GerudoFortress.SetSelectedIndex(ctx.gerudoFortress);
    Bridge.SetSelectedIndex(ctx.rainbowBridge);

    StartingAge.SetSelectedIndex(ctx.startingAge);
    BombchusInLogic.SetSelectedIndex(ctx.bombchusInLogic);
    RandomMQDungeons.SetSelectedIndex(ctx.randomMQDungeons);

    ShuffleSongs.SetSelectedIndex(ctx.shuffleSongs);
    Tokensanity.SetSelectedIndex(ctx.tokensanity);
    Scrubsanity.SetSelectedIndex(ctx.scrubsanity);
    ShuffleKokiriSword.SetSelectedIndex(ctx.shuffleKokiriSword);
    ShuffleOcarinas.SetSelectedIndex(ctx.shuffleOcarinas);
    ShuffleWeirdEgg.SetSelectedIndex(ctx.shuffleWeirdEgg);
    ShuffleGerudoToken.SetSelectedIndex(ctx.shuffleGerudoToken);
    ShuffleMagicBeans.SetSelectedIndex(ctx.shuffleMagicBeans);

    Keysanity.SetSelectedIndex(ctx.keysanity);
    BossKeysanity.SetSelectedIndex(ctx.bossKeysanity);
    GanonsBossKey.SetSelectedIndex(ctx.ganonsBossKey);
    MapsAndCompasses.SetSelectedIndex(ctx.mapsAndCompasses);

    SkipChildStealth.SetSelectedIndex(ctx.skipChildStealth);
    FourPoesCutscene.SetSelectedIndex(ctx.fourPoesCutscene);
    BigPoeTargetCount.SetSelectedIndex(ctx.bigPoeTargetCount - 1);

    DamageMultiplier.SetSelectedIndex(ctx.damageMultiplier);
    StartingTime.SetSelectedIndex(ctx.startingTime);

    BoomerangAsAdult.SetSelectedIndex(ctx.boomerangAsAdult);
    HammerAsChild.SetSelectedIndex(ctx.hammerAsChild);

    ItemPoolValue.SetSelectedIndex(ctx.itemPoolValue);
  }

  bool BombchuDrop                      = false;
  bool SkippedTrials                    = false;
  bool ShuffleDungeonEntrances          = false;
  bool ShuffleOverworldEntrances        = false;
  bool ShuffleInteriorEntrances         = false;
  bool ShuffleSpecialIndoorEntrances    = false;
  bool Shopsanity                       = false;
  bool DekuTreeDungeonMode              = false;
  bool DodongosCavernDungeonMode        = false;
  bool JabuJabusBellyDungeonMode        = false;
  bool ForestTempleDungeonMode          = false;
  bool FireTempleDungeonMode            = false;
  bool WaterTempleDungeonMode           = false;
  bool SpiritTempleDungeonMode          = false;
  bool ShadowTempleDungeonMode          = false;
  bool BottomOfTheWellDungeonMode       = false;
  bool GerudoTrainingGroundsDungeonMode = false;
  bool GanonsCastleDungeonMode          = false;

  //Individual Options
  bool LogicGrottosWithoutAgony         = false;
  bool LogicVisibleCollision            = false;
  bool LogicFewerTunicRequirements      = false;
  bool LogicLostWoodsBridge             = false;
  bool LogicLostWoodsGSBean             = false;
  bool LogicLabDiving                   = false;
  bool LogicLabWallGS                   = false;
  bool LogicGraveyardPoH                = false;
  bool LogicChildDampeRacePoH           = false;
  bool LogicGerudoKitchen               = false;
  bool LogicLensWasteland               = false;
  bool LogicReverseWasteland            = false;
  bool LogicColossusGS                  = false;
  bool LogicManOnRoof                   = false;
  bool LogicKakarikoTowerGS             = false;
  bool LogicDMTBombable                 = false;
  bool LogicDMTSoilGS                   = false;
  bool LogicLinkGoronDins               = false;
  bool LogicGoronCityLeftMost           = false;
  bool LogicGoronCityPot                = false;
  bool LogicGoronCityPotWithStrength    = false;
  bool LogicChildRollingWithStrength    = false;
  bool LogicCraterUpperToLower          = false;
  bool LogicCraterBeanPoHWithHovers     = false;
  bool LogicBiggoronBolero              = false;
  bool LogicZoraWithHovers              = false;
  bool LogicZoraWithCucco               = false;
  bool LogicZoraRiverLower              = false;
  bool LogicZoraRiverUpper              = false;
  bool LogicDekuB1WebsWithBow           = false;
  bool LogicDekuB1Skip                  = false;
  bool LogicDekuBasementGS              = false;
  bool LogicDCStaircase                 = false;
  bool LogicDCJump                      = false;
  bool LogicDCSlingshotSkip             = false;
  bool LogicDCScarecrowGS               = false;
  bool LogicJabuBossGSAdult             = false;
  bool LogicJabuScrubJumpDive           = false;
  bool LogicForestOutsideBackdoor       = false;
  bool LogicForestScarecrow             = false;
  bool LogicForestVines                 = false;
  bool LogicForestOutdoorEastGS         = false;
  bool LogicFireBossDoorJump            = false;
  bool LogicFireStrength                = false;
  bool LogicFireScarecrow               = false;
  bool LogicFireFlameMaze               = false;
  bool LogicFireSongOfTime              = false;
  bool LogicWaterHookshotEntry          = false;
  bool LogicWaterTempleTorchLongshot    = false;
  bool LogicWaterCentralBow             = false;
  bool LogicWaterCrackedWallNothing     = false;
  bool LogicWaterCrackedWallHovers      = false;
  bool LogicWaterBossKeyRegion          = false;
  bool LogicWaterDragonBombchu          = false;
  bool LogicWaterBKJumpDive             = false;
  bool LogicWaterNorthBasementLedgeJump = false;
  bool LogicWaterBKChest                = false;
  bool LogicWaterDragonJumpDive         = false;
  bool LogicWaterRiverGS                = false;
  bool LogicWaterFallingPlatformGS      = false;
  bool LogicSpiritLowerAdultSwitch      = false;
  bool LogicSpiritChildBombchu          = false;
  bool LogicSpiritWall                  = false;
  bool LogicSpiritLobbyGS               = false;
  bool LogicSpiritMapChest              = false;
  bool LogicSpiritSunChest              = false;
  bool LogicShadowFireArrowEntry        = false;
  bool LogicShadowUmbrella              = false;
  bool LogicShadowFreestandingKey       = false;
  bool LogicShadowStatue                = false;
  bool LogicBotwCageGS                  = false;
  bool LogicChildDeadhand               = false;
  bool LogicGtgWithoutHookshot          = false;
  bool LogicGtgFakeWall                 = false;
  bool LogicLensSpirit                  = false;
  bool LogicLensShadow                  = false;
  bool LogicLensShadowBack              = false;
  bool LogicLensBotw                    = false;
  bool LogicLensGtg                     = false;
  bool LogicLensCastle                  = false;
  bool LogicSpiritTrialHookshot         = false;

  //Function to set flags depending on settings
  void UpdateSettings() {
    LogicGrottosWithoutAgony = true;
    LogicFewerTunicRequirements = true;
    LogicBiggoronBolero = true;
    LogicManOnRoof = true;
    LogicDekuB1Skip = true;

    //1 is MQ, 0 is Vanilla
    if (RandomMQDungeons) {
      DekuTreeDungeonMode              = Random() % 2;
      DodongosCavernDungeonMode        = Random() % 2;
      JabuJabusBellyDungeonMode        = Random() % 2;
      ForestTempleDungeonMode          = Random() % 2;
      FireTempleDungeonMode            = Random() % 2;
      WaterTempleDungeonMode           = Random() % 2;
      SpiritTempleDungeonMode          = Random() % 2;
      ShadowTempleDungeonMode          = Random() % 2;
      BottomOfTheWellDungeonMode       = Random() % 2;
      GerudoTrainingGroundsDungeonMode = Random() % 2;
      GanonsCastleDungeonMode          = Random() % 2;
    }

    if (StartingTime.Is(STARTINGTIME_NIGHT))
      HasNightStart = true;

    if (GanonsBossKey.Is(GANONSBOSSKEY_LACS_MEDALLIONS)) {
      LACSCondition = LACSCONDITION_MEDALLIONS;
    } else if (GanonsBossKey.Is(GANONSBOSSKEY_LACS_STONES)) {
      LACSCondition = LACSCONDITION_STONES;
    } else if (GanonsBossKey.Is(GANONSBOSSKEY_LACS_DUNGEONS)) {
      LACSCondition = LACSCONDITION_DUNGEONS;
    } else {
      LACSCondition = LACSCONDITION_VANILLA;
    }

  }
}
