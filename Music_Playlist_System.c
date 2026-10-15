#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

/* ================= SONG STRUCTURE ================= */

struct Song
{
    int id;
    char name[50];
    char artist[50];
    char genre[30];
};

/* ================= LINKED LIST ================= */

struct Node
{
    struct Song song;
    struct Node *next;
};

struct Node *playlist = NULL;

/* Add song to playlist */
void addToPlaylist(struct Song s)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->song = s;
    newNode->next = NULL;

    if (playlist == NULL)
    {
        playlist = newNode;
    }
    else
    {
        temp = playlist;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Song added to playlist!\n");
}

/* Display playlist */
void displayPlaylist()
{
    struct Node *temp = playlist;

    if (playlist == NULL)
    {
        printf("Playlist is empty.\n");
        return;
    }

    printf("\n----- MY PLAYLIST -----\n");

    while (temp != NULL)
    {
        printf("ID: %d | %s | %s | %s\n",
               temp->song.id,
               temp->song.name,
               temp->song.artist,
               temp->song.genre);

        temp = temp->next;
    }
}

/* Delete song from playlist */
void deleteFromPlaylist(int id)
{
    struct Node *temp = playlist;
    struct Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->song.id == id)
        {
            if (prev == NULL)
                playlist = temp->next;
            else
                prev->next = temp->next;

            free(temp);

            printf("Song removed from playlist.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Song not found.\n");
}

/* ================= STACK ================= */

/* Stack for recently played songs */

struct Song recentStack[MAX];
int top = -1;

void pushRecent(struct Song s)
{
    if (top == MAX - 1)
    {
        printf("Recent history is full.\n");
        return;
    }

    top++;
    recentStack[top] = s;
}

void showRecent()
{
    int i;

    if (top == -1)
    {
        printf("No recently played songs.\n");
        return;
    }

    printf("\n----- RECENTLY PLAYED -----\n");

    for (i = top; i >= 0; i--)
    {
        printf("%s - %s\n",
               recentStack[i].name,
               recentStack[i].artist);
    }
}

/* ================= QUEUE ================= */

/* Queue for songs waiting to be played */

struct Song playQueue[MAX];

int front = -1;
int rear = -1;

void enqueue(struct Song s)
{
    if (rear == MAX - 1)
    {
        printf("Play queue is full.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    playQueue[rear] = s;

    printf("Song added to play queue.\n");
}

void playNext()
{
    struct Song s;

    if (front == -1 || front > rear)
    {
        printf("Play queue is empty.\n");
        return;
    }

    s = playQueue[front];

    printf("\nNow Playing: %s - %s\n",
           s.name,
           s.artist);

    pushRecent(s);

    front++;

    if (front > rear)
    {
        front = -1;
        rear = -1;
    }
}

/* ================= BINARY SEARCH TREE ================= */

struct TreeNode
{
    struct Song song;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *root = NULL;

/* Create BST node */
struct TreeNode *createTreeNode(struct Song s)
{
    struct TreeNode *newNode;

    newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));

    newNode->song = s;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

/* Insert song into BST */
struct TreeNode *insertBST(struct TreeNode *root, struct Song s)
{
    if (root == NULL)
    {
        return createTreeNode(s);
    }

    if (s.id < root->song.id)
    {
        root->left = insertBST(root->left, s);
    }
    else
    {
        root->right = insertBST(root->right, s);
    }

    return root;
}

/* Search song by ID */
struct TreeNode *searchBST(struct TreeNode *root, int id)
{
    if (root == NULL || root->song.id == id)
        return root;

    if (id < root->song.id)
        return searchBST(root->left, id);
    else
        return searchBST(root->right, id);
}

/* ================= RECOMMENDATION ================= */

void recommend(struct Song current)
{
    struct TreeNode *result;

    printf("\n----- RECOMMENDATION -----\n");

    printf("Because you are listening to: %s\n",
           current.name);

    printf("Genre: %s\n", current.genre);

    /*
       Simple recommendation:
       Search the BST for another song.
       In this simple project we demonstrate
       BST searching by song ID.
    */

    result = searchBST(root, current.id + 1);

    if (result != NULL)
    {
        printf("Recommended Song: %s\n",
               result->song.name);

        printf("Artist: %s\n",
               result->song.artist);

        printf("Genre: %s\n",
               result->song.genre);
    }
    else
    {
        printf("No recommendation available.\n");
    }
}

/* ================= MAIN ================= */

int main()
{
    int choice;
    int id;

    struct Song songs[5] =
    {
        {1, "Perfect", "Ed Sheeran", "Pop"},
        {2, "Believer", "Imagine Dragons", "Rock"},
        {3, "Blinding Lights", "The Weeknd", "Pop"},
        {4, "Shape of You", "Ed Sheeran", "Pop"},
        {5, "Faded", "Alan Walker", "EDM"}
    };

    /* Insert songs into BST */
    for (int i = 0; i < 5; i++)
    {
        root = insertBST(root, songs[i]);
    }

    /* Add some songs to playlist */
    addToPlaylist(songs[0]);
    addToPlaylist(songs[1]);
    addToPlaylist(songs[2]);

    while (1)
    {
        printf("\n==============================\n");
        printf("      MUSIC PLAYLIST SYSTEM\n");
        printf("==============================\n");

        printf("1. Display Playlist\n");
        printf("2. Add Song to Playlist\n");
        printf("3. Remove Song from Playlist\n");
        printf("4. Add Song to Play Queue\n");
        printf("5. Play Next Song\n");
        printf("6. Show Recently Played\n");
        printf("7. Search Song\n");
        printf("8. Get Recommendation\n");
        printf("9. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displayPlaylist();
                break;

            case 2:
                printf("\nAvailable Songs:\n");

                for (int i = 0; i < 5; i++)
                {
                    printf("%d. %s - %s - %s\n",
                           songs[i].id,
                           songs[i].name,
                           songs[i].artist,
                           songs[i].genre);
                }

                printf("Enter Song ID: ");
                scanf("%d", &id);

                if (id >= 1 && id <= 5)
                    addToPlaylist(songs[id - 1]);
                else
                    printf("Invalid Song ID.\n");

                break;

            case 3:
                printf("Enter Song ID to remove: ");
                scanf("%d", &id);

                deleteFromPlaylist(id);
                break;

            case 4:
                printf("\nAvailable Songs:\n");

                for (int i = 0; i < 5; i++)
                {
                    printf("%d. %s\n",
                           songs[i].id,
                           songs[i].name);
                }

                printf("Enter Song ID: ");
                scanf("%d", &id);

                if (id >= 1 && id <= 5)
                    enqueue(songs[id - 1]);
                else
                    printf("Invalid Song ID.\n");

                break;

            case 5:
                playNext();
                break;

            case 6:
                showRecent();
                break;

            case 7:
                printf("Enter Song ID to search: ");
                scanf("%d", &id);

                {
                    struct TreeNode *result;

                    result = searchBST(root, id);

                    if (result != NULL)
                    {
                        printf("\nSong Found!\n");
                        printf("Name: %s\n", result->song.name);
                        printf("Artist: %s\n", result->song.artist);
                        printf("Genre: %s\n", result->song.genre);
                    }
                    else
                    {
                        printf("Song not found.\n");
                    }
                }

                break;

            case 8:
                printf("Enter Song ID you are listening to: ");
                scanf("%d", &id);

                if (id >= 1 && id <= 5)
                    recommend(songs[id - 1]);
                else
                    printf("Invalid Song ID.\n");

                break;

            case 9:
                printf("Thank you!\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
