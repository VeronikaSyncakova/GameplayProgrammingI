#include <./include/Orc.h>

void Orc::barrelRoll() 
{ 
    std::cout << " {}\n ||\n )(\n|__|\n|  |\n|__|\n" << std::endl; 
}
void Orc::walkIntoFight() { std::cout << "      Orcs be orcking on their way towards victory!" << std::endl; }
void Orc::winMessage() { std::cout << "Orcs make mashed potatoes from their enemies!" << std::endl; }

Type Orc::getType()
{
    return Type::ORC;

}

