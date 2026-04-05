add_llvm_component_group(ChadArch)

set(LLVM_TARGET_DEFINITIONS ChadArch.td)

tablegen(LLVM ChadArchGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM ChadArchGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM ChadArchGenSubtargetInfo.inc -gen-subtarget)
tablegen(LLVM ChadArchGenMCPseudoLowering.inc -gen-pseudo-lowering)
tablegen(LLVM ChadArchGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM ChadArchGenCallingConv.inc -gen-callingconv)
tablegen(LLVM ChadArchGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM ChadArchGenMCCodeEmitter.inc -gen-emitter)

add_public_tablegen_target(ChadArchCommonTableGen)

add_llvm_target(ChadArchCodeGen
  ChadArchTargetMachine.cpp
  ChadArchRegisterInfo.cpp
  ChadArchInstrInfo.cpp
  ChadArchSubtarget.cpp
  ChadArchAsmPrinter.cpp
  ChadArchISelDagToDag.cpp
  ChadArchISelLowering.cpp
  ChadArchMCInstLower.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  ChadArchInfo
  AsmPrinter
  SelectionDAG

  ADD_TO_COMPONENT
  ChadArch
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)