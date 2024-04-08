#ifndef PLAYER_VISITORPATTERN_H
#define PLAYER_VISITORPATTERN_H

// Forward declaration to avoid circular dependency. Its normal for visitor pattern
class Player;
class Petani;
class Peternak;
class Walikota;

// Visitor pattern to avoid dynamic_cast. Needed to decide the action of each player but the only information we know is that the type is Player (base class)
// Derived classes of Command will override only one of the following options:
// 1. void execute(Player*);
// 2. void execute(Petani*), void execute(Peternak*), void execute(Walikota*);
class CommanderVisitor
{
    public:
        virtual void execute(Player*) = 0; // Command overrides this. If derived classes of Command overrides this, that means the argument type doesn't matter.
        virtual void execute(Petani*) = 0;        // Derived classes override this.
        virtual void execute(Peternak*) = 0;      // Derived classes override this.
        virtual void execute(Walikota*) = 0;      // Derived classes override this.
};

class PlayerElement
{
    public:
        virtual void executed(CommanderVisitor&) = 0;
};

#endif