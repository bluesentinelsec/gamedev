#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <string>

namespace si
{

class sdlSurface
{
  public:
    sdlSurface() {};

    // Constructor that takes a surface pointer
    sdlSurface(const std::string &path)
    {
        aSurface = IMG_Load(path.c_str());
        SDL_assert(aSurface != nullptr);
    }

    // Destructor to handle cleanup
    ~sdlSurface()
    {
        SDL_FreeSurface(aSurface);
    }

    // Copy constructor
    sdlSurface(const sdlSurface &other) : aSurface(nullptr)
    {
        aSurface = SDL_DuplicateSurface(other.aSurface);
    }

    // Move constructor
    sdlSurface(sdlSurface &&other) noexcept : aSurface(other.aSurface)
    {
        other.aSurface = nullptr;
    }

    // Copy assignment
    sdlSurface &operator=(const sdlSurface &other)
    {
        if (this != &other)
        {
            sdlSurface copy(other);
            std::swap(aSurface, copy.aSurface);
        }
        return *this;
    }

    // Move assignment
    sdlSurface &operator=(sdlSurface &&other) noexcept
    {
        if (this != &other)
        {
            SDL_FreeSurface(aSurface);
            aSurface = other.aSurface;
            other.aSurface = nullptr;
        }
        return *this;
    }

    // Getter for the underlying surface
    SDL_Surface *get() const
    {
        return aSurface;
    }

    void set(const std::string &path)
    {
        aSurface = IMG_Load(path.c_str());
        SDL_assert(aSurface != nullptr);
    }

  private:
    SDL_Surface *aSurface = nullptr;
};

} // namespace si