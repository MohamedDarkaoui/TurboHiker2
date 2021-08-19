#include "EntityFactory.h"

SFML::EntityFactory::EntityFactory(const std::string &path_to_config_file)  {

    // reusing code from the course computer graphics
    path = path_to_config_file;
    try{
        std::ifstream fin(path_to_config_file);
        fin >> configuration;
        fin.close();
    }
    catch(ini::ParseException& ex){
        std::cerr << "Error parsing file: " << path_to_config_file << ": " << ex.what() << std::endl;
    }
}

std::shared_ptr<SFML::SFMLPlayer> SFML::EntityFactory::createPlayer() {
    std::string sprite_path = configuration["player"]["sprite"].as_string_or_die();
    double speed = configuration["hiker"]["speed"].as_double_or_die();
    unsigned int lane = TurboHiker::Random::getInstance().randomInt(0,4);
    std::pair<double,double> size;
    size.first = configuration["player"]["sizeX"].as_double_or_die();
    size.second = configuration["player"]["sizeY"].as_double_or_die();
    std::vector<double> lanePositions = configuration["world"]["laneXcoordinates"].as_double_tuple_or_die();
    double speedUpFactor = configuration["player"]["speedUpFactor"].as_double_or_die();
    double yellingRange = configuration["player"]["yellingRange"].as_double_or_die();

    return std::make_shared<SFML::SFMLPlayer>(lane,size,lanePositions,speed,speedUpFactor,yellingRange, sprite_path);
}

std::set<std::shared_ptr<SFML::SFMLCompetingHiker>> SFML::EntityFactory::createCompetingHikers(unsigned int player_lane) {
    double speed = configuration["hiker"]["speed"].as_double_or_die();
    std::pair<double,double> size;
    size.first = configuration["CompetingHiker"]["sizeX"].as_double_or_die();
    size.second = configuration["CompetingHiker"]["sizeY"].as_double_or_die();
    std::vector<double> lanePositions = configuration["world"]["laneXcoordinates"].as_double_tuple_or_die();
    double speedUpFactor = configuration["CompetingHiker"]["speedUpFactor"].as_double_or_die();
    std::string sprite_path = configuration["CompetingHiker"]["sprite"].as_string_or_die();
    std::set<std::shared_ptr<SFML::SFMLCompetingHiker>> competingHikers;
    for (unsigned int i = 0; i < 4; i++){
        if (i != player_lane)
            competingHikers.insert(std::make_shared<SFML::SFMLCompetingHiker>(i,size,lanePositions,
                                                                                           speed,speedUpFactor,
                                                                                           sprite_path));
    }
    assert(competingHikers.size() == 3 && "Wrong amount of competing hikers created");
    return competingHikers;
}

std::shared_ptr<SFML::SFMLStaticEnemy> SFML::EntityFactory::createStaticEnemy(unsigned int lane, double y_pos) {
    double speed = configuration["staticEnemy"]["speed"].as_double_or_die();
    std::pair<double,double> size;
    size.first = configuration["staticEnemy"]["sizeX"].as_double_or_die();
    size.second = configuration["staticEnemy"]["sizeY"].as_double_or_die();
    std::vector<double> lanePositions = configuration["world"]["laneXcoordinates"].as_double_tuple_or_die();
    std::string sprite_path = configuration["staticEnemy"]["sprite"].as_string_or_die();
    auto enemy = std::make_shared<SFML::SFMLStaticEnemy>(lane,size,lanePositions,speed,sprite_path);
    enemy->setYposition(y_pos);
    return enemy;

}

