add_llvm_component_group(ChadArch)

set(LLVM_TARGET_DEFINITIONS ChadArch.td)

tablegen(LLVM ChadArchGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM ChadArchGenInstrInfo.inc -gen-instr-info)

add_public_tablegen_target(ChadArchCommonTableGen)

add_llvm_target(ChadArchCodeGen
  ChadArchTargetMachine.cpp
  ChadArchRegisterInfo.cpp
  ChadArchInstrInfo.cpp

  LINK_COMPONENTS
  CodeGen
  Core
  Support
  Target
  ChadArchInfo

  ADD_TO_COMPONENT
  ChadArch
  )

add_subdirectory(MCTargetDesc)
add_subdirectory(TargetInfo)