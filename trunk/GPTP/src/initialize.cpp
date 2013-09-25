#include "definitions.h"
#include "Plugin.h"
#include "hook_tools.h"

//Hook header files
#include "hooks/game_hooks.h"
#include "hooks/apply_upgrade_flags.h"
#include "hooks/armor_bonus.h"
#include "hooks/bunker_hooks.h"
#include "hooks/cloak_nearby_units.h"
#include "hooks/consume.h"
#include "hooks/detector.h"
#include "hooks/do_weapon_damage.h"
#include "hooks/energy_regeneration.h"
#include "hooks/harvest.h"
#include "hooks/max_unit_energy.h"
#include "hooks/rally_point.h"
#include "hooks/recharge_shields.h"
#include "hooks/sight_range.h"
#include "hooks/stim_packs.h"
#include "hooks/unit_speed.h"
#include "hooks/update_status_effects.h"
#include "hooks/update_unit_timers.h"
#include "hooks/weapon_cooldown.h"
#include "hooks/weapon_range.h"
#include "hooks/unit_destructor_special.h"
#include "hooks/psi_field.h"
#include "graphics/draw_hook.h"

//Defined in CUnit.cpp
extern const u32 Func_DamageWith;

/// This function is called when the plugin is loaded into StarCraft.
/// You can enable/disable each group of hooks by commenting them.
/// You can also add custom modifications to StarCraft.exe by using:
///    memoryPatch(address_to_patch, value_to_patch_with);

BOOL WINAPI Plugin::InitializePlugin(IMPQDraftServer *lpMPQDraftServer) {
  hooks::injectGameHooks();
  hooks::injectApplyUpgradeFlags();

  hooks::injectArmorBonusHook();

  hooks::injectBunkerHooks();
  hooks::injectCloakNearbyUnits();
  hooks::injectConsumeHooks();
  hooks::injectDetectorHooks();

  jmpPatch(doWeaponDamageWrapper,         Func_DamageWith);

  jmpPatch(regenerateEnergyWrapper,       offsets::Hook_RegenerateEnergy);

  hooks::injectHarvestResource();
  hooks::injectUnitMaxEnergyHook();

  hooks::injectRallyHooks();
  hooks::injectRechargeShieldsHooks();

  jmpPatch(getSightRangeWrapper,          offsets::Hook_GetSightRange);
  hooks::injectStimPacksHooks();

  hooks::injectUnitSpeedHooks();

  jmpPatch(updateStatusEffectsWrapper,    offsets::Hook_UpdateStatusEffects);

  hooks::injectUpdateUnitTimers();

  hooks::injectWeaponCooldownHook();  
  hooks::injectWeaponRangeHooks();

  hooks::injectUnitDestructorSpecial();
  hooks::injectPsiFieldHooks();

  InjectDrawHook();

  return TRUE;
}
