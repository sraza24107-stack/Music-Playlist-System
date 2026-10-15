#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 5

/* =========================
   QUEUE FOR LEVEL 1
   ========================= */

char queue[MAX][20];
int front = 0;
int rear = -1;

void enqueue(char word[])
{
    if (rear == MAX - 1)
    {
        return;
    }

    rear++;
    strcpy(queue[rear], word);
}

char* dequeue()
{
    if (front > rear)
    {
        return NULL;
    }

    return queue[front++];
}

/* =========================
   STACK FOR PREVIOUS GUESSES
   ========================= */

char stack[MAX][20];
int top = -1;

void push(char word[])
{
    if (top == MAX - 1)
    {
        return;
    }

    top++;
    strcpy(stack[top], word);
}

void displayStack()
{
    int i;

    printf("\nPrevious Answers:\n");

    if (top == -1)
    {
        printf("No answers yet.\n");
        return;
    }

    for (i = top; i >= 0; i--)
    {
        printf("%s\n", stack[i]);
    }
}

/* =========================
   LINKED LIST FOR WORD CHAIN
   ========================= */

struct node
{
    char word[20];
    struct node *next;
};

struct node *head = NULL;

void addWord(char word[])
{
    struct node *newnode;
    struct node *temp;

    newnode = (struct node*)malloc(sizeof(struct node));

    strcpy(newnode->word, word);
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}

void displayChain()
{
    struct node *temp = head;

    printf("\nWord Chain:\n");

    while (temp != NULL)
    {
        printf("%s", temp->word);

        if (temp->next != NULL)
        {
            printf(" -> ");
        }

        temp = temp->next;
    }

    printf("\n");
}

/* =========================
   BINARY SEARCH TREE
   ========================= */

struct tree
{
    char word[20];
    struct tree *left;
    struct tree *right;
};

struct tree* createNode(char word[])
{
    struct tree *newnode;

    newnode = (struct tree*)malloc(sizeof(struct tree));

    strcpy(newnode->word, word);

    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct tree* insert(struct tree *root, char word[])
{
    if (root == NULL)
    {
        return createNode(word);
    }

    if (strcmp(word, root->word) < 0)
    {
        root->left = insert(root->left, word);
    }
    else if (strcmp(word, root->word) > 0)
    {
        root->right = insert(root->right, word);
    }

    return root;
}

int search(struct tree *root, char word[])
{
    if (root == NULL)
    {
        return 0;
    }

    if (strcmp(word, root->word) == 0)
    {
        return 1;
    }

    if (strcmp(word, root->word) < 0)
    {
        return search(root->left, word);
    }

    return search(root->right, word);
}

/* =========================
   CONVERT WORD TO UPPERCASE
   ========================= */

void upper(char word[])
{
    int i;

    for (i = 0; word[i] != '\0'; i++)
    {
        word[i] = toupper(word[i]);
    }
}

/* =========================
   MAIN
   ========================= */

int main()
{
    char player[30];
    char answer[20];
    char *correctWord;

    int score = 0;
    int i;

    struct tree *root = NULL;

    /* Dictionary */
    char dictionary[][20] =
    {
        "APPLE",
        "BALL",
        "CAT",
        "DOG",
        "ELEPHANT",
        "HOUSE",
        "RAT",
        "TABLE",
        "TIGER",
        "TRAIN"
    };

    /* =========================
       CREATE BST
       ========================= */

    for (i = 0; i < 10; i++)
    {
        root = insert(root, dictionary[i]);
    }

    /* =========================
       CREATE LEVEL 1 QUEUE
       ========================= */

    enqueue("APPLE");
    enqueue("TIGER");
    enqueue("HOUSE");

    printf("====================================\n");
    printf("          WORD WARS\n");
    printf("====================================\n");

    printf("Enter your name: ");
    scanf("%s", player);

    printf("\nWelcome %s!\n", player);

    /* =========================
       LEVEL 1
       ========================= */

    printf("\n====================================\n");
    printf("             LEVEL 1\n");
    printf("           WORD SCRAMBLE\n");
    printf("====================================\n");

    /* First word */

    correctWord = dequeue();

    printf("\nScrambled Word: E P P L A\n");
    printf("Your answer: ");
    scanf("%s", answer);

    upper(answer);

    push(answer);

    if (strcmp(answer, correctWord) == 0)
    {
        printf("Correct! +10 points\n");
        score += 10;
    }
    else
    {
        printf("Wrong answer!\n");
        printf("Correct answer: %s\n", correctWord);
    }

    /* Second word */

    correctWord = dequeue();

    printf("\nScrambled Word: R G I T E\n");
    printf("Your answer: ");
    scanf("%s", answer);

    upper(answer);

    push(answer);

    if (strcmp(answer, correctWord) == 0)
    {
        printf("Correct! +10 points\n");
        score += 10;
    }
    else
    {
        printf("Wrong answer!\n");
        printf("Correct answer: %s\n", correctWord);
    }

    /* Third word */

    correctWord = dequeue();

    printf("\nScrambled Word: S O H U E\n");
    printf("Your answer: ");
    scanf("%s", answer);

    upper(answer);

    push(answer);

    if (strcmp(answer, correctWord) == 0)
    {
        printf("Correct! +10 points\n");
        score += 10;
    }
    else
    {
        printf("Wrong answer!\n");
        printf("Correct answer: %s\n", correctWord);
    }

    printf("\nYour Level 1 Score = %d\n", score);

    displayStack();

    /* =========================
       CHECK FOR LEVEL 2
       ========================= */

    if (score < 20)
    {
        printf("\nYou need at least 20 points to enter Level 2.\n");
        printf("GAME OVER!\n");
        return 0;
    }

    printf("\n====================================\n");
    printf("          LEVEL 2 UNLOCKED!\n");
    printf("====================================\n");

    printf("\nWORD CHAIN CHALLENGE\n");

    /*
       Starting word
    */

    strcpy(answer, "CAT");

    addWord(answer);

    printf("\nStarting word: CAT\n");

    /* Player enters next word */

    printf("\nEnter a word starting with T: ");
    scanf("%s", answer);

    upper(answer);

    if (answer[0] != 'T')
    {
        printf("Wrong starting letter!\n");
        printf("GAME OVER!\n");
        return 0;
    }

    if (!search(root, answer))
    {
        printf("Word not found in dictionary!\n");
        printf("GAME OVER!\n");
        return 0;
    }

    addWord(answer);
    score += 10;

    /* Next word */

    printf("\nEnter a word starting with R: ");
    scanf("%s", answer);

    upper(answer);

    if (answer[0] != 'R')
    {
        printf("Wrong starting letter!\n");
        printf("GAME OVER!\n");
        return 0;
    }

    if (!search(root, answer))
    {
        printf("Word not found in dictionary!\n");
        printf("GAME OVER!\n");
        return 0;
    }

    addWord(answer);
    score += 10;

    /* Display final chain */

    displayChain();

    printf("\n====================================\n");
    printf("             YOU WIN!\n");
    printf("====================================\n");

    printf("Player: %s\n", player);
    printf("Final Score: %d\n", score);

    return 0;
}
