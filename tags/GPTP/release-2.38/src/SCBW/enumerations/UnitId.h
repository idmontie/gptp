#pragma once

namespace UnitId {
enum Enum {
  //Short names used in unitdef.txt
  marine              = 0,
  ghost               = 1,
  vulture             = 2,
  goliath             = 3,
  goliath_turret      = 4,
  siege_tank          = 5,
  siege_tank_turret   = 6,
  scv                 = 7,
  wraith              = 8,
  science_vessel      = 9,
  gui_montag          = 10,
  dropship            = 11,
  battlecruiser       = 12,
  spider_mine         = 13,
  nuclear_missile     = 14,
  civilian            = 15,
  sarah_kerrigan      = 16,
  alan_schezar        = 17,
  alan_schezar_turret = 18,
  jim_raynor_vulture  = 19,
  jim_raynor_marine   = 20,
  tom_kazansky        = 21,
  magellan            = 22,
  edmund_duke         = 23,
  edmund_duke_turret  = 24,
  edmund_duke_s       = 25,
  edmund_duke_s_turret= 26,
  arcturus_mengsk     = 27,
  hyperion            = 28,
  norad_ii            = 29,
  siege_tank_s        = 30,
  siege_tank_s_turret = 31,
  firebat             = 32,
  scanner_sweep       = 33,
  medic               = 34,
  larva               = 35,
  egg                 = 36,
  zergling            = 37,
  hydralisk           = 38,
  ultralisk           = 39,
  broodling           = 40,
  drone               = 41,
  overlord            = 42,
  mutalisk            = 43,
  guardian            = 44,
  queen               = 45,
  defiler             = 46,
  scourge             = 47,
  torrasque           = 48,
  matriarch           = 49,
  infested_terran     = 50,
  infested_kerrigan   = 51,
  unclean_one         = 52,
  hunter_killer       = 53,
  devouring_one       = 54,
  kukulza_mutalisk    = 55,
  kukulza_guardian    = 56,
  yggdrasill          = 57,
  valkyrie            = 58,
  cocoon              = 59,
  corsair             = 60,
  dark_templar        = 61,
  devourer            = 62,
  dark_archon         = 63,
  zealot              = 65,
  dragoon             = 66,
  high_templar        = 67,
  archon              = 68,
  shuttle             = 69,
  scout               = 70,
  arbiter             = 71,
  carrier             = 72,
  interceptor         = 73,
  dark_templar_hero   = 74,
  zeratul             = 75,
  tassadar_zeratul    = 76,
  fenix_zealot        = 77,
  fenix_dragoon       = 78,
  tassadar            = 79,
  mojo                = 80,
  warbringer          = 81,
  gantrithor          = 82,
  reaver              = 83,
  observer            = 84,
  scarab              = 85,
  danimoth            = 86,
  aldaris             = 87,
  artanis             = 88,
  rhynadon            = 89,
  bengalaas           = 90,
  cargo_ship          = 91,
  mercenary_gunship   = 92,
  scantid             = 93,
  kakaru              = 94,
  ragnasaur           = 95,
  ursadon             = 96,
  lurker_egg          = 97,
  raszagal            = 98,
  samir_duran         = 99,
  alexei_stukov       = 100,
  map_revealer        = 101,
  gerard_dugalle      = 102,
  lurker              = 103,
  command_center = 106,
  comsat_station = 107,
  nuclear_silo = 108,
  supply_depot = 109,
  refinery = 110,
  barracks = 111,
  academy = 112,
  factory = 113,
  starport = 114,
  control_tower = 115,
  science_facility = 116,
  covert_ops = 117,
  physics_lab = 118,
  machine_shop = 120,
  engineering_bay = 122,
  armory = 123,
  missile_turret = 124,
  bunker = 125,


  infested_command_center = 130,
  hatchery = 131,
  lair = 132,
  hive = 133,
  nydus_canal = 134,
  hydralisk_den = 135,
  defiler_mound = 136,
  greater_spire = 137,
  queen_nest = 138,
  evolution_chamber = 139,
  ultralisk_cavern = 140,
  spire = 141,
  spawning_pool = 142,
  creep_colony = 143,
  spore_colony = 144,
  sunken_colony = 146,
  extractor = 149,

  probe = 64,
  nexus = 154,
  robotics_facility = 155,
  pylon = 156,
  assimilator = 157,
  observatory = 159,
  gateway = 160,
  photon_cannon = 162,
  citadel_of_adun = 163,
  cybernetics_core = 164,
  templar_archives = 165,
  forge = 166,
  stargate = 167,
  fleet_beacon = 169,
  arbiter_tribunal = 170,
  robotics_support_bay = 171,
  shield_battery = 172,
  khaydarin_crystal_formation = 173,
  protoss_temple      = 174,
  xelnaga_temple      = 175,
  mineral_field_1     = 176,
  mineral_field_2     = 177,
  mineral_field_3     = 178,

