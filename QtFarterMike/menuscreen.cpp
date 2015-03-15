#include "menuscreen.h"
#include "game.h"

MenuScreen::MenuScreen()
{
}

MenuScreen::~MenuScreen()
{
}

void MenuScreen::Init(Game& AGame)
{
    FOptions.clear();
    FOptions.push_back("New Game");
    FOptions.push_back("Exit");

    for (unsigned I = 0; I < FOptions.size(); I++)
    {
        int X = AGame.GetSurface()->w / 2;
        int Y = I * 50;
        FButtons[I] = Button(X, Y, 100, 25);
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
            break;

        case SDL_MOUSEBUTTONUP:
            mx = event.button.x;
            my = event.button.y;
            for (unsigned I = 0; I < FOptions.size(); I++)
            {
                FButtons[I].Clicked = false;
                if ((mx > FButtons[I].Box.x) && (mx < FButtons[I].Box.x + FButtons[I].Box.w))
                {
                    if ((my > FButtons[I].Box.y) && (my < FButtons[I].Box.y + FButtons[I].Box.h))
                    {
                        FButtons[I].Clicked = true;
                        AGame.SetScreen(AGame.stLevel1);
                    }
                }
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
    for (unsigned I = 0; I < FOptions.size(); I++)
    {
        FButtons[I].Draw(AGame.GetSurface());
    }
}
