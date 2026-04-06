#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void setColor(int color)
{
#ifdef _WIN32
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#endif
}
void showTitle()
{
    printf("====================================\n");
    printf("       GUESS THE NUMBER GAME        \n");
    printf("====================================\n");
}

void loading()
{
    printf("Starting Game");
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        fflush(stdout);
#ifdef _WIN32
        Sleep(500);
#else
        sleep(1);
#endif
    }
    printf("\n");
}


int main()
{
    int choice;

    while (1)
    {
        clearScreen();
        showTitle();

        printf("1. Play Game\n");
        printf("2. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 2)
        {
            printf("Good bye!\n");
            return 0;
        }
        else if (choice != 1)
        {
            printf("Invalid choice! Press Enter...");
            getchar();
            getchar();
            continue;
        }

        int play_Again = 1;

        while (play_Again)
        {
            clearScreen();
            showTitle();
            loading();

            int number, guess;
            int attempts = 0;
            int max_Attempts = 0;
            int difficulty, range;
            int history[100], i = 0;
            time_t start, end;
            double time_taken;
            int best_Score = 9999;
            FILE *file = fopen("high score.txt", "r");
            if (file != NULL)
            {
                fscanf(file, "%d", &best_Score);
                fclose(file);
            }
            printf("\n Best Score (least attempts): %d\n", best_Score);
            printf("\n Select Difficulty:\n");
            printf("1. Easy (1-10)\n");
            printf("2. Medium (1-50)\n");
            printf("3. Hard (1-100)\n");
            printf("Enter choice: ");
            scanf("%d", &difficulty);
            switch (difficulty)
            {
            case 1:
                range = 10;
                max_Attempts = 5;
                break;
            case 2:
                range = 50;
                max_Attempts = 7;
                break;
            case 3:
                range = 100;
                max_Attempts = 10;
                break;
            default:
                range = 50;
                max_Attempts = 7;
            }
            srand(time(0));
            number = rand() % range + 1;
            printf("\nGuess the number between 1 and %d\n", range);
            start = time(0);
            while (attempts < max_Attempts)
            {
                printf("\n------------------------------------\n");
                printf("Enter your guess: ");
                scanf("%d", &guess);
                history[i++] = guess;
                attempts++;
                int diff = abs(number - guess);
                if (guess == number)
                {
                    setColor(10);
                    printf("\nCorrect! You guessed in %d attempts\n", attempts);
                    setColor(7);
                    if (attempts < best_Score)
                    {
                        printf("New High Score!\n");
                        FILE *file = fopen("high score.txt", "w");
                        if (file != NULL)
                        {
                            fprintf(file, "%d", attempts);
                            fclose(file);
                        }
                    }
                    break;
                }
                else if (guess > number)
                {
                    setColor(12);
                    printf("Too High!\n");
                }
                else
                {
                    setColor(12);
                    printf("Too Low!\n");
                }
                setColor(7);
                setColor(14);
                if (diff <= 3)
                    printf("Very Hot!\n");
                else if (diff <= 10)
                    printf("Warm\n");
                else
                    printf("Cold\n");
                setColor(7);
                printf("Attempts left: %d\n", max_Attempts - attempts);
            }

            end = time(0);
            time_taken = difftime(end, start);
            if (guess != number)
            {
                setColor(12);
                printf("\nGame Over! Number was %d\n", number);
                setColor(7);
            }
            
            printf("\n Time taken: %.2f seconds\n", time_taken);
            printf("\n Guess History: ");
            for (int j = 0; j < i; j++)
                printf("%d ", history[j]);
            printf("\n");
            printf("\nDo you want to play_Again? (1=Yes, 0=No): ");
            scanf("%d", &play_Again);
        }
    }

    return 0;
}
