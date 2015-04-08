#include "menuscreen.h"
#include "game.h"
#include "texture.h"

MenuScreen::MenuScreen()
{
}

MenuScreen::~MenuScreen()
{
}

void MenuScreen::Init(Game& AGame)
{
    const std::string path = "res/MenuBackground.png";
    FBackground = LoadTexture(AGame.GetRenderer(), path.c_str());
    SDL_SetTextureBlendMode(FBackground, SDL_BLENDMODE_BLEND);

    FSpriteSheet.LoadFromFile(AGame.GetRenderer(), "res/MenuSprites.png");

    FOptions.clear();
    FOptions.push_back("New Game");
    FOptions.push_back("Exit");

    int Width;
    int Height;
    SDL_GetWindowSize(AGame.GetWindow(), &Width, &Height);

    for (unsigned I = 0; I < FOptions.size(); I++)
    {
        int BWidth = Width / 5;
        int BHeight = Height / 9;
        int X = ((Width / 2) - (BWidth / 2));
        int Y = ((Height / 2) + (I * (BHeight * 2)));
        FButtons[I] = Button(X, Y, BWidth, BHeight);
        FButtons[I].Clicked = false;
    }

    printf("MenuScreen Init Successful\n");
}

void MenuScreen::Clean()
{
    printf("MenuScreen Clean Successful\n");
}

void MenuScreen::HandleEvents(Game& AGame)
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
                        if ((I == 0) && (FButtons[I].Clicked))
                        {
                            AGame.SetLevelSelectionScreen();
                        }
                        if ((I == 1) && (FButtons[I].Clicked))
                        {
                            AGame.Quit();
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

void MenuScreen::Update(Game& AGame)
{

}

void MenuScreen::Draw(Game& AGame)
{
    SDL_RenderCopy(AGame.GetRenderer(), FBackground, NULL, NULL);

    int Frame;

    FButtons[0].Draw(AGame.GetRenderer());
    Frame = 0;
    if (FButtons[0].Clicked)
    {
        Frame = 1;
    }
    FSpriteSheet.Draw(AGame.GetRenderer(), stStart, Frame, &FButtons[0].Rect);

    FButtons[1].Draw(AGame.GetRenderer());
    Frame = 0;
    if (FButtons[1].Clicked)
    {
        Frame = 1;
    }
    FSpriteSheet.Draw(AGame.GetRenderer(), stExit, Frame, &FButtons[1].Rect);
}
