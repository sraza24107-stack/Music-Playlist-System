# 🎵 Music Playlist & Recommendation System

### Data Structures and Algorithms (DSA) Mini Project | C Programming

A menu-driven music playlist management system developed in C, demonstrating the practical application of **Linked Lists, Queues, Stacks, and Binary Search Trees (BSTs)** for playlist management, playback, recently played history, song searching, and basic recommendations.

---

## 📌 Project Overview

Managing a music collection involves more than simply storing song names. A playlist system must organize songs, manage playback order, maintain recently played history, and retrieve songs efficiently.

The **Music Playlist & Recommendation System** demonstrates how different data structures can work together to perform these operations. Each data structure is assigned a specific responsibility based on the operation it supports.

This project was developed as a college-level DSA mini project using the C programming language.

## 🎯 Objectives

- Apply fundamental data structures to a practical application.
- Implement dynamic playlist management using a linked list.
- Manage songs waiting for playback using a queue.
- Maintain recently played songs using a stack.
- Search for songs using a Binary Search Tree.
- Demonstrate a basic recommendation mechanism through BST searching.
- Understand algorithm efficiency through time and space complexity analysis.

## ✨ Features

| Feature | Description |
|---|---|
| Display Playlist | Displays songs stored in the playlist. |
| Add Song | Appends a song to the linked list. |
| Remove Song | Searches for a song ID and removes the corresponding playlist node. |
| Add to Play Queue | Adds a song to the rear of the playback queue. |
| Play Next Song | Retrieves the next queued song and records it in recent history. |
| Recently Played | Displays played songs from newest to oldest. |
| Search Song | Searches for a song by ID using a BST. |
| Recommend a Song | Searches for the next sequential song ID using the BST. |
| Exit | Terminates the program. |

## 🧠 Data Structures Used

### 1. Linked List — Playlist Management

A linked list stores songs as nodes containing song information and a pointer to the next node.

**Operations:**
- `addToPlaylist()` — appends a song to the playlist.
- `displayPlaylist()` — traverses and displays the playlist.
- `deleteFromPlaylist()` — removes a song by ID and frees its allocated node.

**Why it is used:** A linked list supports dynamic insertion and deletion without requiring a fixed-size array for the playlist.

### 2. Queue — Playback Management

The queue stores songs waiting to be played. It follows the **FIFO (First In, First Out)** principle.

**Operations:**
- `enqueue()` — adds a song to the rear of the queue.
- `playNext()` — retrieves the song at the front and advances the queue.

**Why it is used:** Songs are played in the same order in which they enter the playback queue.

**Implementation note:** The queue uses an array with a maximum capacity of 20 songs.

### 3. Stack — Recently Played History

The stack maintains a record of songs that have been played. It follows the **LIFO (Last In, First Out)** principle.

**Operations:**
- `pushRecent()` — pushes a played song onto the stack.
- `showRecent()` — displays recent songs from the top of the stack downwards.

**Why it is used:** The most recently played song appears first when viewing the playback history.

**Implementation note:** The stack has a maximum capacity of 20 songs.

### 4. Binary Search Tree — Searching and Recommendations

The BST stores songs using their IDs as keys. Smaller IDs are placed in the left subtree, while larger IDs are placed in the right subtree.

**Operations:**
- `insertBST()` — inserts a song into the BST.
- `searchBST()` — searches for a song by ID.
- `recommend()` — searches for a song whose ID is one greater than the current song's ID.

**Why it is used:** A BST demonstrates ordered data storage and branch-based searching.

**Recommendation example:**

`Current Song: Perfect (ID 1) → Search ID 2 → Recommended: Believer`

The recommendation mechanism is intentionally simple. It is based on sequential song IDs, not genre similarity, user preferences, collaborative filtering, or machine learning.

## ⚙️ System Workflow

1. Initialize the sample songs and data structures.
2. Insert the sample songs into the BST.
3. Populate the initial playlist.
4. Display the menu of nine operations.
5. Accept the user's choice and execute the corresponding function.
6. Update the relevant data structure.
7. Display the result and return to the menu.
8. Terminate when the user selects Exit.

## 🛠️ Technologies Used

