#ifndef MAPDESIGN_H
#define MAPDESIGN_H

#include <QString>

//#include "branch-container.h"
//#include "branchitem.h"
#include "container.h"
#include "frame-container.h"
#include "linkobj.h"

// Extended QList, which allows to access element at position n or, if n does not exist,
// the last existing element before n
template <typename T> class ConfigList {
  public:
    QList <T> qlist;
    ConfigList <T> & operator<<(const T &other);
    T & operator[](int i);
    T tryAt(int);
    int count();
    // FIXME-3 not used void setDefault(const T &);

  protected:
    T defaultValue;
};

/*! \brief A MapDesign defines the visual appearance of a map, e.g. how branches, frames,     links look. Settings depend on
      - depth
      - Mode: NewBranch, RelinkBranch
    Settings may be overriden locallay and locally also depend on other settings, 
    e.g. links may depend on frames
*/

class BranchContainer;
class BranchItem;

/////////////////////////////////////////////////////////////////////////////

class MapDesign {
  public:
    enum HeadingColorHint {
        SpecificColor,
        InheritedColor,
        UnchangedColor,
        UndefinedColor};

    enum UpdateMode {
        NewItem,
        RelinkedItem};

    MapDesign();
    void init();

    void setName(const QString &);
    QString getName();

    Container::Layout branchesContainerLayout(int depth);
    Container::Layout imagesContainerLayout(int depth);

    LinkObj::ColorHint linkColorHint();
    void setLinkColorHint(const LinkObj::ColorHint &lch);
    QColor defaultLinkColor();
    void setDefaultLinkColor(const QColor &col);

    LinkObj::Style linkStyle(int depth);
    bool setLinkStyle(const LinkObj::Style &style, int depth);

    void updateBranchHeadingColor(
            BranchItem *branchItem,
            int depth);

    FrameContainer::FrameType frameType(bool useInnerFrame, int depth);
    void updateFrames(
            BranchContainer *branchContainer,
            const UpdateMode &mode,
            int depth);

    QColor selectionColor();
    void setSelectionColor(const QColor &col);

  private:
    QString name;

    // Container layouts
    ConfigList <Container::Layout> branchContainerLayouts;
    ConfigList <Container::Layout> imageContainerLayouts;

    // Colors of headings
    ConfigList <MapDesign::HeadingColorHint> headingColorHints;
    ConfigList <QColor> headingColors;

    // Frames
    ConfigList <FrameContainer::FrameType> innerFrameTypes;
    ConfigList <QColor> innerFramePenColors;
    ConfigList <QColor> innerFrameBrushColors;
    ConfigList <int> innerFramePenWidths;

    ConfigList <FrameContainer::FrameType> outerFrameTypes;
    ConfigList <QColor> outerFramePenColors;
    ConfigList <QColor> outerFrameBrushColors;
    ConfigList <int> outerFramePenWidths;

    // Links
    LinkObj::ColorHint linkColorHintInt;
    QColor defaultLinkCol;
    ConfigList <LinkObj::Style> linkStyles;

    // Selection
    QColor selectionColorInt;
};

#endif
