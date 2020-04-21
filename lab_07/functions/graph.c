#include <string.h>

#include "graph.h"
#include "parser.h"

void print_matrix(char array_station[LEN][MAX_LEN_STATION], int matrix[LEN][LEN], int n)
{
    printf("             ");
    for (int i = 0; i < n; i++)
        printf("%25s ", array_station[i]);

    puts("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%10s ", array_station[i]);
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == INF)
                printf("    oo    ");
            else
                printf("    %7d    ", matrix[i][j]);
        }
        printf("\n\n\n");
    }
}

void reset_function(int matrix[LEN][LEN], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = INF;
}

void parser_matrix(FILE *f, char array_station[LEN][MAX_LEN_STATION], int matrix[LEN][LEN])
{
    char station_first[MAX_LEN_STATION];
    char station_second[MAX_LEN_STATION];
    int length;
    int price;

    int count = 0;

    fseek(f, COUNT_INFO, 0);

    while (!feof(f))
    {
        fscanf(f, "%s -- %s [label=\" %d, %d \"];", station_first, station_second, &length, &price);

        if (!strcmp(station_first, "}") || !strcmp(station_second, "}"))
            break;

        matrix[find_station(array_station, station_first)][find_station(array_station, station_second)] = length + price;
        matrix[find_station(array_station, station_second)][find_station(array_station, station_first)] = length + price;

        // printf("%d = %s -- %d = %s\n", find_station(array_station, station_first), station_first, find_station(array_station, station_second), station_second);
        // printf("%s -- %s [label=\" %d, %d \"];\n", station_first, station_second, length, price);
    }
}

void floid(int count, int matrix[LEN][LEN], int path[LEN][LEN], int dist[LEN][LEN])
{
    // инициализация матриц путей и расстояний
    for (int u = 0; u < count; ++u)
        for (int v = 0; v < count; ++v)
            if (matrix[u][v] || u == v)
            {
                path[u][v] = v;
                dist[u][v] = matrix[u][v];
            }
            else
            {
                path[u][v] = LEN;
                dist[u][v] = INF;
            }

    // сам алгоритм флойда
    for (int k = 0; k < count; ++k)
        for (int u = 0; u < count; ++u)
            if (dist[u][k] != INF)
                for (int v = 0; v < count; ++v)
                    if (dist[u][v] > dist[u][k] + dist[k][v])
                    {
                        dist[u][v] = dist[u][k] + dist[k][v];
                        path[u][v] = path[u][k];
                    }
}

void show_path(int start, int end, int path[LEN][LEN], int dist[LEN][LEN], char station[LEN][MAX_LEN_STATION])
{

    // вывод пути из вершины u в v и расстояния между ними
    if (path[start][end] == LEN)
    {
        printf("Нет пути!\n");
        return;
    }

    int x = start;

    printf("%10s", station[x]);
    while (x != end)
    {
        printf(" %10s", station[x = path[x][end]]);
    }
    printf(" (S + P = %d)\n", dist[start][end]);
}