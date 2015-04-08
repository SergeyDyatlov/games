#include "scorescreen.h"
#include "game.h"
#include "texture.h"

ScoreScreen::ScoreScreen()
{
}

ScoreScreen::~ScoreScreen()
{
}

void ScoreScreen::Init(Game& AGame)
{
    FBackground = LoadTexture(AGame.GetRenderer(), "res/ScoreBackground.png");

    FScoreSheet.LoadFromFile(AGame.GetRenderer(), "res/ScoreSprites.png");;

    FOptions.clear();
    FOptions.push_back("Select Level");
    FOptions.push_back("Restart Level");
    FOptions.push_back("Next Level");

    int Width;
    int Height;
    SDL_GetWindowSize(AGame.GetWindow(), &Width, &Height);

    for (unsigned I = 0; I < FOptions.size(); I++)
    {
        int BWidth = Width / 6;
        int BHeight = Height / 9;
        int X = ((Width / 12) + (I * (BWidth * 2)));
        int Y = (Height - BHeight * 2);
        FButtons[I] = Button(X, Y, BWidth, BHeight);
        FButtons[I].Clicked = false;
    }

    printf("\n Scores{\n");
    printf("\t Coins: %d\n", AGame.Scores.Coins);
    printf("\t Killed: %d\n", AGame.Scores.Killed);
    printf(" }\n\n");

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
                            AGame.SetMenuScreen();
                        }
                        if ((I == 1) && (FButtons[I].Clicked))
                        {
                            AGame.SetLevelScreen(AGame.CurrentLevel);
                        }
                        if ((I == 2) && (FButtons[I].Clicked))
                        {
                            AGame.SetLevelScreen(AGame.CurrentLevel + 1);
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

void ScoreScreen::Update(Game& AGame)
{

}

void ScoreScreen::Draw(Game& AGame)
{
    SDL_RenderCopy(AGame.GetRenderer(), FBackground, NULL, NULL);

    int Width;
    int Height;
    SDL_GetWindowSize(AGame.GetWindow(), &Width, &Height);

    SDL_Rect Rect;
    Rect.x = Width / 6;
    Rect.y = Height / 4;
    Rect.w = 64;
    Rect.h = 64;
    FScoreSheet.Draw(AGame.GetRenderer(), stCoins, 0, &Rect);

    AGame.Font.Height = 32;
    int x = Rect.x + Rect.w * 2;
    AGame.Font.DrawText(AGame.GetRenderer(), x, 100, std::to_string(AGame.Scores.Coins));


    int Frame;
    FButtons[0].Draw(AGame.GetRenderer());
    Frame = 0;
    if (FButtons[0].Clicked)
    {
        Frame = 1;
    }
    FScoreSheet.Draw(AGame.GetRenderer(), stMenu, Frame, &FButtons[0].Rect);

    FButtons[1].Draw(AGame.GetRenderer());
    Frame = 0;
    if (FButtons[1].Clicked)
    {
        Frame = 1;
    }
    FScoreSheet.Draw(AGame.GetRenderer(), stRestart, Frame, &FButtons[1].Rect);

    FButtons[2].Draw(AGame.GetRenderer());
    Frame = 0;
    if (FButtons[2].Clicked)
    {
        Frame = 1;
    }
    FScoreSheet.Draw(AGame.GetRenderer(), stNext, Frame, &FButtons[2].Rect);
}
