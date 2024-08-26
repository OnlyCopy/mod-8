#include <iostream>
#include <string>
#include <cstdlib>  // For random numbers
#include <ctime>    // For seeding random numbers

// Base class for all characters
class Character {
public:
    std::string name;
    int health;

    Character() : health(100) {} // Initialize health to 100

    virtual void useSkill(Character& enemy) {
        std::cout << "Using skill of a generic character.\n";
    }

    bool isAlive() const {
        return health > 0;
    }
};

// Derived class for Warrior
class Warrior : public Character {
public:
    Warrior() {
        name = "Warrior";
    }

    void useSkill(Character& enemy) override {
        int damage = 20;
        std::cout << name << " uses Slash Attack and deals " << damage << " damage!\n";
        enemy.health -= damage;
    }
};

// Derived class for Mage
class Mage : public Character {
public:
    Mage() {
        name = "Mage";
    }

    void useSkill(Character& enemy) override {
        int damage = 25;
        std::cout << name << " casts Fireball and deals " << damage << " damage!\n";
        enemy.health -= damage;
    }
};

// Derived class for Archer
class Archer : public Character {
public:
    Archer() {
        name = "Archer";
    }

    void useSkill(Character& enemy) override {
        int damage = 15;
        std::cout << name << " shoots an Arrow and deals " << damage << " damage!\n";
        enemy.health -= damage;
    }
};

// Derived class for Thief
class Thief : public Character {
public:
    Thief() {
        name = "Thief";
    }

    void useSkill(Character& enemy) override {
        int damage = 10;
        std::cout << name << " performs a Stealth Attack and deals " << damage << " damage!\n";
        enemy.health -= damage;
    }
};

// Derived class for Mimic
class Mimic : public Character {
public:
    Mimic() {
        name = "Mimic";
    }

    void useSkill(Character& enemy) override {
        int damage = 18;
        std::cout << name << " mimics the last used skill and deals " << damage << " damage!\n";
        enemy.health -= damage;
    }
};

// Function for enemy attack
void enemyAttack(Character& player) {
    int damage = 15; // Enemy deals a fixed amount of damage
    std::cout << "Enemy attacks and deals " << damage << " damage!\n";
    player.health -= damage;
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed for random numbers

    std::cout << "Welcome to Bloodsport Arcade..\n";
    std::cout << "Please select a character: \n";
    std::cout << "1. Warrior\n";
    std::cout << "2. Mage\n";
    std::cout << "3. Archer\n";
    std::cout << "4. Thief\n";
    std::cout << "5. Mimic\n";

    int choice;
    std::cout << "Enter the number of your choice: ";
    std::cin >> choice;

    Character* player = nullptr;

    // Create the chosen character
    switch (choice) {
    case 1:
        player = new Warrior();
        break;
    case 2:
        player = new Mage();
        break;
    case 3:
        player = new Archer();
        break;
    case 4:
        player = new Thief();
        break;
    case 5:
        player = new Mimic();
        break;
    default:
        std::cout << "Invalid choice. Please restart the game and choose a valid character.\n";
        return 0;
    }

    std::cout << "You have chosen the " << player->name << ".\n";

    // Initialize enemy
    Character enemy;
    enemy.name = "Enemy";
    enemy.health = 80; // Enemy starts with 80 health points

    // Game loop
    while (player->isAlive() && enemy.isAlive()) {
        // Player's turn
        std::cout << "\nYour turn:\n";
        player->useSkill(enemy);

        // Check if enemy is defeated
        if (!enemy.isAlive()) {
            std::cout << "You have defeated the enemy!\n";
            break;
        }

        // Enemy's turn
        std::cout << "\nEnemy's turn:\n";
        enemyAttack(*player);

        // Check if player is defeated
        if (!player->isAlive()) {
            std::cout << "You have been defeated by the enemy...\n";
            break;
        }

        // Display health status
        std::cout << "\nYour health: " << player->health << "\n";
        std::cout << "Enemy health: " << enemy.health << "\n";
    }

    // Clean up dynamic memory
    delete player;

    return 0;
}
