SET(CMAKE_CXX_STANDARD 14)
ADD_EXECUTABLE(
        TurboHiker
        main.cpp
        presentation-lib/Game/Game.cpp
        presentation-lib/Game/Game.cpp
        logic-lib/Position/Position2D.cpp
        logic-lib/Entity/Entity.cpp
        logic-lib/Entity/World.cpp
        logic-lib/Entity/StaticEnemy.cpp
        logic-lib/Entity/StaticEnemy.h
        presentation-lib/Transformation/Transformation.cpp
        presentation-lib/Transformation/Transformation.h
        logic-lib/Entity/Hiker.cpp
        logic-lib/Entity/Player.cpp
        logic-lib/Entity/Player.h
        logic-lib/Random/Random.cpp
        logic-lib/Random/Random.h
        logic-lib/Entity/Enemy.h
        logic-lib/Entity/MovingEnemy.cpp
        logic-lib/Entity/MovingEnemy.h
        logic-lib/Entity/CompetingHiker.cpp
        logic-lib/Entity/CompetingHiker.h
        logic-lib/Clock/Clock.cpp logic-lib/Clock/Clock.h
        logic-lib/Entity/Enemy.cpp
        logic-lib/AbstractFactory/AbstractFactory.h
        ../ini_config/ini_configuration.cc
        presentation-lib/SFMLEntities/SFMLPlayer.cpp
        presentation-lib/SFMLEntities/SFMLPlayer.h
        presentation-lib/EntityFactory/EntityFactory.cpp
        presentation-lib/EntityFactory/EntityFactory.h
        presentation-lib/SFMLEntities/SFMLWorld.cpp
        presentation-lib/SFMLEntities/SFMLWorld.h
        presentation-lib/SFMLEntities/SFMLEntity.cpp
        presentation-lib/SFMLEntities/SFMLEntity.h presentation-lib/SFMLEntities/SFMLCompetingHiker.cpp presentation-lib/SFMLEntities/SFMLCompetingHiker.h presentation-lib/SFMLEntities/SFMLStaticEnemy.cpp presentation-lib/SFMLEntities/SFMLStaticEnemy.h)


TARGET_LINK_LIBRARIES (TurboHiker sfml-graphics sfml-window sfml-system sfml-audio)
INSTALL(TARGETS TurboHiker DESTINATION ${PROJECT_SOURCE_DIR}/bin)