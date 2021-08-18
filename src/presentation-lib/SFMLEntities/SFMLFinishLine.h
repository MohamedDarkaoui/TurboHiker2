#ifndef TURBOHIKER_SFMLFINISHLINE_H
#define TURBOHIKER_SFMLFINISHLINE_H

#include "../../logic-lib/Entity/FinishLine.h"
#include "SFMLEntity.h"

namespace SFML {

class SFMLFinishLine : public TurboHiker::FinishLine, public SFMLEntity {
public:
    SFMLFinishLine(const std::string &pathToImage, TurboHiker::Position2D position,
                   std::pair<double, double> &size, std::pair<int,int> imageCoordinates);

    void updateVisuals(const TurboHiker::Position2D& relativePos, std::pair<double,double> size) override;
};
}

#endif //TURBOHIKER_SFMLFINISHLINE_H
