#include "Source.h"

int main() {
	int map_width, map_height, movements_quantity,
		xpos, ypos, caterpillar_length, i, j, dx = 1, dy = 0;
	char **map, *cursor, letter;
	bool is_dead = false;
	scanf("%d %d %d", &map_width, &map_height, &movements_quantity);
	scanf("%d %d %d", &xpos, &ypos, &caterpillar_length);
	getchar();
	letter = fgetc(stdin);

	ListElement *head = create_node(letter);
	ListElement *tail = head;
	for (i = 0; i < caterpillar_length - 1; i++) {
		scanf("%c", &letter);
		add_node_back(letter, tail);
	}
	getchar();
	map = new char *[map_height];
	for (i = 0; i < map_height; i++) {
		map[i] = new char[map_width + 1];
	}
	for (i = 0; i < map_height; i++) {
		fgets(map[i], map_width + 1, stdin);
		getchar();
	}

	for (i = 0; i < movements_quantity; i++) {

		if (xpos < 1) xpos = map_width;
		else if (xpos > map_width) xpos = 1;
		if (ypos < 1) ypos = map_height;
		else if (ypos > map_height) ypos = 1;
		cursor = &map[ypos - 1][xpos - 1];

		if ((*cursor) >= 'A' && (*cursor) != '`') {
			if ((*cursor) >= 'a') {
				add_node_front(*cursor, head);
				(*cursor)--;
			}
			else
			{
				add_node_back(*cursor, tail);
				(*cursor)--;
			}
		}
		else if ((*cursor) == '`') {
			remove_node_front(head, is_dead);
		}
		else if ((*cursor) == '@') {
			remove_node_back(tail, is_dead);
		}
		else if ((*cursor) == '1') {
			dx = 0;
			dy = -1;
		}
		else if ((*cursor) == '2') {
			dx = 0;
			dy = 1;
		}
		else if ((*cursor) == '3') {
			dx = -1;
			dy = 0;
		}
		else if ((*cursor) == '4') {
			dx = 1;
			dy = 0;
		}

		xpos += dx;
		ypos += dy;
		if (is_dead) break;
	}
	xpos -= dx;
	ypos -= dy;
	printf("%d %d ", xpos, ypos);
	if (!is_dead) {
		print_list(head);
		free_list(head);
	}
	else printf("#");

	printf("\n");
	for (i = 0; i < map_height; i++) {
		for (j = 0; j < map_width; j++) {
			if (map[i][j] == '`') map[i][j] = '@';
		}
		printf("%s\n", map[i]);
	}

	for (i = 0; i < map_height; i++) delete[] map[i];
	delete[] map;

	return 0;
}