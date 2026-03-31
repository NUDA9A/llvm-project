#include "ChadArch.h"
#include "ChadArchInstPrinter.h"
#include "ChadArchMCAsmInfo.h"
#include "MCTargetDesc/ChadArchInfo.h"
#include "TargetInfo/ChadArchTargetInfo.h"
#include "llvm/MC/MCDwarf.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Support/ErrorHandling.h"

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

static MCAsmInfo *createChadArchMCAsmInfo(const MCRegisterInfo &MRI,
                                          const Triple &TT,
                                          const MCTargetOptions &Options) {
  CHADARCH_DUMP_MAGENTA
  MCAsmInfo *MAI = new ChadArchELFMCAsmInfo(TT);
  unsigned SP = MRI.getDwarfRegNum(ChadArch::R1, true);
  MCCFIInstruction Inst = MCCFIInstruction::cfiDefCfa(nullptr, SP, 0);
  MAI->addInitialFrameState(Inst);
  return MAI;
}

static MCInstPrinter *createChadArchMCInstPrinter(const Triple &T,
                                                  unsigned SyntaxVariant,
                                                  const MCAsmInfo &MAI,
                                                  const MCInstrInfo &MII,
                                                  const MCRegisterInfo &MRI) {
  CHADARCH_DUMP_MAGENTA
  return new ChadArchInstPrinter(MAI, MII, MRI);
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
  RegisterMCAsmInfoFn X(TheChadArchTarget, createChadArchMCAsmInfo);
  TargetRegistry::RegisterMCRegInfo(TheChadArchTarget,
                                    createChadArchMCRegisterInfo);
  TargetRegistry::RegisterMCInstrInfo(TheChadArchTarget,
                                      createChadArchMCInstrInfo);
  TargetRegistry::RegisterMCSubtargetInfo(TheChadArchTarget,
                                          createChadArchMCSubtargetInfo);
  TargetRegistry::RegisterMCInstPrinter(TheChadArchTarget,
                                        createChadArchMCInstPrinter);
}