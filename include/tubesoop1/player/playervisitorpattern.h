#ifndef PLAYER_VISITORPATTERN_H
#define PLAYER_VISITORPATTERN_H

// Forward declaration to avoid circular dependency. Its normal for visitor pattern
class PlayerElement;
class Petani;
class Peternak;
class Walikota;

// Visitor pattern to avoid dynamic_cast. Needed to decide the action of each player but the only information we know is that the type is Player (base class)
class CommanderVisitor
{
    public:
        void execute(PlayerElement*);
        virtual void execute(Petani*) = 0;
        virtual void execute(Peternak*) = 0;
        virtual void execute(Walikota*) = 0;
};

class PlayerElement
{
    public:
        virtual void executed(CommanderVisitor&) = 0;
};

#endif