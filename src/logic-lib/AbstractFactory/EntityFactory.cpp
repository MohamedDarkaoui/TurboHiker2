#include "EntityFactory.h"

EntityFactory::EntityFactory(const std::string& path) {

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

std::vector<std::shared_ptr<CompetingHiker>> EntityFactory::createCompetingHikers(unsigned int player_lane) {
    double speed = configuration["hiker"]["speed"].as_double_or_die();

    std::vector<std::shared_ptr<CompetingHiker>> competingHikers;
    for (unsigned int i = 0; i < 4; i++){
        if (i != player_lane)
            competingHikers.push_back(std::make_shared<CompetingHiker>(CompetingHiker(speed,i)));
    }
    assert(competingHikers.size() == 3 && "Wrong amount of competing hikers created");
    return competingHikers;
}








