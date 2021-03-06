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
        presentation-lib/SFMLEntities/SFMLEntity.h
        presentation-lib/SFMLEntities/SFMLCompetingHiker.cpp
        presentation-lib/SFMLEntities/SFMLCompetingHiker.h
        presentation-lib/SFMLEntities/SFMLStaticEnemy.cpp
        presentation-lib/SFMLEntities/SFMLStaticEnemy.h
        presentation-lib/SFMLEntities/SFMLMovingEnemy.cpp
        presentation-lib/SFMLEntities/SFMLMovingEnemy.h
        presentation-lib/Animation/Animation.cpp
        presentation-lib/Animation/Animation.h
        presentation-lib/SFMLEntities/SFMLGroundPlot.cpp
        presentation-lib/SFMLEntities/SFMLGroundPlot.h
        logic-lib/Entity/GroundPlot.cpp
        logic-lib/Entity/GroundPlot.h
        logic-lib/Observer/Observer.h
        logic-lib/Observer/Observable.cpp
        logic-lib/Observer/Observable.h
        logic-lib/Score/Score.cpp
        logic-lib/Score/Score.h
        logic-lib/Entity/FinishLine.cpp
        logic-lib/Entity/FinishLine.h
        presentation-lib/SFMLEntities/SFMLFinishLine.cpp
        presentation-lib/SFMLEntities/SFMLFinishLine.h
        logic-lib/Entity/CollectableItem.cpp
        logic-lib/Entity/CollectableItem.h
        logic-lib/Entity/PassiveItem.cpp
        logic-lib/Entity/PassiveItem.h
        presentation-lib/SFMLEntities/SFMLPassiveItem.cpp
        presentation-lib/SFMLEntities/SFMLPassiveItem.h
        logic-lib/Entity/ActiveItem.cpp
        logic-lib/Entity/ActiveItem.h
        presentation-lib/SFMLEntities/SFMLActiveItem.cpp
        presentation-lib/SFMLEntities/SFMLActiveItem.h
        logic-lib/Entity/Bomb.cpp logic-lib/Entity/Bomb.h presentation-lib/SFMLEntities/SFMLBomb.cpp presentation-lib/SFMLEntities/SFMLBomb.h)


TARGET_LINK_LIBRARIES (TurboHiker sfml-graphics sfml-window sfml-system sfml-audio)
INSTALL(TARGETS TurboHiker DESTINATION ${PROJECT_SOURCE_DIR}/bin)