std::set<std::shared_ptr<SFML::SFMLStaticEnemy>> SFML::EntityFactory::createStaticEnemies() {
    unsigned int amount = configuration["staticEnemy"]["amount"].as_int_or_die();
    double max = configuration["world"]["height"].as_double_or_die() -1;

    std::set<std::shared_ptr<SFML::SFMLStaticEnemy>> enemies;
    for (unsigned int i = 0; i < amount; i++){
        unsigned int lane = TurboHiker::Random::getInstance().randomInt(0,4);
        double random_y_pos = TurboHiker::Random::getInstance().random(2,max);
        auto enemy = createStaticEnemy(lane,random_y_pos);
        enemies.insert(enemy);
    }
    return enemies;
}
std::shared_ptr<SFML::SFMLMovingEnemy> SFML::EntityFactory::createMovingEnemy(unsigned int lane, double y_pos, double speed) {
    std::pair<double,double> size;
    size.first = configuration["movingEnemy"]["sizeX"].as_double_or_die();
    size.second = configuration["movingEnemy"]["sizeY"].as_double_or_die();
    std::vector<double> lanePositions = configuration["world"]["laneXcoordinates"].as_double_tuple_or_die();
    std::string sprite_path = configuration["movingEnemy"]["sprite"].as_string_or_die();
    double speedUpFactor = configuration["movingEnemy"]["speedUpFactor"].as_double_or_die();
    auto enemy = std::make_shared<SFML::SFMLMovingEnemy>(lane,size,lanePositions,speed,speedUpFactor,sprite_path);
    enemy->setYposition(y_pos);
    return enemy;
}

std::set<std::shared_ptr<SFML::SFMLMovingEnemy>> SFML::EntityFactory::createMovingEnemies() {

    unsigned int amount = configuration["movingEnemy"]["amount"].as_int_or_die();
    double max = configuration["world"]["height"].as_double_or_die() * 1.5;
    double speed = configuration["movingEnemy"]["speed"].as_double_or_die();
    double world_bottom = 0;

    std::set<std::shared_ptr<SFML::SFMLMovingEnemy>> enemies;
    for (unsigned int i = 0; i < amount; i++){
        unsigned int lane = TurboHiker::Random::getInstance().randomInt(0,4);
        double random_y_pos = TurboHiker::Random::getInstance().random(world_bottom,max);
        auto enemy = createMovingEnemy(lane,random_y_pos,speed);
        enemies.insert(enemy);
    }
    return enemies;
}


std::shared_ptr<SFML::SFMLWorld> SFML::EntityFactory::createWorld() {
    double height = configuration["world"]["height"].as_double_or_die();
    double width = configuration["world"]["width"].as_double_or_die();
    std::pair<double,double> size = std::make_pair(width,height);
    std::shared_ptr<AbstractFactory> newFactory = std::make_shared<EntityFactory>(path);
    return std::make_shared<SFML::SFMLWorld>(TurboHiker::Position2D{0,0}, size, newFactory);
}

std::set<std::shared_ptr<SFML::SFMLGroundPlot>> SFML::EntityFactory::createGroundPlots() {
    double height = configuration["world"]["height"].as_double_or_die();

    double origin = 0;
    std::pair<int,int> dimensions;
    std::pair<double,double> size;

    dimensions.first = configuration["groundPlot"]["columns"].as_int_or_die();
    dimensions.second = configuration["groundPlot"]["rows"].as_int_or_die();

    size.first = configuration["groundPlot"]["sizeX"].as_int_or_die();
    size.second = configuration["groundPlot"]["sizeY"].as_int_or_die();

    std::string sprite_path = configuration["groundPlot"]["sprite"].as_string_or_die();

    std::pair<int,int> imageCoordinate;
    imageCoordinate.first = configuration["groundPlot"]["imageCoordinateX"].as_int_or_die();
    imageCoordinate.second = configuration["groundPlot"]["imageCoordinateY"].as_int_or_die();

    std::set<std::shared_ptr<SFML::SFMLGroundPlot>> plots;
    double current_top = origin;

    while(current_top <= height*1.5){
        std::shared_ptr<SFML::SFMLGroundPlot> gp = std::make_shared<SFML::SFMLGroundPlot>
                (TurboHiker::Position2D{0,current_top},size,sprite_path,dimensions,imageCoordinate);
        plots.insert(gp);

        current_top += size.second;
    }
    return plots;
}

