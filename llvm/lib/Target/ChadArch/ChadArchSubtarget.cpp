#include "ChadArchSubtarget.h"
#include "ChadArch.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "chadarch-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "ChadArchGenSubtargetInfo.inc"

ChadArchSubtarget::ChadArchSubtarget(const Triple &TT, const std::string &CPU,
                                     const std::string &FS,
                                     const TargetMachine &TM)
    : ChadArchGenSubtargetInfo(TT, CPU, CPU, FS), TLInfo(TM, *this),
      FrameLowering(*this), InstrInfo() {
  CHADARCH_DUMP_CYAN
}