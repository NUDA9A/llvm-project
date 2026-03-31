include "llvm/Target/Target.td"
include "ChadArchRegisterInfo.td"
include "ChadArchInstrInfo.td"
include "ChadArchCallingConv.td"

class Proc<string Name, list<SubtargetFeature> Features> : Processor<Name, NoItineraries, Features>;

def : Proc<"generic", []>;

def ChadArchInstrInfo : InstrInfo;
def ChadArch : Target {
    let InstructionSet = ChadArchInstrInfo;
}