add_llvm_component_group(ChadArch)

add_llvm_target(ChadArchCodeGen
  ChadArchTargetMachine.cpp

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