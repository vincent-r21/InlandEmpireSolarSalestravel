/*
Program requirements:
1. If the marketing specialist begins the trip from home in Riverside, determine the variations of the trip to the noted cities that he must take to market the solar products.
2. Determine shortest path, and the most low-cost trips for the marketing specialist.
3. Create a C++ program to provide the representation of the trips, low-cost and shortest paths, including matrices, adjacencies.
4. Provide documentation that explains solution and programming approaches.
*/

#include <iostream>
#include <vector> 
#include <climits> // For utilization of INT_MAX which is used to represent absence of a direct connection between nodes
#include <string>  // For more feasible string manipulation
#include <iomanip> // For output formatting
#include <cfloat>  // For FLT_MAX to handle float costs
using namespace std;

// Define number of cities
const int NUM_CITIES = 4; // Riverside, Moreno Valley, Perris, Hemet
const string CITY_NAMES[NUM_CITIES] = { "Riverside", "Moreno Valley", "Perris", "Hemet" };

// Adjacency matrix for distances between cities (rounded to the nearest miles)
int distances[NUM_CITIES][NUM_CITIES] =
{
    {0, 16, 24, 33},  // Riverside to other cities
    {16, 0, 18, 26},  // Moreno Valley to other cities
    {24, 18, 0, 30},  // Perris to other cities
    {33, 26, 30, 0}   // Hemet to other cities
};

// Adjacency matrix for costs (calculated based on realistic fuel costs per mile with decimals for cents)
// Use floats to allow precise cost calculations (below numbers are already calculated/given based on miles per gallon equation)
float costs[NUM_CITIES][NUM_CITIES] =
{
    {0.0f, 2.40f, 3.60f, 4.95f}, // Costs from Riverside to others
    {2.40f, 0.0f, 2.70f, 4.35f}, // Costs from Moreno Valley to others
    {3.60f, 2.70f, 0.0f, 4.80f}, // Costs from Perris to others
    {4.95f, 4.35f, 4.80f, 0.0f}  // Costs from Hemet to others
};

// Generic function to display matrices (supports both int and float types)
template <typename T>
void displayMatrix(const string& title, T matrix[NUM_CITIES][NUM_CITIES])
{
    // Displays the adjacency matrix with proper formatting
    cout << title << ":\n\n";
    cout << setw(15) << " "; // Leave space for row headers
    for (int i = 0; i < NUM_CITIES; ++i)
        cout << setw(15) << CITY_NAMES[i]; // Column headers for cities
    cout << endl;
    cout << string(15 * (NUM_CITIES + 1), '-') << endl; // Line separator for better readability

    for (int i = 0; i < NUM_CITIES; ++i)
    {
        cout << setw(15) << CITY_NAMES[i]; // Row headers for cities
        for (int j = 0; j < NUM_CITIES; ++j)
        {
            // Check if the node is unreachable
            if (matrix[i][j] == FLT_MAX) // FLT_MAX for float infinity representation
                cout << setw(15) << "INF"; // Display 'INF' for unreachable nodes
            else
                // Use fixed precision for float values
                cout << setw(15) << fixed << setprecision(2) << matrix[i][j];
        }
        cout << endl; // New line after each row
    }
    cout << endl;
}

// Dijkstra's Algorithm to find shortest & lowest-cost paths    // Can handle both int and float matrices
template <typename T>
void dijkstra(T graph[NUM_CITIES][NUM_CITIES], int startCity, const string& metric)
{
    // Step 1 - Initialization
    vector<float> dist(NUM_CITIES, FLT_MAX); // Distance array initialized to infinity (FLT_MAX for float compatibility)
    vector<bool> visited(NUM_CITIES, false); // All cities are initially unvisited
    vector<int> previous(NUM_CITIES, -1);    // To store/track the path
    dist[startCity] = 0; // Distance to the starting city is 0

    // Step 2 - Process each city
    for (int i = 0; i < NUM_CITIES - 1; ++i)
    {
        float minDist = FLT_MAX; // Smallest known distance (float version of infinity)
        int u = -1; // Variable to track the city with the smallest distance

        // Find the unvisited city with the smallest distance
        for (int j = 0; j < NUM_CITIES; ++j)
        {
            if (!visited[j] && dist[j] < minDist) // Only consider unvisited cities
            {
                minDist = dist[j]; // Update smallest distance
                u = j;             // Update city index
            }
        }

        if (u == -1) break; // Exit if no city is reachable
        visited[u] = true;  // Mark the city as visited

        // Step 3 - Update distances for adjacent nodes
        for (int v = 0; v < NUM_CITIES; ++v)
        {
            // If there's a valid connection and a shorter path is found
            if (!visited[v] && graph[u][v] != 0 && dist[u] != FLT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v]; // Update the shortest distance
                previous[v] = u; // Track the path
            }
        }
    }

    // Step 4 - Output results
    cout << "\nResults for " << metric << " from " << CITY_NAMES[startCity] << ":\n";
    cout << string(60, '-') << endl; // Line separator for clear sectioning
    cout << left << setw(15) << "Destination" << setw(15) << "Distance/Cost" << "Path\n";
    cout << string(60, '-') << endl;

    for (int i = 0; i < NUM_CITIES; ++i)
    {
        if (dist[i] == FLT_MAX)
        {
            // If unreachable, indicate no path
            cout << setw(15) << CITY_NAMES[i] << setw(15) << "INF" << "No Path\n";
        }
        else
        {
            // Display the shortest distance or lowest cost and the path
            cout << setw(15) << CITY_NAMES[i] << setw(15) << fixed << setprecision(2) << dist[i];
            vector<int> path; // Path to the destination
            for (int at = i; at != -1; at = previous[at])
                path.push_back(at); // Backtrack through previous array
            for (int j = path.size() - 1; j >= 0; --j)
            {
                cout << CITY_NAMES[path[j]];
                if (j > 0) cout << " -> "; // Arrow separator for the path
            }
            cout << endl;
        }
    }
    cout << endl;
}

int main()
{
    // Welcome message to users
    cout << "Welcome to the Inland Empire Solar Sales Travel Program!\n";
    cout << "Here are the cities:\n";

    // Display the cities for user selection
    for (int i = 0; i < NUM_CITIES; ++i)
        cout << i << ": " << CITY_NAMES[i] << endl;

    // Process 1: Receive user input for the starting city
    int startCity;
    cout << "Enter the number of the starting city: ";
    cin >> startCity;

    // Validate user input
    if (cin.fail() || startCity < 0 || startCity >= NUM_CITIES)
    {
        // If input is invalid, notify the user and exit
        cout << "Invalid city number. Exiting program.\n";
        return 1;
    }

    // Process 2: Display adjacency matrices
    cout << "\nAdjacency Matrix of Distances:\n";
    displayMatrix("Distances (Miles)", distances);

    cout << "\nAdjacency Matrix of Costs:\n";
    displayMatrix("Costs (Dollars)", costs);

    // Process 3: Compute shortest paths based on distances
    cout << "\nCalculating shortest paths...";
    dijkstra(distances, startCity, "Shortest Distance (in miles)");

    // Process 4: Compute lowest-costing paths based on fuel costs
    cout << "\nCalculating most cost-effective paths...";
    dijkstra(costs, startCity, "Lowest Cost (in U.S dollars)");

    return 0;
}
