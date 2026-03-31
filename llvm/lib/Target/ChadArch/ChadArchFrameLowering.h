#ifndef LLVM_LIB_TARGET_CHADARCH_CHADARCHFRAMELOWERING_H
#define LLVM_LIB_TARGET_CHADARCH_CHADARCHFRAMELOWERING_H

#include "ChadArch.h"
#include "llvm/CodeGen/TargetFrameLowering.h"

namespace llvm {
class ChadArchSubtarget;

class ChadArchFrameLowering : public TargetFrameLowering {
public:
  ChadArchFrameLowering(const ChadArchSubtarget &STI)
      : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, Align(4), 0),
        STI(STI) {
    CHADARCH_DUMP_GREEN
  }

  /// emitProlog/emitEpilog - These methods insert prolog and epilog code into
  /// the function.
  void emitPrologue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {}
  void emitEpilogue(MachineFunction &MF,
                    MachineBasicBlock &MBB) const override {}

  /// hasFP - Return true if the specified function should have a dedicated
  /// frame pointer register. For most targets this is true only if the function
  /// has variable sized allocas or if frame pointer elimination is disabled.
  bool hasFPImpl(const MachineFunction &MF) const override { return false; }

private:
  const ChadArchSubtarget &STI;
};

} // namespace llvm

#endif // LLVM_LIB_TARGET_CHADARCH_CHADARCHFRAMELOWERING_H