#include <iostream>
#include <string>
#include <vector>

class Room {
public:
    Room(const std::string& description) : description_(description) {}
    virtual ~Room() {}

    virtual void enter() {
        std::cout << "You are in a " << description_ << ".\n";
    }

private:
    std::string description_;
};

class TreasureRoom : public Room {
public:
    TreasureRoom() : Room("Treasure Room") {}

    void enter() override {
        std::cout << "You found a chest full of gold!\n";
    }
};

class EnemyRoom : public Room {
public:
    EnemyRoom() : Room("Enemy Room") {}

    void enter() override {
        std::cout << "A fierce dragon attacks you!\n";
    }
};

class Player {
public:
    void moveTo(Room* newRoom) {
        currentRoom_ = newRoom;
        currentRoom_->enter();
    }

private:
    Room* currentRoom_;
};

int main() {
    Room regularRoom("Regular Room");
    TreasureRoom treasureRoom;
    EnemyRoom enemyRoom;

    Player player;
    player.moveTo(&regularRoom);
    player.moveTo(&treasureRoom);
    player.moveTo(&enemyRoom);

    return 0;
}
