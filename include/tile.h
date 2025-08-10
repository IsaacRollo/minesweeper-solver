#ifndef TILE_H
#define TILE_H

namespace isaacr {

class Tile {
public:
    Tile() :
        _flagged(false),
        _bomb(false),
        _clicked(false),
        _bombAdj(0) {}

    void switchFlag();
    void switchBomb();
    void setBombAdj(int bombAdj);
    void incrementBombAdj();
    bool isBomb();
    bool isFlagged();
    bool isClicked();
    int getBombAdj();
    bool click();
    char drawTile();

private:
    bool _flagged;
    bool _bomb;
    bool _clicked;
    int _bombAdj;
};

} 

#endif // TILE_H
