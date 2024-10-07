#pragma once

#include <SDL.h>

#include "surface.hpp"

namespace si
{

class Texture
{
  public:
    Texture() {};

    // Constructor creates a new SDL_Texture
    Texture(SDL_Renderer *renderer, const sdlSurface &surf)
    {
        m_texture = SDL_CreateTextureFromSurface(renderer, surf.get());
        SDL_assert(m_texture != nullptr);
    }

    // Move constructor
    Texture(Texture &&other) noexcept : m_texture(other.m_texture)
    {
        other.m_texture = nullptr;
    }

    // Move assignment
    Texture &operator=(Texture &&other) noexcept
    {
        if (this != &other)
        {
            SDL_DestroyTexture(m_texture);
            m_texture = other.m_texture;
            other.m_texture = nullptr;
        }
        return *this;
    }

    // Destructor frees the SDL_Texture
    ~Texture()
    {
        SDL_DestroyTexture(m_texture);
    }

    // Copy operations are deleted to prevent accidental copies
    Texture(const Texture &) = delete;
    Texture &operator=(const Texture &) = delete;

    // Get the raw SDL_Texture pointer
    SDL_Texture *get() const noexcept
    {
        return m_texture;
    }

    void set(SDL_Renderer *renderer, const sdlSurface &surf)
    {
        SDL_assert(renderer != nullptr);
        SDL_assert(surf.get() != nullptr);

        m_texture = SDL_CreateTextureFromSurface(renderer, surf.get());
        SDL_assert(m_texture != nullptr);
    }

  private:
    SDL_Texture *m_texture = nullptr;
};

} // namespace si
