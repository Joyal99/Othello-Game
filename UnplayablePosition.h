#ifndef UNPLAYABLE_POSITION_H
#define UNPLAYABLE_POSITION_H

#include "Position.h"

class UnplayablePosition : public Position {
public:
    UnplayablePosition(int row, int col);
    bool canPlay() const override;
};

#endif // UNPLAYABLE_POSITION_H