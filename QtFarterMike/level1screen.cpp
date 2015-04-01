#include "level1screen.h"
#include "game.h"

Level1Screen::Level1Screen()
{
}

Level1Screen::~Level1Screen()
{
}

void Level1Screen::Init(Game& AGame)
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
    Map[8]  = "|                                                                           H  |";
    Map[9]  = "|                             $E$                                        ******|";
    Map[10] = "|                 $                           $  $                     ********|";
    Map[11] = "|  P        $$$   $    p    *******  $$$     $  $  $         E       **********|";
    Map[12] = "|     $$$       *****      ********* $$$  ******** $ ****$ $    $ $************|";
    Map[13] = "################################################################################";

    MapWidth = Map[0].length();
    MapHeight = 14;

    Enemies.clear();

    Coins.clear();

    for (int row = 0; row < MapWidth; ++row) {
        for (int col = 0; col < MapHeight; ++col) {
            char ch = Map[col][row];
            switch (ch) {
            case 'E':
            {
                Enemy enemy;
                enemy.Level = this;
                enemy.Rect.x = row * TILE_SIZE;
                enemy.Rect.y = col * TILE_SIZE;
                enemy.Rect.w = TILE_SIZE;
                enemy.Rect.h = TILE_SIZE * 2;
                enemy.Dummy = enemy.Rect;
                Enemies.push_back(enemy);
            }
                break;

            case '$':
            {
                Sprite coin;
                coin.Frames.CurFrame = 0;
                coin.Frames.MinFrame = 0;
                coin.Frames.MaxFrame = 10;
                coin.Rect.w = TILE_SIZE;
                coin.Rect.h = TILE_SIZE;
                coin.Rect.x = row * TILE_SIZE;
                coin.Rect.y = col * TILE_SIZE;
                Coins.push_back(coin);
            }
                break;
            default:
                break;
            }
        }
    }

    printf("Level1Screen Init Successful\n");
}

void Level1Screen::Clean()
{
    printf("Level1Screen Clean Successful\n");
}

void Level1Screen::HandleEvents(Game& AGame)
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
            case SDLK_UP:
                Player.Rect.y -= 10;
                break;
            case SDLK_DOWN:
                Player.Rect.y += 10;
                break;
            }
        default:
            break;
        }
    }
}

void Level1Screen::Update(Game& AGame)
{
    LevelScreen::Update(AGame);

    SDL_Rect Rect = Player.Rect;
    for (int row = Rect.x / TILE_SIZE; row <= (Rect.x + Rect.w) / TILE_SIZE; ++row) {
        for (int col = Rect.y / TILE_SIZE; col <= (Rect.y + Rect.h) / TILE_SIZE; ++col) {
            char ch = Map[col][row];
            switch (ch) {
            case 'H':
                AGame.SetScoreScreen();
                break;
            default:
                break;
            }
        }
    }

    for (std::vector<Enemy>::iterator enemy = Enemies.begin(); enemy != Enemies.end(); ++enemy)
    {
        enemy->Update();
    }

    for (std::vector<Sprite>::iterator coin = Coins.begin(); coin != Coins.end(); ++coin)
    {
        coin->Update();
        if (SDL_HasIntersection(&Player.Rect, &coin->Rect))
        {
            AGame.Scores.Coins += 1;
            Coins.erase(coin);
        }
    }
}

void Level1Screen::Draw(Game& AGame)
{
    FSpriteSheet.Draw(AGame.GetSurface(), stBackground, 0, &FBgRect);

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
                FSpriteSheet.Draw(AGame.GetSurface(), stBlock, 0, &Rect);
                break;
            case '~':
                FSpriteSheet.Draw(AGame.GetSurface(), stWater, 0, &Rect);
                break;
            case '#':
                FSpriteSheet.Draw(AGame.GetSurface(), stGround, 0, &Rect);
                break;
            case 'p':
                FSpriteSheet.Draw(AGame.GetSurface(), stPepper, 0, &Rect);
                break;
            default:
                break;
            }
        }
    }

    for (std::vector<Sprite>::iterator it = Coins.begin(); it != Coins.end(); ++it)
    {
        SDL_Rect Rect = it->Rect;
        Rect.x -= OffsetX;
        FSpriteSheet.Draw(AGame.GetSurface(), stCoin, it->Frames.CurFrame, &Rect);
    }

//    for (unsigned I = 0; I < Coins.size(); ++I)
//    {
//        SDL_Rect Rect = Coins[I].Rect;
//        Rect.x -= OffsetX;
//        FSpriteSheet.Draw(AGame.GetSurface(), stCoin, Coins[I].Frames.CurFrame, &Rect);
//    }

    for (unsigned I = 0; I < Enemies.size(); ++I) {
        SDL_Rect Rect = Enemies[I].Rect;
        SDL_Rect Dummy = Enemies[I].Dummy;
        Rect.x -= OffsetX;
        FSpriteSheet.Draw(AGame.GetSurface(), stEnemy, Enemies[I].CurrentFrame, &Rect);
        //Dummy.x -= OffsetX;
        //SDL_FillRect(AGame.GetSurface(), &Dummy, SDL_MapRGB(AGame.GetSurface() -> format, 0, 255, 0));
    }

    SDL_Rect SRect = Player.Rect;
    SRect.x -= OffsetX;

    FSpriteSheet.Draw(AGame.GetSurface(), stHero, 0, &SRect);
}
