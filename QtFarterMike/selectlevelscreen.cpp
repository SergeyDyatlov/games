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
    FOptions.push_back(1);
    FOptions.push_back(0);
    FOptions.push_back(0);
    FOptions.push_back(0);
    FOptions.push_back(0);
    FOptions.push_back(0);

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
                        if ((I == 0) && (FButtons[I].Clicked) && FOptions[I] > 0)
                        {
                            FButtons[0].Clicked = false;
                            AGame.SetLevelScreen(1);
                        }
                        if ((I == 1) && (FButtons[I].Clicked) && FOptions[I] > 0)
                        {
                            FButtons[1].Clicked = false;
                            AGame.SetLevelScreen(2);
                        }
                        if ((I == 2) && (FButtons[I].Clicked) && FOptions[I] > 0)
                        {
                            FButtons[2].Clicked = false;
                        }
                        if ((I == 3) && (FButtons[I].Clicked) && FOptions[I] > 0)
                        {
                            FButtons[3].Clicked = false;
                        }
                        if ((I == 4) && (FButtons[I].Clicked) && FOptions[I] > 0)
                        {
                            FButtons[4].Clicked = false;
                        }
                        if ((I == 5) && (FButtons[I].Clicked) && FOptions[I] > 0)
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
        Pick.y = 0;

        if (FOptions[I] > 0) {
            Pick.y = (I + 1) * 32;
        }

        Pick.w = 32;
        Pick.h = 32;
        SDL_BlitScaled(FSurface, &Pick, AGame.GetSurface(), &FButtons[I].Rect);
    }
}
