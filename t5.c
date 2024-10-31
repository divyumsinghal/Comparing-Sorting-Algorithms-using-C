//
// Created by divyu on 24/10/2024.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxNumberOfLetters 100
#define MaxNumberOfGames 19000
#define minYear 1996
#define yearSize 21

typedef struct {
    char title[MaxNumberOfLetters];
    char platform[MaxNumberOfLetters];
    int score;
    int year;
} Game;

int next_field(FILE *csv, char *word, int max_len) {
    int i = 0;
    char c = fgetc(csv);
    int quotes_are_open = 0;

    while (c != EOF && i < max_len - 1) {
        if (c == '"') {
            quotes_are_open = !quotes_are_open;
        }
        else if ((c == ',' || c == '\n') && !quotes_are_open) {
            break;
        }
        else {
            word[i++] = c;
        }
        c = fgetc(csv);
    }

    word[i] = '\0';

    if (c == EOF)
        return -1;

    if (c != '\n') {
        c = fgetc(csv);
        if (c != '\n') {
            ungetc(c, csv);
        }
    }

    return i;
}

int partition(Game arr[], int low, int high) {
	const int pivot = arr[high].score;
	int i = (low - 1);

	for (int j = low; j < high; j++) {
		if (arr[j].score < pivot) {
			i++;
			Game temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	Game temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;

	return (i + 1);
}


void quickSortrecursive(Game arr[], int p, int r) {
	if (p < r) {
		int q = partition(arr, p, r);
		quickSortrecursive(arr, p, q - 1);
		quickSortrecursive(arr, q + 1, r);
	}

}


void Sort(Game arr[], int size)
{
	quickSortrecursive(arr, 0, size - 1);
}

void selectionSort(Game arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].score < arr[min_idx].score) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            Game temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

Game game_arr[MaxNumberOfGames];
Game game_year[yearSize][MaxNumberOfGames];
int game_number_yearly[yearSize] = {0};
int game_number = 0;

int main() {
    printf("Starting \n");
    FILE *csv = fopen("data/t4_ign.csv", "r");

    if (csv == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    printf("File loaded \n");

    char letter;
    while ((letter = fgetc(csv)) != '\n' && letter != EOF) {}

    printf("Looping through data \n");

    while (!feof(csv) && game_number < MaxNumberOfGames) {
        char word[MaxNumberOfLetters];
        if (next_field(csv, word, MaxNumberOfLetters) == -1)
            break;
        strcpy(game_arr[game_number].title, word);

        next_field(csv, word, MaxNumberOfLetters);
        strcpy(game_arr[game_number].platform, word);

        next_field(csv, word, MaxNumberOfLetters);
        game_arr[game_number].score = atoi(word);

        next_field(csv, word, MaxNumberOfLetters);
        game_arr[game_number].year = atoi(word);

        int year_index = game_arr[game_number].year - minYear;

        if (year_index >= 0 && year_index < yearSize) {
            game_year[year_index][game_number_yearly[year_index]] = game_arr[game_number];
            game_number_yearly[year_index]++;
        }
        else if (year_index < 0 )
        {
            printf("error! %d", game_arr[game_number].year);
        }
        else if (year_index >= yearSize )
        {
            printf("error! 2");
        }

        game_number++;
    }

    printf("Game sorting \n");
    Sort(game_arr, game_number);

    for (int i = 0; i < yearSize; i++) {
        selectionSort(game_year[i], game_number_yearly[i]);
    }

    printf("Games sorted \n");

    for (int i = game_number - 1; i >= game_number - 10 && i >= 0; i--)
        printf("%d: %s : %s : %d\n", game_arr[i].score, game_arr[i].title, game_arr[i].platform, game_arr[i].year);

    printf("\nGames sorted by year:\n");


     for (int year = 0; year < yearSize; year++) {
        if (game_number_yearly[year] > 0) {
            printf("\nYear %d:\n", year + minYear);
            for (int j = game_number_yearly[year] - 1; j >= game_number_yearly[year]  - 5 & j >= 0; j--) {
                printf("%d: %s : %s : %d\n",
                    game_year[year][j].score,
                    game_year[year][j].title,
                    game_year[year][j].platform,
                    game_year[year][j].year);
            }
        }
        else {
            printf("\nYear %d: has no games?? \n", year + minYear);
        }
    }

    printf("\nTotal games processed: %d\n", game_number);
    fclose(csv);
    return 0;
}