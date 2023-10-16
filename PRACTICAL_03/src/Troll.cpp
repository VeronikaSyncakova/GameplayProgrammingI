#include <./include/Troll.h>

void Troll::winMessage() { std::cout << "Trolls dont get trolled!" << std::endl; }
void Troll::walkIntoFight() { std::cout << "     Trolls be trolling on their way towards victory!" << std::endl; }
void Troll::motivation()
{
    std::string array[]={"It's not the size of the dog in the fight, it's the size of the fight in the dog.",
    "If you can't go back to your mother's womb, you'd better learn to be a good fighter.", 
    "You must not fight too often with one enemy, or you will teach him all your art of war."};
    int quote;
    quote=(rand()%3);
    std::cout<<array[quote]<<"\n";
    
}

Type Troll::getType()
{
    return Type::TROLL;
}