#include "energy_regeneration.h"
#include "max_unit_energy.h"
#include "../SCBW/enumerations.h"
#include "../SCBW/scbwdata.h"
#include "../SCBW/api.h"


/// Determines cloaking energy consumption.
u16 getCloakingEnergyConsumption(const CUnit *unit) {
  //Default StarCraft behavior
  if (unit->id == UnitId::TerranGhost
      || unit->id == UnitId::Hero_SarahKerrigan
      || unit->id == UnitId::Hero_InfestedKerrigan
      || unit->id == UnitId::Hero_SamirDuran
      || unit->id == UnitId::Hero_InfestedDuran
      || unit->id == UnitId::Hero_AlexeiStukov)
    return 10;
  else if (unit->id == UnitId::TerranWraith
           || unit->id == UnitId::Hero_TomKazansky
           )
    return 13;
  else
    return 0;
}

namespace hooks {

/// This hook handles energy regeneration, as well as energy drain for cloaking.
void regenerateEnergyHook(CUnit *unit) {
  using scbw::isCheatEnabled;
  using CheatFlags::TheGathering;

  //If the unit is not a spellcaster, don't regenerate energy
  if (!unit->isValidCaster())
    return;
  
  //If the unit is not fully constructed, don't regenerate energy
  if (!(unit->status & UnitStatus::Completed))
    return;

  //Spend energy for cloaked units
  if (unit->status & (UnitStatus::Cloaked | UnitStatus::RequiresDetection)  //If the unit is cloaked
      && !(unit->status & UnitStatus::CloakingForFree)                      //...and must consume energy to stay cloaked
      && !isCheatEnabled(TheGathering)                                      //...and the energy cheat is not available
      ) {
    u16 cloakingEnergyCost = getCloakingEnergyConsumption(unit);
    if (unit->energy < cloakingEnergyCost) {
      if (unit->secondaryOrderId == OrderId::Cloak)
        unit->setSecondaryOrder(OrderId::Nothing2); //Supposedly, immediately decloaks the unit.
      return;
    }
    unit->energy -= cloakingEnergyCost;
  }
  else {
    u16 maxEnergy;
    if (unit->id == UnitId::dark_archon
        && unit->mainOrderId == OrderId::CompletingArchonSummon
        && !(unit->mainOrderState)
        )
      maxEnergy = unit->getMaxEnergy() / 4;  //Energy amount on spawn; 50 without and 62.5 with upgrades.
    else
      maxEnergy = unit->getMaxEnergy();

    if (unit->energy != maxEnergy) {
      //+25% energy regen if the unit has energy upgrade
      u16 energy = unit->energy + (maxEnergy == 64000 ? 10 : 8);
      if (energy > maxEnergy)
        energy = maxEnergy;
      unit->energy = energy;
    }
  }

  //If the unit is currently selected, redraw its graphics
  if (unit->sprite->flags & 8) {
    for (CImage *i = unit->sprite->imageHead; i; i = i->link.next)
      if (i->paletteType == 11)
        i->flags |= 1;
  }
}

} //hooks
