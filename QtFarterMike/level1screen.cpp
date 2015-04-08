#include "level1screen.h"
#include "game.h"
#include "getresourcepath.h"
#include "texture.h"

Level1Screen::Level1Screen()
{
    Map[0]  = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
    Map[1]  = "|                                                                              |";
    Map[2]  = "|                                                                              |";
    Map[3]  = "|                                                                              |";
    Map[4]  = "|  P                           E                                            H  |";
    Map[5]  = "|                             $ $                                        ******|";
    Map[6]  = "|                 $                           $  $           E         ********|";
    Map[7]  = "|           $$$   $    p    *******  $$$     $  $  $                 **********|";
    Map[8]  = "|     $$$       *****      ********* $$$  ******** $ ****$ $    $ $************|";
    Map[9]  = "################################################################################";
}

Level1Screen::~Level1Screen()
{
}

void Level1Screen::Init(Game& AGame)
{
    LevelScreen::Init(AGame);

    Background = LoadTexture(AGame.GetRenderer(), getResourcePath() + "/Level1Background.png");
    LevelSheet.LoadFromFile(AGame.GetRenderer(), getResourcePath() + "/Level1Sprites.png");
    PlayerSheet.LoadFromFile(AGame.GetRenderer(), getResourcePath() + "/PlayerSprites.png");
    EnemySheet.LoadFromFile(AGame.GetRenderer(), getResourcePath() + "/EnemySprites.png");

    printf("Level1Screen Init Successful\n");
}

void Level1Screen::Clean()
{
    printf("Level1Screen Clean Successful\n");
}

void Level1Screen::HandleEvents(Game& AGame)
{
    LevelScreen::HandleEvents(AGame);
}

void Level1Screen::Update(Game& AGame)
{
    LevelScreen::Update(AGame);
}

void Level1Screen::Draw(Game& AGame)
{
    LevelScreen::Draw(AGame);
}
