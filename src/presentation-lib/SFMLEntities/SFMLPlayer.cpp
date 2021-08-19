#include <iostream>
#include "SFMLPlayer.h"

SFML::SFMLPlayer::SFMLPlayer(unsigned int lane, std::pair<double, double> &size, std::vector<double>& lanePositionsX, double
speed,double speedUpFactor, double yellingRange, const std::string& path_to_image) :
Player(lane,size,lanePositionsX,speed,speedUpFactor,yellingRange), SFMLEntity(path_to_image){
    auto relative_position = getRelativePosition(getPosition());
    initialize(size,relative_position);
    animation->update(3);
    shape.setTextureRect(animation->getCurrentFrame());


    assert(yelling_sound_buffer.loadFromFile("sounds/yell.wav") && "Error loading yelling sound");
    assert(dashing_sound_buffer.loadFromFile("sounds/dash.wav") && "Error loading dashing sound");
    assert(colliding_sound_buffer.loadFromFile("sounds/collision.wav") && "Error loading collision sound");

    yelling_sound.setBuffer(yelling_sound_buffer);
    dashing_sound.setBuffer(dashing_sound_buffer);
    colliding_sound.setBuffer(colliding_sound_buffer);
}

void SFML::SFMLPlayer::handleEvents(sf::Event &event, sf::RenderWindow& window, double world_height) {
    if (getPosition().getY() >= world_height){
        finished = true;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
    }
    else {
        while (window.pollEvent(event)){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                speedUp();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                slowDown();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                runAtTurboSpeed();
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Left)
                    moveLeft();
                else if (event.key.code == sf::Keyboard::Right)
                    moveRight();
                else if (event.key.code == sf::Keyboard::W)
                    useActiveReward();
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                    yell();
            }
            if (event.type == sf::Event::KeyReleased){
                if (event.key.code == sf::Keyboard::Up){
                    if (getAcceleration() == Hiker::SPEED_UP)
                        slowDown();
                }
                if (event.key.code == sf::Keyboard::Down){
                    if (getAcceleration() == Hiker::SLOW_DOWN)
                        speedUp();
                }
                if (event.key.code == sf::Keyboard::Q)
                    stopRunningAtTurboSpeed();
            }
            // "close requested" event: we close the window
            else if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}



void SFML::SFMLPlayer::updateAnimation() {
    if (getSpeed() == 0)
        return;
    setClockTickTime(floor(200/(100*getSpeed())));
    if (clock->clockTicked()){
        animation->update(3);
        shape.setTextureRect(animation->getCurrentFrame());
    }
}

void SFML::SFMLPlayer::updateVisuals(const TurboHiker::Position2D &relativePos, std::pair<double, double> size) {
    SFMLEntity::updateVisuals(relativePos, size);
}

sf::Text SFML::SFMLPlayer::visualizeScore(sf::Font &font) {
    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color(139,0,0));
    int score = getScore()->getPoints(getPosition().getY());
    std::string score_string = std::to_string(score);
    text.setString(score_string);

    return text;
}

sf::Text SFML::SFMLPlayer::visualizeActiveRewards(sf::Font &font) {
    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color(139,0,0));
    std::string s = " ";
    if (!rewardsEmpty()){
        s+="[";
        for (auto reward : getRewards()){
            if (reward.first){
                if (reward.second > 0)
                    s+="+";
                else if (reward.second < 0)
                    s+="-";
            }
            else
                s+="o";
        }
        s+="]";
    }
    text.setString(s);
    TurboHiker::Position2D pos = Transformation::getInstance().transform(TurboHiker::Position2D{-0.3,3});
    text.setPosition(float(pos.getX()),float(pos.getY()));
    return text;
}

sf::Text SFML::SFMLPlayer::visualizePassiveRewards(sf::Font &font) {
    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color(139,0,0));
    if (isBonusSpeed()){
        text.setString("BONUS");
        TurboHiker::Position2D pos = Transformation::getInstance().transform(TurboHiker::Position2D{-1,0});
        text.setPosition(float(pos.getX()),float(pos.getY()));
    }
    return text;
}

void SFML::SFMLPlayer::yell() {
    Player::yell();
    yelling_sound.play();
}

void SFML::SFMLPlayer::collide() {
    if (finished)
        return;
    if (!isColliding() && !isBonusSpeed()){
        TurboHiker::Player::collide();
        colliding_sound.play();
    }
}

void SFML::SFMLPlayer::moveLeft() {
    if (getMovement() == Hiker::STANDARD && getLane() > 0) {
        CompetingHiker::moveLeft();
        dashing_sound.play();
    }
}

void SFML::SFMLPlayer::moveRight() {
    if (getMovement() == STANDARD && getLane() < 3) {
        dashing_sound.play();
        CompetingHiker::moveRight();
    }
}

bool SFML::SFMLPlayer::isFinished() const {
    return finished;
}
