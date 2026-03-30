#ifndef LLVM_LIB_TARGET_CHADARCH_CHADARCHINSTRINFO_H
#define LLVM_LIB_TARGET_CHADARCH_CHADARCHINSTRINFO_H

#include "ChadArchRegisterInfo.h"
#include "MCTargetDesc/ChadArchInfo.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

#define GET_INSTRINFO_HEADER
#include "ChadArchGenInstrInfo.inc"

namespace llvm {

class ChadArchSubtarget;

class ChadArchInstrInfo : public ChadArchGenInstrInfo {
public:
  ChadArchInstrInfo();
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_CHADARCH_CHADARCHINSTRINFO_H