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

    FMap[0]  = "********************************************************************************";
    FMap[1]  = "*                                                                              *";
    FMap[2]  = "*                           $                                                  *";
    FMap[3]  = "*      $$$$$                $                                                  *";
    FMap[4]  = "*      $$$$$      $  $      $                                                  *";
    FMap[5]  = "**** ********** ********  ****** ***     $                                     *";
    FMap[6]  = "*                                                                              *";
    FMap[7]  = "*                                    ***   ***                                 *";
    FMap[8]  = "*                 $$$                    $                                  H  *";
    FMap[9]  = "*                                                  ***                    ******";
    FMap[10] = "*              ***   ***                        ******                         *";
    FMap[11] = "*              ***   ***     $    $    $     *********   **  **  **            *";
    FMap[12] = "*      ***                                ************~~~~~~~~~~~~~~~~~~~~~~~~~*";
    FMap[13] = "********************************************************************************";

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

}

void Level1Screen::Draw(Game& AGame)
{
    for (int row = 0; row < FMapWidth ; row++)
    {
        for (int col = 0; col < FMapHeight; col++)
        {
            SDL_Rect Rect;
            Rect.x = row * 32;
            Rect.y = col * 32;
            Rect.w = 32;
            Rect.h = 32;

            Uint32 Color;
            Color = SDL_MapRGB(AGame.GetSurface() -> format, 0, 0, 0);

            char ch = FMap[col][row];
            switch (ch)
            {
            case '*':
                Color = SDL_MapRGB(AGame.GetSurface() -> format, 192, 192, 192);
                break;
            case '$':
                Color = SDL_MapRGB(AGame.GetSurface() -> format, 192, 192, 0);
                break;
            case '~':
                Color = SDL_MapRGB(AGame.GetSurface() -> format, 0, 0, 192);
                break;
            case 'H':
                Color = SDL_MapRGB(AGame.GetSurface() -> format, 0, 192, 0);
                break;

            default:
                break;
            }

            SDL_FillRect(AGame.GetSurface(), &Rect, Color);
        }
    }
}
