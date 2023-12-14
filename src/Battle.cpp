#include "Battle.hpp"
#include <string>
#include <random>
#include <chrono>
unsigned seed_battle = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine generator_battle(seed_battle);
std::uniform_int_distribution<int> probability_escape(0,100);
std::uniform_int_distribution<int> type_attack(0,1);

void Battle::init()
{   
    life_value = new ObjetoDeJogo("Life Value", TextSprite("VIDA: "), 2, 14);
    objs.push_back(life_value);

    enemies[0] = new Character(ObjetoDeJogo("Cat", SpriteAnimado("../rsc/Sprites/sprite_cat.anm"), 20, 45), 50, 60, 20, 60, 20);
    objs.push_back(enemies[0]);

    enemies[1] = new Character(ObjetoDeJogo("Cat", SpriteAnimado("../rsc/Sprites/sprite_cat.anm"), 20, 45), 50, 60, 20, 60, 20);
    objs.push_back(enemies[1]);

    menu = new ObjetoDeJogo("Battle Menu", Sprite("../rsc/Sprites/sprite_battle_menu.spr"), 38, 30);
    objs.push_back(menu);
    option_menu = new ObjetoDeJogo("Battle Menu", Sprite("../rsc/Sprites/sprite_option_menu.spr"), 45, 44);
    objs.push_back(option_menu);

    option_enemy = new ObjetoDeJogo("Option Enemy", Sprite("../rsc/Sprites/sprite_option_enemy.spr"), 11, 58);
    objs.push_back(option_enemy);

    dialogue_box = new ObjetoDeJogo("Dialogue Box", Sprite("../rsc/Sprites/sprite_dialogue_box.spr"), 41, 20);
	objs.push_back(dialogue_box);
	dialogue_box->desativarObj();

	text = new ObjetoDeJogo("Text", TextSprite(""), 45, 92);
	objs.push_back(text);
	text->desativarObj();
}

unsigned Battle::run()
{   
    int key = 0;
    option = 0;
    value_option_enemy = 0;

    *life_value = ObjetoDeJogo("Life Value", TextSprite("VIDA: " + std::to_string(player->getLife())), 2, 14);

    option_menu->moveTo(45, (46 + 46*option - 7*option +5*option%2));
    option_enemy->moveTo(4, value_option_enemy*50 + 65);

    enemies[0]->moveTo(30 - (enemies[0]->getSprite()->getAltura()), 45);
    enemies[1]->moveTo(30 - (enemies[1]->getSprite()->getAltura()), 100);
    option_enemy->desativarObj();

    showText(enemies[0]->getName() + " e " + enemies[1]->getName() + " apareceram!");

    while(true){
        *life_value = ObjetoDeJogo("Life Value", TextSprite("VIDA: " + std::to_string(player->getLife())), 2, 14);

        key = getch();
        
        if(key == KEY_RIGHT)
        {
            ++option %= 3;
        }
        else if (key == KEY_LEFT)
        {
            (option-1 < 0)? option = 2 : option--;
        }
        else if(key == KEY_X)
        {
            if(option == 0 || option == 1)
            {
                option_enemy->ativarObj();
                clearScreen();
                while (true){
                    key = getch();
                    if(key == KEY_X)
                    {
                        if(enemies[value_option_enemy]->isAlive())
                        {
                            resolveAttack(enemies[value_option_enemy], option);
                            break;
                        }
                    }
                    if(key == KEY_RIGHT)
                    {
                        ++value_option_enemy %= 2;
                    }
                    else if (key == KEY_LEFT)
                    {
                        (value_option_enemy-1 < 0)? value_option_enemy = 1 : value_option_enemy--;
                    }
                    else if(key == KEY_Q) break;
                    option_enemy->moveTo(4, value_option_enemy*50 + 65);
                    clearScreen();
                }
                option_enemy->desativarObj();
            }
            else if(option == 2)
            {
                if (probability_escape(generator_battle) < 60)
                {
                    showText("Escapou sem problemas.");
                    return 1;
                }
                else showText("Nao pode fugir!");
            }
        }
        for(int i = 0; i < 2; i++)
        {
            if(!enemies[i]->isAlive()) enemies[i]->desativarObj();
        }

        if(!enemies[0]->isAlive() && !enemies[1]->isAlive()) return 1;
        if(!player->isAlive()) return GAME_OVER;

        option_menu->moveTo(45, (46 + 46*option - 7*option +5*option%2));

        clearScreen();
    }

    return OPENING;
}

void Battle::showText(std::string t)
{   int key = 0;
    option_menu->desativarObj();
    menu->desativarObj();
	dialogue_box->ativarObj();
    text->ativarObj();
	int text_size = t.size();
	*text = ObjetoDeJogo("Text", TextSprite(t), 45, (100-text_size/2));
    clearScreen();
    key = getch();
    menu->ativarObj();
    option_menu->ativarObj();
	text->desativarObj();
	dialogue_box->desativarObj();
}

void Battle::setEnemy(const Character &enemy1, const Character &enemy2)
{
    *enemies[0] = enemy1;
    *enemies[1] = enemy2;
}

void Battle::resolveAttack(Character *const target, int type)
{
    showText("Voce atacou " + target->getName() + "!!");
    showText("Tirou " + std::to_string(player->Attack(target, 50, type)) + " de dano!!");
    for (int i = 0; i < 2; i++)
    {
        if(enemies[i]->isAlive())
        {   
            showText(enemies[i]->getName() + " atacou!!");
            showText("Tirou " + std::to_string(enemies[i]->Attack(player, 10, type_attack(generator_battle))) + " de dano!!");
        }
    }
}