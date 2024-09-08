#include "pathutils.hpp"


namespace game
{
std::filesystem::path pathutils::GetResourcePath()
{
    return getResourcePath(ArgvZero);
}

void pathutils::InitFilesystem(char *argvZero)
{
    ArgvZero = argvZero;
}

std::filesystem::path pathutils::getResourcePath(char *argvZero)
{
#if __APPLE__ && defined(Pong_Release)
    auto exePath = std::filesystem::canonical(std::filesystem::path(argvZero));
    auto resourcesPath = exePath.parent_path().parent_path() / "Resources";
    return resourcesPath;
#endif
    return std::filesystem::current_path();
}

std::filesystem::path pathutils::WithResourcePath(const char *path)
{
    std::filesystem::path resourcePath = GetResourcePath();
    std::filesystem::path mediaPath = path;
    auto mergedPath = resourcePath / mediaPath;
    return mergedPath.c_str();
}

} // namespace game