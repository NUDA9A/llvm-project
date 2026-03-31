#ifndef LLVM_LIB_TARGET_CHADARCH_CHADARCHTARGETMACHINE_H
#define LLVM_LIB_TARGET_CHADARCH_CHADARCHTARGETMACHINE_H

#include "ChadArchSubtarget.h"
#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheChadArchTarget;

class ChadArchTargetMachine : public CodeGenTargetMachineImpl {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  ChadArchSubtarget Subtarget;

public:
  ChadArchTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                        StringRef FS, const TargetOptions &Options,
                        std::optional<Reloc::Model> RM,
                        std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                        bool JIT);

  const ChadArchSubtarget *getSubtargetImpl(const Function &) const override {
    CHADARCH_DUMP_CYAN
    return &Subtarget;
  }

  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
  TargetLoweringObjectFile *getObjFileLowering() const override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_CHADARCH_CHADARCHTARGETMACHINE_H