- **Programming Language:** C
- **Core Concepts:** Structures, pointers, functions, dynamic memory allocation, and recursion where applicable
- **Data Structures:** Linked List, Queue, Stack, Binary Search Tree
- **Development Environment:** Code::Blocks or another compatible C compiler
- **Version Control and Hosting:** GitHub

## 📊 Time Complexity Analysis

Let `n` represent the number of elements in the relevant data structure.

| Operation | Time Complexity |
|---|---|
| Add to playlist (at end) | O(n) |
| Display playlist | O(n) |
| Remove song from playlist | O(n) |
| Push song onto stack | O(1) |
| Display recent history | O(n) |
| Enqueue a song | O(1) |
| Play next song | O(1) |
| BST search | O(log n) average, O(n) worst case |
| BST insertion | O(log n) average, O(n) worst case |
| Recommendation lookup | O(log n) average, O(n) worst case |

### Space Complexity

- **Linked List:** O(n) for stored playlist nodes.
- **Stack:** O(1) per stored song, with a fixed capacity of 20.
- **Queue:** O(1) per stored song, with a fixed capacity of 20.
- **BST:** O(n) for the stored song nodes.

The overall auxiliary storage requirement is O(n), excluding fixed-size structures and implementation-specific details.

*Complexities are based on the implementation described in the project presentation. BST performance depends on the shape of the tree; an unbalanced tree can degrade to linear time.*

## ▶️ How to Run the Project

### Prerequisites

- Code::Blocks or another C compiler, such as GCC.
- The C source file included in this repository.

### Using Code::Blocks

1. Clone or download this repository.
2. Open Code::Blocks.
3. Create a C project or open the source file.
4. Compile and run the program.
5. Select an operation from the displayed menu.

### Using GCC

If the source file is named `main.c`, open a terminal in the directory containing the file and execute:

```bash
gcc main.c -o music_playlist
```

Run the program:

**Windows**
```bash
music_playlist.exe
```

**Linux**
```bash
./music_playlist
```

Replace `main.c` with the actual C source filename if it differs.

## 📂 Repository Structure

```text
music-playlist-system/
│
├── main.c
├── DSA FINAL PPT.pptx
└── README.md
```

The filenames shown are examples for the source file and README. Keep your actual source filename in the repository. The presentation filename above matches the uploaded PowerPoint.

## 📑 Project Presentation

The PowerPoint presentation covers:

- Problem statement and objectives
- System overview and data structure mapping
- Sample songs and menu operations
- Linked list, queue, stack, and BST concepts
- Algorithms and pseudocode
- C implementation and program flow
- Recommendation mechanism
- Time and space complexity analysis
- Execution walkthrough and conclusion

**Presentation:** [`DSA FINAL PPT.pptx`](./DSA%20FINAL%20PPT.pptx)

## ⚠️ Current Scope and Limitations

- The application uses a menu-driven console interface.
- The queue and stack have fixed capacities.
- The recommendation mechanism uses sequential song IDs rather than personalized recommendations.
- The project demonstrates playlist management and playback logic; it does not implement actual audio playback.
- Playlist persistence, a graphical interface, and machine-learning-based recommendations are potential future enhancements.

## 🚀 Future Enhancements

- Integrate actual audio playback.
- Add permanent playlist storage using file handling.
- Implement circular queues for improved queue reuse.
- Introduce genre-based or user-preference-based recommendations.
- Explore machine-learning-based recommendation algorithms.
- Develop a graphical user interface.
- Add playlist sorting, filtering, and playback controls.

## 👥 Project Team

**Presented by:**
- Shadab Raza
- Riya Saxena
- Sonali Anjana

**Project:** Music Playlist & Recommendation System  
**Subject:** Data Structures and Algorithms  
**Project Type:** College Mini Project

## 🎓 Learning Outcomes

Through this project, we demonstrate:

- Practical use of four fundamental data structures.
- Dynamic memory management and pointer manipulation in C.
- Implementation of searching, insertion, deletion, and traversal.
- Understanding of FIFO and LIFO principles.
- Analysis of time and space complexity.
- Integration of multiple data structures into one application.

## 📜 License

This project is intended for educational and academic purposes. A suitable open-source license may be added if the project is formally distributed.

---

**Thank you for visiting our project! 🎶**

If you find this project useful for learning Data Structures and Algorithms, consider starring the repository.
