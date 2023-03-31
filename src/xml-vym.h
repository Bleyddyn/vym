#ifndef XML_VYM_H
#define XML_VYM_H

#include "xml-base.h"

class SlideItem;
class Task;

/*! \brief Parsing VYM maps from XML documents */

class VymReader : public BaseReader {
  public:
  // FIXME-1 Below is mostly obsolete, also in legacy...
  enum Content {
      TreeContent = 0x0001,   // FIXME-2 unused
      SlideContent = 0x0002,
      XLinkContent = 0x0004   // FIXME-2 unused
  };

    VymReader (VymModel*);
    virtual bool read(QIODevice *device);

  private:
    void raiseUnknownElementError();
    void readVymMap();
    void readSelection();
    void readSetting();
    void readAttribute();
    void readBranchOrMapCenter(File::LoadMode loadModeBranch, int insertPosBranch);
    void readHeadingOrVymNote();
    void readFrame();
    void readStandardFlag();
    void readUserFlagDef();
    void readUserFlag();
    void readImage();
    void readXLink();
    void readSlide();

    void readVymMapAttr();
    void readBranchAttr();
    void readOrnamentsAttr();
    void readFrameAttr();
    void readTaskAttr();

    int branchesCounter;
    int branchesTotal;

    VymText vymtext;

    bool useProgress;
};

#endif
