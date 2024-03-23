#include <iostream>
using namespace std;

const int INF = 100000;
static int NUM_VERTICES;

void print(int arr[]) {
    for(int i = 0; i < NUM_VERTICES; i++){
        if (arr[i] == INF)
            cout << "inf  ";
        else
            cout << arr[i] << "  ";
    }
        
    cout << endl;
}

void print(char arr[]) {
    for(int i = 0; i < NUM_VERTICES; i++)
        cout << arr[i] << "  ";
    cout << endl;
}



int main() {

    int num_connections,curr_conn;
    cout << "Enter number of vertices: ";
    cin >> NUM_VERTICES;

    char* vertices = new char [NUM_VERTICES];   //vertex names
    int* connections = new int [NUM_VERTICES];  //connections per vertex
    char** connected_vertices = new char* [NUM_VERTICES];
    int** weights = new int* [NUM_VERTICES];    //weights for each connected vertex

    cout << "Enter corresponding vertices(For example: a,b,c...):\n";
    for (int i=0;i<NUM_VERTICES;i++){
        cout << "Vertex " << i+1 << ": ";
        cin >> vertices[i];
    }

    cout << "Enter number of connections for each vertex:\n";
    for (int i=0;i<NUM_VERTICES;i++){
        cout << "Vertex " << vertices[i] << ": ";
        cin >> connections[i];
    }

    int max_conn=connections[0];
    for (int i=1;i<NUM_VERTICES;i++){
        if (connections[i]>max_conn)
            max_conn = connections[i];
    }
    
    //allocating memory for 2-d array according to max connection
    for (int i = 0; i < NUM_VERTICES; i++) {
        connected_vertices[i] = new char[max_conn];
        weights[i] = new int[max_conn];
    }

    // input - connections and weights
    for (int i=0;i<NUM_VERTICES;i++){
        cout << "Enter connected vertices and weights for Vertex " << vertices[i] << ":\n";
        curr_conn = connections[i];

        for (int j=0;j<curr_conn;j++){
            cout << "Vertex: ";
            cin >> connected_vertices[i][j];
            cout << "Weight: ";
            cin >> weights [i][j];
        }
    }

    char starting_vertex = vertices[0];
    int* temp_labels = new int [NUM_VERTICES];
    int* perm_labels = new int [NUM_VERTICES];
    int* perm_indices = new int [NUM_VERTICES];

    temp_labels[0] =0;
    perm_labels[0] =0;
    perm_indices[0] = 0;

    for (int i = 1; i < NUM_VERTICES; i++) {
        temp_labels[i] = INF;
        perm_labels[i] = INF;
        perm_indices[i] = -1;
    }

    int last_perm_index = 0;
    bool complete = false;
    int iter_num = 1;

    while(!complete) {
        complete = true;
        for(int i = 1; i < NUM_VERTICES; i++) {
            if (temp_labels[i] != perm_labels[i] || perm_labels[i] == INF) {
                int distance = INF;
                int temp_index = i;
                int temp_connections = connections[i];
                char permanent_vertex = vertices[last_perm_index];

                for (int j = 0; j < temp_connections; j++) {
                    if (permanent_vertex == connected_vertices[temp_index][j])
                        distance = weights[temp_index][j];
                }

                temp_labels[i] = min(temp_labels[i], temp_labels[last_perm_index] + distance);
            }
        }
        for (int i = 0; i < NUM_VERTICES; i++) {
            if (temp_labels[i] != perm_labels[i] || perm_labels[i] == INF) 
                complete = false;
            
        }

        int min_index = -1;

        for (int i = 0; i < NUM_VERTICES; i++) {
            if (i != last_perm_index && perm_indices[i] == -1) {
                min_index = i;
                break;
            }
        }

        if (min_index == -1)
            break;

        
        int perm_index, perm_label_values;
        bool less = false;

        for (int i = 0; i < NUM_VERTICES; i++) {
            if (i != last_perm_index && perm_indices[i] == -1) {
                if (temp_labels[i] < temp_labels[min_index] && temp_labels[i] != INF) {
                    perm_index = i;
                    perm_label_values = temp_labels[i];
                    perm_indices[i] = i;
                    less = true;
                }
            }
        }

        if (!less){
            for (int i = 0; i < NUM_VERTICES; i++) {
                if (i != last_perm_index && perm_indices[i] == -1) {
                    if (temp_labels[i] == temp_labels[min_index] && temp_labels[i] != INF) {
                        perm_index = i;
                        perm_label_values = temp_labels[i];
                        perm_indices[i] = i;
                    }
                }
            }
        }

        perm_labels[perm_index] = perm_label_values;
        last_perm_index = perm_index;

    }

    cout << "Distances from u to all other vertices:\n";
    print(vertices);
    print(perm_labels);

    for (int i = 0; i < NUM_VERTICES; i++) {
        delete[] connected_vertices[i];
        delete[] weights[i];
    }
    delete[] connected_vertices;
    delete[] weights;
    delete[] temp_labels;
    delete[] perm_labels;
    delete[] perm_indices;

    return 0;
}
