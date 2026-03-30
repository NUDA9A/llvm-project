#include "ChadArch.h"
#include "MCTargetDesc/ChadArchInfo.h"
#include "TargetInfo/ChadArchTargetInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

#define GET_REGINFO_MC_DESC
#include "ChadArchGenRegisterInfo.inc"

#define GET_INSTRINFO_MC_DESC
#include "ChadArchGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "ChadArchGenSubtargetInfo.inc"

static MCRegisterInfo *createChadArchMCRegisterInfo(const Triple &TT) {
  CHADARCH_DUMP_MAGENTA
  MCRegisterInfo *X = new MCRegisterInfo();
  InitChadArchMCRegisterInfo(X, ChadArch::R0);
  return X;
}

static MCSubtargetInfo *
createChadArchMCSubtargetInfo(const Triple &TT, StringRef CPU, StringRef FS) {
  CHADARCH_DUMP_MAGENTA
  return createChadArchMCSubtargetInfoImpl(TT, CPU, CPU, FS);
}

static MCInstrInfo *createChadArchMCInstrInfo() {
  CHADARCH_DUMP_MAGENTA
  MCInstrInfo *X = new MCInstrInfo();
  InitChadArchMCInstrInfo(X);
  return X;
}

// We need to define this function for linking succeed
extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeChadArchTargetMC() {
  CHADARCH_DUMP_MAGENTA
  Target &TheChadArchTarget = getTheChadArchTarget();
  TargetRegistry::RegisterMCRegInfo(TheChadArchTarget,
                                    createChadArchMCRegisterInfo);
  TargetRegistry::RegisterMCInstrInfo(TheChadArchTarget,
                                      createChadArchMCInstrInfo);
  TargetRegistry::RegisterMCSubtargetInfo(TheChadArchTarget,
                                          createChadArchMCSubtargetInfo);
}