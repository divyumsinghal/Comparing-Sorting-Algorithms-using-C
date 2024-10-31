//
// Created by divyu on 24/10/2024.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MaxNumberOfLetters 100
#define MaxNumberOfGames 19000

typedef struct
{
    char title[MaxNumberOfLetters];
    char platform[MaxNumberOfLetters];
    int score;
    int year;
} Game;

int next_field(FILE *csv, char *word, int max_len)
{
    int i = 0;
    char c = fgetc(csv);
    int quotes_are_open = 0;

    while (c != EOF && i < max_len - 1)
    {
        if (c == '"')
        {
            if (quotes_are_open == 0)
                quotes_are_open = 1;
            else
                quotes_are_open = 0;
        }
        else if (c == ',' || c == '\n')
        {
            if (quotes_are_open == 1)
            {
                word[i++] = c;
            }
            else // if quotes_are_open == 0
            {
                break;
            }
        }
        else
        {
            word[i++] = c;
        }

        c = fgetc(csv);
    }

    word[i] = '\0';

    if (c == EOF)
        return -1;

    c = fgetc(csv);

    if (c != '\n')
    {
        ungetc(c, csv);
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

Game game_arr[MaxNumberOfGames];

int main()
{
    printf("Starting \n");

    FILE *csv = fopen("data/t4_ign.csv", "r");

    printf("file loaded \n");

    if (csv == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    // Skip the first line

    char letter = fgetc(csv);

    while (letter != '\n')
    {
        letter = fgetc(csv);
    }


    int game_number = 0;

    printf("looping through data \n");


    while(!feof(csv))
    {
        char word[MaxNumberOfLetters];

        next_field(csv, word, MaxNumberOfLetters);
        strcpy(game_arr[game_number].title, word);

        next_field(csv, word, MaxNumberOfLetters);
        strcpy(game_arr[game_number].platform, word);

        next_field(csv, word, MaxNumberOfLetters);
        game_arr[game_number].score = atoi(word);

        next_field(csv, word, MaxNumberOfLetters);
        game_arr[game_number].year = atoi(word);

        // printf("%d: %s : %s : %d\n", game_arr[game_number].score, game_arr[game_number].title, game_arr[game_number].platform, game_arr[game_number].year);

        game_number++;

    }

    printf("Game sorting \n");

    Sort(game_arr, game_number);

    printf("Game sorted \n");

    for (int i = game_number - 1; i >= game_number - 10 && i >= 0; i--)
        printf("%d: %s : %s : %d\n", game_arr[i].score, game_arr[i].title, game_arr[i].platform, game_arr[i].year);


    fclose(csv);
    return 0;
}
