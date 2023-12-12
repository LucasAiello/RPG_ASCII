#ifndef __NPC__
#define __NPC__
#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Texts : public ObjetoDeJogo
{

    public:

        Texts(const ObjetoDeJogo &obj, std::list<std::string> texts) : ObjetoDeJogo(obj), texts(texts) {}

        std::string getText (int pos) const {
            auto text = texts.begin();
            if (pos < texts.size()){
                for (int i = 0; i < pos; i++) text++;
                
                return (*text);
            }

            return "";
        }

        int getAmountTexts(void) const { return texts.size(); }

    private:

        std::list<std::string> texts;


};

#endif 