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

int next_field(FILE* csv, char* word, int max_len)
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


Game game_arr[11][MaxNumberOfGames];
int game_number[11] = {0};

int main()
{
	printf("Starting \n");

	FILE* csv = fopen("data/t4_ign.csv", "r");

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


	printf("looping through data \n");

	Game Buffer;


	while (!feof(csv))
	{
		char word[MaxNumberOfLetters];

		next_field(csv, word, MaxNumberOfLetters);
		strcpy(Buffer.title, word);

		next_field(csv, word, MaxNumberOfLetters);
		strcpy(Buffer.platform, word);

		next_field(csv, word, MaxNumberOfLetters);
		Buffer.score = atoi(word);

		next_field(csv, word, MaxNumberOfLetters);
		Buffer.year = atoi(word);

		// printf("%d: %s : %s : %d\n", game_arr[game_number].score, game_arr[game_number].title, game_arr[game_number].platform, game_arr[game_number].year);

		game_arr[Buffer.score][game_number[Buffer.score]] = Buffer;


		game_number[Buffer.score]++;

	}

	printf("Game sorted \n");

	for (int i = game_number[10] - 1; i >= game_number[10] - 10 && i >= 0; i--)
		printf("%d: %s : %s : %d\n", game_arr[10][i].score, game_arr[10][i].title, game_arr[10][i].platform, game_arr[10][i].year);


	fclose(csv);
	return 0;
}
