#ifndef LLVM_LIB_TARGET_CHADARCH_MCTARGETDESC_CHADARCHINFO_H
#define LLVM_LIB_TARGET_CHADARCH_MCTARGETDESC_CHADARCHINFO_H

#include "llvm/MC/MCInstrDesc.h"

namespace llvm {

namespace ChadArchOp {
enum OperandType : unsigned {
  OPERAND_SIMM16 = MCOI::OPERAND_FIRST_TARGET,
};
} // namespace ChadArchOp

} // end namespace llvm

#endif