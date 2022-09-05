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
};


