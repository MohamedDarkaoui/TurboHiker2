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
    std::cout<<sprite_path;
    double speed = configuration["hiker"]["speed"].as_double_or_die();
    unsigned int lane = Random::getInstance().randomInt(0,4);
    return std::make_shared<SFMLPlayer>(SFMLPlayer(speed,lane,sprite_path));
}

std::set<std::shared_ptr<SFMLCompetingHiker>> EntityFactory::createCompetingHikers(unsigned int player_lane) {
    double speed = configuration["hiker"]["speed"].as_double_or_die();

    std::set<std::shared_ptr<SFMLCompetingHiker>> competingHikers;
    for (unsigned int i = 0; i < 4; i++){
        if (i != player_lane)
            competingHikers.insert(std::make_shared<SFMLCompetingHiker>(SFMLCompetingHiker(speed, i)));
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

    std::set<std::shared_ptr<SFMLStaticEnemy>> enemies;
    for (unsigned int i = 0; i < amount; i++){
        unsigned int lane = Random::getInstance().randomInt(0,4);
        auto enemy = std::make_shared<SFMLStaticEnemy>(SFMLStaticEnemy(lane));
        double random_y_pos = Random::getInstance().random(world_bottom, max);
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

    return std::make_shared<SFMLWorld>(SFMLWorld(top,height,left,width));
}


