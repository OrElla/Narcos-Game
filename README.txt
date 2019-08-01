README:

Narcos Readme:

Or Ella 
ID: 203304969
Guy Moshe
ID: 308378843

General Description:
This program is a super Mario type game inspired by the successful T.V series Narcos.
It tells the story of Pablo Escobar - the most notorious drug lord from Colombia, in this
game, Pablo has to travel across a map and get his beer while he can come across some 
enemies like policemen and dangerous animals, on the way he can obtain energy drinks,
money bags , coins ,and other collectables.

Design:

Command :
An abstract class which is a part of a command design pattern, every class that inherit from
It is inchargeof a differnet screen at the game.

Controller:
This class runs the main loop of the game

Tile:
This class represents every object of the game

StaticIcons:
This class represents the static icons of the game.

DynamicIcon:
This class represents the Dynamic icons of the game.

Factory:
An abstract class which has 2 derived classes that are part of a Factory design pattern.
One of them creates static game objects and the other dynamic game objects.

CollisionHandler:
This namespace is in charge of all the game object's collisions, it uses a multimethod design pattern that handles collisions of game objects with a map data structure.

Pablo:
The main character that the player moves.

Collectables:
An abstract class that all of its derived classes represents collectable items the the main character can obtain.
Enemy:
An abstract class that represents a dynamic enemy of the main character, its derived classes are policeman and Animal

FileManager:
This class is a part of a singleton design pattern, it loads all of the pictures, sounds, and music for the game. 


Added Files:

Fonts – keeps all the fonts
Images – keeps all the pictures
Levels – keeps the levels
Screens – keeps the menu and background screens
Sounds – keeps all the game sounds

Data structures:
m_board – 2d vector that holds all of the staticIcons positions
m_statics – 1d vector that holds all the static Icons
m_dynamics – 1d vector that holds all the dynamic Icons
m_map – a map that holds all the game objects collision functions


Known Bugs:

Collision between the main character and dynamic/static objects not always happens




  




