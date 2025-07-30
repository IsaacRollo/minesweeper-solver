#include <tile.h>

void tile::Tile::switchFlag(){
    _flagged = !(_flagged);
}

void tile::Tile::switchBomb(){
    _bomb = !(_bomb);
}

void tile::Tile::setBombAdj(int bombAdj){
    _bombAdj = bombAdj;
}

bool tile::Tile::isBomb(){
    return _bomb;
}

bool tile::Tile::isFlagged(){
    return _flagged;
}

bool tile::Tile::click(){
    _clicked = true;
    return _bomb;
}

char tile::Tile::drawTile(){
    if(_flagged) return 'f';
    if(!_clicked) return ' ';
    if(_bomb) return 'b';
    return _bombAdj;
}