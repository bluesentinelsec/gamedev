#pragma once

#include <filesystem>

namespace game
{

static char *ArgvZero;

class pathutils
{
  public:
    static void InitFilesystem(char *argvZero);
    static std::filesystem::path GetResourcePath();
    static std::filesystem::path WithResourcePath(const char *path);

  private:
    static std::filesystem::path getResourcePath(char *argvZero);
};

} // namespace game
