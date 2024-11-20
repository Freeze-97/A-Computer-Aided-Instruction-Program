#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void practice(void);
void test(void);
void addition(int practice);
void subtraction(int practice);
void addition_subtraction(int practice);
void print_response(int correct); // Correct parameter = 1 means positive response
void print_results(char question[][6], int real_answer[], int your_answer[]);


int main() {
    char name[20];
    printf("Enter your name: ");
    scanf("%19s", name); // %19s limits the users input to first 19 characters
    printf("Welcome, %s!\n", name);
    srand(time(NULL));

    int input;
    do {
        printf("You can choose:\n1. do practices\n2. complete a test\n3. quit the program\nEnter your choice: ");
        scanf("%d", &input);
        if(input == 1) {
            practice();
        } else if(input == 2) {
            test();
        }else if(input == 3) {
            return 0;
        } else {
            printf("Invalid input!\n");
        }
    } while(input != 3);

    return 0;
}

void practice(void) {
    printf("\nNow, you can choose to do practices on:\n1. additions\n2. subtractions\n3. addition and subtractions\nEnter your choice: ");
    int input;
    scanf("%d", &input);

    if(input == 1) {
        printf("Now, you will be given 10 questions to solve:\n");
        addition(1);
    } else if(input == 2) {
        printf("Now, you will be given 10 questions to solve:\n");
        subtraction(1);
    } else if(input == 3) {
        printf("Now, you will be given 10 questions to solve:\n");
        addition_subtraction(1);
    } else {
        printf("invalid input!\n");
    }
}

void test(void) {
    int input;
    printf("\nNow, you can choose to do a test on:\n1. additions\n2. subtractions\n3. addition and subtractions\nEnter your choice: ");
    scanf("%d", &input);

    if(input == 1) {
        printf("Now, you will be given 15 questions to solve:\n");
        addition(0);
    } else if(input == 2) {
        printf("Now, you will be given 15 questions to solve:\n");
        subtraction(0);
    } else if(input == 3) {
        printf("Now, you will be given 15 questions to solve:\n");
        addition_subtraction(0);
    } else {
        printf("invalid input!\n");
    }
}

void addition(int practice) {
    // This is for the results after a test
    char questions[15][6];
    int real_answer[15];
    int your_answer[15];
    int points = 0;

    int i = 0;
    int rounds;
    if(practice) {
        rounds = 10;
    } else {
        rounds = 15;
    }
    
    while(i < rounds) {
        int a, b;
        a = rand() % 100;
        b = rand() % (100 - a); // Answer can never be above 99
        int answer;

        do {
            printf("How much is %d + %d: ", a, b);
            scanf("%d", &answer);

            if(!practice) { // test
                snprintf(questions[i], sizeof(questions[i]), "%d+%d", a, b); // stores a + b in string fromat
                real_answer[i] = a + b;
                your_answer[i] = answer;

                if(answer == a + b) {
                    points++;
                }
            }

            if(practice) {
                if(answer == a + b) {
                    print_response(1);
                } else {
                    print_response(0);
                }
            }
        } while(answer != a + b && practice); // will only loop if practice is on
        i++;
    }

    if(!practice) {
        float correct_ans = (points / 15.0) * 100;
        printf("Your test result is %.2f%%\n", correct_ans);
        print_results(questions, real_answer, your_answer);
    }
}

void subtraction(int practice) {
    char questions[15][6];
    int real_answer[15];
    int your_answer[15];
    int points = 0;

    int i = 0;
    int rounds;
    if(practice) {
        rounds = 10;
    } else {
        rounds = 15;
    }
    while(i < rounds) {
        int a, b;
        a = rand() % 100;
        b = rand() % (100 - a);
        int answer;

        // Switch variables
        if(b > a) {
            int temp = b;
            b = a;
            a = temp;
        }

        do {
            printf("How much is %d - %d: ", a, b);
            scanf("%d", &answer);

            if(!practice) {
                snprintf(questions[i], sizeof(questions[i]), "%d-%d", a, b); // stores a - b in string fromat
                real_answer[i] = a - b;
                your_answer[i] = answer;

                if(answer == a - b) {
                    points++;
                }
            }

            if(practice) {
                if(answer == a - b) {
                    print_response(1);
                } else {
                    print_response(0);
                }
            }
        } while(answer != a - b && practice);
        i++;
    }

    if(!practice) {
        float correct_ans = (points / 15.0) * 100;
        printf("Your test result is %.2f%%\n", correct_ans);
        print_results(questions, real_answer, your_answer);
    }
}

void addition_subtraction(int practice) {
    char questions[15][6];
    int real_answer[15];
    int your_answer[15];
    int points = 0;

    int i = 0;
    int rounds;
    if(practice) {
        rounds = 10;
    } else {
        rounds = 15;
    }
    while(i < rounds) {
        int rand_num = rand() % 2;
        if(rand_num) { // addition
            int a, b;
            a = rand() % 100;
            b = rand() % (100 - a); // Answer can never be above 99
            int answer;

            do {
                printf("How much is %d + %d: ", a, b);
                scanf("%d", &answer);

                if(!practice) { // test
                    snprintf(questions[i], sizeof(questions[i]), "%d+%d", a, b); // stores a + b in string fromat
                    real_answer[i] = a + b;
                    your_answer[i] = answer;

                    if(answer == a + b) {
                        points++;
                    }
                }

                if(practice) {
                    if(answer == a + b) {
                        print_response(1);
                    } else {
                        print_response(0);
                    }
                }
            } while(answer != a + b && practice);
        } else { // subtraction
            int a, b;
            a = rand() % 100;
            b = rand() % (100 - a);
            int answer;

            // Switch variables
            if(b > a) {
                int temp = b;
                b = a;
                a = temp;
            }

            if(!practice) {
                snprintf(questions[0], sizeof(questions[i]), "%d-%d", a, b); // stores a - b in string fromat
                real_answer[i] = a - b;
                your_answer[i] = answer;

                if(answer == a - b) {
                    points++;
                }
            }

            do {
                printf("How much is %d - %d: ", a, b);
                scanf("%d", &answer);

                if(practice) {
                    if(answer == a - b) {
                        print_response(1);
                    } else {
                        print_response(0);
                    }
                }
            } while(answer != a - b && practice);
        }
        i++;
    }

    if(!practice) {
        float correct_ans = (points / 15.0) * 100;
        printf("Your test result is %.2f%%\n", correct_ans);
        print_results(questions, real_answer, your_answer);
    }
}

void print_response(int correct) {
    if(correct == 1) {
        switch((rand() % 6) + 1) {
        case 1:
            printf("Very good!\n");
            break;
        case 2:
            printf("Excellent!\n");
            break;
        case 3:
            printf("Nice work!\n");
            break;
        case 4:
            printf("Well done!\n");
            break;
        case 5:
            printf("Great!\n");
            break;
        case 6:
            printf("Keep up the good work!\n");
            break;
        default:
            break;
        }
    } else {
        switch((rand() % 4) + 1) {
        case 1:
            printf("No. Please try again.\n");
            break;
        case 2:
            printf("Wrong. Try once again.\n");
            break;
        case 3:
            printf("Dont give up!\n");
            break;
        case 4:
            printf("No. Keep trying.\n");
            break;
        default:
            break;
        }
    }
}

void print_results(char questions[][6], int real_answer[], int your_answer[]) {
    printf("Question      Correct Answer      Your Answer\n");
    printf("------------------------------------------------\n");

    for (int i = 0; i < 15; i++) {
        printf("%-12s %-18d %d\n", questions[i], real_answer[i], your_answer[i]);
    }
    printf("\n");
}
