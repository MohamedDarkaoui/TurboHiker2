#ifndef TURBOHIKER_TRANSFORMATION_H
#define TURBOHIKER_TRANSFORMATION_H

#include <utility>
#include "../../logic-lib/Position/Position2D.h"

namespace SFML {

    class Transformation {
    private:
        double win_x = 1040;
        double win_y = 780;

        Transformation() = default;

    public:
        Transformation(Transformation const&) =  delete;

        void operator=(Transformation const&) = delete;

        TurboHiker::Position2D transform(TurboHiker::Position2D) const;

        std::pair<float,float> transformSize(const double &width, const double& height) const;

        static Transformation& getInstance();
    };
}

#endif //TURBOHIKER_TRANSFORMATION_H
