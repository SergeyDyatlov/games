#include "level2screen.h"
#include "game.h"

Level2Screen::Level2Screen()
{
}

Level2Screen::~Level2Screen()
{
}

void Level2Screen::Init(Game& AGame)
{
    LevelScreen::Init(AGame);

    FBgRect.x = 0;
    FBgRect.y = 0;
    FBgRect.w = AGame.GetSurface()->w;
    FBgRect.h = AGame.GetSurface()->h;

    Map[0]  = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
    Map[1]  = "|                                                                              |";
    Map[2]  = "|                                                                              |";
    Map[3]  = "|                                                                              |";
    Map[4]  = "|                                                                              |";
    Map[5]  = "|                                                                              |";
    Map[6]  = "|                                                                              |";
    Map[7]  = "|                                                                              |";
    Map[8]  = "|                                                                              |";
    Map[9]  = "|                                                                              |";
    Map[10] = "|                                                                              |";
    Map[11] = "|                                                                              |";
    Map[12] = "|                                                                              |";
    Map[13] = "################################################################################";

    MapWidth = Map[0].length();
    MapHeight = 14;

    printf("Level2Screen Init Successful\n");
}

void Level2Screen::Clean()
{
    printf("Level2Screen Clean Successful\n");
}

void Level2Screen::HandleEvents(Game& AGame)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            AGame.Quit();
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT:
                Player.Rect.x -= 10;
                break;

            case SDLK_RIGHT:
                Player.Rect.x += 10;
                break;
            }

        default:
            break;
        }
    }
}

void Level2Screen::Update(Game& AGame)
{
    LevelScreen::Update(AGame);
}

void Level2Screen::Draw(Game& AGame)
{
    FSpriteSheet.Draw(AGame.GetSurface(), stBackground, &FBgRect);

    for (int row = OffsetX / TILE_SIZE - 1; row < (OffsetX + AGame.GetSurface()->w) / TILE_SIZE ; row++)
    {
        for (int col = 0; col < MapHeight; col++)
        {
            SDL_Rect Rect;
            Rect.x = (row * TILE_SIZE) - OffsetX;
            Rect.y = col * TILE_SIZE;
            Rect.w = TILE_SIZE;
            Rect.h = TILE_SIZE;

            char ch = Map[col][row];
            switch (ch)
            {
            case '*':
                FSpriteSheet.Draw(AGame.GetSurface(), stBlock, &Rect);
                break;
            case '$':
                FSpriteSheet.Draw(AGame.GetSurface(), stCoin, &Rect);
                break;
            case '~':
                FSpriteSheet.Draw(AGame.GetSurface(), stWater, &Rect);
                break;
            case '#':
                FSpriteSheet.Draw(AGame.GetSurface(), stGround, &Rect);
                break;
            case 'p':
                FSpriteSheet.Draw(AGame.GetSurface(), stPepper, &Rect);
                break;
            default:
                break;
            }
        }
    }

    for (unsigned I = 0; I < Enemies.size(); ++I) {
        SDL_Rect Rect = Enemies[I].Rect;
        Rect.x -= OffsetX;
        FSpriteSheet.Draw(AGame.GetSurface(), stEnemy, &Rect);
    }

    SDL_Rect SRect = Player.Rect;
    SRect.x -= OffsetX;

    FSpriteSheet.Draw(AGame.GetSurface(), stHero, &SRect);
}