#include <tile.h>
#include <map.h>
#include <iostream>

void play(){
    int height;
    int width;
    int bombs;

    std::cout << "Input the Height, Width, and amount of Bombs for this map.\n";
    std::cin >> height >> width >> bombs;
    isaacr::Map playTest(height, width, bombs);

    std::string action;
    int x;
    int y;

    while(playTest.getLeft() != 0){

        playTest.printMap();

        std::cout << "Enter the action you want to perform and the coordinates to perform it on.\n";
        std::cin >> action >> x >> y;

        if(action == "click")
            playTest.clickTile(x, y);
        else if(action == "flag")
            playTest.switchFlag(x, y);
        else if(action == "solve")
            playTest.solveMap();
        else
            std::cout << "Incorrect input\n";
    }

    playTest.printMap();
    std::cout << "You won congratulations.\n";

}

int main() {
    std::cout << "Game Starting\n";

    isaacr::Tile tileTest;

    std::cout << tileTest.isBomb() << " " << tileTest.isFlagged() << "\n";

    tileTest.switchBomb();
    tileTest.switchFlag();

    std::cout << tileTest.isBomb() << " " << tileTest.isFlagged() << "\n";

    isaacr::Map mapTest(10, 10, 5);
    mapTest.printMap();
    mapTest.solveMap();
    mapTest.printMap();

    play();
    
    return 0;
}

