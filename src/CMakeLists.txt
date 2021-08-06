SET(CMAKE_CXX_STANDARD 14)
ADD_EXECUTABLE(
        TurboHiker
        main.cpp
        presentation-lib/Game/Game.cpp
        presentation-lib/EventHandler/EventHandler.cpp
        presentation-lib/Game/Game.cpp
        logic-lib/Position/Position2D.cpp
        logic-lib/Entity/Entity.cpp
        logic-lib/Entity/World.cpp
        logic-lib/Entity/StaticEnemy.cpp
        logic-lib/Entity/StaticEnemy.h
        presentation-lib/Transformation/Transformation.cpp
        presentation-lib/Transformation/Transformation.h logic-lib/Entity/Hiker.cpp logic-lib/Entity/player.cpp logic-lib/Entity/player.h)


TARGET_LINK_LIBRARIES (TurboHiker sfml-graphics sfml-window sfml-system sfml-audio)
INSTALL(TARGETS TurboHiker DESTINATION ${PROJECT_SOURCE_DIR}/bin)