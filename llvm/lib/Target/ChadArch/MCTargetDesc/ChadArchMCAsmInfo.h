#ifndef LLVM_LIB_TARGET_CHADARCH_MCTARGETDESC_CHADARCHMCASMINFO_H
#define LLVM_LIB_TARGET_CHADARCH_MCTARGETDESC_CHADARCHMCASMINFO_H

#include "llvm/MC/MCAsmInfoELF.h"

namespace llvm {

class Triple;

class ChadArchELFMCAsmInfo : public MCAsmInfoELF {
public:
  explicit ChadArchELFMCAsmInfo(const Triple &TheTriple);
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_CHADARCH_MCTARGETDESC_CHADARCHMCASMINFO_H