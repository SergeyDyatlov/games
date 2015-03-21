#include "levelscreen.h"
#include "game.h"

LevelScreen::LevelScreen()
{

}

LevelScreen::~LevelScreen()
{
}

void LevelScreen::Init(Game& AGame)
{
    OffsetX = 0;

    Player.Rect.x = 100;
    Player.Rect.y = 8 * TILE_SIZE;
    Player.Rect.w = TILE_SIZE;
    Player.Rect.h = TILE_SIZE * 2;

    Scores.Coins = 0;
    Scores.Killed = 0;
}

void LevelScreen::Clean()
{

}

void LevelScreen::HandleEvents(Game& AGame)
{

}

void LevelScreen::Update(Game& AGame)
{
    if (Player.Rect.x > AGame.GetSurface()->w / 2) {
        if (Player.Rect.x < ((MapWidth * TILE_SIZE) - AGame.GetSurface()->w / 2)) {
            OffsetX = Player.Rect.x - AGame.GetSurface()->w / 2;
            OffsetX += Player.Rect.w / 2;
        }
    }
}

void LevelScreen::Draw(Game& AGame)
{

}
