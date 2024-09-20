#ifndef XML_OWL_H
#define XML_OWL_H

#include <map>

#include "xml-base.h"

/*! \brief Parsing OWL (RDF) files from XML documents */

class OwlReader : public BaseReader {
  public:
    OwlReader (VymModel*);
    virtual bool read(QIODevice *device);

  private:
    void readOwlMap();
    void readOwlOntology();
    void readClass(File::LoadMode loadModeBranch, int insertPosBranch);

    void readMapDesign();
    void readMapDesignElement();
    void readMapDesignCompatibleAttributes();
    void readSelection();
    void readSetting();
    void readAttribute();
    void readHeadingOrVymNote();
    void readFrame();
    void readLegacyXLink();
    void readStandardFlag();
    void readUserFlagDef();
    void readUserFlag();
    void readImage();
    void readXLink();
    void readSlide();
    void readTask();

    void readVymMapAttr();
    void readBranchAttr();
    void readOrnamentsAttr();
    void readFrameAttr();

    int branchesCounter;
    int branchesTotal;

    VymText vymtext;

    bool useProgress;

    std::map<QString, BranchItem *> branchesByResource;
};

#endif
