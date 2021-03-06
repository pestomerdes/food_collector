/*
 * Project name: Food collection
 * Version 4
 * Student : Albert Eduard Merino Pulido
 */
#ifndef map_h
#define map_h
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <stack>
#include <list>

#include "cell.h"


using namespace std;

class Map {
public:
    static const int initX;
    static const int initY;
    static float seed;
    static bool isSeed;

    // Constructors
    Map();
    Map(int, int);
    Map(char *);

    // Getters
    int getHeight();
    int getWidth();
    void setSeed(float);
    float getSeed();
    vector<vector<Cell *> > getMap();
    string toString();

    // Methods
    void generate();
    Cell * getInitPosition(CellType);
    void setPosition(CellType, Cell *);
    vector<Cell *> getFood();
    vector<Cell *> getCandidateFood();
    bool isCandidate(Cell *);
    int getScore(CellType);
    Cell * getPosition(CellType);
    void setBulletEnable(bool);
    bool getBulletEnable();
    bool isInInitialPosition(CellType);
    int getFoodRemaining();
    bool hasFood();
    void eat(CellType);
    void incrementScore(CellType);
    vector<Direction> getLegalActions(Cell *);
    Map generateSuccessor(CellType, Direction);
    Cell * getNextState(Cell *, Direction);
    void crash(CellType);
    void getStateRepresentation(Map currentState, Map lastState);

    // Print
    void print();

    int scorePlayer, scoreEnemy;
private:
    void initCells();
    void connect(Cell *);
    void connectCells();
    void inside();
    void middle();
    void inferiorRandom();
    void middleRandom();
    void openRandom(Cell *, vector<Direction> );
    void mirror();
    void initMap();

    bool insideCondition(unsigned int, unsigned int);
    void initWhitePositionCells();
    Cell * randomDiscoverPath(Cell *);

    void getMapFromFile(char *);
    void print(vector<vector<Cell *> > );
    void populateStateRepresentation(vector<vector<vector<vector<int> > > > &all, int tensor, Map state);
    void printState(vector<vector<vector<vector<int> > > > all);
protected
    : int height, width;
    vector<vector<Cell *> > map;
    vector<vector<Cell *> > visited;
    int totalFood;
    Cell * player;
    Cell * enemy;
    Cell * bullet;
    bool bulletEnable;
};
#endif // ifndef map_h
