#include <stdio.h>
#include <string.h>

struct Movie
{
    char title[100];
    char director[50];
    int year;
    float rating;
    char genre[30];
};

void inputMovieDetails(struct Movie s[], int num_of_movies)
{
    printf("\n==========INPUT MOVIE DETAILS==========");
    for (int i = 0; i < num_of_movies; i++)
    {
        printf("\n======Movie %d======", i + 1);

        printf("\nTitle: ");
        fgets(s[i].title, sizeof(s[i].title), stdin);
        s[i].title[strcspn(s[i].title, "\n")] = 0;

        printf("\nDirector: ");
        fgets(s[i].director, sizeof(s[i].director), stdin);
        s[i].director[strcspn(s[i].director, "\n")] = 0;

        printf("\nYear: ");
        scanf("%d", &s[i].year);

        printf("\nRating: ");
        scanf("%f", &s[i].rating);
        getchar();

        printf("\nGenre: ");
        fgets(s[i].genre, sizeof(s[i].genre), stdin);
        s[i].genre[strcspn(s[i].genre, "\n")] = 0;
    }
}

void displayMovieDetails(struct Movie s[], int num_of_movies)
{
    if (num_of_movies > 0)
    {
        printf("\n\n======================MOVIE DETAILS======================");
        printf("\n%-15s %-12s %-10s %-10s %-15s", "Title", "Director", "Year", "Rating", "Genre");
        printf("\n-------------------------------------------------------------");
        for (int i = 0; i < num_of_movies; i++)
        {
            printf("\n%-15s %-12s %-10d %-10.1f %-15s",
                   s[i].title,
                   s[i].director,
                   s[i].year,
                   s[i].rating,
                   s[i].genre);
        }
    }
    else
    {
        printf("\nNo Movies Found! Add Movies to view them.");
    }
}

float findAverageRating(struct Movie s[], int num_of_movies)
{
    float averageRating = 0;
    float total = 0;

    for (int i = 0; i < num_of_movies; i++)
    {
        total += s[i].rating;
    }
    averageRating = (num_of_movies > 0) ? (total / num_of_movies) : 0.0f;

    return averageRating;
}

int findHighestRated(struct Movie s[], int num_of_movie)
{
    int highestRatedIndex = 0;

    for (int i = 0; i < num_of_movie; i++)
    {
        if (s[i].rating > s[highestRatedIndex].rating)
        {
            highestRatedIndex = i;
        }
    }

    return highestRatedIndex;
}

int findOldestMovie(struct Movie s[], int num_of_movie)
{
    int oldestIndex = 0;

    for (int i = 0; i < num_of_movie; i++)
    {
        if (s[i].year < s[oldestIndex].year)
        {
            oldestIndex = i;
        }
    }

    return oldestIndex;
}

int countofMoviesPerGenre(struct Movie s[], int num_of_movie, char genre[])
{
    int count = 0;

    for (int i = 0; i < num_of_movie; i++)
    {
        if (strcmp(s[i].genre, genre) == 0)
        {
            count++;
        }
    }

    return count;
}

void searchMovie(struct Movie s[], int num_of_movie, char search[])
{
    int movieIndex = 0;

    for (int i = 0; i < num_of_movie; i++)
    {
        if (strcmp(s[i].title, search) == 0)
        {
            movieIndex = 1;
            printf("\n\n======Movie Details======");
            printf("\n--------------------------");
            printf("\nTitle: %s", s[i].title);
            printf("\nDirector: %s", s[i].director);
            printf("\nYear: %d", s[i].year);
            printf("\nRating: %.1f", s[i].rating);
            printf("\nGenre: %s", s[i].genre);
            break;
        }
    }
    if (!movieIndex)
    {
        printf("\n\nMovie Not Found!");
    }
}

void updateMovieRating(struct Movie s[], int num_of_movie, char search_update[], float proposed_rating)
{
    for (int i = 0; i < num_of_movie; i++)
    {
        if (strcmp(s[i].title, search_update) == 0)
        {
            if (proposed_rating < 0 || proposed_rating > 10.0)
            {
                printf("\n\nInvalid Rating!");
            }
            else
            {
                s[i].rating = proposed_rating;
                printf("\n\nMovie Rating Updated Successfully!");
            }
        }
    }
}

int deleteMovie(struct Movie s[], int num_of_movie, char search_delete[])
{
    int found = 0;
    for (int i = 0; i < num_of_movie; i++)
    {
        if (strcmp(s[i].title, search_delete) == 0)
        {
            found = 1;
            strcpy(s[i].title, s[i + 1].title);
            strcpy(s[i].director, s[i + 1].director);
            s[i].year = s[i + 1].year;
            s[i].rating = s[i + 1].rating;
            strcpy(s[i].genre, s[i + 1].genre);
        }
    }
    if (found)
    {
        num_of_movie--;
        printf("\n\nMovie Deleted Successfully!");
    }
    else
    {
        printf("\nMovie NOT found!");
    }

    return num_of_movie;
}

int main()
{
    struct Movie movies[10];
    int num_of_movies = 0;
    char genre[30];
    int running = 1;
    int choice;
    char search_update[30];
    char search_delete[30];
    char search[30];
    float proposed_rating;

    while (running)
    {
        printf("\n\n===========MOVIE MENU============");
        printf("\n1. Add Movie");
        printf("\n2. Display Movies");
        printf("\n3. Serach Movie");
        printf("\n4. Update Rating");
        printf("\n5. Delete Movie");
        printf("\n6. Top Rated Movie");
        printf("\n7. Oldest Movie");
        printf("\n8. Movies Per Genre");
        printf("\n9. Exit");

        printf("\n\nChoose: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            printf("\nHow many movies? ");
            scanf("%d", &num_of_movies);
            getchar();

            inputMovieDetails(movies, num_of_movies);
            break;
        case 2:
            displayMovieDetails(movies, num_of_movies);
            break;
        case 3:
            printf("\nSearch... ");
            fgets(search, sizeof(search), stdin);
            search[strcspn(search, "\n")] = 0;

            searchMovie(movies, num_of_movies, search);
            break;
        case 4:
            printf("\nSearch for a Movie: ");
            fgets(search_update, sizeof(search_update), stdin);
            search_update[strcspn(search_update, "\n")] = 0;

            printf("\nEnter you Proposed rating: ");
            scanf("%f", &proposed_rating);
            getchar();

            updateMovieRating(movies, num_of_movies, search_update, proposed_rating);
            break;
        case 5:
            printf("\nSearch for Movie to delete: ");
            fgets(search_delete, sizeof(search_delete), stdin);
            search_delete[strcspn(search_delete, "\n")] = 0;

            deleteMovie(movies, num_of_movies, search_delete);

            num_of_movies = deleteMovie(movies, num_of_movies, search_delete);
            break;
        case 6:
            int highestRated = findHighestRated(movies, num_of_movies);
            printf("\n\nHighest Rated Movie: %s (%.1f)", movies[highestRated].title, movies[highestRated].rating);
            break;
        case 7:
            int oldestMovie = findOldestMovie(movies, num_of_movies);
            printf("\n\nOldest Movie: %s - %d", movies[oldestMovie].title, movies[oldestMovie].year);
            break;
        case 8:
            printf("\n\nEnter Genre to count: ");
            scanf("%s", genre);
            getchar();

            int movieCount = countofMoviesPerGenre(movies, num_of_movies, genre);
            printf("\nMovies in %s genre: %d", genre, movieCount);
            break;
        case 9:
            printf("\nGoodbye!");
            running = 0;
            break;
        default:
            printf("\nInvalid Choice. Try Again!");
        }
    }

    return 0;
}
