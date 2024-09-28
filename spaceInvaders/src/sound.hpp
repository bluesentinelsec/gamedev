#include <SDL.h>
#include <SDL_mixer.h>
#include <stdexcept>
#include <string>

namespace si
{
class Sound
{
  public:
    Sound() {};
    
    // Constructor that loads a Mix_Chunk from a file
    explicit Sound(const std::string &file) : chunk(nullptr)
    {
        chunk = Mix_LoadWAV(file.c_str());
        SDL_assert(chunk != nullptr);
    }

    // Destructor that frees the Mix_Chunk
    ~Sound()
    {
        Mix_FreeChunk(chunk);
    }

    // Deleted copy constructor and copy assignment operator to avoid copying
    Sound(const Sound &) = delete;
    Sound &operator=(const Sound &) = delete;

    // Move constructor
    Sound(Sound &&other) noexcept : chunk(other.chunk)
    {
        other.chunk = nullptr;
    }

    // Move assignment operator
    Sound &operator=(Sound &&other) noexcept
    {
        if (this != &other)
        {
            // Free existing resource
            if (chunk)
            {
                Mix_FreeChunk(chunk);
            }
            // Transfer ownership
            chunk = other.chunk;
            other.chunk = nullptr;
        }
        return *this;
    }

    // Provides access to the underlying Mix_Chunk*
    Mix_Chunk *get() const
    {
        return chunk;
    }

    void set(const std::string &file)
    {
        chunk = Mix_LoadWAV(file.c_str());
        SDL_assert(chunk != nullptr);
    }

    void play()
    {
        Mix_PlayChannel(-1, chunk, 0);
    }

  private:
    Mix_Chunk *chunk;
};
} // namespace si