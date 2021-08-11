#include "EntityFactory.h"

EntityFactory::EntityFactory(const std::string &path)  {

    // reusing code from the course computer graphics
    try{
        std::ifstream fin(path);
        fin >> configuration;
        fin.close();
    }
    catch(ini::ParseException& ex){
        std::cerr << "Error parsing file: " << path << ": " << ex.what() << std::endl;
    }
}

std::shared_ptr<Player> EntityFactory::createPlayer() {
    double speed = configuration["hiker"]["speed"].as_double_or_die();
    unsigned int lane = Random::getInstance().randomInt(0,4);
    return std::make_shared<Player>(Player(speed,lane));
}

std::set<std::shared_ptr<CompetingHiker>> EntityFactory::createCompetingHikers(unsigned int player_lane) {
    double speed = configuration["hiker"]["speed"].as_double_or_die();

    std::set<std::shared_ptr<CompetingHiker>> competingHikers;
    for (unsigned int i = 0; i < 4; i++){
        if (i != player_lane)
            competingHikers.insert(std::make_shared<CompetingHiker>(CompetingHiker(speed,i)));
    }
    assert(competingHikers.size() == 3 && "Wrong amount of competing hikers created");
    return competingHikers;
}

std::set<std::shared_ptr<Enemy>> EntityFactory::createStaticEnemies() {
    unsigned int amount = configuration["staticEnemy"]["amount"].as_int_or_die();
    double world_height = configuration["world"]["height"].as_double_or_die();
    double world_top = configuration["world"]["top"].as_double_or_die();
    double min = configuration["staticEnemy"]["minSpawnYposition"].as_double_or_die();
    double max = configuration["staticEnemy"]["maxSpawnYposition"].as_double_or_die();
    double world_bottom = world_top - world_height + min;

    std::set<std::shared_ptr<Enemy>> enemies;
    for (unsigned int i = 0; i < amount; i++){
        unsigned int lane = Random::getInstance().randomInt(0,4);
        auto enemy = std::make_shared<StaticEnemy>(StaticEnemy(lane));
        double random_y_pos = Random::getInstance().random(world_bottom, max);
        enemy->setYposition(random_y_pos);
        enemies.insert(enemy);
    }
    return enemies;
}


