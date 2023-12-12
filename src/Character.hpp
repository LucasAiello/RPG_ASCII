#ifndef __CHARACTER__
#define __CHARACTER__

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Character : public ObjetoDeJogo
{

    public:

        Character(const ObjetoDeJogo &obj, int life, unsigned p_atk, unsigned m_atk, unsigned p_def, unsigned m_def) : ObjetoDeJogo(obj), life(life), physical_attack(p_atk), magic_attack(m_atk), physical_defense(p_def), magic_defense(m_def) {}

        virtual int Attack (Character *const target, int damage, int type)
        {
            (type == 0)? damage += physical_attack : damage += magic_attack; 
            return (target->receiveDamage(damage, type));
        }

        virtual int receiveDamage (int damage, int type)
        {
            (type == 0)? damage -= physical_defense : damage -= magic_defense;
            if (damage < 10) damage = 10;
            life -= damage;
            return damage;
        }

        bool isAlive (void) const { return (this->life > 0); }

        unsigned getPhysical_Atk(void) const { return physical_attack; }
        unsigned getPhysical_Def(void) const { return physical_defense; }
        unsigned getMagic_Atk(void) const { return magic_attack; }
        unsigned getMagic_Def(void) const { return magic_defense; }
        unsigned getLife(void) const { return life; }

    protected:

        int life;
        unsigned physical_attack;
        unsigned magic_attack;
        unsigned physical_defense;
        unsigned magic_defense;

};


#endif