std::shared_ptr<SFML::SFMLFinishLine> SFML::EntityFactory::createFinishLine() {
    std::string sprite_path = configuration["finishLine"]["sprite"].as_string_or_die();
    TurboHiker::Position2D position(0,0);
    position.setX(0);
    position.setY(configuration["world"]["height"].as_double_or_die()+0.8);
    std::pair<double,double> size = std::make_pair(6,2);
    std::pair<int,int> imageCoordinate;
    imageCoordinate.first = configuration["finishLine"]["imageCoordinateX"].as_int_or_die();
    imageCoordinate.second = configuration["finishLine"]["imageCoordinateY"].as_int_or_die();
    std::shared_ptr<SFML::SFMLFinishLine> finishLine = std::make_shared<SFML::SFMLFinishLine>(sprite_path,position,
                                                                                                 size,imageCoordinate);

    return finishLine;
}

std::set<std::shared_ptr<SFML::SFMLPassiveItem>> SFML::EntityFactory::createPassiveItem() {
    std::string sprite_path = configuration["passiveItem"]["sprite"].as_string_or_die();
    unsigned int amount = configuration["passiveItem"]["amount"].as_int_or_die();
    std::pair<double,double> size;
    size.first = configuration["passiveItem"]["sizeX"].as_double_or_die();
    size.second = configuration["passiveItem"]["sizeY"].as_double_or_die();
    std::vector<double> lanePositions = configuration["world"]["laneXcoordinates"].as_double_tuple_or_die();
    double max = configuration["world"]["height"].as_double_or_die() -4;
    std::set<std::shared_ptr<SFML::SFMLPassiveItem>> items;

    std::vector<int> first_place_rewards = configuration["passiveItem"]["firstBonuses"].as_int_tuple_or_die();
    std::vector<int> second_place_rewards = configuration["passiveItem"]["secondBonuses"].as_int_tuple_or_die();
    std::vector<int> third_place_rewards = configuration["passiveItem"]["thirdBonuses"].as_int_tuple_or_die();
    std::vector<int> fourth_place_rewards = configuration["passiveItem"]["fourthBonuses"].as_int_tuple_or_die();

    std::vector<std::vector<int>> v = {first_place_rewards,second_place_rewards,third_place_rewards,fourth_place_rewards};

    for(unsigned int i = 0; i < amount; i++){
        unsigned int lane = TurboHiker::Random::getInstance().randomInt(0,4);
        auto item = std::make_shared<SFML::SFMLPassiveItem>(sprite_path,lane,size,lanePositions, v);
        item->setPosition({item->getPosition().getX(),TurboHiker::Random::getInstance().random(2,max)});
        items.insert(item);
    }
    return items;
}

std::set<std::shared_ptr<SFML::SFMLActiveItem>> SFML::EntityFactory::createActiveItems() {
    std::string sprite_path = configuration["activeItem"]["sprite"].as_string_or_die();
    unsigned int amount = configuration["activeItem"]["amount"].as_int_or_die();
    std::pair<double,double> size;
    size.first = configuration["activeItem"]["sizeX"].as_double_or_die();
    size.second = configuration["activeItem"]["sizeY"].as_double_or_die();
    std::vector<double> lanePositions = configuration["world"]["laneXcoordinates"].as_double_tuple_or_die();
    double max = configuration["world"]["height"].as_double_or_die() -4;
    std::set<std::shared_ptr<SFML::SFMLActiveItem>> items;

    for(unsigned int i = 0; i < amount; i++){
        unsigned int lane = TurboHiker::Random::getInstance().randomInt(0,4);
        auto item = std::make_shared<SFML::SFMLActiveItem>(sprite_path,lane,size,lanePositions);
        item->setPosition({item->getPosition().getX(),TurboHiker::Random::getInstance().random(2,max)});
        items.insert(item);
    }
    return items;
}





