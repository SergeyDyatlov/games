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

    Player.SetRect(SDL_Rect{100, 2 * TILE_SIZE, TILE_SIZE, TILE_SIZE * 2});
    Player.Level = this;
    Player.SetHealth(100);
    Player.Direction = 1;

    Enemies.clear();
    Coins.clear();

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
    int Width;
    int Height;
    SDL_GetWindowSize(AGame.GetWindow(), &Width, &Height);

    if (Player.GetRect().x > Width / 2) {
        if (Player.GetRect().x < ((MapWidth * TILE_SIZE) - Width / 2)) {
            OffsetX = Player.GetRect().x - Width / 2;
            OffsetX += Player.GetRect().w / 2;
        }
    }
}

void LevelScreen::Draw(Game& AGame)
{

}
