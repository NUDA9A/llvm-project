#include "ChadArchISelLowering.h"
#include "ChadArch.h"
#include "ChadArchRegisterInfo.h"
#include "ChadArchSubtarget.h"
#include "llvm/CodeGen/CallingConvLower.h"
#include "llvm/CodeGen/MachineFunction.h"

#define DEBUG_TYPE "ChadArch-lower"

using namespace llvm;

ChadArchTargetLowering::ChadArchTargetLowering(const TargetMachine &TM,
                                               const ChadArchSubtarget &STI)
    : TargetLowering(TM), STI(STI) {
  CHADARCH_DUMP_RED
  addRegisterClass(MVT::i32, &ChadArch::GPRRegClass);
}

const char *ChadArchTargetLowering::getTargetNodeName(unsigned Opcode) const {
  CHADARCH_DUMP_RED
  switch (Opcode) {
  case ChadArchISD::CALL:
    return "ChadArchISD::CALL";
  case ChadArchISD::RET:
    return "ChadArchISD::RET";
  }
  return nullptr;
}