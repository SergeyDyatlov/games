#include "font.h"

int CharWidth[256] =
{
//
    16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
//
    16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,
//  , !, ", #, $, %, &, `, (, ), *, +, ,, -, ., /,
     8, 4, 4, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 4, 8,
// o, 1, 2, 3, 4, 5, 6, 7, 8, 9, :, ;, <, =, >, ?,
     8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 4, 4, 8, 8, 8, 8,
// @, A, B, C, D, E, F, G, H, I, J, K, L, M, N, O
     8,12,12,12,12,12,12,12,12, 8,12,12,12,12,12,12,
// P, Q, R, S, T, U, V, W, x, Y, Z, [, \, ], ^, _
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
// ', a, b, c, d, e, f, g, h, i, j, k, l, m, n, o
    12,12,12,12,12,12,12,12,12, 4,12,12,12,12,12,12,
// p, q, r, s, t, u, v, w, x, y, z, {, :, }, ~, ^
    12,12,12,12,12,12,12,12,12,12,12,16,16,16,16,16,
// А, Б, В, Г, Д, Е, Ж, З, И, Й, К, Л, М, Н, О, П
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
// Р, С, Т, У, Ф, Х, Ц, Ч, Ш, Щ, Ъ, Ы, Ь, Э, Ю, Я
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
// а, б, в, г, д, е, ж, з, и, й, к, л, м, н, о, п
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
// р, с, т, у, ф, х, ц, ч, ш, щ, ъ, ы, ь, э, ю, я
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
//
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
//
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
//
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,
//
    12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12
};

TFont::TFont()
{
    Height = 32;
}

void TFont::LoadFromFile(const std::string &path)
{
    FBitmap = NULL;
    FBitmap = SDL_LoadBMP(path.c_str());
    if (FBitmap == NULL)
    {
        printf("Unable to load bitmap %s! Error: %s\n", path.c_str(), SDL_GetError());
    };
}

void TFont::DrawChar(SDL_Surface* Surface, int X, int Y, int asciicode)
{
    SDL_Rect pick;
    pick.x = ((asciicode % 16) * 16 + 8) - CharWidth[asciicode] / 2;
    pick.y = (asciicode / 16) * 16;
    pick.w = CharWidth[asciicode];
    pick.h = 16;

    SDL_Rect area;
    area.x = X;
    area.y = Y;
    area.w = CharWidth[asciicode] + (Height / 4);
    area.h = Height;
    SDL_BlitScaled(FBitmap, &pick, Surface, &area);
}

void TFont::DrawText(SDL_Surface* Surface, int X, int Y, const std::string &text)
{
    int asciicode;
    SDL_Rect rect;
    rect.x = X;
    rect.y = Y;
    for (unsigned int i=0; i<text.length(); i++)
    {
        asciicode = text[i];
        DrawChar(Surface, rect.x, rect.y, asciicode);
        rect.x = rect.x + CharWidth[asciicode] + (Height / 4);
    }
}

int TFont::TextWidth(const std::string &text)
{

}
