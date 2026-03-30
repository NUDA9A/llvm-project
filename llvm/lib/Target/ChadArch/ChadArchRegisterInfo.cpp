#include "ChadArchRegisterInfo.h"
#include "ChadArch.h"
#include "ChadArchFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "ChadArchGenRegisterInfo.inc"

ChadArchRegisterInfo::ChadArchRegisterInfo()
    : ChadArchGenRegisterInfo(ChadArch::R0) {
  CHADARCH_DUMP_GREEN
}