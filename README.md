# TurboHiker


#### COmpile and run

- ./build.sh
- ./run.sh

#### Game Description

- Try to be the first competing hiker to finish the race while scoring as many points as you can.
- There will be static and moving enemy hikers blocking your way.
- If you can't avoid the enemy hikers, you can yell at them which will scare the static enemy hikers and slow down the moving enemy hikers with a 50% chance.
- Try to avoid the bombs at all cost.
- Your score will be displayed on the top left corner and the collected items on top center of the window.
- A '-' means that you can spawn an enemy hiker who moves down, a '+' means that you can spawn an enemy hiker who moves upwards and a 'o' means that you can spawn a static enemy.

#### Game Rules

- You can only move forward.
- Changing from one lane to another is done in one step.
- Colliding with the enemy hikers or the competing hikers results in major slowdown of your movement and reduces the score.
- Colliding with bombs results in respawning from position 0.
- Yelling and taking items reduces your score.

### Controls

- ↑ : move upwards
- →: move right
- ↓: move down
- ←: move left
- SPACE: yell
- W: move at turbo speed

## Report
I have separated my design in two parts, one is for the game logic and the other is for the game presentation.
### Entity
Anything that we see in our game world is an entity, even the world itself.  Every entity is located somewhere in the game world and has unique interactions with different entities, depending on what kind of entity they are. There are different kinds of entities and each has its own role.

A **hiker** is a special entity that can and may move on the y-axis, in other words, it has a speed which is changeable.

The **competing hiker** can on top of that also move from a lane to another lane in one step, which means that the movement on the x-axis is very restricted, just like the popular game Subway Surfers. In addition, this hiker can run at ‘turbo’ speed, which is a special speed-up and collide with other entities, the reaction to colliding depends on the entity. This kind of hikers can also take passive rewards and get a boost or collect active ones and use them later. They also have a score.

The **player** is a competing hiker that can yell. The yelling has no effect on other competing hikers, but it can possible trigger a reaction from the enemy hikers. The yelling has a range, and only those enemies inside the range may react to the yelling.

There are two kinds of **enemies**, **static** and **moving** enemies. These are special hikers that can react to the yelling of the player, either by getting scared and run away or by slowing down respectively. Sometimes the enemies are not intimidated by the player though.

As an extension to the project, I have added some **collectable items** to the game. The **passive** items are immediately used after collecting them. They can only be collected by competing hikers, including the player and give a speed boost for a certain duration. There is a higher chance of getting boosts with long durations for competitors that are behind. The **active** items can be collected by the competitors. These are either a static enemy or a moving enemy. Competitors that are running behind have a higher chance of getting a moving enemy that goes forward and the competitors that are ahead have higher chance of getting a moving hiker that runs backwards. This way they can shoot moving hikers at each other. This last part is one of my own extensions.

The **bomb** is also one of my own extensions. To make sure the player does not abuse the “run at turbo speed” option, I have added some bombs that give a big punishment if hit by a competitor. The punishment is namely that the competitor will have to start the race all over, from y-position 0. The bomb only moves to the right in the x-axis.

The **ground plot** entity is just a visualization of the race track and the **finish line** speaks for itself.

### The World
The world follows the composite design pattern somewhat.  It contains sets of other entities and makes sure all entities are updated. On top of that, it handles collisions, yelling, item collecting and tracks the player with its own position coordinates. More importantly, the world creates all entities and spawns them in the right position.
### Ini configuration
To make the game easier to balance and have less hard coded values in the code, I have added a configuration file that contains all information needed to create entities.
### The abstract factory
This is an interface that is implemented by the entity factory. It creates SFML entities after reading the necessary information from the ini configuration file. An instance of this class is used in the world class to create and spawn all the entities.
### Singletons
I have created two singletons,  the Random class that generates random integers and random doubles and a transformation class that transforms logical coordinates into pixel values that can be used by the SFML window.
### Score
All competing hikers have a score that is updated every time an event occurs. The score of a competing hiker depends on its position and the number of times collided, yelled, collected items etc. Score is implemented with the observer design pattern.
### Clock
Since we were not permitted to use sfml::Clock, I created my own clock, which I use to update entities and animations with different tick durations.
### SFML Entities
The class SFMLEntity adds visualization to entities and is not very related to the Entity class from the logic library.
All other SFML entities inherit from both SFMLEntity and the Entity. These can update the visualization on the screen and do some sfml event handling.
### Game
The game class contains the main game loop and draws everything on the window.

