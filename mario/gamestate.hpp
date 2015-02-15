#pragma once

class GameState 
{
  public:
    virtual void init() = 0;
    virtual void draw() const = 0;
    virtual void update() = 0;
    virtual void keyPressed(unsigned char key, int x, int y) = 0;
    virtual void keySpecial(int key, int x, int y) = 0;
};

