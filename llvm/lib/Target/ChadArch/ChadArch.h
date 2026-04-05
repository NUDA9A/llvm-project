#ifndef LLVM_LIB_TARGET_ChadArch_ChadArch_H
#define LLVM_LIB_TARGET_ChadArch_ChadArch_H

#include "MCTargetDesc/ChadArchMCTargetDesc.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Target/TargetMachine.h"

// #define CHADARCH_DUMP(Color)                                                   \
//   {                                                                            \
//     llvm::errs().changeColor(Color)                                            \
//         << __func__ << "\n\t\t" << __FILE__ << ":" << __LINE__ << "\n";        \
//     llvm::errs().changeColor(llvm::raw_ostream::WHITE);                        \
//   }
// // #define CHADARCH_DUMP(Color) {}

#define CHADARCH_DUMP(Color)                                                   \
  {                                                                            \
  }

#define CHADARCH_DUMP_RED CHADARCH_DUMP(llvm::raw_ostream::RED)
#define CHADARCH_DUMP_GREEN CHADARCH_DUMP(llvm::raw_ostream::GREEN)
#define CHADARCH_DUMP_YELLOW CHADARCH_DUMP(llvm::raw_ostream::YELLOW)
#define CHADARCH_DUMP_CYAN CHADARCH_DUMP(llvm::raw_ostream::CYAN)
#define CHADARCH_DUMP_MAGENTA CHADARCH_DUMP(llvm::raw_ostream::MAGENTA)
#define CHADARCH_DUMP_WHITE CHADARCH_DUMP(llvm::raw_ostream::WHITE)

namespace llvm {
class ChadArchTargetMachine;
class FunctionPass;
class ChadArchSubtarget;
class AsmPrinter;
class InstructionSelector;
class MCInst;
class MCOperand;
class MachineInstr;
class MachineOperand;
class PassRegistry;

bool lowerChadArchMachineInstrToMCInst(const MachineInstr *MI, MCInst &OutMI,
                                       AsmPrinter &AP);
bool LowerChadArchMachineOperandToMCOperand(const MachineOperand &MO,
                                            MCOperand &MCOp,
                                            const AsmPrinter &AP);

FunctionPass *createChadArchISelDag(ChadArchTargetMachine &TM,
                                    CodeGenOptLevel OptLevel);

} // namespace llvm

#endif // LLVM_LIB_TARGET_ChadArch_ChadArch_H