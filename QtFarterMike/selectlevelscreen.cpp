#include "selectlevelscreen.h"
#include "game.h"

SelectLevelScreen::SelectLevelScreen()
{
}

SelectLevelScreen::~SelectLevelScreen()
{
}

void SelectLevelScreen::Init(Game& AGame)
{
    FOptions.clear();
    FOptions.push_back("1");
    FOptions.push_back("2");
    FOptions.push_back("3");
    FOptions.push_back("4");
    FOptions.push_back("5");
    FOptions.push_back("6");

    for (unsigned I = 0; I < FOptions.size(); I++)
    {
        int BWidth = AGame.GetSurface()->w / 16;
        int BHeight = AGame.GetSurface()->h / 9;
        int X = ((AGame.GetSurface()->w / 6) + (I * BWidth * 2));
        int Y = ((AGame.GetSurface()->h / 6) + (BHeight * 2));
        FButtons[I] = Button(X, Y, BWidth, BHeight);
        FButtons[I].Clicked = false;
    }

    FSurface = NULL;
    const std::string path = "res/SelectLevelSprites.bmp";
    FSurface = SDL_LoadBMP(path.c_str());
    if (FSurface == NULL)
    {
        printf("Unable to load bitmap: SelectLevelSprites.bmp");
    }
    SDL_SetColorKey(FSurface, SDL_RLEACCEL, SDL_MapRGB(FSurface->format, 255, 255, 255));

    printf("SelectLevelScreen Init Successful\n");
}

void SelectLevelScreen::Clean()
{
    printf("SelectLevelScreen Clean Successful\n");
}

void SelectLevelScreen::HandleEvents(Game& AGame)
{
    SDL_Event event;

    int mx = 0;
    int my = 0;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            AGame.Quit();
            break;

        case SDL_MOUSEBUTTONDOWN:
            mx = event.button.x;
            my = event.button.y;
            for (unsigned I = 0; I < FOptions.size(); I++)
            {
                FButtons[I].Clicked = false;
                if ((mx > FButtons[I].Rect.x) && (mx < FButtons[I].Rect.x + FButtons[I].Rect.w))
                {
                    if ((my > FButtons[I].Rect.y) && (my < FButtons[I].Rect.y + FButtons[I].Rect.h))
                    {
                        FButtons[I].Clicked = true;
                    }
                }
            }
            break;

        case SDL_MOUSEBUTTONUP:
            mx = event.button.x;
            my = event.button.y;
            for (unsigned I = 0; I < FOptions.size(); I++)
            {
                if ((mx > FButtons[I].Rect.x) && (mx < FButtons[I].Rect.x + FButtons[I].Rect.w))
                {
                    if ((my > FButtons[I].Rect.y) && (my < FButtons[I].Rect.y + FButtons[I].Rect.h))
                    {
                        if ((I == 0) && (FButtons[0].Clicked))
                        {
                            FButtons[0].Clicked = false;
                            AGame.SetScreen(AGame.stLevel1);
                        }
                        if ((I == 1) && (FButtons[1].Clicked))
                        {
                            FButtons[1].Clicked = false;
                            AGame.SetScreen(AGame.stLevel2);
                        }
                        if ((I == 2) && (FButtons[2].Clicked))
                        {
                            FButtons[2].Clicked = false;
                        }
                        if ((I == 3) && (FButtons[3].Clicked))
                        {
                            FButtons[3].Clicked = false;
                        }
                        if ((I == 4) && (FButtons[4].Clicked))
                        {
                            FButtons[4].Clicked = false;
                        }
                        if ((I == 5) && (FButtons[5].Clicked))
                        {
                            FButtons[5].Clicked = false;
                        }
                    }
                }
            }
            break;

        default:
            break;
        }
    }
}

void SelectLevelScreen::Update(Game& AGame)
{

}

void SelectLevelScreen::Draw(Game& AGame)
{
    for (unsigned I = 0; I < FOptions.size(); I++)
    {
        FButtons[I].Draw(AGame.GetSurface());

        SDL_Rect Pick;
        Pick.x = 0;
        Pick.y = I * 32;
        Pick.w = 32;
        Pick.h = 32;
        SDL_BlitScaled(FSurface, &Pick, AGame.GetSurface(), &FButtons[I].Rect);
    }
}
