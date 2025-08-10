#ifndef MAP_H
#define MAP_H

#include <cstdlib>
#include <vector>
#include <ctime>
#include "tile.h"

namespace isaacr {

class Map {
public:
    Map(int height, int width, int bombs) :
        _height(height),
        _width(width),
        _bombs(bombs) 
        {
            _unclearedTiles = height * width - bombs;
            _tiles = std::vector<std::vector<isaacr::Tile>>(height, std::vector<isaacr::Tile>(width));

            int bombsAdded = 0;
            std::vector<std::pair<int, int>> adjTiles{
                {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {1, 1}, {1, 0}, {1, -1}, {0, 1}
            };
            std::srand(std::time(0));
            while(bombsAdded < bombs){
                int x = rand() % width;
                int y = rand() % height;
                if(!_tiles[y][x].isBomb()){
                    _tiles[y][x].switchBomb();
                    bombsAdded++;

                    for(auto tile:adjTiles){
                        int dx = tile.first + x;
                        int dy = tile.second + y;
                        if(dx >= 0 && dx < width && dy >= 0 && dy < height){
                            _tiles[dy][dx].incrementBombAdj();
                        }
                    }
                }
            }
        }

        void clickTile(int x, int y);
        void cascadeClick(int x, int y);
        void switchFlag(int x, int y);
        int getLeft();
        void solveMap();
        void printMap();

private:
    std::vector<std::vector<isaacr::Tile>> _tiles;
    int _height;
    int _width;
    int _bombs;
    int _unclearedTiles; //does not include bombs

};

} 

#endif // MAP_H