#ifndef LLVM_LIB_TARGET_CHADARCH_CHADARCHTARGETMACHINE_H
#define LLVM_LIB_TARGET_CHADARCH_CHADARCHTARGETMACHINE_H

#include "llvm/CodeGen/CodeGenTargetMachineImpl.h"
#include <optional>

namespace llvm {
extern Target TheChadArchTarget;

class ChadArchTargetMachine : public CodeGenTargetMachineImpl {
public:
  ChadArchTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                        StringRef FS, const TargetOptions &Options,
                        std::optional<Reloc::Model> RM,
                        std::optional<CodeModel::Model> CM, CodeGenOptLevel OL,
                        bool JIT);

  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
};
} // end namespace llvm

#endif // LLVM_LIB_TARGET_CHADARCH_CHADARCHTARGETMACHINE_H