#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    Position(int row, int col);

    char getDisc() const;
    void updateDisc(char newDisc);
    virtual bool canPlay() const;

private:
    int row;
    int col;
    char disc;
};

#endif // POSITION_H