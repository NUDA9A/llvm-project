#include "ChadArchTargetMachine.h"
#include "ChadArch.h"
#include "TargetInfo/ChadArchTargetInfo.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "llvm/CodeGen/TargetPassConfig.h"
#include "llvm/MC/TargetRegistry.h"
#include <optional>

using namespace llvm;

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeChadArchTarget() {
  // Register the target.
  CHADARCH_DUMP_CYAN
  RegisterTargetMachine<ChadArchTargetMachine> A(getTheChadArchTarget());
}

ChadArchTargetMachine::ChadArchTargetMachine(const Target &T, const Triple &TT,
                                             StringRef CPU, StringRef FS,
                                             const TargetOptions &Options,
                                             std::optional<Reloc::Model> RM,
                                             std::optional<CodeModel::Model> CM,
                                             CodeGenOptLevel OL, bool JIT)
    : CodeGenTargetMachineImpl(T, "e-m:e-p:32:32-i8:8:32-i16:16:32-i64:64-n32",
                               TT, CPU, FS, Options, Reloc::Static,
                               getEffectiveCodeModel(CM, CodeModel::Small), OL),
      TLOF(std::make_unique<TargetLoweringObjectFileELF>()),
      Subtarget(TT, std::string(CPU), std::string(FS), *this) {
  CHADARCH_DUMP_CYAN
  initAsmInfo();
}

namespace {
class ChadArchPassConfig : public TargetPassConfig {
public:
  ChadArchPassConfig(ChadArchTargetMachine &TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  ChadArchTargetMachine &getChadArchTargetMachine() const {
    return getTM<ChadArchTargetMachine>();
  }

  bool addInstSelector() override {
    CHADARCH_DUMP_CYAN
    addPass(createChadArchISelDag(getChadArchTargetMachine(), getOptLevel()));
    return false;
  }
};

} // end anonymous namespace

TargetPassConfig *ChadArchTargetMachine::createPassConfig(PassManagerBase &PM) {
  CHADARCH_DUMP_CYAN
  return new ChadArchPassConfig(*this, PM);
}

TargetLoweringObjectFile *ChadArchTargetMachine::getObjFileLowering() const {
  CHADARCH_DUMP_CYAN
  return TLOF.get();
}