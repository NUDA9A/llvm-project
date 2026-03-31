#ifndef LLVM_LIB_TARGET_CHADARCH_CHADARCHISELLOWERING_H
#define LLVM_LIB_TARGET_CHADARCH_CHADARCHISELLOWERING_H

#include "ChadArch.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/CodeGen/TargetLowering.h"

namespace llvm {

class ChadArchSubtarget;
class ChadArchTargetMachine;

namespace ChadArchISD {

enum NodeType : unsigned {
  // Start the numbering where the builtin ops and target ops leave off.
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
  RET,
  CALL,
  BR_CC,
};

} // namespace ChadArchISD

} // end namespace llvm

#endif // LLVM_LIB_TARGET_CHADARCH_CHADARCHISELLOWERING_H