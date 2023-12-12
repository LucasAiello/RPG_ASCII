#include  "Map.hpp"

bool Map::colideComBloco() const
{
	for (auto it = colisons.begin() ; it != colisons.end() ; ++it)
		if (player->colideCom(**it)) {
			return true;
		}

	return false;
}

void Map::showText(unsigned l, unsigned c)
{
	for (auto it = texts.begin() ; it != texts.end() ; ++it)
		if (player->colideCom(**it)) {
			player->moveTo(l,c);
			int amount_texts = (*it)->getAmountTexts();
			dialogue_box->ativarObj();
			text->ativarObj();
			for (int i = 0; i < amount_texts; i++){
				int text_size = ((*it)->getText(i)).size();
				*text = ObjetoDeJogo("Text", TextSprite((*it)->getText(i)), 45, (100-text_size/2));
				update();
				draw(screen);
				system("cls");
				show(screen);
				getch();
			}
		}
	text->desativarObj();
	dialogue_box->desativarObj();
}

Character& Map::getEnemy(int i)
{	
	int cont = 0;
	for (auto it = enemies.begin() ; it != enemies.end() ; ++it, cont++){
		if (cont == i) return *(it);
	}
	exit(0);
}