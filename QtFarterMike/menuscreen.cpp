#include "menuscreen.h"

MenuScreen::MenuScreen()
{
}

void MenuScreen::Init(Game& AGame)
{
    Options.push_back("New Game");
    Options.push_back("Exit");

    for (unsigned I = 0; I < Options.size(); I++)
    {
        int X = AGame.GetSurface()->w / 2;
        int Y = I * 50;
        Buttons[I] = Button(X, Y, 100, 25);
        Buttons[I].Clicked = false;
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
            for (unsigned I = 0; I < Options.size(); I++)
            {
                Buttons[I].Clicked = false;
                if ((mx > Buttons[I].Box.x) && (mx < Buttons[I].Box.x + Buttons[I].Box.w))
                {
                    if ((my > Buttons[I].Box.y) && (my < Buttons[I].Box.y + Buttons[I].Box.h))
                    {
                        Buttons[I].Clicked = true;
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
    if (Buttons[0].Clicked == true)
    {
        AGame.SetScreen(AGame.stLevel1);
    }
}

void MenuScreen::Draw(Game& AGame)
{
    for (unsigned I = 0; I < Options.size(); I++)
    {
        Buttons[I].Draw(AGame.GetSurface());
    }
}
