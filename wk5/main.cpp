// Brian Foster Coding 1 Week 15
// Classes today!

// self-documenting code means the code can only do ONE thing, or be used ONE way.



#include <iostream>
#include <string>
using namespace std;

// classes are custom variable types
// variables
// functions

// constructors
// getters and setters (privacy)
// tamagotchi

class robot {
private:
    // data members
    string name;
    int charge;
    int boredom;

public:
    // constructor, sets up the class with input variables
    // doesn't have a return type, must be named same as class
    robot(string givenName, int givenCharge, int givenBoredom) {
        name = givenName;
        charge = givenCharge;
        boredom = givenBoredom;
        status();
    }

    // default constructor
    robot() {
        name = "Rob";
        charge = 10;
        boredom = 10;
        status();
    }

    // member functions
    void status() {
        cout << "Hello, my name is " << name;
        cout << " and my charge is " << charge << ".\n";
        cout << "I am ";        // start the sentence

        if(boredom < 5) cout << "happy";
        else if(boredom < 10) cout << "bored";
        else if(boredom < 15) cout << "frustrated";
        else cout << "ENRAGED";

        cout << ".\n";          // end the sentence
    }

    // Getters
    string getName() {
        return name;
    }

    int getCharge() {
        return charge;
    }

    int getBoredom() {
        return boredom;
    }

    // Setters
    void setName(string givenName) {
        if(givenName.size() <= 5) {
            name = givenName;
        }
        else {
            cout << "error: " << givenName << " is too long.\n";
        }
        
    }

    void setCharge(int givenCharge) {
        // clamp charge to between 0 and 100
        if(givenCharge < 0) charge = 0;         // floor is 0
        else if(givenCharge > 100) charge = 100;    // ceiling is 100
        else charge = givenCharge;
    }

    void setBoredom(int givenBoredom) {
        if(givenBoredom > 20) boredom = 20;     // clamp max to ceiling of 20.
        boredom = givenBoredom;
    }

    // get AND set at the same time.
    void changeChargeBy(int amount = 1) {
        setCharge(charge += amount);
    }

}; // end of robot class


int main() {
    cout << "Classes!\n";

    // create our first instance of a robot.
    robot artoo("R2-D2", 45, 3);    // using a constructor to set the values.
    // artoo.name = "R2-D2";       // dot syntax goes from large to small
    // artoo.charge = 45;    
    // artoo.boredom = 3;      
    cout << "Artoo has " << artoo.getName().size() << " characters in their name.\n";           

    robot threepio;                     // default constructor is being run here
    threepio.setName("C-3P0");          // using the setter
    threepio.setCharge(2);
    threepio.setBoredom(12);

    artoo.status();
    threepio.status();

    cout << "Threepio has low battery, let's have artoo charge him up!\n";

    while(threepio.getCharge() < 15) {
        if(artoo.getCharge() > 0) {
            artoo.changeChargeBy(-1);       // subtract 1 from artoo's charge
            threepio.changeChargeBy(1);     // add 1 to threepio;s charge.
        }
        else {
            cout << "Artoo is out of energy!\n";
            break;
        }
        
    }

    artoo.status();
    threepio.status();

    robot ted;
    robot fourthRobot;

    vector<robot> bots;

    robot rob("Rob", 10, 0);

    int = 12;

    return 0;
}