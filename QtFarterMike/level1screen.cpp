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
    FOffsetX = 0;
    FMapHeight = 14;
    FMapWidth = 80;

    FBgRect.x = 0;
    FBgRect.y = 0;
    FBgRect.w = AGame.GetSurface()->w;
    FBgRect.h = AGame.GetSurface()->h;

    FMap[0]  = "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||";
    FMap[1]  = "|                                                                              |";
    FMap[2]  = "|        $                  $                                                  |";
    FMap[3]  = "|                           $    E                       $   $                 |";
    FMap[4]  = "|      $   $      $  $      $                            $$ $$                 |";
    FMap[5]  = "|          *  *   *  *   *** ** ***      $               $ $ $                 |";
    FMap[6]  = "|                                     p                  $   $                 |";
    FMap[7]  = "|                     $              ***   ***           $   $                 |";
    FMap[8]  = "|                     $                  $                                  H  |";
    FMap[9]  = "|                    * *                           ***           E        *****|";
    FMap[10] = "|                                          E                $  $               |";
    FMap[11] = "|               $          *  $  E     $     ****        **  **  **            |";
    FMap[12] = "|  p         *         p                  *********p**~~~~~~~~~~~~~~~~~~~~~~~~~|";
    FMap[13] = "###############~~~##############################################################";

    for (int row = 0; row < FMapWidth; ++row) {
        for (int col = 0; col < FMapHeight; ++col) {
            char ch = FMap[col][row];
            if (ch == 'E') {
                Enemy enemy;
                enemy.Rect.x = row * 32;
                enemy.Rect.y = col * 32;
                enemy.Rect.w = 32;
                enemy.Rect.h = 64;
                FEnemies.push_back(enemy);
            }
        }
    }

    FHero.Rect.x = 100;
    FHero.Rect.y = 8 * 32;
    FHero.Rect.w = 32;
    FHero.Rect.h = 64;

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
                FHero.Rect.x -= 10;
                break;

            case SDLK_RIGHT:
                FHero.Rect.x += 10;
                break;
            }

        default:
            break;
        }
    }
}

void Level1Screen::Update(Game& AGame)
{
    if (FHero.Rect.x > AGame.GetSurface()->w / 2)
    {
        if (FHero.Rect.x < ((FMapWidth * 32) - AGame.GetSurface()->w / 2))
        {
            FOffsetX = FHero.Rect.x - AGame.GetSurface()->w / 2;
        }
    }

    SDL_Rect Rect = FHero.Rect;
    for (int row = Rect.x / 32; row < (Rect.x + Rect.w) / 32; ++row) {
        for (int col = Rect.y / 32; col < (Rect.y + Rect.h) / 32; ++col) {
            char ch = FMap[col][row];
            switch (ch) {
            case 'H':
                AGame.SetScreen(AGame.stMenu);
                break;
            default:
                break;
            }
        }
    }
}

void Level1Screen::Draw(Game& AGame)
{
    FSpriteSheet.Draw(AGame.GetSurface(), stBackground, &FBgRect);

    for (int row = FOffsetX / 32 - 1; row < (FOffsetX + AGame.GetSurface()->w) / 32 ; row++)
    {
        for (int col = 0; col < FMapHeight; col++)
        {
            SDL_Rect Rect;
            Rect.x = (row * 32) - FOffsetX;
            Rect.y = col * 32;
            Rect.w = 32;
            Rect.h = 32;

            char ch = FMap[col][row];
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

    for (unsigned I = 0; I < FEnemies.size(); ++I) {
        SDL_Rect Rect = FEnemies[I].Rect;
        Rect.x -= FOffsetX;
        FSpriteSheet.Draw(AGame.GetSurface(), stEnemy, &Rect);
    }

    SDL_Rect SRect = FHero.Rect;
    SRect.x -= FOffsetX;

    FSpriteSheet.Draw(AGame.GetSurface(), stHero, &SRect);
}
