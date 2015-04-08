#include "levelscreen.h"
#include "game.h"

LevelScreen::LevelScreen()
{
    FLeft = false;
    FRight = false;
}

LevelScreen::~LevelScreen()
{
}

void LevelScreen::Init(Game& AGame)
{
    int Width;
    int Height;
    SDL_GetWindowSize(AGame.GetWindow(), &Width, &Height);

    FButtons[btLeft] = Button(50, Height - 100, 50, 50);
    FButtons[btLeft].Clicked = false;
    FButtons[btRight] = Button(150, Height - 100, 50, 50);
    FButtons[btRight].Clicked = false;
    FButtons[btJump] = Button(Width - 100, Height - 100, 50, 50);
    FButtons[btJump].Clicked = false;

    MapWidth = Map[0].length();
    MapHeight = 10;

    OffsetX = 0;

    Player.SetRect(SDL_Rect{100, 2 * TILE_SIZE, TILE_SIZE, TILE_SIZE * 2});
    Player.Level = this;
    Player.SetHealth(100);
    Player.Direction = 1;

    Enemies.clear();
    Coins.clear();

    for (int row = 0; row < MapWidth; ++row) {
        for (int col = 0; col < MapHeight; ++col) {
            char ch = Map[col][row];
            switch (ch) {
            case 'E':
            {
                Enemy enemy;
                enemy.Level = this;
                SDL_Rect Rect;
                Rect.x = row * TILE_SIZE;
                Rect.y = col * TILE_SIZE;
                Rect.w = TILE_SIZE;
                Rect.h = TILE_SIZE * 2;
                enemy.SetRect(Rect);
                enemy.Dummy = enemy.GetRect();
                Enemies.push_back(enemy);
            }
                break;

            case '$':
            {
                Sprite coin;
                coin.Frame = 0;
                coin.StartFrame = 0;
                coin.EndFrame = 9;
                coin.Rect.w = TILE_SIZE;
                coin.Rect.h = TILE_SIZE;
                coin.Rect.x = row * TILE_SIZE;
                coin.Rect.y = col * TILE_SIZE;
                Coins.push_back(coin);
            }
                break;
            default:
                break;
            }
        }
    }

    AGame.Scores.Coins = 0;
    AGame.Scores.Killed = 0;
}

void LevelScreen::Clean()
{

}

void LevelScreen::HandleEvents(Game& AGame)
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
            for (unsigned I = 0; I < FButtons.size(); I++)
            {
                FButtons[I].Clicked = false;
                if ((mx > FButtons[I].Rect.x) && (mx < FButtons[I].Rect.x + FButtons[I].Rect.w))
                {
                    if ((my > FButtons[I].Rect.y) && (my < FButtons[I].Rect.y + FButtons[I].Rect.h))
                    {
                        FButtons[I].Clicked = true;
                        if ((I == 0) && (FButtons[I].Clicked))
                        {
                            FLeft = true;
                        }
                        if ((I == 1) && (FButtons[I].Clicked))
                        {
                            FRight = true;
                        }
                        if ((I == 2) && (FButtons[I].Clicked))
                        {
                            Player.Jump();
                        }
                    }
                }
            }
            break;

        case SDL_MOUSEBUTTONUP:
            mx = event.button.x;
            my = event.button.y;
            for (unsigned I = 0; I < FButtons.size(); I++)
            {
                if ((mx > FButtons[I].Rect.x) && (mx < FButtons[I].Rect.x + FButtons[I].Rect.w))
                {
                    if ((my > FButtons[I].Rect.y) && (my < FButtons[I].Rect.y + FButtons[I].Rect.h))
                    {
                        if ((I == 0) && (FButtons[I].Clicked))
                        {
                            FLeft = false;
                        }
                        if ((I == 1) && (FButtons[I].Clicked))
                        {
                            FRight = false;
                        }
                        if ((I == 2) && (FButtons[I].Clicked))
                        {

                        }
                    }
                }
                FButtons[I].Clicked = false;
            }
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT:
                FLeft = true;
                break;

            case SDLK_RIGHT:
                FRight = true;
                break;

            case SDLK_UP:
                Player.Jump();
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym)
            {
            case SDLK_LEFT:
                FLeft = false;
                break;

            case SDLK_RIGHT:
                FRight = false;
                break;
            }
            break;
        default:
            break;
        }
    }
}

