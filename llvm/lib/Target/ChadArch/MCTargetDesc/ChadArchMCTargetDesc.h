#ifndef LLVM_LIB_TARGET_CHADARCH_MCTARGETDESC_CHADARCHMCTARGETDESC_H
#define LLVM_LIB_TARGET_CHADARCH_MCTARGETDESC_CHADARCHMCTARGETDESC_H

namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;

MCCodeEmitter *createChadArchMCCodeEmitter(const MCInstrInfo &MCII,
                                           MCContext &Ctx);
} // namespace llvm

#define GET_REGINFO_ENUM
#include "ChadArchGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "ChadArchGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_CHADARCH_MCTARGETDESC_CHADARCHMCTARGETDESC_H