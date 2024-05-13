#include <stdio.h>

#define MAX_QUIZ_SIZE 100
#define MAX_QUESTION_SIZE 100
#define MAX_CHOICES 4

typedef struct {
    char question[MAX_QUESTION_SIZE];
    char choices[MAX_CHOICES][MAX_QUESTION_SIZE];
    int correct_choice;
} Question;

void create_Quiz(Question *quiz, int num_questions);
void take_Quiz(Question *quiz, int num_questions);

int main() {
    Question quiz[MAX_QUIZ_SIZE];
    int num_questions;
    printf("||_Customize_Quiz_System_||\nBy_Mahdi\n\n");
    printf("Enter The Number Of Questions For Your Quiz (Max %d): ", MAX_QUIZ_SIZE);
    scanf("%d", &num_questions);
    getchar();

    create_Quiz(quiz, num_questions);
    take_Quiz(quiz, num_questions);

    return 0;
}

void create_Quiz(Question *quiz, int num_questions) {
    for (int i = 0; i < num_questions; i++) {
        printf("Enter Question %d: ", i + 1);
        fgets(quiz[i].question, MAX_QUESTION_SIZE, stdin);

        printf("Enter Choices:\n");
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("Choice %d: ", j + 1);
            fgets(quiz[i].choices[j], MAX_QUESTION_SIZE, stdin);
        }

        printf("Enter Correct Choice Number: ");
        scanf("%d", &quiz[i].correct_choice);
        getchar();
    }
}

void take_Quiz(Question *quiz, int num_questions) {
    int score = 0;
    printf("Answer The Following Questions:\n");
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d: %s", i + 1, quiz[i].question);

        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("%d. %s", j + 1, quiz[i].choices[j]);
        }

        int user_choice;
        printf("Your Choice: ");
        scanf("%d", &user_choice);
        getchar(); 

        if (user_choice == quiz[i].correct_choice) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect!\nCorrect Answer is:%d\n",quiz[i].correct_choice);
        }
    }
    printf("Your score: %d/%d\n", score, num_questions);
}