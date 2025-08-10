#include <map.h>
#include <iostream>
#include <queue>

void isaacr::Map::clickTile(int x, int y){
    if(x < 0 || x >= _width || y < 0 || y >= _height){
        std::cout << "Input out of bounds\n";
    }
    else{
        if(_tiles[y][x].isFlagged())
            std::cout << "This Tile is Flagged. Unflag it to click.\n";
        else if(_tiles[y][x].isClicked())
            std::cout << "This Tile has already been clicked on.\n";
        else if (_tiles[y][x].click())
            std::cout << "Oh no a bomb. D:\n";
        else{
            std::cout << "The tile has been cleared.\n";
            _unclearedTiles--;
            if(_tiles[y][x].getBombAdj() == 0)
                cascadeClick(x, y);
        }
    }

}

void isaacr::Map::cascadeClick(int x, int y){
    std::queue<std::pair<int, int>> coordsToCas;
    coordsToCas.push({y, x});

    std::vector<std::pair<int, int>> adjTiles{
        {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {1, 1}, {1, 0}, {1, -1}, {0, 1}
    };

    while(!coordsToCas.empty()){
        y = coordsToCas.front().first;
        x = coordsToCas.front().second;
        coordsToCas.pop();
        for(auto tile:adjTiles){
            int dx = x + tile.second;
            int dy = y + tile.first;
            if(dx >= 0 && dx < _width && dy >= 0 && dy < _height && !_tiles[dy][dx].isClicked()){
                _tiles[dy][dx].click();
                _unclearedTiles--;
                if(_tiles[dy][dx].getBombAdj() == 0)
                    coordsToCas.push({dy, dx});
            }
        }

    }
}

void isaacr::Map::switchFlag(int x, int y){
    if(x < 0 || x >= _width || y < 0 || y >= _height){
        std::cout << "Input out of bounds\n";
    }
    else if(_tiles[y][x].isClicked())
        std::cout << "This tile has already been clicked, and thus can not be flagged\n";
    else
        _tiles[y][x].switchFlag();
}

int isaacr::Map::getLeft(){
    return _unclearedTiles;
}

void isaacr::Map::solveMap(){
    for(int i = 0; i < _tiles.size(); i++){
        for(int j = 0; j < _tiles[i].size(); j++){
            if(!_tiles[i][j].isBomb())
                _tiles[i][j].click();
                _unclearedTiles--;
        }
    }
}

void isaacr::Map::printMap(){

    std::cout << " ";
    for(int j = 0; j < _tiles[0].size(); j++){
        std::cout << j << " ";
    }
    std::cout << "\n";
    
    for(int i = 0; i < _tiles.size(); i++){
        std::cout << "-";
        for(int j = 0; j < _tiles[i].size(); j++){
            std::cout << "--";
        }
        std::cout << "\n|";
        for(int j = 0; j < _tiles[i].size(); j++){
            std::cout << _tiles[i][j].drawTile() << "|";
        }
        std::cout << "\n";
    }
    std::cout << "-";
    for(int j = 0; j < _width; j++){
        std::cout << "--";
    }
    std::cout << "\n";
}