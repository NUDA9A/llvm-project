#ifndef LLVM_LIB_TARGET_CHADARCH_CHADARCHREGISTERINFO_H
#define LLVM_LIB_TARGET_CHADARCH_CHADARCHREGISTERINFO_H

#define GET_REGINFO_HEADER
#include "ChadArchGenRegisterInfo.inc"

namespace llvm {

struct ChadArchRegisterInfo : public ChadArchGenRegisterInfo {
public:
  ChadArchRegisterInfo();
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_CHADARCH_CHADARCHREGISTERINFO_H