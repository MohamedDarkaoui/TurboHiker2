#ifndef TURBOHIKER_SFMLFINISHLINE_H
#define TURBOHIKER_SFMLFINISHLINE_H

#include "../../logic-lib/Entity/FinishLine.h"
#include "SFMLEntity.h"

class SFMLFinishLine : public FinishLine, public SFMLEntity {
public:
    SFMLFinishLine(const std::string &pathToImage, Position2D position,
                   std::pair<double, double> &size, std::pair<int,int> imageCoordinates);

    void updateVisuals(const Position2D& reference) override;
};


#endif //TURBOHIKER_SFMLFINISHLINE_H
