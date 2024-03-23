#include <iostream>
using namespace std;

int main(){

    int num_vertices, num_connections,curr_conn;
    cout << "Enter number of vertices: ";
    cin >> num_vertices;

    char* vertices = new char [num_vertices];   //vertex names
    int* connections = new int [num_vertices];  //connections per vertex
    char** connected_vertices = new char* [num_vertices];
    int** weights = new int* [num_vertices];    //weights for each connected vertex
    
    cout << "Enter corresponding vertices(For example: a,b,c...):\n";
    for (int i=0;i<num_vertices;i++){
        cout << "Vertex " << i+1 << ": ";
        cin >> vertices[i];
    }

    cout << "Enter number of connections for each vertex:\n";
    for (int i=0;i<num_vertices;i++){
        cout << "Vertex " << vertices[i] << ": ";
        cin >> connections[i];
        char c = connections[i];

        connected_vertices[i] = new char [c];
        weights[i] = new int [c];
    }

    for (int i=0;i<num_vertices;i++){
        cout << "Enter connected vertices and weights for Vertex " << vertices[i] << ":\n";
        curr_conn = connections[i];

        for (int j=0;j<curr_conn;j++){
            cout << "Vertex: ";
            cin >> connected_vertices[i][j];
            cout << "Weight: ";
            cin >> weights [i][j];
        }
    }


    return 0;
}