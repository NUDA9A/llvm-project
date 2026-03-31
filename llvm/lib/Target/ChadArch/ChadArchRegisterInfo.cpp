#include "ChadArchRegisterInfo.h"
#include "ChadArch.h"
#include "ChadArchFrameLowering.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

using namespace llvm;

#define GET_REGINFO_TARGET_DESC
#include "ChadArchGenRegisterInfo.inc"

ChadArchRegisterInfo::ChadArchRegisterInfo()
    : ChadArchGenRegisterInfo(ChadArch::R0) {
  CHADARCH_DUMP_GREEN
}

const MCPhysReg *
ChadArchRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  CHADARCH_DUMP_GREEN
  return CSR_ChadArch_SaveList;
}

BitVector
ChadArchRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  CHADARCH_DUMP_GREEN
  ChadArchFrameLowering const *TFI = getFrameLowering(MF);

  BitVector Reserved(getNumRegs());
  Reserved.set(ChadArch::R1);

  if (TFI->hasFP(MF)) {
    Reserved.set(ChadArch::R2);
  }
  return Reserved;
}

bool ChadArchRegisterInfo::requiresRegisterScavenging(
    const MachineFunction &MF) const {
  return false;
}

bool ChadArchRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                               int SPAdj, unsigned FIOperandNum,
                                               RegScavenger *RS) const {
  CHADARCH_DUMP_GREEN
  assert(SPAdj == 0 && "Unexpected non-zero SPAdj value");

  MachineInstr &MI = *II;
  MachineFunction &MF = *MI.getParent()->getParent();
  DebugLoc DL = MI.getDebugLoc();

  int FrameIndex = MI.getOperand(FIOperandNum).getIndex();
  Register FrameReg;
  int Offset = getFrameLowering(MF)
                   ->getFrameIndexReference(MF, FrameIndex, FrameReg)
                   .getFixed();
  Offset += MI.getOperand(FIOperandNum + 1).getImm();

  if (!isInt<16>(Offset)) {
    llvm_unreachable("");
  }

  MI.getOperand(FIOperandNum).ChangeToRegister(FrameReg, false, false, false);
  MI.getOperand(FIOperandNum + 1).ChangeToImmediate(Offset);
  return false;
}

Register
ChadArchRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  CHADARCH_DUMP_GREEN
  const TargetFrameLowering *TFI = getFrameLowering(MF);
  return TFI->hasFP(MF) ? ChadArch::R2 : ChadArch::R1;
}

const uint32_t *
ChadArchRegisterInfo::getCallPreservedMask(const MachineFunction &MF,
                                           CallingConv::ID CC) const {
  CHADARCH_DUMP_GREEN
  return CSR_ChadArch_RegMask;
}