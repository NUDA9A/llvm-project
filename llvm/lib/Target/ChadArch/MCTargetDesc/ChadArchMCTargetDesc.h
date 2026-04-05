#ifndef LLVM_LIB_TARGET_CHADARCH_MCTARGETDESC_CHADARCHMCTARGETDESC_H
#define LLVM_LIB_TARGET_CHADARCH_MCTARGETDESC_CHADARCHMCTARGETDESC_H

#include <memory>

namespace llvm {
class MCCodeEmitter;
class MCContext;
class MCInstrInfo;
class MCAsmBackend;
class MCObjectTargetWriter;
class MCRegisterInfo;
class MCSubtargetInfo;
class MCTargetOptions;
class Target;

MCCodeEmitter *createChadArchMCCodeEmitter(const MCInstrInfo &MCII,
                                           MCContext &Ctx);
MCAsmBackend *createChadArchAsmBackend(const Target &T,
                                       const MCSubtargetInfo &STI,
                                       const MCRegisterInfo &MRI,
                                       const MCTargetOptions &Options);
std::unique_ptr<MCObjectTargetWriter>
createChadArchELFObjectWriter(bool Is64Bit, uint8_t OSABI);
} // namespace llvm

#define GET_REGINFO_ENUM
#include "ChadArchGenRegisterInfo.inc"

#define GET_INSTRINFO_ENUM
#include "ChadArchGenInstrInfo.inc"

#endif // LLVM_LIB_TARGET_CHADARCH_MCTARGETDESC_CHADARCHMCTARGETDESC_H