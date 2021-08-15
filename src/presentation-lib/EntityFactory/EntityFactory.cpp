#include "EntityFactory.h"


EntityFactory::EntityFactory(const std::string &path_to_config_file)  {

    // reusing code from the course computer graphics
    try{
        std::ifstream fin(path_to_config_file);
        fin >> configuration;
        fin.close();
    }
    catch(ini::ParseException& ex){
        std::cerr << "Error parsing file: " << path_to_config_file << ": " << ex.what() << std::endl;
    }
}

std::shared_ptr<SFMLPlayer> EntityFactory::createPlayer() {
    std::string sprite_path = "../../";
    sprite_path += configuration["player"]["sprite"].as_string_or_die();
    double speed = configuration["hiker"]["speed"].as_double_or_die();
    unsigned int lane = Random::getInstance().randomInt(0,4);
    std::pair<double,double> size;
    size.first = configuration["player"]["sizeX"].as_double_or_die();
    size.second = configuration["player"]["sizeY"].as_double_or_die();
    std::vector<double> lanePositions = configuration["world"]["laneXcoordinates"].as_double_tuple_or_die();
    double speedUpFactor = configuration["player"]["speedUpFactor"].as_double_or_die();
    double yellingRange = configuration["player"]["yellingRange"].as_double_or_die();

    return std::make_shared<SFMLPlayer>(SFMLPlayer(lane,size,lanePositions,speed,speedUpFactor,yellingRange, sprite_path));
}

std::set<std::shared_ptr<SFMLCompetingHiker>> EntityFactory::createCompetingHikers(unsigned int player_lane) {
    double speed = configuration["hiker"]["speed"].as_double_or_die();
    std::pair<double,double> size;
    size.first = configuration["CompetingHiker"]["sizeX"].as_double_or_die();
    size.second = configuration["CompetingHiker"]["sizeY"].as_double_or_die();
    std::vector<double> lanePositions = configuration["world"]["laneXcoordinates"].as_double_tuple_or_die();
    double speedUpFactor = configuration["CompetingHiker"]["speedUpFactor"].as_double_or_die();
    std::string sprite_path = "../../";
    sprite_path += configuration["CompetingHiker"]["sprite"].as_string_or_die();
    std::set<std::shared_ptr<SFMLCompetingHiker>> competingHikers;
    for (unsigned int i = 0; i < 4; i++){
        if (i != player_lane)
            competingHikers.insert(std::make_shared<SFMLCompetingHiker>(SFMLCompetingHiker(i,size,lanePositions,
                                                                                           speed,speedUpFactor,
                                                                                           sprite_path)));
    }
    assert(competingHikers.size() == 3 && "Wrong amount of competing hikers created");
    return competingHikers;
}

std::set<std::shared_ptr<SFMLStaticEnemy>> EntityFactory::createStaticEnemies() {
    unsigned int amount = configuration["staticEnemy"]["amount"].as_int_or_die();
    double world_height = configuration["world"]["height"].as_double_or_die();
    double world_top = configuration["world"]["top"].as_double_or_die();
    double min = configuration["staticEnemy"]["minSpawnYposition"].as_double_or_die();
    double max = configuration["staticEnemy"]["maxSpawnYposition"].as_double_or_die();
    double world_bottom = world_top - world_height + min;
    std::pair<double,double> size;
    size.first = configuration["staticEnemy"]["sizeX"].as_double_or_die();
    size.second = configuration["staticEnemy"]["sizeY"].as_double_or_die();
    std::vector<double> lanePositions = configuration["world"]["laneXcoordinates"].as_double_tuple_or_die();
    double speed = configuration["staticEnemy"]["speed"].as_double_or_die();
    std::string sprite_path = "../../";
    sprite_path += configuration["staticEnemy"]["sprite"].as_string_or_die();

    std::set<std::shared_ptr<SFMLStaticEnemy>> enemies;
    for (unsigned int i = 0; i < amount; i++){
        unsigned int lane = Random::getInstance().randomInt(0,4);
        auto enemy = std::make_shared<SFMLStaticEnemy>(SFMLStaticEnemy(lane,size,lanePositions,speed,sprite_path));
        double random_y_pos = Random::getInstance().random(world_bottom,max);
        enemy->setYposition(random_y_pos);
        enemies.insert(enemy);
    }
    return enemies;
}

