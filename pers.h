#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class person
{
    short armor, healthPoints, basicAttack, attackSpeed, weaponDamage, agility, healingPoints, clan;
    bool alive;
    char typeOfCharacter;


    public:
        person(char p, short k)
        {
            typeOfCharacter=p;
            clan=k;
            srand( (time(0)*1000) + (time(0)/1000) );
            alive=1;
            if(typeOfCharacter=='l')
            {
                armor=60;
                healthPoints=80+rand()%41;
                basicAttack=5+rand()%6;
                attackSpeed=1+rand()%2;
                weaponDamage=10+rand()%11;
                agility=10+rand()%11;
                healingPoints=0;
            }
            else if(typeOfCharacter=='m')
            {
                armor=0;
                healthPoints=40+rand()%121;
                basicAttack=3+rand()%3;
                attackSpeed=1;
                weaponDamage=1+rand()%5;
                agility=5+rand()%6;
                healingPoints=rand()%11;
            }
        }

        person operator+(person opponent)
        {
            if(typeOfCharacter==opponent.typeOfCharacter && clan==opponent.clan)
            // ������ ���� ����� ������ ���� �� ������ �����
            {
                if(typeOfCharacter=='l') // ������ �����
                {
                    agility*=1.1;
                    opponent.agility*=1.1;
                }

                else if(typeOfCharacter=='m') // ������ �����
                {
                    healthPoints*=1.1;
                    opponent.healthPoints*=1.1;
                }
            }
            if(typeOfCharacter!=opponent.typeOfCharacter && clan==opponent.clan)
            // ������ ����� ������ ���� � ������ �����
            {
                if(typeOfCharacter=='l') // ������ �����, � ������ ������
                {
                    healthPoints*=1+(10+rand()%11)/100;
                }

                else if(typeOfCharacter=='m') // ������ ������, � ������ �����
                {
                    opponent.healthPoints*=1+(10+rand()%11)/100;
                }
            }
            if(clan!=opponent.clan) // ���� ���� �� ����� �����
            {
                if(typeOfCharacter==opponent.typeOfCharacter && typeOfCharacter=='l')
                // ���� ������ �����
                {
                    //cout << "healthPoints = " << healthPoints << ", opponent healthPoints = " << opponent.healthPoints << endl;
                    while ( healthPoints>0 && opponent.healthPoints>0 ) {

                        if ( opponent.agility <= rand()%100 ) {
                            opponent.healthPoints -= (basicAttack + weaponDamage) * attackSpeed
                            * (100 - opponent.armor) / 100;
                            if ( opponent.healthPoints<=0 ) {
                                opponent.alive = false;
                                break;
                            }

                        }

                        if ( agility <= rand()%100 ) {
                            healthPoints -= (opponent.basicAttack + opponent.weaponDamage)
                            * opponent.attackSpeed * (100 - armor) / 100;
                            if ( healthPoints<=0 ) {
                                alive = false;
                                break;
                            }

                        }
                    }


                }
            }
        }
};
