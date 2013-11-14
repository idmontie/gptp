#include "definitions.h"
#include "Plugin.h"
#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

//Called when the user hits the configure button in MPQDraft or FireGraft
BOOL WINAPI Plugin::Configure(HWND hParentWnd) {
  /*
   *  You can't really change the version from
   *  here with the current format.  However, you
   *  can check the version and probably set any
   *  globals.
   */

  MessageBox(
    hParentWnd,
    PLUGIN_NAME " (ID: " STR(PLUGIN_ID) ")"
    "\nMade by pastelmind"
    "\nBuilt on " __DATE__ " " __TIME__
    "\n"
    "\n[Features]"
    "\n- Stim Packs: 20HP cost for Fiends, add effect overlay"
    "\n- Plague: Deal full damage, always reduce HP to 1 / 256"
    "\n- First Aid Packs upgrade: Terran infantry HP regen"
    "\n- Changed cooldown modifiers for Acid Spore / Ensnare / Stim Packs"
    "\n- Changed unit speed modifiers for Ensnare and Stim Packs"
    "\n- Improved unit weapon tooltip text"
    "\n- Dark Swarm reduces range attack damage by 50%"
    "\n- Damage types: Venomous - 100%/125%/150%, Concussive - 100%/75%/50%"
    "\n- Recharge Shields: overcharge, +distance, +efficiency"
    "\n- Display attack range circle for Siege Mode Tanks selected"
    "\n- Irradiate: Damage non-organic units, SVs are immune"
    "\n- Energy upgrades provide +25% energy regeneration"
    "\n- Ocular Implants spell: +2 sight range, +1 attack range"
    "\n- Sight range upgrades: Thermal Sensors, Prescience, Antennae"
    "\n"
    "\nNote: This plugin is compatible with the Smart Rally plugin."
    ,
    PLUGIN_NAME,
    MB_TASKMODAL
  );

  return TRUE;
}

