#include "level2screen.h"
#include "game.h"
#include "getresourcepath.h"
#include "texture.h"

Level2Screen::Level2Screen()
{
    Map[0] = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
    Map[1] = "|                                                                              |";
    Map[2] = "|                                                                              |";
    Map[3] = "|                                                                              |";
    Map[4] = "|                                                                              |";
    Map[5] = "|                                                                              |";
    Map[6] = "|                                                                              |";
    Map[7] = "|                         ****                                                 |";
    Map[8] = "|     *       *         *        *           *           *                     |";
    Map[9] = "################################################################################";
}

Level2Screen::~Level2Screen()
{
}

void Level2Screen::Init(Game& AGame)
{
    LevelScreen::Init(AGame);

    Background = LoadTexture(AGame.GetRenderer(), getResourcePath() + "/Level1Background.png");
    LevelSheet.LoadFromFile(AGame.GetRenderer(), getResourcePath() + "/Level1Sprites.png");
    PlayerSheet.LoadFromFile(AGame.GetRenderer(), getResourcePath() + "/PlayerSprites.png");
    EnemySheet.LoadFromFile(AGame.GetRenderer(), getResourcePath() + "/EnemySprites.png");

    printf("Level2Screen Init Successful\n");
}

void Level2Screen::Clean()
{
    printf("Level2Screen Clean Successful\n");
}

void Level2Screen::HandleEvents(Game& AGame)
{
    LevelScreen::HandleEvents(AGame);
}

void Level2Screen::Update(Game& AGame)
{
    LevelScreen::Update(AGame);
}

void Level2Screen::Draw(Game& AGame)
{
    LevelScreen::Draw(AGame);
}
