#include "ai_common.h"
#include <SCBW/enumerations.h>
#include <SCBW/api.h>
#include <SCBW/UnitFinder.h>
#include <cassert>

namespace AI {

bool isTargetWorthHitting(const CUnit *target, const CUnit *attacker) {
  //If the target is hidden by the fog-of-war
  if (!target->sprite->isVisibleTo(attacker->playerId))
    return false;

  //If the target is not detectable
  if (target->status & (UnitStatus::Cloaked | UnitStatus::RequiresDetection)
      && !target->isVisibleTo(attacker->playerId))
    return false;

  if (scbw::isAlliedTo(attacker->playerId, target->getLastOwnerId()))
    return false;

  if (target->id == UnitId::ProtossScarab
      || target->id == UnitId::spider_mine
      || target->id == UnitId::interceptor)
    return false;

  //Target is a worker inside a gas building
  if (target->mainOrderId == OrderId::HarvestGas1
      || target->mainOrderId == OrderId::HarvestGas2
      || target->mainOrderId == OrderId::HarvestGas3)
    return false;

  return true;
}

//Logically equivalent to function @ 0x00476180
bool unitCanAttack(const CUnit *unit) {
  if (unit->id == UnitId::lurker) {
    if (unit->status & UnitStatus::Burrowed
        && Unit::GroundWeapon[unit->id] != WeaponId::None)
      return true;
  }
  else if (unit->id == UnitId::carrier || unit->id == UnitId::gantrithor) {
    if ((unit->carrier.inHangarCount + unit->carrier.outHangarCount) > 0)
      return true;
  }
  else if (unit->id == UnitId::reaver || unit->id == UnitId::warbringer) {
    if (unit->carrier.inHangarCount > 0)
      return true;
  }
  else {
    if (Unit::GroundWeapon[unit->id] != WeaponId::None
        || Unit::AirWeapon[unit->id] != WeaponId::None)
      return true;
  }

  return false;
}

bool isTargetAttackingAlly(const CUnit *target, const CUnit *unit) {
  if (CUnit *secondTarget = target->orderTarget.unit) {
    if (secondTarget->playerId < 8
        && scbw::isAlliedTo(unit->playerId, secondTarget->getLastOwnerId()))
      return true;
  }

  return false;
}

bool isUmsMode(s8 playerId) {
  assert(0 <= playerId && playerId < 8);
  return AIScriptController[playerId].AI_Flags.isUseMapSettings;
}

//-------- isUnitInUnsafeRegion() --------//

//Internal use only
const u32 Func_GetRegionIdAtPosEx = 0x0049C9F0;
u16 getRegionIdAtPosEx(s32 x, s32 y) {
  static u16 result;

  __asm {
    PUSHAD
    MOV EDI, x
    MOV ECX, y
    CALL Func_GetRegionIdAtPosEx
    MOV result, AX
    POPAD
  }

  return result;
}

//Based on code @ 0x00440BB0
bool isUnitInUnsafeRegion(const CUnit *unit) {
  u16 currentRegion = getRegionIdAtPosEx(unit->getX(), unit->getY());
  AiCaptain *currentAiCaptain = &AiRegionCaptains[unit->playerId][currentRegion];
  return currentAiCaptain->captainType == 3
    || currentAiCaptain->unknown_0x1C
    || currentAiCaptain->unknown_0x20
    || currentAiCaptain->captainFlags & 0x20;
}

//-------- getTechUseErrorMessage() --------//

//Internal use only
const u32 Func_IsInfestable = 0x00402210;
bool isInfestableCC(const CUnit *unit) {
  static Bool32 result;
  
  __asm {
    PUSHAD
    MOV EDX, unit
    CALL Func_IsInfestable
    MOV result, EAX
    POPAD
  }

  return result != 0;
}

//TODO: Add a hook module for this
u16 getTechUseErrorMessage(const CUnit *target, s8 castingPlayer, int techId) {
  if (target->stasisTimer)
    return 900;         //Units in stasis can't be targeted.<0>

  switch (techId) {
    case TechId::Feedback:
      if (Unit::BaseProperty[target->id] & UnitProperty::Building)
        return 877;     //Unable to target structure.<0>
      if (Unit::BaseProperty[target->id] & UnitProperty::Spellcaster
          && !(target->status & UnitStatus::IsHallucination))
        return 1330;    //Must target units with energy.<0>
      break;

    case TechId::MindControl:
      if (target->playerId == castingPlayer)
        return 1327;    //Must target enemy units<0>
      if (Unit::BaseProperty[target->id] & UnitProperty::Building)
        return 877;     //Unable to target structure.<0>
      if (target->id == UnitId::vulture
          || target->id == UnitId::larva
          || target->id == UnitId::egg
          || target->id == UnitId::cocoon
          || target->id == UnitId::interceptor
          || target->id == UnitId::ProtossScarab
          || target->id == UnitId::ZergLurkerEgg)
        return 876;     //Invalid target.<0>
      break;

    case TechId::Hallucination:
      if (target->id == UnitId::interceptor)
        return 876;     //Invalid target.<0>
      if (Unit::BaseProperty[target->id] & UnitProperty::Building)
        return 877;     //Unable to target structure.<0>
      break;

    case TechId::DefensiveMatrix:
    case TechId::Irradiate:
    case TechId::Restoration:
    case TechId::OpticalFlare:
      if (Unit::BaseProperty[target->id] & UnitProperty::Building)
        return 877;     //Unable to target structure.<0>
      break;

    case TechId::Infestation:
      if (!isInfestableCC(target))
        return 870;     //Must target severely damaged Terran Command Center.<0>
      break;

    case TechId::Consume:
      if (Unit::BaseProperty[target->id] & UnitProperty::Building
          || target->playerId != castingPlayer
          || !(Unit::GroupFlags[target->id].isZerg)
          || target->id == UnitId::larva)
        return 897;     //Invalid target.<0>
      break;
  }

  return 0;             //No error
}

//-------- Unit stats shown in-game --------//

int getCurrentHpInGame(const CUnit *unit) {
  return (unit->hitPoints + 255) / 256;
}

int getMaxHpInGame(const CUnit *unit) {
  return (Unit::MaxHitPoints[unit->id] + 255) / 256;
}

int getCurrentLifeInGame(const CUnit *unit) {
  if (Unit::ShieldsEnabled[unit->id])
    return getCurrentHpInGame(unit) + unit->shields / 256;
  else
    return getCurrentHpInGame(unit);
}

//-------- Unit stat accumulators --------//

class UnitStatSumProc: public scbw::UnitFinderCallbackProcInterface {
  protected:
    const CUnit *caster;
    int sum;
    u8 weaponId;
  public:
    void set(const CUnit *caster, u8 weaponId = WEAPON_TYPE_COUNT) {
      this->caster = caster; this->weaponId = weaponId; sum = 0;
    }
    int getSum() const { return sum; }

