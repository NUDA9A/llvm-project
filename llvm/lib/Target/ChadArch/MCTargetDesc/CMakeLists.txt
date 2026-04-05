add_llvm_component_library(LLVMChadArchDesc
  ChadArchMCTargetDesc.cpp
  ChadArchMCAsmInfo.cpp
  ChadArchInstPrinter.cpp
  ChadArchMCCodeEmitter.cpp

  LINK_COMPONENTS
  MC
  Support
  ChadArchInfo

  ADD_TO_COMPONENT
  ChadArch
 )