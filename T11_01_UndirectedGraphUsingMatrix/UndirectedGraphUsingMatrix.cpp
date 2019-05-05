#include <iostream>

using namespace std;

#define MAX_VERTEX  10

class UndirectedGraphUsingMatrix
{
public:
    UndirectedGraphUsingMatrix(int vertexs[], int vertexLen, int edges[][2], int edgeLen):mVertexs(), mMartrix(), mVertexNum(0), mEdgeNum(0)
    {
        mVertexNum = vertexLen;
        mEdgeNum = edgeLen;
        for (int i = 0; i < mVertexNum; i++)
        {
            mVertexs[i] = vertexs[i];
        }
        for (int i = 0; i < mEdgeNum; i++)
        {
            int v1 = getPosition(edges[i][0]);
            int v2 = getPosition(edges[i][1]);
            mMartrix[v1][v2] = 1;
            mMartrix[v2][v1] = 1;
        }
    }

    ~UndirectedGraphUsingMatrix()
    {

    }

    int getPosition(int vertex)
    {
        for (int i = 0; i < mVertexNum; i++)
        {
            if (mVertexs[i] == vertex)
            {
                return i;
            }
        }

        return -1;
    }

    void print()
    {
        cout << "the martrix of graph is:" << endl;
        for (int i = 0; i < mVertexNum; i++)
        {
            for (int j = 0; j < mVertexNum; j++)
            {
                cout << mMartrix[i][j] << "  ";
            }
            cout << endl;
        }
    }
protected:
private:
    int mVertexs[MAX_VERTEX];
    int mVertexNum;
    int mEdgeNum;
    int mMartrix[MAX_VERTEX][MAX_VERTEX];
};

void test1()
{
    int vertexs[] = { 1, 2, 3, 4, 5, 6, 7 };
    int edges[][2] = {
        {1, 3},
        {1, 4},
        {1, 6},
        {2, 3},
        {3, 4},
        {5, 7},
        {6, 7}
    };

    int vertexLen = sizeof(vertexs) / sizeof(vertexs[0]);
    int edgeLen = sizeof(edges) / sizeof(edges[0]);

    UndirectedGraphUsingMatrix graph(vertexs, vertexLen, edges, edgeLen);
    graph.print();
    
}

int main(int argc, char** argv)
{
    test1();
    getchar();
    return 0;
}