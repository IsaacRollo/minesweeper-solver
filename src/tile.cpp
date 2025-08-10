#include <tile.h>

void isaacr::Tile::switchFlag(){
    _flagged = !(_flagged);
}

void isaacr::Tile::switchBomb(){
    _bomb = !(_bomb);
}

void isaacr::Tile::setBombAdj(int bombAdj){
    _bombAdj = bombAdj;
}

void isaacr::Tile::incrementBombAdj(){
    _bombAdj++;
}

bool isaacr::Tile::isBomb(){
    return _bomb;
}

bool isaacr::Tile::isFlagged(){
    return _flagged;
}

bool isaacr::Tile::isClicked(){
    return _clicked;
}

int isaacr::Tile::getBombAdj(){
    return _bombAdj;
}

bool isaacr::Tile::click(){
    _clicked = true;
    return _bomb;
}

char isaacr::Tile::drawTile(){
    if(_flagged) return 'f';
    if(!_clicked) return ' ';
    if(_bomb) return 'b';
    return _bombAdj + '0';
}