#include <ctime>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;
/* Game with 4 different types of creatures: humans, cyberdemons, balrogs, and elves. We will be simulating a match between them */
/* Rules */
/* 1 - Every creature inflicts damage that is a random number r, where 0 < r <= strength */
/* 2 - Balrogs, and Cyberdemons have a 5% chance of inflicting a demonic attack, which is an additional 50 damage points */
/* 3 - Elves have a 10% chance to inflict a magical attack that doubles the normal amount of damange */




class Creature {
protected:
    string description;
    int strength; // How much maximum damage can the creature inflict
    int hitpoints; // How much damage can it sustain before dying
    int damagesustained; // Records the damage sustained by the creature. Starts out with zero. Creature dies when damagesustained >= hitpoints
public:
    Creature() : description{"No Description"}, strength{0}, hitpoints{0}, damagesustained{0} {}
    Creature(string description, int strength, int hitpoints, int damagesustained) : description{description}, strength{strength}, hitpoints{hitpoints}, damagesustained{damagesustained} {}
    string getDescription() {return description;}
    int getDamagesustained() {return damagesustained;}
    int setDamagesustained(int d)  {damagesustained = d;} 
    virtual int attack()=0; // Creature attacks. Each dervied class will implement the appropriate attack
    
};

// To do - Code up Humans, Cyberdemons, Balrogs, and Elves classes all derived from Creature class with appropriate attack() methods
// You can put all the code in this one file for this assignment.

class Humans : public Creature { //Derived Humans class
    private: 
        int humanDamage;
    public:
        Humans() : Creature() {}
        Humans(string description, int strength, int hitpoints, int damagesustained) : Creature{description, strength, hitpoints, damagesustained} {}
        virtual int attack();
};

class Cyberdemons : public Creature { //Derived Cyberdemons class
    private:
        int cyberdemonDamage;
    public:
        Cyberdemons() : Creature() {}
        Cyberdemons(string description, int strength, int hitpoints, int damagesustained) : Creature{description, strength, hitpoints, damagesustained} {}
        virtual int attack();
};

class Balrogs : public Creature { //Derived Balrogs class
    private:
        int balrogDamage;
    public:
        Balrogs() : Creature() {}
        Balrogs(string description, int strength, int hitpoints, int damagesustained) : Creature{description, strength, hitpoints, damagesustained} {}
        virtual int attack();
};

class Elves : public Creature { //Derived Elves class
    private:
        int elfDamage;
    public:
        Elves() : Creature() {}
        Elves(string description, int strength, int hitpoints, int damagesustained) : Creature{description, strength, hitpoints, damagesustained} {}
        virtual int attack();
};

string match(Creature* c1, Creature* c2);

int main()
{
    srand(time(0)); //Randomizes the rand integers based off of time
    Humans* hum = new Humans("human", 100, 100, 0); // Description, strength, hitpoints
    Cyberdemons* cyb = new Cyberdemons("cyberdemon", 200, 100, 0);
    Balrogs* bal = new Balrogs("balrog", 50, 200, 0);
    Elves* elv = new Elves("elves", 200, 200, 0);
    cout << "And the winner between humans and cyberdemons is... " << match(hum, cyb) << endl;
    cout << "And the winner between balrogs and elves is... " << match(bal, elv) << endl;
    cout << "And the winner between cyberdemons and balrogs is... " << match(cyb, bal) << endl;
    
    return 0;
}



string match(Creature* c1, Creature* c2)
{
    // Round 1
    c2->setDamagesustained(c1->attack()); //Assigns the damage from c1 to c2
    c1->setDamagesustained(c2->attack());

    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Sleep for a second
    
    // Round 2
    c2->setDamagesustained(c1->attack()); //Assigns the damage from c1 to c2
    c1->setDamagesustained(c2->attack());

    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // Sleep for a second
    
    // Round 3
    c2->setDamagesustained(c1->attack()); //Assigns the damage from c1 to c2
    c1->setDamagesustained(c2->attack());
    
    
    // Winner! Whoever has more health or has sustained less damage
    if (c1->getDamagesustained() <= c2->getDamagesustained())
        return c1->getDescription();
    else
        return c2->getDescription();
    
}

int Humans::attack(){ //Human attack
    humanDamage = 0;
    humanDamage = (rand() % strength);
    return humanDamage;
}
int Cyberdemons::attack(){ //Cyberdemon attack 
    cyberdemonDamage = 0;
    cyberdemonDamage = (rand() % strength);
    int extraDamage = (rand() % 100) + 1; //Determines if the attack power is increased by 50
    if(extraDamage <= 5){
        cyberdemonDamage = cyberdemonDamage + 50;
}
return cyberdemonDamage;
}

int Balrogs::attack(){ //Balrog attack
    balrogDamage = 0;
    balrogDamage = (rand() % strength);
    int extraDamage = (rand() % 100) + 1; //Determines if the attack power is increased by 50
    if(extraDamage <= 5){
        balrogDamage = balrogDamage + 50;
}
return balrogDamage;
}

int Elves::attack(){ //Elf attack
    elfDamage = 0;
    elfDamage = (rand() % strength);
    int extraDamage = (rand() % 100) + 1; //Determines if the attack power is doubled
    if(extraDamage <= 10){
        elfDamage = elfDamage * 2;
}
return elfDamage;
}