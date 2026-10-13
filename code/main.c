#include <stdio.h>
#include <string.h>

#define MAX 20          
#define INF 999999      

int  n = 0;             
char name[MAX][30];     
int  dist[MAX][MAX];    
int  rate = 1;          


void createGraph()
{
    int i, j, d;

    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            dist[i][j] = 0;

    printf("\nHow many buildings are there (2 to %d)? ", MAX);
    scanf("%d", &n);
    if (n < 2 || n > MAX) {
        printf("Invalid number of buildings.\n");
        n = 0;
        return;
    }

    printf("\nEnter building names (no spaces, use _ if needed):\n");
    for (i = 0; i < n; i++) {
        printf("  Building %d name: ", i + 1);
        scanf("%29s", name[i]);
    }

    printf("\nEnter the distance in metres between each pair of buildings.\n");
    printf("Enter 0 if the two buildings cannot be connected directly.\n\n");
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            do {
                printf("  %s <-> %s : ", name[i], name[j]);
                scanf("%d", &d);
                if (d < 0)
                    printf("  Distance cannot be negative. Try again.\n");
            } while (d < 0);

            dist[i][j] = d;
            dist[j][i] = d;      
        }
    }

    printf("\nCost of laying cable per metre (e.g. 100): ");
    scanf("%d", &rate);
    if (rate < 1) rate = 1;

    printf("\nGraph created successfully.\n");
}

void showMatrix()
{
    int i, j;

    if (n == 0) {
        printf("\nPlease create the graph first (option 1).\n");
        return;
    }

    printf("\nDistance matrix in metres (0 = no direct link):\n\n");
    printf("%-12s", "");
    for (j = 0; j < n; j++)
        printf("%-12s", name[j]);
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%-12s", name[i]);
        for (j = 0; j < n; j++)
            printf("%-12d", dist[i][j]);
        printf("\n");
    }
}

int prim(int start, int show)
{
    int key[MAX];        
    int parent[MAX];     
    int visited[MAX];    
    int order[MAX];      
    int count = 0;
    int total = 0;
    int i, u, v;

    for (i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = -1;
        visited[i] = 0;
    }
    key[start] = 0;          

    for (i = 0; i < n; i++) {

        u = -1;
        for (v = 0; v < n; v++) {
            if (visited[v] == 0 && (u == -1 || key[v] < key[u]))
                u = v;
        }

        if (key[u] == INF) {
            if (show)
                printf("\nWARNING: Graph is DISCONNECTED! "
                       "Some buildings cannot be reached.\n");
            return -1;
        }

        visited[u] = 1;
        order[count] = u;
        count++;
        total = total + key[u];

       for (v = 0; v < n; v++) {
            if (dist[u][v] > 0 && visited[v] == 0 && dist[u][v] < key[v]) {
                key[v] = dist[u][v];
                parent[v] = u;
            }
        }
    }

    /* Step 5 : print the result */
    if (show) {
        printf("\nSelection order:\n  ");
        for (i = 0; i < count; i++) {
            printf("%s", name[order[i]]);
            if (i < count - 1) printf(" -> ");
        }
        printf("\n");

        printf("\n%-14s %-14s %s\n", "Parent", "Child", "Distance(m)");
        printf("----------------------------------------\n");
        for (i = 1; i < count; i++) {
            v = order[i];
            printf("%-14s %-14s %d\n", name[parent[v]], name[v], key[v]);
        }
        printf("----------------------------------------\n");
        printf("Total cable length    : %d metres\n", total);
        printf("Total installation cost: %d  (rate %d per metre)\n",
               total * rate, rate);
    }

    return total;
}

int chooseStart()
{
    int i, s;

    printf("\nBuildings:\n");
    for (i = 0; i < n; i++)
        printf("  %d. %s\n", i + 1, name[i]);

    printf("Select starting building number: ");
    scanf("%d", &s);

    if (s < 1 || s > n) {
        printf("Invalid choice.\n");
        return -1;
    }
    return s - 1;
}


void runPrim()
{
    int s;

    if (n == 0) {
        printf("\nPlease create the graph first (option 1).\n");
        return;
    }

    s = chooseStart();
    if (s == -1) return;

    printf("\nMinimum cost network starting from %s:\n", name[s]);
    prim(s, 1);
}

void compareStarts()
{
    int i, t;

    if (n == 0) {
        printf("\nPlease create the graph first (option 1).\n");
        return;
    }

    printf("\n%-16s %-16s %s\n", "Start building", "Cable length(m)", "Cost");
    printf("--------------------------------------------\n");
    for (i = 0; i < n; i++) {
        t = prim(i, 0);
        if (t == -1)
            printf("%-16s Disconnected graph\n", name[i]);
        else
            printf("%-16s %-16d %d\n", name[i], t, t * rate);
    }
    printf("\nNote: the MST total is the same for every start.\n");
    printf("Only the selection order can change.\n");
}


/* ------------------------------------------------------------
   OPTION 5 : Validate connectivity
   ------------------------------------------------------------ */
void checkConnectivity()
{
    if (n == 0) {
        printf("\nPlease create the graph first (option 1).\n");
        return;
    }

    if (prim(0, 0) == -1)
        printf("\nWARNING: Graph is DISCONNECTED. "
               "Add more connections.\n");
    else
        printf("\nGraph is CONNECTED. All buildings can be linked.\n");
}


/* ------------------------------------------------------------
   Main menu
   ------------------------------------------------------------ */
int main()
{
    int choice;

    do {
        printf("\n========== CAMPUS NETWORK PLANNER (PRIM'S) ==========\n");
        printf("1. Create graph (buildings and distances)\n");
        printf("2. Show distance matrix\n");
        printf("3. Find minimum cost network from a starting building\n");
        printf("4. Compare results from all starting buildings\n");
        printf("5. Check connectivity\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
            break;

        switch (choice) {
            case 1: createGraph();       break;
            case 2: showMatrix();        break;
            case 3: runPrim();           break;
            case 4: compareStarts();     break;
            case 5: checkConnectivity(); break;
            case 6: printf("\nThank you!\n"); break;
            default: printf("\nInvalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
