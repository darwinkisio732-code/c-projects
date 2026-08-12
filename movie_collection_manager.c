#include <stdio.h>
#include <string.h>

#define MAX_MOVIES 10
#define TITLE_LEN 100
#define NAME_LEN 50
#define GENRE_LEN 30

typedef struct {
    char title[TITLE_LEN];
    char director[NAME_LEN];
    int year;
    float rating;
    char genre[GENRE_LEN];
} Movie;

// Helper to safely read string inputs and strip newlines
void read_string(char *buffer, int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void inputMovieDetails(Movie movies[], int *count) {
    int to_add;
    printf("\nHow many movies would you like to add? ");
    if (scanf("%d", &to_add) != 1 || to_add <= 0) {
        printf("Invalid number!\n");
        return;
    }
    getchar(); // Clear buffer newline

    if (*count + to_add > MAX_MOVIES) {
        printf("Cannot add %d movies. Space remaining: %d\n", to_add, MAX_MOVIES - *count);
        return;
    }

    for (int i = 0; i < to_add; i++) {
        int idx = *count;
        printf("\n====== Movie %d ======\n", idx + 1);

        printf("Title: ");
        read_string(movies[idx].title, TITLE_LEN);

        printf("Director: ");
        read_string(movies[idx].director, NAME_LEN);

        printf("Year: ");
        scanf("%d", &movies[idx].year);

        printf("Rating (0.0 - 10.0): ");
        scanf("%f", &movies[idx].rating);
        getchar(); // Clear buffer newline

        printf("Genre: ");
        read_string(movies[idx].genre, GENRE_LEN);

        (*count)++;
    }
}

void displayMovieDetails(const Movie movies[], int count) {
    if (count == 0) {
        printf("\nNo Movies Found! Add Movies to view them.\n");
        return;
    }

    printf("\n================================ MOVIE DETAILS ================================\n");
    printf("%-25s %-20s %-8s %-8s %-15s\n", "Title", "Director", "Year", "Rating", "Genre");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-25s %-20s %-8d %-8.1f %-15s\n",
               movies[i].title, movies[i].director, movies[i].year, movies[i].rating, movies[i].genre);
    }
}

float findAverageRating(const Movie movies[], int count) {
    if (count == 0) return 0.0f;

    float total = 0.0f;
    for (int i = 0; i < count; i++) {
        total += movies[i].rating;
    }
    return total / count;
}

int findHighestRated(const Movie movies[], int count) {
    if (count == 0) return -1;

    int highestIdx = 0;
    for (int i = 1; i < count; i++) {
        if (movies[i].rating > movies[highestIdx].rating) {
            highestIdx = i;
        }
    }
    return highestIdx;
}

int findOldestMovie(const Movie movies[], int count) {
    if (count == 0) return -1;

    int oldestIdx = 0;
    for (int i = 1; i < count; i++) {
        if (movies[i].year < movies[oldestIdx].year) {
            oldestIdx = i;
        }
    }
    return oldestIdx;
}

int countofMoviesPerGenre(const Movie movies[], int count, const char genre[]) {
    int total = 0;
    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].genre, genre) == 0) {
            total++;
        }
    }
    return total;
}

void searchMovie(const Movie movies[], int count, const char search[]) {
    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, search) == 0) {
            printf("\n====== Movie Details ======");
            printf("\nTitle:    %s", movies[i].title);
            printf("\nDirector: %s", movies[i].director);
            printf("\nYear:     %d", movies[i].year);
            printf("\nRating:   %.1f", movies[i].rating);
            printf("\nGenre:    %s\n", movies[i].genre);
            return;
        }
    }
    printf("\nMovie Not Found!\n");
}

void updateMovieRating(Movie movies[], int count, const char search_title[], float new_rating) {
    if (new_rating < 0.0f || new_rating > 10.0f) {
        printf("\nInvalid Rating! Must be between 0.0 and 10.0.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, search_title) == 0) {
            movies[i].rating = new_rating;
            printf("\nMovie Rating Updated Successfully!\n");
            return;
        }
    }
    printf("\nMovie Not Found!\n");
}

int deleteMovie(Movie movies[], int count, const char search_title[]) {
    for (int i = 0; i < count; i++) {
        if (strcasecmp(movies[i].title, search_title) == 0) {
            // Shift elements to left
            for (int j = i; j < count - 1; j++) {
                movies[j] = movies[j + 1];
            }
            printf("\nMovie Deleted Successfully!\n");
            return count - 1;
        }
    }
    printf("\nMovie NOT found!\n");
    return count;
}

void print_menu(void) {
    printf("\n=========== MOVIE MENU ============");
    printf("\n1. Add Movie");
    printf("\n2. Display Movies");
    printf("\n3. Search Movie");
    printf("\n4. Update Rating");
    printf("\n5. Delete Movie");
    printf("\n6. Top Rated Movie");
    printf("\n7. Oldest Movie");
    printf("\n8. Movies Per Genre");
    printf("\n9. Exit");
    printf("\n\nChoose: ");
}

int main(void) {
    Movie movies[MAX_MOVIES];
    int num_of_movies = 0;
    int choice;
    char query[TITLE_LEN];
    float proposed_rating;

    while (1) {
        print_menu();

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid option. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar(); // Clear buffer newline

        switch (choice) {
            case 1:
                inputMovieDetails(movies, &num_of_movies);
                break;
            case 2:
                displayMovieDetails(movies, num_of_movies);
                break;
            case 3:
                printf("\nSearch Title: ");
                read_string(query, TITLE_LEN);
                searchMovie(movies, num_of_movies, query);
                break;
            case 4:
                printf("\nSearch Title to Update: ");
                read_string(query, TITLE_LEN);
                printf("Enter Proposed Rating (0.0 - 10.0): ");
                scanf("%f", &proposed_rating);
                getchar();
                updateMovieRating(movies, num_of_movies, query, proposed_rating);
                break;
            case 5:
                printf("\nSearch Title to Delete: ");
                read_string(query, TITLE_LEN);
                num_of_movies = deleteMovie(movies, num_of_movies, query);
                break;
            case 6: {
                int highest = findHighestRated(movies, num_of_movies);
                if (highest != -1) {
                    printf("\nHighest Rated Movie: %s (%.1f)\n", movies[highest].title, movies[highest].rating);
                } else {
                    printf("\nNo movies available.\n");
                }
                break;
            }
            case 7: {
                int oldest = findOldestMovie(movies, num_of_movies);
                if (oldest != -1) {
                    printf("\nOldest Movie: %s (%d)\n", movies[oldest].title, movies[oldest].year);
                } else {
                    printf("\nNo movies available.\n");
                }
                break;
            }
            case 8: {
                printf("\nEnter Genre to Count: ");
                read_string(query, GENRE_LEN);
                int count = countofMoviesPerGenre(movies, num_of_movies, query);
                printf("\nMovies in '%s' genre: %d\n", query, count);
                break;
            }
            case 9:
                printf("\nGoodbye!\n\n");
                return 0;
            default:
                printf("\nInvalid Choice. Try Again!\n");
                break;
        }
    }

    return 0;
}
