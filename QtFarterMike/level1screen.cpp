#include "level1screen.h"
#include "game.h"

Level1Screen::Level1Screen()
{
    FLeft = false;
    FRight = false;
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
    Map[4]  = "|  P                           E                                            H  |";
    Map[5]  = "|                             $ $                                        ******|";
    Map[6]  = "|                 $                           $  $           E         ********|";
    Map[7]  = "|           $$$   $    p    *******  $$$     $  $  $                 **********|";
    Map[8]  = "|     $$$       *****      ********* $$$  ******** $ ****$ $    $ $************|";
    Map[9]  = "################################################################################";

    MapWidth = Map[0].length();
    MapHeight = 10;

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
                SDL_Rect Rect;
                Rect.x = row * TILE_SIZE;
                Rect.y = col * TILE_SIZE;
                Rect.w = TILE_SIZE;
                Rect.h = TILE_SIZE * 2;
                enemy.SetRect(Rect);
                enemy.Dummy = enemy.GetRect();
                Enemies.push_back(enemy);
            }
                break;

            case '$':
            {
                Sprite coin;
                coin.Frame = 0;
                coin.StartFrame = 0;
                coin.EndFrame = 9;
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
                FLeft = true;
                break;

            case SDLK_RIGHT:
                FRight = true;
                break;

            case SDLK_UP:
                Player.Jump();
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT:
                FLeft = false;
                break;

            case SDLK_RIGHT:
                FRight = false;
                break;
            }
            break;
        default:
            break;
        }
    }
}

void Level1Screen::Update(Game& AGame)
{
    LevelScreen::Update(AGame);

    if (FLeft == true)
    {
        Player.Left();
    }
    else if (FRight == true)
    {
        Player.Right();
    }
    else if (FLeft == false && FRight == false)
    {
        Player.Stop();
    }

    SDL_Rect Rect = Player.GetRect();
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

    Player.Animate();
    Player.Update();

    for (auto &coin: Coins)
      coin.Animate();
    auto localHasIntersection = [this](const Sprite &coin)
        {
            auto tmp = Player.GetRect();
            return SDL_HasIntersection(&tmp, &coin.Rect);
        };
    AGame.Scores.Coins += std::count_if(std::begin(Coins), std::end(Coins), localHasIntersection);
    Coins.erase(std::remove_if(std::begin(Coins), std::end(Coins), localHasIntersection), std::end(Coins));
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

    for (std::vector<Sprite>::iterator coin = Coins.begin(); coin != Coins.end(); ++coin)
    {
        SDL_Rect Rect = coin->Rect;
        Rect.x -= OffsetX;
        FSpriteSheet.Draw(AGame.GetSurface(), stCoin, coin->Frame, &Rect);
    }

    for (unsigned I = 0; I < Enemies.size(); ++I) {
        SDL_Rect Rect = Enemies[I].GetRect();
        Rect.x -= OffsetX;
        switch (Enemies[I].Action) {
        case eaMoveLeft:
            FEnemySheet.Draw(AGame.GetSurface(), estLeft, Enemies[I].Frame, &Rect);
            break;
        case eaMoveRight:
            FEnemySheet.Draw(AGame.GetSurface(), estRight, Enemies[I].Frame, &Rect);
            break;
        case eaStand:
            FEnemySheet.Draw(AGame.GetSurface(), estStand, Enemies[I].Frame, &Rect);
            break;
        default:
            break;
        }
        //Dummy.x -= OffsetX;
        //SDL_FillRect(AGame.GetSurface(), &Dummy, SDL_MapRGB(AGame.GetSurface() -> format, 0, 255, 0));
    }

    SDL_Rect SRect = Player.GetRect();
    SRect.x -= OffsetX;

    switch (Player.Action) {
    case paMoveLeft:
        FPlayerSheet.Draw(AGame.GetSurface(), stLeft, Player.Frame, &SRect);
        break;
    case paMoveRight:
        FPlayerSheet.Draw(AGame.GetSurface(), stRight, Player.Frame, &SRect);
        break;
    case paStand:
        FPlayerSheet.Draw(AGame.GetSurface(), stStand, Player.Frame, &SRect);
        break;
    default:
        break;
    }
}
