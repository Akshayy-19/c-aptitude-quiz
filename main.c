#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL 10

void Menu(void);
void loadQuestions(void);
int askQuestion(int index);
int calculateResult(int score, int total);
void showResult(char name[], int score, int total);

char questions[TOTAL][80];
char options[TOTAL][4][30];
int answers[TOTAL];

const char *bank[] = {
    "What is 15 percent of 200?|20|25|30|35|3",
    "If 3x + 7 = 22, then x is|3|4|5|6|3",
    "The HCF of 24 and 36 is|6|8|9|12|4",
    "A train 120 m long at 60 km/h crosses a pole in|5 sec|6 sec|7 sec|8 sec|3",
    "log base 10 of 1000 equals|1|2|3|4|3",
    "The integral of 5x^2 dx is|5x^3/3|15x^3|5x^3|x^5|1",
    "Average speed of 60 km/h and 40 km/h|48|50|52|55|1",
    "Simple interest on 5000 at 8 percent for 2 years|400|600|800|1000|3",
    "The derivative of sin x is|-cos x|cos x|tan x|-sin x|2",
    "Smallest prime number greater than 50|51|53|55|57|2"
};

int main(void)
{
    char name[50] = "";
    int choice;
    int score = 0;
    int i;

    while (1)
    {
        Menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1)
        {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            printf("Please enter a number.\n");
            continue;
        }

        switch (choice)
        {
            case 1:
                printf("\nEnter your name: ");
                if (scanf("%49s", name) != 1)
                {
                    printf("Could not read name.\n");
                    name[0] = '\0';
                    break;
                }
                printf("Welcome, %s! Good luck.\n", name);
                break;

            case 2:
                if (name[0] == '\0')
                {
                    printf("\nEnter your name first (choice 1).\n");
                    break;
                }
                loadQuestions();
                score = 0;
                for (i = 0; i < TOTAL; i++)
                    score += askQuestion(i);
                showResult(name, score, TOTAL);
                break;

            case 3:
                printf("\nGoodbye! Your answers are not saved.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

void Menu(void)
{
    printf("\n===== Smart Aptitude Quiz =====\n");
    printf("1. Enter Student Name\n");
    printf("2. Start Quiz\n");
    printf("3. Exit\n");
    printf("----------------------------\n");
}

void loadQuestions(void)
{
    char copy[200];
    char *token;
    int i;
    int j;

    for (i = 0; i < TOTAL; i++)
    {
        strcpy(copy, bank[i]);
        token = strtok(copy, "|");
        if (token == NULL)
            continue;

        strcpy(questions[i], token);

        for (j = 0; j < 4; j++)
        {
            token = strtok(NULL, "|");
            if (token == NULL)
                break;
            strcpy(options[i][j], token);
        }

        token = strtok(NULL, "|");
        answers[i] = (token != NULL) ? atoi(token) : 1;

        if (answers[i] < 1 || answers[i] > 4)
            answers[i] = 1;
    }

    printf("\n%d questions loaded.\n", TOTAL);
}

int askQuestion(int index)
{
    int choice;
    int j;

    printf("\n----- Question %d of %d -----\n", index + 1, TOTAL);
    printf("%d. %s\n", index + 1, questions[index]);

    for (j = 0; j < 4; j++)
        printf("%d. %s\n", j + 1, options[index][j]);

    while (1)
    {
        printf("Your answer (1-4): ");
        if (scanf("%d", &choice) != 1)
        {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            printf("Please enter a number from 1 to 4.\n");
            continue;
        }

        if (choice >= 1 && choice <= 4)
            break;

        printf("Invalid option. Try again.\n");
    }

    if (choice == answers[index])
    {
        printf("Correct!\n");
        return 1;
    }

    printf("Wrong. Correct answer: %s\n", options[index][answers[index] - 1]);
    return 0;
}

int calculateResult(int score, int total)
{
    if (total <= 0)
        return 0;

    return (score * 100) / total;
}

void showResult(char name[], int score, int total)
{
    float percentage;
    int percent;
    char grade;

    percent = calculateResult(score, total);
    percentage = (float)percent;

    printf("\n============ RESULT ============\n");
    printf("Name        : %s\n", name);
    printf("Score       : %d / %d\n", score, total);
    printf("Percentage  : %.2f %%\n", percentage);

    if (percent >= 90)
    {
        grade = 'A';
        printf("Performance : Excellent\n");
    }
    else if (percent >= 75)
    {
        grade = 'B';
        printf("Performance : Very Good\n");
    }
    else if (percent >= 60)
    {
        grade = 'C';
        printf("Performance : Good, keep practising\n");
    }
    else if (percent >= 40)
    {
        grade = 'D';
        printf("Performance : Average, revise the topics\n");
    }
    else
    {
        grade = 'F';
        printf("Performance : Needs improvement\n");
    }

    printf("Grade       : %c\n", grade);
    printf("===============================\n");
}
