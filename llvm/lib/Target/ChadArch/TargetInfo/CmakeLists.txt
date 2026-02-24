add_llvm_component_library(LLVMChadArchInfo
  ChadArchTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  ChadArch
  )