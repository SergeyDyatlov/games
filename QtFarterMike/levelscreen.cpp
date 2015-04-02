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

    Player.SetRect(SDL_Rect{100, 8 * TILE_SIZE, TILE_SIZE, TILE_SIZE * 2});
    Player.Level = this;
    AGame.Scores.Coins = 0;
    AGame.Scores.Killed = 0;
}

void LevelScreen::Clean()
{

}

void LevelScreen::HandleEvents(Game& AGame)
{

}

void LevelScreen::Update(Game& AGame)
{
    if (Player.GetRect().x > AGame.GetSurface()->w / 2) {
        if (Player.GetRect().x < ((MapWidth * TILE_SIZE) - AGame.GetSurface()->w / 2)) {
            OffsetX = Player.GetRect().x - AGame.GetSurface()->w / 2;
            OffsetX += Player.GetRect().w / 2;
        }
    }
}

void LevelScreen::Draw(Game& AGame)
{

}