    virtual void proc(CUnit *target) = 0;
};

class EnemyLifeSumProc: public UnitStatSumProc {
  public:
    void proc(CUnit *target) {
      if (target == caster)
        return;

      if (target->status & UnitStatus::Invincible)
        return;

      if (!scbw::canWeaponTargetUnit(weaponId, target, caster))
        return;

      if (scbw::isAlliedTo(caster->playerId, target->getLastOwnerId()))
        return;

      if (weaponId == WeaponId::Plague)
        sum += getCurrentHpInGame(target);
      else if (weaponId == WeaponId::Maelstrom) {
        if (Unit::BaseProperty[target->id] & UnitProperty::Organic
            && target->maelstromTimer == 0) {
          sum += getCurrentLifeInGame(target);
        }
      }
      else
        sum += getCurrentLifeInGame(target);
    }
};

class AllyLifeSumProc: public UnitStatSumProc {
  public:
    void proc(CUnit *target) {
      if (target == caster)
        return;

      if (target->status & UnitStatus::Invincible)
        return;

      if (!scbw::canWeaponTargetUnit(weaponId, target, caster))
        return;

      if (!scbw::isAlliedTo(caster->playerId, target->getLastOwnerId()))
        return;

      sum += getCurrentLifeInGame(target);
    }
};

class EnemyShieldsSumProc: public UnitStatSumProc {
  public:
    void proc(CUnit *target) {
      if (target->status & UnitStatus::Invincible)
        return;

      if (!scbw::isAlliedTo(caster->playerId, target->getLastOwnerId()))
        return;

      if (!Unit::ShieldsEnabled[target->id])
        return;

      sum += target->shields / 256;
    }
};

class EnemyEnergySumProc: public UnitStatSumProc {
  public:
    void proc(CUnit *target) {
      if (target->status & UnitStatus::Invincible)
        return;

      if (!scbw::isAlliedTo(caster->playerId, target->getLastOwnerId()))
        return;

      if (!(Unit::BaseProperty[target->id] & UnitProperty::Spellcaster))
        return;

      if (target->status & UnitStatus::IsHallucination)
        return;

      sum += target->energy / 256;
    }
};

//-------- Get total unit stats in area --------//

scbw::UnitFinder unitStatTotalFinder;

int getTotalEnemyLifeInArea(int x, int y, int searchBounds, const CUnit *caster, u8 weaponId) {
  unitStatTotalFinder.search(x - searchBounds, y - searchBounds,
                             x + searchBounds, y + searchBounds);
  EnemyLifeSumProc sumProc;
  sumProc.set(caster, weaponId);
  unitStatTotalFinder.forEach(sumProc);
  return sumProc.getSum();
}

int getTotalAllyLifeInArea(int x, int y, int searchBounds, const CUnit *caster, u8 weaponId) {
  unitStatTotalFinder.search(x - searchBounds, y - searchBounds,
                             x + searchBounds, y + searchBounds);
  AllyLifeSumProc sumProc;
  sumProc.set(caster, weaponId);
  unitStatTotalFinder.forEach(sumProc);
  return sumProc.getSum();
}

int getTotalEnemyShieldsInArea(int x, int y, int searchBounds, const CUnit *caster) {
  unitStatTotalFinder.search(x - searchBounds, y - searchBounds,
                             x + searchBounds, y + searchBounds);
  EnemyShieldsSumProc sumProc;
  sumProc.set(caster);
  unitStatTotalFinder.forEach(sumProc);
  return sumProc.getSum();
}

int getTotalEnemyEnergyInArea(int x, int y, int searchBounds, const CUnit *caster) {
  unitStatTotalFinder.search(x - searchBounds, y - searchBounds,
                             x + searchBounds, y + searchBounds);
  EnemyEnergySumProc sumProc;
  sumProc.set(caster);
  unitStatTotalFinder.forEach(sumProc);
  return sumProc.getSum();
}

} //AI
