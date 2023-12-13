#ifndef __NPC__
#define __NPC__
#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include <iostream>
#include <fstream>

class Texts : public ObjetoDeJogo
{

    public:

        Texts(const ObjetoDeJogo &obj, std::list<std::string> texts) : ObjetoDeJogo(obj), texts(texts) {}
        Texts(const ObjetoDeJogo &obj) : ObjetoDeJogo(obj){}

        std::string getText (int pos) const {
            auto text = texts.begin();
            if (pos < texts.size()){
                for (int i = 0; i < pos; i++) text++;
                
                return (*text);
            }

            return "";
        }

        int getAmountTexts(void) const { return texts.size(); }

        void readfile(std::string str){
            std::ifstream file(str);

            if( file.is_open() )
            {
                while(file)
                {
                    std::string text;
                    std::getline(file, text);
                    texts.push_back(text);
                }
                texts.pop_back();
            }
        }

    private:

        std::list<std::string> texts;


};

#endif 