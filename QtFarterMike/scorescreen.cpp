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
    FBackgroundSurface = NULL;
    const std::string path = "res/ScoreBackground.bmp";
    FBackgroundSurface = SDL_LoadBMP(path.c_str());
    if (FBackgroundSurface == NULL)
    {
        printf("Unable to load bitmap: ScoreBackground.bmp");
    }
    SDL_SetColorKey(FBackgroundSurface, SDL_RLEACCEL, SDL_MapRGB(FBackgroundSurface->format, 255, 255, 255));

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
    SDL_BlitScaled(FBackgroundSurface, NULL, AGame.GetSurface(), NULL);

    SDL_Rect Rect;
    Rect.x = AGame.GetSurface()->w / 6;
    Rect.y = AGame.GetSurface()->h / 4;
    Rect.w = 64;
    Rect.h = 64;
    FSpriteSheet.Draw(AGame.GetSurface(), stCoins, 0, &Rect);

    AGame.Font.Height = 32;
    int x = Rect.x + Rect.w * 2;
    AGame.Font.DrawText(AGame.GetSurface(), x, 100, std::to_string(AGame.Scores.Coins));


    int Frame;
    FButtons[0].Draw(AGame.GetSurface());
    Frame = 0;
    if (FButtons[0].Clicked)
    {
        Frame = 1;
    }
    FSpriteSheet.Draw(AGame.GetSurface(), stMenu, Frame, &FButtons[0].Rect);

    FButtons[1].Draw(AGame.GetSurface());
    Frame = 0;
    if (FButtons[1].Clicked)
    {
        Frame = 1;
    }
    FSpriteSheet.Draw(AGame.GetSurface(), stRestart, Frame, &FButtons[1].Rect);

    FButtons[2].Draw(AGame.GetSurface());
    Frame = 0;
    if (FButtons[2].Clicked)
    {
        Frame = 1;
    }
    FSpriteSheet.Draw(AGame.GetSurface(), stNext, Frame, &FButtons[2].Rect);
}
