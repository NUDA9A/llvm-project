include "llvm/Target/Target.td"
include "ChadArchRegisterInfo.td"
include "ChadArchInstrInfo.td"

def ChadArchInstrInfo : InstrInfo;
def ChadArch : Target {
    let InstructionSet = ChadArchInstrInfo;
}