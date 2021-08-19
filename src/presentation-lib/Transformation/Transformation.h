#ifndef TURBOHIKER_TRANSFORMATION_H
#define TURBOHIKER_TRANSFORMATION_H

#include <utility>
#include "../../logic-lib/Position/Position2D.h"

namespace SFML {

class Transformation {
private:
    double win_x = 1040;
    double win_y = 780;

    /**
     * default constructor
     */
    Transformation() = default;

public:
    /////// delete ////////
    Transformation(Transformation const&) =  delete;

    void operator=(Transformation const&) = delete;
    //////////////////////

    /**
     * transforms logical coordinates into pixel values
     * @return the transformed pixel values
     */
    TurboHiker::Position2D transform(TurboHiker::Position2D) const;

    /**
     * transforms the size from logical size to window size
     * @param width: logical width
     * @param height: logical height
     * @return window size
     */
    std::pair<float,float> transformSize(const double &width, const double& height) const;

    /**
     * typical singleton getInstance function
     * @return an instance of the singleton
     */
    static Transformation& getInstance();
};
}

#endif //TURBOHIKER_TRANSFORMATION_H
