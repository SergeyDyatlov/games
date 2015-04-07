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
    FBackground = IMG_LoadTexture(AGame.GetRenderer(), "res/SelectLevelBackground.bmp");

    FOptions.clear();
    FOptions.push_back(1);
    FOptions.push_back(0);
    FOptions.push_back(0);
    FOptions.push_back(0);
    FOptions.push_back(0);
    FOptions.push_back(0);

    int Width;
    int Height;
    SDL_GetWindowSize(AGame.GetWindow(), &Width, &Height);

    for (unsigned I = 0; I < FOptions.size(); I++)
    {
        int BWidth = Width / 16;
        int BHeight = Height / 9;
        int X = ((Width / 6) + (I * BWidth * 2));
        int Y = ((Height / 6) + (BHeight * 2));
        FButtons[I] = Button(X, Y, BWidth, BHeight);
        FButtons[I].Clicked = false;
    }

    FTexture = IMG_LoadTexture(AGame.GetRenderer(), "res/SelectLevelSprites.bmp");
    SDL_SetTextureBlendMode(FTexture, SDL_BLENDMODE_BLEND);

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
                            AGame.SetLevelScreen(1);
                        }
                        if ((I == 1) && (FButtons[I].Clicked) && FOptions[I] > 0)
                        {
                            AGame.SetLevelScreen(2);
                        }
                        if ((I == 2) && (FButtons[I].Clicked) && FOptions[I] > 0)
                        {

                        }
                        if ((I == 3) && (FButtons[I].Clicked) && FOptions[I] > 0)
                        {

                        }
                        if ((I == 4) && (FButtons[I].Clicked) && FOptions[I] > 0)
                        {

                        }
                        if ((I == 5) && (FButtons[I].Clicked) && FOptions[I] > 0)
                        {

                        }
                    }
                }
                FButtons[I].Clicked = false;
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
    SDL_RenderCopy(AGame.GetRenderer(), FBackground, NULL, NULL);

    for (unsigned I = 0; I < FOptions.size(); I++)
    {
        FButtons[I].Draw(AGame.GetRenderer());

        SDL_Rect Pick;
        Pick.x = 0;
        Pick.y = 0;

        if (FOptions[I] > 0) {
            Pick.y = (I + 1) * 32;
        }

        if (FButtons[I].Clicked)
        {
            Pick.x = 32;
        }

        Pick.w = 32;
        Pick.h = 32;
        SDL_RenderCopy(AGame.GetRenderer(), FTexture, &Pick, &FButtons[I].Rect);
    }
}
