#include "ChadArch.h"
#include "MCTargetDesc/ChadArchMCTargetDesc.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/MC/MCELFObjectWriter.h"
#include "llvm/MC/MCExpr.h"
#include "llvm/MC/MCObjectWriter.h"
#include "llvm/MC/MCValue.h"
#include "llvm/Support/ErrorHandling.h"

using namespace llvm;

namespace {
class ChadArchELFObjectWriter : public MCELFObjectTargetWriter {
public:
  ChadArchELFObjectWriter(bool Is64Bit, uint8_t OSABI)
      : MCELFObjectTargetWriter(Is64Bit, OSABI, ELF::EM_CHADARCH,
                                /*HasRelocationAddend*/ true) {}

  ~ChadArchELFObjectWriter() override = default;

protected:
  unsigned getRelocType(MCContext &Ctx, const MCValue &Target,
                        const MCFixup &Fixup, bool IsPCRel) const override;

  bool needsRelocateWithSymbol(const MCValue &Val, const MCSymbol &Sym,
                               unsigned Type) const override;
};
} // namespace

unsigned ChadArchELFObjectWriter::getRelocType(MCContext &Ctx,
                                               const MCValue &Target,
                                               const MCFixup &Fixup,
                                               bool IsPCRel) const {
  MCFixupKind Kind = Fixup.getKind();
  if (Kind >= FirstLiteralRelocationKind)
    return Kind - FirstLiteralRelocationKind;

  llvm_unreachable("Unimplemented fixup -> relocation");
}

bool ChadArchELFObjectWriter::needsRelocateWithSymbol(const MCValue &,
                                                      const MCSymbol &,
                                                      unsigned Type) const {
  return false;
}

std::unique_ptr<MCObjectTargetWriter>
llvm::createChadArchELFObjectWriter(bool Is64Bit, uint8_t OSABI) {
  return std::make_unique<ChadArchELFObjectWriter>(Is64Bit, OSABI);
}