std::set<std::shared_ptr<SFMLMovingEnemy>> EntityFactory::createMovingEnemies() {
    unsigned int amount = configuration["movingEnemy"]["amount"].as_int_or_die();
    double world_height = configuration["world"]["height"].as_double_or_die();
    double world_top = configuration["world"]["top"].as_double_or_die();
    double min = configuration["movingEnemy"]["minSpawnYposition"].as_double_or_die();
    double max = configuration["movingEnemy"]["maxSpawnYposition"].as_double_or_die();
    double world_bottom = world_top - world_height + min;
    std::pair<double,double> size;
    size.first = configuration["movingEnemy"]["sizeX"].as_double_or_die();
    size.second = configuration["movingEnemy"]["sizeY"].as_double_or_die();
    std::vector<double> lanePositions = configuration["world"]["laneXcoordinates"].as_double_tuple_or_die();
    double speed = configuration["movingEnemy"]["speed"].as_double_or_die();
    std::string sprite_path = "../../";
    sprite_path += configuration["movingEnemy"]["sprite"].as_string_or_die();
    double speedUpFactor = configuration["movingEnemy"]["speedUpFactor"].as_double_or_die();

    std::set<std::shared_ptr<SFMLMovingEnemy>> enemies;
    for (unsigned int i = 0; i < amount; i++){
        unsigned int lane = Random::getInstance().randomInt(0,4);
        auto enemy = std::make_shared<SFMLMovingEnemy>(SFMLMovingEnemy(lane,size,lanePositions,speed,speedUpFactor,sprite_path));
        double random_y_pos = Random::getInstance().random(world_bottom,max);
        enemy->setYposition(random_y_pos);
        enemies.insert(enemy);
    }
    return enemies;
}


std::shared_ptr<SFMLWorld> EntityFactory::createWorld() {
    double top = configuration["world"]["top"].as_double_or_die();
    double height = configuration["world"]["height"].as_double_or_die();
    double left = configuration["world"]["left"].as_double_or_die();
    double width = configuration["world"]["width"].as_double_or_die();
    std::pair<double,double> size = std::make_pair(width,height);

    return std::make_shared<SFMLWorld>(Position2D{0,0},size);
}

std::set<std::shared_ptr<SFMLGroundPlot>> EntityFactory::createGroundPlots() {
    double top = configuration["world"]["top"].as_double_or_die();
    double height = configuration["world"]["height"].as_double_or_die();

    double origin = top - height - 3;
    std::pair<int,int> dimensions;
    std::pair<double,double> size;

    dimensions.first = configuration["groundPlot"]["columns"].as_int_or_die();
    dimensions.second = configuration["groundPlot"]["rows"].as_int_or_die();

    size.first = configuration["groundPlot"]["sizeX"].as_int_or_die();
    size.second = configuration["groundPlot"]["sizeY"].as_int_or_die();

    std::string sprite_path = "../../";
    sprite_path += configuration["groundPlot"]["sprite"].as_string_or_die();

    std::pair<int,int> imageCoordinate;
    imageCoordinate.first = configuration["groundPlot"]["imageCoordinateX"].as_int_or_die();
    imageCoordinate.second = configuration["groundPlot"]["imageCoordinateY"].as_int_or_die();

    std::set<std::shared_ptr<SFMLGroundPlot>> plots;
    double current_top = origin;

    while(current_top <= top){
        std::shared_ptr<SFMLGroundPlot> gp = std::make_shared<SFMLGroundPlot>
                (SFMLGroundPlot({0,current_top},size,sprite_path,dimensions,imageCoordinate));
        plots.insert(gp);

        current_top += size.second;
    }
    return plots;
}


