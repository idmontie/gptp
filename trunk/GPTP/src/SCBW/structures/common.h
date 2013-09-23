//Based on BWAPI's BW/Position.h

#pragma once
#include "../../types.h"
#pragma pack(1)

struct Point16 {
  u16 x;
  u16 y;

  bool operator ==(const Point16 &rhs) const {
    return x == rhs.x && y == rhs.y;
  }
  bool operator !=(const Point16 &rhs) const {
    return !(*this == rhs);
  }
};

struct Point32 {
  int x;
  int y;
};

struct Box16 {
  s16 left;
  s16 top;
  s16 right;
  s16 bottom;
};

struct Box32 {
  s32 left;
  s32 top;
  s32 right;
  s32 bottom;
};


C_ASSERT(sizeof(Point16) == 4);
C_ASSERT(sizeof(Point32) == 8);
C_ASSERT(sizeof(Box16) == 8);
C_ASSERT(sizeof(Box32) == 16);

#pragma pack()
