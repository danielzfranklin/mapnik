#ifndef MAPNIK_FOR_RUST_HPP
#define MAPNIK_FOR_RUST_HPP

// mapnik
#include <mapnik/agg_renderer.hpp>
#include <mapnik/image.hpp>

// stl
#include <memory>

namespace mapnik {
namespace for_rust {

using renderer = agg_renderer<image_rgba8>;

std::unique_ptr<image_rgba8> image_new_default(unsigned int width, unsigned int height)
{
    return std::make_unique<image_rgba8>(width, height);
}

/*!
 * Returns a rgba8_t::type, or u32. AutoCXX just can't handle it.
 */
const int* image_data(image_rgba8 const& pixmap)
{
    return static_cast<const int*>(pixmap.data());
}

std::unique_ptr<renderer> renderer_new_default(Map const& map, image_rgba8& pixmap)
{
    return std::make_unique<renderer>(map, pixmap);
}

/*!
 * \brief apply renderer to all map layers.
 */
void renderer_apply(renderer& ren)
{
    ren.apply();
}

} // namespace for_rust
} // namespace mapnik

#endif
