#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <time.h>     
#include <string.h>  

#define ROWS 100
#define COLS 100
#define GENERATIONS 1000

#define RESET "\033[0m"
#define GREEN "\033[32m"

void print_grid(int grid[ROWS][COLS]) {
    system("clear"); 
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf(grid[i][j] ? GREEN "█" RESET : " ");
        }
        printf("\n");
    }
}

// Function to count live neighbors
int count_neighbors(int grid[ROWS][COLS], int x, int y) {
    int count = 0;
    int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS) {
            count += grid[nx][ny];
        }
    }
    return count;
}

// Function to update the grid
void update_grid(int grid[ROWS][COLS]) {
    int new_grid[ROWS][COLS] = {0};

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(grid, i, j);
            if (grid[i][j] == 1) {
                new_grid[i][j] = (neighbors == 2 || neighbors == 3);
            } else {
                new_grid[i][j] = (neighbors == 3);
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

// Function to initialize the grid with a glider
void initialize_glider(int grid[ROWS][COLS]) {
    grid[1][2] = 1;
    grid[2][3] = 1;
    grid[3][1] = 1;
    grid[3][2] = 1;
    grid[3][3] = 1;
}

// Function to randomize the grid
void initialize_random(int grid[ROWS][COLS]) {
    srand(time(NULL)); // Seed
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

// Function for user input initialization
void initialize_manual(int grid[ROWS][COLS]) {
    int x, y;
    printf("Enter live cell positions (x y), or (-1 -1) to finish:\n");
    while (1) {
        scanf("%d %d", &x, &y);
        if (x == -1 || y == -1) break;
        if (x >= 0 && x < ROWS && y >= 0 && y < COLS) {
            grid[x][y] = 1;
        } else {
            printf("Invalid position, try again.\n");
        }
    }
}

// Function to save grid to a file
void save_grid(int grid[ROWS][COLS], const char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        printf("Error saving file!\n");
        return;
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fprintf(file, "%d", grid[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
    printf("Grid saved to %s\n", filename);
}

// Function to load grid from a file
void load_grid(int grid[ROWS][COLS], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error loading file!\n");
        return;
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fscanf(file, "%1d", &grid[i][j]);
        }
    }
    fclose(file);
    printf("Grid loaded from %s\n", filename);
}

int main() {
    int grid[ROWS][COLS] = {0};
    int choice;
    char filename[50];

    printf("Game of Life - Choose Initialization:\n");
    printf("1. Glider pattern\n");
    printf("2. Random pattern\n");
    printf("3. Manual input\n");
    printf("4. Load from file\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            initialize_glider(grid);
            break;
        case 2:
            initialize_random(grid);
            break;
        case 3:
            initialize_manual(grid);
            break;
        case 4:
            printf("Enter filename: ");
            scanf("%s", filename);
            load_grid(grid, filename);
            break;
        default:
            printf("Invalid choice, using glider.\n");
            initialize_glider(grid);
    }

    // Run the simulation
    for (int gen = 0; gen < GENERATIONS; gen++) {
        print_grid(grid);
        update_grid(grid);
        usleep(100000);
    }

    // Save the grid option
    printf("Save grid? (1 = Yes, 0 = No): ");
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter filename: ");
        scanf("%s", filename);
        save_grid(grid, filename);
    }

    return 0;
}
