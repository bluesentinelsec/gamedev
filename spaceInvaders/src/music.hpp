#include <SDL.h>
#include <SDL_mixer.h>
#include <stdexcept>
#include <string>

namespace si
{
class Music
{
  public:
    // Default constructor
    Music() {};

    // Constructor that loads a Mix_Music from a file
    explicit Music(const std::string &file) : music(nullptr)
    {
        music = Mix_LoadMUS(file.c_str());
        SDL_assert(music != nullptr);
    }

    // Destructor that frees the Mix_Music
    ~Music()
    {
        if (music)
        {
            Mix_FreeMusic(music);
        }
    }

    // Deleted copy constructor and copy assignment operator to avoid copying
    Music(const Music &) = delete;
    Music &operator=(const Music &) = delete;

    // Move constructor
    Music(Music &&other) noexcept : music(other.music)
    {
        other.music = nullptr;
    }

    // Move assignment operator
    Music &operator=(Music &&other) noexcept
    {
        if (this != &other)
        {
            // Free existing resource
            if (music)
            {
                Mix_FreeMusic(music);
            }
            // Transfer ownership
            music = other.music;
            other.music = nullptr;
        }
        return *this;
    }

    // Provides access to the underlying Mix_Music*
    Mix_Music *get() const
    {
        return music;
    }

    // Sets a new music file
    void set(const std::string &file)
    {
        // Free existing music if necessary
        if (music)
        {
            Mix_FreeMusic(music);
        }

        music = Mix_LoadMUS(file.c_str());
        SDL_assert(music != nullptr);
    }

    // Plays the music
    void play(int loops = 1)
    {
        if (Mix_PlayMusic(music, loops) == -1)
        {
            throw std::runtime_error("Failed to play music: " + std::string(Mix_GetError()));
        }
    }

    // Pauses the music
    void pause()
    {
        Mix_PauseMusic();
    }

    // Resumes the music
    void resume()
    {
        Mix_ResumeMusic();
    }

    // Stops the music
    void stop()
    {
        Mix_HaltMusic();
    }

  private:
    Mix_Music *music;
};
} // namespace si
