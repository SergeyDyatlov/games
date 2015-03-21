#include "scorescreen.h"
#include "game.h"

ScoreScreen::ScoreScreen()
{
}

ScoreScreen::~ScoreScreen()
{
}

void ScoreScreen::Init(Game& AGame)
{
    FOptions.clear();
    FOptions.push_back("Select Level");
    FOptions.push_back("Restart Level");
    FOptions.push_back("Next Level");

    for (unsigned I = 0; I < FOptions.size(); I++)
    {
        int BWidth = AGame.GetSurface()->w / 6;
        int BHeight = AGame.GetSurface()->h / 9;
        int X = ((AGame.GetSurface()->w / 12) + (I * (BWidth * 2)));
        int Y = (AGame.GetSurface()->h - BHeight * 2);
        FButtons[I] = Button(X, Y, BWidth, BHeight);
        FButtons[I].Clicked = false;
    }

    printf("ScoreScreen Init Successful\n");
}

void ScoreScreen::Clean()
{
    printf("ScoreScreen Clean Successful\n");
}

void ScoreScreen::HandleEvents(Game& AGame)
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
                            FButtons[I].Clicked = false;
                            AGame.SetScreen(AGame.stMenu);
                        }
                        if ((I == 1) && (FButtons[I].Clicked))
                        {
                            FButtons[I].Clicked = false;
                            AGame.RestartLevel();
                        }
                        if ((I == 2) && (FButtons[I].Clicked))
                        {
                            FButtons[I].Clicked = false;
                            AGame.NextLevel();
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

void ScoreScreen::Update(Game& AGame)
{

}

void ScoreScreen::Draw(Game& AGame)
{
    FButtons[0].Draw(AGame.GetSurface());
    FSpriteSheet.Draw(AGame.GetSurface(), stMenu, &FButtons[0].Rect);

    FButtons[1].Draw(AGame.GetSurface());
    FSpriteSheet.Draw(AGame.GetSurface(), stRestart, &FButtons[1].Rect);

    FButtons[2].Draw(AGame.GetSurface());
    FSpriteSheet.Draw(AGame.GetSurface(), stNext, &FButtons[2].Rect);
}
