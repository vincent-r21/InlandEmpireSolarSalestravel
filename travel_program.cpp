#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <iomanip> // For better output formatting
#include <cfloat>  // For FLT_MAX
using namespace std;

// Define number of cities and city names
const int NUM_CITIES = 4;
const string CITY_NAMES[NUM_CITIES] = { "Riverside", "Moreno Valley", "Perris", "Hemet" };

// Adjacency matrix for distances (in miles)
int distances[NUM_CITIES][NUM_CITIES] = 
{
    {0, 16, 24, 33},
    {16, 0, 18, 26},
    {24, 18, 0, 30},
    {33, 26, 30, 0}
};

// Adjacency matrix for costs (in dollars, with decimal precision)
float costs[NUM_CITIES][NUM_CITIES] = 
{
    {0.0f, 2.40f, 3.60f, 4.95f},
    {2.40f, 0.0f, 2.70f, 4.35f},
    {3.60f, 2.70f, 0.0f, 4.80f},
    {4.95f, 4.35f, 4.80f, 0.0f}
};

// Function to display a matrix (int or float)
template <typename T>
void displayMatrix(const string& title, T matrix[NUM_CITIES][NUM_CITIES]) 
{
    cout << title << ":\n\n";
    cout << setw(15) << " ";
    for (int i = 0; i < NUM_CITIES; ++i)
        cout << setw(15) << CITY_NAMES[i];
    cout << endl;

    for (int i = 0; i < NUM_CITIES; ++i) 
    {
        cout << setw(15) << CITY_NAMES[i];
        for (int j = 0; j < NUM_CITIES; ++j) 
        {
            if (matrix[i][j] == INT_MAX)
                cout << setw(15) << "INF";
            else
                cout << setw(15) << fixed << setprecision(2) << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// Dijkstra's algorithm for shortest path or lowest cost
template <typename T>
void dijkstra(T graph[NUM_CITIES][NUM_CITIES], int startCity, const string& metric) 
{
    vector<float> dist(NUM_CITIES, FLT_MAX);
    vector<bool> visited(NUM_CITIES, false);
    vector<int> previous(NUM_CITIES, -1);
    dist[startCity] = 0;

    for (int i = 0; i < NUM_CITIES - 1; ++i) 
    {
        float minDist = FLT_MAX;
        int u = -1;

        // Find unvisited city with smallest distance
        for (int j = 0; j < NUM_CITIES; ++j) 
        {
            if (!visited[j] && dist[j] < minDist) 
            {
                minDist = dist[j];
                u = j;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < NUM_CITIES; ++v) 
        {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != FLT_MAX &&
                dist[u] + graph[u][v] < dist[v]) 
            {
                dist[v] = dist[u] + graph[u][v];
                previous[v] = u;
            }
        }
    }

    cout << "Results for " << metric << " from " << CITY_NAMES[startCity] << ":\n";
    cout << left << setw(15) << "Destination" << setw(15) << "Distance/Cost" << "Path\n";

    for (int i = 0; i < NUM_CITIES; ++i) 
    {
        if (dist[i] == FLT_MAX) 
        {
            cout << setw(15) << CITY_NAMES[i] << setw(15) << "INF" << "No Path\n";
        } 
        else 
        {
            cout << setw(15) << CITY_NAMES[i] << setw(15) << fixed << setprecision(2) << dist[i];
            vector<int> path;
            for (int at = i; at != -1; at = previous[at])
                path.push_back(at);
            for (int j = path.size() - 1; j >= 0; --j) 
            {
                cout << CITY_NAMES[path[j]];
                if (j > 0) cout << " -> ";
            }
            cout << endl;
        }
    }
    cout << endl;
}

int main() 
{
    cout << "Welcome to the Inland Empire Solar Sales Travel Program!\n";
    cout << "Here are the cities:\n";

    for (int i = 0; i < NUM_CITIES; ++i)
        cout << i << ": " << CITY_NAMES[i] << endl;

    int startCity;
    cout << "Enter the number of the starting city: ";
    cin >> startCity;

    // Validate input
    if (cin.fail() || startCity < 0 || startCity >= NUM_CITIES) 
    {
        cout << "Invalid input. Please enter a number between 0 and " << NUM_CITIES - 1 << ".\n";
        return 1;
    }

    cout << "\nAdjacency Matrix of Distances:\n";
    displayMatrix("Distances (Miles)", distances);

    cout << "\nAdjacency Matrix of Costs:\n";
    displayMatrix("Costs (Dollars)", costs);

    cout << "\nCalculating shortest paths...\n";
    dijkstra(distances, startCity, "Shortest Distance");

    cout << "\nCalculating most cost-effective paths...\n";
    dijkstra(costs, startCity, "Lowest Cost");

    return 0;
}
