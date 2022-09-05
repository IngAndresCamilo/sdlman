#include "SdlmanDataStructure.h"


ColorsNode* ColorsList::AddColor(const char *name, int r, int g, int b) {
	ColorsNode* ptr = this->head;
	ColorsNode* new_color = new colornode_t{name, H(r), H(g), H(b), NULL};

	for (; ptr->next != nullptr; ptr = ptr->next) {}

	ptr->next = new_color;
	this->counter;

	return new_color;
}

void ColorsList::PrintColors() {
	ColorsNode* node = this->head;

	for (; node != nullptr; node = node->next) {
		printf("%s = (%d, %d, %d)\n", node->name, node->R, node->G, node->B);
	}
}

void ColorsList::GetDefautColors() {
	this->AddColor("BLACK", 0, 0, 0);
	this->AddColor("RED", 245, 25, 55);
	this->AddColor("GREEN", 49, 232, 122);
	this->AddColor("BLUE", 52, 52, 222);
	this->AddColor("PURPLE", 182, 40, 210);
}


ColorsNode* ColorsList::GetColor(const char* color_name) {
	ColorsNode* node = this->head;

	for (; node != nullptr; node = node->next) {
		if (!strcmp(node->name, color_name)) {
			return node;
		}
	}

	return nullptr;
}