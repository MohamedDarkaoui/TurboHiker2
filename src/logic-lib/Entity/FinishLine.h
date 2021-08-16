#ifndef TURBOHIKER_FINISHLINE_H
#define TURBOHIKER_FINISHLINE_H

#include "Entity.h"

class FinishLine : public Entity{
private:

public:
    FinishLine(Position2D position, std::pair<double, double> &size);

    void update() override;
};


#endif //TURBOHIKER_FINISHLINE_H
