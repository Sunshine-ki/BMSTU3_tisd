#include <stdio.h>

#define N 100
#define INF 1000000

void read_graph(int adj[N][N], int n)
{
    // граф считывается следующим образом: сначала считывается кол-во вершин и кол-во ребер,
    // а затем ребра в следующем формате: <начальная вершина> <конечная вершина> <расстояние между ними>
    // замечание: данная функция считывает орграф
    int m;
    printf("Введите  кол-во вершин и кол-во ребер\n");
    scanf("%d %d", &n, &m);
    printf("Введите тройки <начальная вершина> <конечная вершина> <расстояние между ними>\n");
    for (int u, v, w; m--; adj[u][v] = w)
        scanf("%d%d%d", &u, &v, &w);
}

void floid(int adj[N][N], int path[N][N], int dist[N][N], int n)
{
    // инициализация матриц путей и расстояний
    for (int u = 0; u < n; ++u)
        for (int v = 0; v < n; ++v)
            if (adj[u][v] || u == v)
            {
                path[u][v] = v;
                dist[u][v] = adj[u][v];
            }
            else
            {
                path[u][v] = N;
                dist[u][v] = INF;
            }

    // сам алгоритм флойда
    for (int k = 0; k < n; ++k)
        for (int u = 0; u < n; ++u)
            if (dist[u][k] != INF)
                for (int v = 0; v < n; ++v)
                    if (dist[u][v] > dist[u][k] + dist[k][v])
                    {
                        dist[u][v] = dist[u][k] + dist[k][v];
                        path[u][v] = path[u][k];
                    }
}

void show_path(int u, int v, int path[N][N], int dist[N][N])
{
    // вывод пути из вершины u в v и расстояния между ними
    if (path[u][v] == N)
    {
        printf("No path\n");
        return;
    }

    int x = u;

    printf("%d", x);
    while (x != v)
        printf(" %d", x = path[x][v]);
    printf(" (%d)\n", dist[u][v]);
}

int main()
{
    // const int N = 100;       // max количество вершин в графе
    // const int INF = 1000000; // бесконечное расстояние, указывает на то, что между вершинами нет пути

    int n;          // кол-во вершин в графе
    int adj[N][N];  // матрица смежности
    int path[N][N]; // матрица путей
    int dist[N][N]; // матрица расстояний
    int u, v;

    read_graph(adj, n);
    floid(adj, path, dist, n);

    while (1) // обрабатываем запросы вывода путей и расстояний между вершинами пока не нажато ctrl-Z (ну или ctrl-D)
    {
        printf("Enter source and destination vertices: ");
        scanf("%d%d", &u, &v);
        // if (EOF == scanf("%d%d", &u, &v))
        // break;
        show_path(u, v, path, dist);
    }

    return 0;
}