#pragma once

namespace game
{

class Pong
{
  public:
    Pong();
    ~Pong();

    void start();
    bool update();
    void render();
    void exit();
};

} // namespace game
