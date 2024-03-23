#include <iostream>
using namespace std;

const int INF = 100000;
const int NUM_VERTICES=4;

void print(int arr[]){
    for(int i=0;i<NUM_VERTICES;i++)
        cout << arr[i] << "  ";
    cout << endl;
}
void print(char arr[]){
    for(int i=0;i<NUM_VERTICES;i++)
        cout << arr[i] << "  ";
    cout << endl;
}


int main(){

    char vertices[NUM_VERTICES] = {'u','a','b','d'};
    int connections[NUM_VERTICES] = {2,2,2,2};  
    char** connected_vertices = new char* [NUM_VERTICES];
    int** weights = new int* [NUM_VERTICES];    
    
    for (int i=0;i<NUM_VERTICES;i++){
        connected_vertices[i] = new char [2];
        weights[i] = new int [2];
    }

    connected_vertices[0][0] ='a';
    connected_vertices[0][1] ='b';
    connected_vertices[1][0] ='u';
    connected_vertices[1][1] ='d';
    connected_vertices[2][0] ='u';
    connected_vertices[2][1] ='d';
    connected_vertices[3][0] ='a';
    connected_vertices[3][1] ='b';
    
    weights[0][0] =2;
    weights[0][1] =3;
    weights[1][0] =2;
    weights[1][1] =4;
    weights[2][0] =3;
    weights[2][1] =5;
    weights[3][0] =4;
    weights[3][1] =5;
    

    char starting_vertex = vertices[0];

    int temp_labels[NUM_VERTICES] = {0,INF,INF,INF};
    int perm_labels[NUM_VERTICES] = {0,INF,INF,INF};
    int perm_indices[NUM_VERTICES] = {0,-1,-1,-1};
    int last_perm_index = 0;

    bool complete=false;

    
    while(!complete){ 
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

        for (int i=0;i<NUM_VERTICES;i++){
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

    
    

    return 0;
}