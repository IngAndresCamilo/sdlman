#pragma once
#include "includes.h"

#define H(n) (Uint8)n // casting an integer into base 16


typedef struct ColorsNode {
	const char* name;
	Uint8 R;
	Uint8 G;
	Uint8 B;

	ColorsNode* next;

} colornode_t;

class ColorsList {
public:
	ColorsNode* head;
	int counter = 0;

	ColorsList() {
		this->head = new colornode_t{ "WHITE",  H(255),  H(255), H(255), nullptr };
		this->counter++;
	}

	~ColorsList() {
		ColorsNode* tmp = nullptr;

		while (this->head != nullptr) {
			tmp = this->head;
			this->head = this->head->next;
			free(tmp);
		}
	}

	ColorsNode* AddColor(const char *name, int r, int g, int b);
	void PrintColors();
	void GetDefautColors();
	ColorsNode* GetColor(const char *color_name);
	//void Delete(int idx);
};



class Surfaces {
public:
	std::vector<std::pair<char*, SDL_Surface*>> surfaces;

	Surfaces() {
		this->surfaces = std::vector<std::pair<char*, SDL_Surface*>>();
	}

	// add a new surface
	void Add(char* name, SDL_Surface* surface);
	// get the surface by name
	SDL_Surface* GetSurface(char* name);
	// free surface list
	~Surfaces() {
		printf("Freeing memory allocated for surfaces...\n\n");
		for (std::pair<char*, SDL_Surface*> p : this->surfaces) {
			SDL_FreeSurface(p.second);
			printf("\t- %s DELETED\n\n", p.first);
		}
	}
};
