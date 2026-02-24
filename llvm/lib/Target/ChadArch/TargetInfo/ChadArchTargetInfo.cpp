#include "TargetInfo/ChadArchTargetInfo.h"
#include "ChadArch.h"
#include "llvm/MC/TargetRegistry.h"

using namespace llvm;

Target &llvm::getTheChadArchTarget() {
  CHADARCH_DUMP_YELLOW
  static Target TheChadArchTarget;
  return TheChadArchTarget;
}

extern "C" LLVM_EXTERNAL_VISIBILITY void LLVMInitializeChadArchTargetInfo() {
  CHADARCH_DUMP_YELLOW
  RegisterTarget<Triple::chadarch> X(getTheChadArchTarget(), "chadarch",
                                "Chad Architecture target for LLVM course", "CHADARCH");
}