void LevelScreen::Update(Game& AGame)
{
    if (FLeft == true)
    {
        Player.Left();
    }
    else if (FRight == true)
    {
        Player.Right();
    }
    else if (FLeft == false && FRight == false)
    {
        Player.Stop();
    }

    Player.Animate();
    Player.Update();

    if (Player.IsDead())
    {
        AGame.SetScoreScreen();
    }

    for (std::vector<Enemy>::iterator enemy = Enemies.begin(); enemy != Enemies.end(); ++enemy)
    {
        enemy->Update();
    }

    for (auto &coin: Coins)
      coin.Animate();
    auto localHasIntersection = [this](const Sprite &coin)
        {
            auto tmp = Player.GetRect();
            return SDL_HasIntersection(&tmp, &coin.Rect);
        };
    AGame.Scores.Coins += std::count_if(std::begin(Coins), std::end(Coins), localHasIntersection);
    Coins.erase(std::remove_if(std::begin(Coins), std::end(Coins), localHasIntersection), std::end(Coins));

    int Width;
    int Height;
    SDL_GetWindowSize(AGame.GetWindow(), &Width, &Height);

    if (Player.GetRect().x > Width / 2) {
        if (Player.GetRect().x < ((MapWidth * TILE_SIZE) - Width / 2)) {
            OffsetX = Player.GetRect().x - Width / 2;
            OffsetX += Player.GetRect().w / 2;
        }
    }

    SDL_Rect Rect = Player.GetRect();
    for (int row = Rect.x / TILE_SIZE; row <= (Rect.x + Rect.w) / TILE_SIZE; ++row) {
        for (int col = Rect.y / TILE_SIZE; col <= (Rect.y + Rect.h) / TILE_SIZE; ++col) {
            char ch = Map[col][row];
            switch (ch) {
            case 'H':
                AGame.SetScoreScreen();
                break;
            default:
                break;
            }
        }
    }
}

void LevelScreen::Draw(Game& AGame)
{
    SDL_RenderCopy(AGame.GetRenderer(), Background, NULL, NULL);

    int Width;
    int Height;
    SDL_GetWindowSize(AGame.GetWindow(), &Width, &Height);

    for (int row = OffsetX / TILE_SIZE - 1; row < (OffsetX + Width) / TILE_SIZE ; row++)
    {
        for (int col = 0; col < MapHeight; col++)
        {
            SDL_Rect Rect;
            Rect.x = (row * TILE_SIZE) - OffsetX;
            Rect.y = col * TILE_SIZE;
            Rect.w = TILE_SIZE;
            Rect.h = TILE_SIZE;

            char ch = Map[col][row];
            switch (ch)
            {
            case '*':
                LevelSheet.Draw(AGame.GetRenderer(), stBlock, 0, &Rect);
                break;
            case '~':
                LevelSheet.Draw(AGame.GetRenderer(), stWater, 0, &Rect);
                break;
            case '#':
                LevelSheet.Draw(AGame.GetRenderer(), stGround, 0, &Rect);
                break;
            case 'p':
                LevelSheet.Draw(AGame.GetRenderer(), stPepper, 0, &Rect);
                break;
            default:
                break;
            }
        }
    }

    for (std::vector<Sprite>::iterator coin = Coins.begin(); coin != Coins.end(); ++coin)
    {
        SDL_Rect Rect = coin->Rect;
        Rect.x -= OffsetX;
        LevelSheet.Draw(AGame.GetRenderer(), stCoin, coin->Frame, &Rect);
    }

    for (unsigned I = 0; I < Enemies.size(); ++I) {
        SDL_Rect Rect = Enemies[I].GetRect();
        Rect.x -= OffsetX;
        switch (Enemies[I].Action) {
        case eaStand:
            EnemySheet.Draw(AGame.GetRenderer(), estStand, Enemies[I].Frame, Enemies[I].Direction, &Rect);
            break;
        case eaMove:
            EnemySheet.Draw(AGame.GetRenderer(), estMove, Enemies[I].Frame, Enemies[I].Direction, &Rect);
            break;
        case eaAttack:
            EnemySheet.Draw(AGame.GetRenderer(), estAttack, Enemies[I].Frame, Enemies[I].Direction, &Rect);
            break;
        default:
            break;
        }
        //Dummy.x -= OffsetX;
        //SDL_FillRect(AGame.GetSurface(), &Dummy, SDL_MapRGB(AGame.GetSurface() -> format, 0, 255, 0));
    }

    SDL_Rect SRect = Player.GetRect();
    SRect.x -= OffsetX;

    switch (Player.Action) {
    case paStand:
        PlayerSheet.Draw(AGame.GetRenderer(), stStand, Player.Frame, Player.Direction, &SRect);
        break;
    case paMove:
        PlayerSheet.Draw(AGame.GetRenderer(), stMove, Player.Frame, Player.Direction, &SRect);
        break;
    default:
        break;
    }

    for (unsigned I = 0; I < FButtons.size(); I++)
    {
        FButtons[I].Draw(AGame.GetRenderer());
        SDL_RenderCopy(AGame.GetRenderer(), Background, NULL, &FButtons[I].Rect);
    }
}
