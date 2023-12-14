#ifndef __PLAYER__
#define __PLAYER__
#include "Character.hpp"
#include "Key.hpp"

class Player : public Character
{

    public:

        Player(const Character &chara) : Character(chara), small_key(false), big_key(false) {}
        void setLife(unsigned life)
        {
            (life > 500)? this->life = 500 : this->life = life;
        }
        void setSmallKey(){ small_key = true; }
        bool getSmallKey(){ return small_key; }
        void setBigKey(){ big_key = true; }
        bool getBigKey(){ return big_key; }
        //void removeKey(std::string location);

    private:
        bool small_key;
        bool big_key;

};

#endif