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

        printf("\nGenre: ");
        scanf("%s", s[i].genre);
        getchar();
    }
}

void displayMovieDetails(struct Movie s[], int num_of_movies)
{

    printf("\n\n====================MOVIE DETAILS====================");
    printf("\n%-15s %-12s %-10s %-10s %-15s", "Title", "Director", "Year", "Rating", "Genre");
    printf("\n-------------------------------------------------------");
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

int main()
{
    struct Movie movies[10];
    int num_of_movies;
    char genre[30];

    printf("\nHow many movies? ");
    scanf("%d", &num_of_movies);
    getchar();

    inputMovieDetails(movies, num_of_movies);

    displayMovieDetails(movies, num_of_movies);

    int highestRated = findHighestRated(movies, num_of_movies);
    printf("\n\nHighest Rated Movie: %s (%.1f)", movies[highestRated].title, movies[highestRated].rating);

    int oldestMovie = findOldestMovie(movies, num_of_movies);
    printf("\n\nOldest Movie: %s - %d", movies[oldestMovie].title, movies[oldestMovie].year);

    printf("\n\nEnter Genre to count: ");
    scanf("%s", genre);
    getchar();

    int movieCount = countofMoviesPerGenre(movies, num_of_movies, genre);
    printf("\nMovies in %s genre: %d", genre, movieCount);

    return 0;
}