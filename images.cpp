#include <filesystem>
#include <print>

#include "raylib.h"

#include "images.h"

ImageLoader::ImageLoader(std::string_view dir)
    : images_{}
{
    load(dir);
}

void ImageLoader::load(std::string_view dir)
{
    for (auto const &dir_entry : std::filesystem::directory_iterator(dir))
    {
        std::string imagename{dir_entry.path().stem()};
        const char *filename = dir_entry.path().c_str();

        std::println("Loading {:<20} {}", imagename, filename);

        images_.emplace(imagename, LoadTexture(filename));
    }
}

ImageLoader::~ImageLoader()
{
    for (auto [key, tex] : images_)
    {
        UnloadTexture(tex);
    }
}

const Texture2D &ImageLoader::at(std::string_view name) const
{
    return images_.at(std::string(name));
}
