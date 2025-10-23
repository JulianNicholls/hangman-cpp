#ifndef IMAGES_H
#define IMAGES_H

#include <string>
#include <unordered_map>

#include "raylib.h"

class ImageLoader
{
  public:
    ImageLoader(std::string_view dir);

    virtual ~ImageLoader();

    ImageLoader operator=(const ImageLoader &other) = delete;

    void load(std::string_view dir);
    const Texture2D &at(std::string_view name) const;

    std::size_t size() const
    {
        return images_.size();
    }

  private:
    std::unordered_map<std::string, Texture2D> images_;
};

#endif // IMAGES_H
