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
    FMap[3]  = "|                           $                                                  |";
    FMap[4]  = "|      $   $      $  $      $                                                  |";
    FMap[5]  = "|          *  *   *  *   *** ** ***      $                                     |";
    FMap[6]  = "|                                     p                                        |";
    FMap[7]  = "|                     $              ***   ***                                 |";
    FMap[8]  = "|                     $                  $                                  p  |";
    FMap[9]  = "|                    * *                           ***                    *****|";
    FMap[10] = "|                                                           $  $               |";
    FMap[11] = "|               $          *  $        $     ****        **  **  **            |";
    FMap[12] = "|  p         *         p                  *********p**~~~~~~~~~~~~~~~~~~~~~~~~~|";
    FMap[13] = "###############~~~##############################################################";

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

        default:
            break;
        }
    }
}

void Level1Screen::Update(Game& AGame)
{
    FOffsetX += 0.1;
    if (FOffsetX + AGame.GetSurface()->w / 32 > FMapWidth)
    {
        FOffsetX = 0;
    }
}

void Level1Screen::Draw(Game& AGame)
{
    FSpriteSheet.Draw(AGame.GetSurface(), stBackground, &FBgRect);

    for (int row = 0; row < FMapWidth ; row++)
    {
        for (int col = 0; col < FMapHeight; col++)
        {
            SDL_Rect Rect;
            Rect.x = (row - FOffsetX) * 32;
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
}
