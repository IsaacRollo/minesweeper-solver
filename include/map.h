#ifndef MAP_H
#define MAP_H

#include <vector>
#include "tile.h"

namespace map {

class Map {
public:
    Map(int height, int width, int bombs) :
        _height(height),
        _width(width),
        _bombs(bombs) {}

private:
    std::vector<std::vector<tile::Tile>> _tiles;
    int _height;
    int _width;
    int _bombs;
    int _unclearedTiles; //does not include bombs

};

} 

#endif // MAP_H