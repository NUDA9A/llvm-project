#include "ChadArchSubtarget.h"
#include "ChadArch.h"
#include "llvm/Target/TargetMachine.h"

using namespace llvm;

#define DEBUG_TYPE "chadarch-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "ChadArchGenSubtargetInfo.inc"

ChadArchSubtarget::ChadArchSubtarget(const StringRef &CPU,
                                     const StringRef &TuneCPU,
                                     const StringRef &FS,
                                     const TargetMachine &TM)
    : ChadArchGenSubtargetInfo(TM.getTargetTriple(), CPU, TuneCPU, FS) {
  CHADARCH_DUMP_CYAN
}