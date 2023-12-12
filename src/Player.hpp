#ifndef __PLAYER__
#define __PLAYER__
#include "Character.hpp"
#include "Key.hpp"

class Player : public Character
{

    public:

        Player(const Character &chara) : Character(chara), count_keys(0) {}
        //void setKey(Key *key);
        //void removeKey(std::string location);

    private:
        Key *keys[3];
        int count_keys;

};

#endif