  //Full names
  TerranMarine                    = 0,
  TerranGhost                     = 1,
  TerranVulture                   = 2,
  TerranGoliath                   = 3,
  TerranGoliathTurret             = 4,
  TerranSiegeTankTankMode         = 5,
  TerranSiegeTankTankModeTurret   = 6,
  TerranSCV                       = 7,
  TerranWraith                    = 8,
  TerranScienceVessel             = 9,
  Hero_GuiMontag                  = 10,
  TerranDropship                  = 11,
  TerranBattlecruiser             = 12,
  TerranVultureSpiderMine         = 13,
  TerranNuclearMissile            = 14,
  TerranCivilian                  = 15,
  Hero_SarahKerrigan              = 16,
  Hero_AlanSchezar                = 17,
  Hero_AlanSchezarTurret          = 18,
  Hero_JimRaynorVulture           = 19,
  Hero_JimRaynorMarine            = 20,
  Hero_TomKazansky                = 21,
  Hero_Magellan                   = 22,
  Hero_EdmundDukeTankMode         = 23,
  Hero_EdmundDukeTankModeTurret   = 24,
  Hero_EdmundDukeSiegeMode        = 25,
  Hero_EdmundDukeSiegeModeTurret  = 26,
  Hero_ArcturusMengsk             = 27,
  Hero_Hyperion                   = 28,
  Hero_NoradII                    = 29,
  TerranSiegeTankSiegeMode        = 30,
  TerranSiegeTankSiegeModeTurret  = 31,
  TerranFirebat                   = 32,
  Spell_ScannerSweep              = 33,
  TerranMedic                     = 34,
  ZergLarva                       = 35,
  ZergEgg                         = 36,
  ZergZergling                    = 37,
  ZergHydralisk                   = 38,
  ZergUltralisk                   = 39,
  ZergBroodling                   = 40,
  ZergDrone                       = 41,
  ZergOverlord                    = 42,
  ZergMutalisk                    = 43,
  ZergGuardian                    = 44,
  ZergQueen                       = 45,
  ZergDefiler                     = 46,
  ZergScourge                     = 47,
  Hero_Torrasque                  = 48,
  Hero_Matriarch                  = 49,
  ZergInfestedTerran              = 50,
  Hero_InfestedKerrigan           = 51,
  Hero_UncleanOne                 = 52,
  Hero_HunterKiller               = 53,
  Hero_DevouringOne               = 54,
  Hero_KukulzaMutalisk            = 55,
  Hero_KukulzaGuardian            = 56,
  Hero_Yggdrasill                 = 57,
  TerranValkyrie                  = 58,
  ZergCocoon                      = 59,
  ProtossCorsair                  = 60,
  ProtossDarkTemplar              = 61,
  ZergDevourer                    = 62,
  ProtossDarkArchon               = 63,
  ProtossProbe                    = 64,
  ProtossZealot                   = 65,
  ProtossDragoon                  = 66,
  ProtossHighTemplar              = 67,
  ProtossArchon                   = 68,
  ProtossShuttle                  = 69,
  ProtossScout                    = 70,
  ProtossArbiter                  = 71,
  ProtossCarrier                  = 72,
  ProtossInterceptor              = 73,
  Hero_DarkTemplar                = 74,
  Hero_Zeratul                    = 75,
  Hero_TassadarZeratulArchon      = 76,
  Hero_FenixZealot                = 77,
  Hero_FenixDragoon               = 78,
  Hero_Tassadar                   = 79,
  Hero_Mojo                       = 80,
  Hero_Warbringer                 = 81,
  Hero_Gantrithor                 = 82,
  ProtossReaver                   = 83,
  ProtossObserver                 = 84,
  ProtossScarab                   = 85,
  Hero_Danimoth                   = 86,
  Hero_Aldaris                    = 87,
  Hero_Artanis                    = 88,
  Critter_Rhynadon                = 89,
  Critter_Bengalaas               = 90,
  Special_CargoShip               = 91,
  Special_MercenaryGunship        = 92,
  Critter_Scantid                 = 93,
  Critter_Kakaru                  = 94,
  Critter_Ragnasaur               = 95,
  Critter_Ursadon                 = 96,
  ZergLurkerEgg                   = 97,
  Hero_Raszagal                   = 98,
  Hero_SamirDuran                 = 99,
  Hero_AlexeiStukov               = 100,
  Special_MapRevealer             = 101,
  Hero_GerardDuGalle              = 102,
  ZergLurker                      = 103,
  Hero_InfestedDuran              = 104,
  Spell_DisruptionWeb             = 105,
  TerranCommandCenter             = 106,
  TerranComsatStation             = 107,
  TerranNuclearSilo               = 108,
  TerranSupplyDepot               = 109,
  TerranRefinery                  = 110,
  TerranBarracks                  = 111,
  TerranAcademy                   = 112,
  TerranFactory                   = 113,
  TerranStarport                  = 114,
  TerranControlTower              = 115,
  TerranScienceFacility           = 116,
  TerranCovertOps                 = 117,
  TerranPhysicsLab                = 118,
  UnusedTerran1                   = 119,
  TerranMachineShop               = 120,
  UnusedTerran2                   = 121,
  TerranEngineeringBay            = 122,
  TerranArmory                    = 123,
  TerranMissileTurret             = 124,
  TerranBunker                    = 125,
  Special_CrashedNoradII          = 126,
  Special_IonCannon               = 127,
  Powerup_UrajCrystal             = 128,
  Powerup_KhalisCrystal           = 129,
  ZergInfestedCommandCenter       = 130,
  ZergHatchery                    = 131,
  ZergLair                        = 132,
  ZergHive                        = 133,
  ZergNydusCanal                  = 134,
  ZergHydraliskDen                = 135,
  ZergDefilerMound                = 136,
  ZergGreaterSpire                = 137,
  ZergQueensNest                  = 138,
  ZergEvolutionChamber            = 139,
  ZergUltraliskCavern             = 140,
  ZergSpire                       = 141,
  ZergSpawningPool                = 142,
  ZergCreepColony                 = 143,
  ZergSporeColony                 = 144,
  UnusedZerg1                     = 145,
  ZergSunkenColony                = 146,
  Special_OvermindWithShell       = 147,
  Special_Overmind                = 148,
  ZergExtractor                   = 149,
  Special_MatureChrysalis         = 150,
  Special_Cerebrate               = 151,
  Special_CerebrateDaggoth        = 152,
  UnusedZerg2                     = 153,
  ProtossNexus                    = 154,
  ProtossRoboticsFacility         = 155,
  ProtossPylon                    = 156,
  ProtossAssimilator              = 157,
  UnusedProtoss1                  = 158,
  ProtossObservatory              = 159,
  ProtossGateway                  = 160,
  UnusedProtoss2                  = 161,
  ProtossPhotonCannon             = 162,
  ProtossCitadelofAdun            = 163,
  ProtossCyberneticsCore          = 164,
  ProtossTemplarArchives          = 165,
  ProtossForge                    = 166,
  ProtossStargate                 = 167,
  Special_StasisCellPrison        = 168,
  ProtossFleetBeacon              = 169,
  ProtossArbiterTribunal          = 170,
  ProtossRoboticsSupportBay       = 171,
  ProtossShieldBattery            = 172,
  Special_KhaydarinCrystalForm    = 173,
  Special_ProtossTemple           = 174,
  Special_XelNagaTemple           = 175,
  ResourceMineralField            = 176,
  ResourceMineralFieldType2       = 177,
  ResourceMineralFieldType3       = 178,
  UnusedCave                      = 179,
  UnusedCaveIn                    = 180,
  UnusedCantina                   = 181,
  UnusedMiningPlatform            = 182,
  UnusedIndependentCommandCenter  = 183,
  Special_IndependentStarport     = 184,
  UnusedIndependentJumpGate       = 185,
  UnusedRuins                     = 186,
  UnusedKhaydarinCrystalFormation = 187,
  ResourceVespeneGeyser           = 188,
  Special_WarpGate                = 189,
  Special_PsiDisrupter            = 190,
  UnusedZergMarker                = 191,
  UnusedTerranMarker              = 192,
  UnusedProtossMarker             = 193,
  Special_ZergBeacon              = 194,
  Special_TerranBeacon            = 195,
  Special_ProtossBeacon           = 196,
  Special_ZergFlagBeacon          = 197,
  Special_TerranFlagBeacon        = 198,
  Special_ProtossFlagBeacon       = 199,
  Special_PowerGenerator          = 200,
  Special_OvermindCocoon          = 201,
  Spell_DarkSwarm                 = 202,
  Special_FloorMissileTrap        = 203,
  Special_FloorHatch              = 204,
  Special_UpperLevelDoor          = 205,
  Special_RightUpperLevelDoor     = 206,
  Special_PitDoor                 = 207,
  Special_RightPitDoor            = 208,
  Special_FloorGunTrap            = 209,
  Special_WallMissileTrap         = 210,
  Special_WallFlameTrap           = 211,
  Special_RightWallMissileTrap    = 212,
  Special_RightWallFlameTrap      = 213,
  Special_StartLocation           = 214,
  Powerup_Flag                    = 215,
  Powerup_YoungChrysalis          = 216,
  Powerup_PsiEmitter              = 217,
  Powerup_DataDisk                = 218,
  Powerup_KhaydarinCrystal        = 219,
  Powerup_MineralClusterType1     = 220,
  Powerup_MineralClusterType2     = 221,
  Powerup_ProtossGasOrbType1      = 222,
  Powerup_ProtossGasOrbType2      = 223,
  Powerup_ZergGasSacType1         = 224,
  Powerup_ZergGasSacType2         = 225,
  Powerup_TerranGasTankType1      = 226,
  Powerup_TerranGasTankType2      = 227,
  None                            = 228,
};
}
