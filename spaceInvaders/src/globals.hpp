#pragma once

namespace si
{

class Globals
{
  public:
    Globals(Globals const &) = delete;
    void operator=(Globals const &) = delete;

    static const int screenWidth = 1280;
    static const int screenHeight = 720;

  private:
    Globals()
    {
    }

    static Globals *instance()
    {
        static Globals inst;
        return &inst;
    }
};

} // namespace si