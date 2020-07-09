#include <stdlib.h>
#include <climits>
#include <stdio.h>
#include <math.h>
#include <utility>
#include <vector>

using namespace std;

void vizinhoMaisProximo(int vert, pair<int*,int>& l, int **m, int inicio);
void vizinhoMaisDistante(int vert, pair<int*,int>& l, int **m, int inicio);
void maisBarata(int vert, pair<int*,int>& l, int **m, int inicio);
int refinamento2Opt(int vert, pair<int*,int>& l, int **m);
void troca2Opt(int first, int second, pair<int*,int>& l);
int refinamentoReinsercao(int vert, pair<int*,int>& l, int **m);
void pushVertice(int posAntiga, int posNova, pair<int*,int>& l);
int VND(int vert, pair<int*,int>& l, int **m);
int multiStart(int vert, pair<int*,int>& l, int **m, int inicio, int times);
int partition(pair<int,int>*& v, int start, int end);
void quickSort(pair<int,int>*& v, int start, int end);