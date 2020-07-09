#include "heuristicas.hpp"
#include <unistd.h>

void vizinhoMaisProximo(int vert, pair<int*,int>& l, int **m, int inicio)
{
    int counter = 0;
    int res = 0;
    int marc[vert];
    l.first[counter] = inicio;

    for(int i = 0; i < vert; i++)
    {
        marc[i] = 0;
    }
    marc[inicio-1] = 1;
    for(int i = inicio-1; ;)
    {
        counter++;
        int temp = INT_MAX;
        for(int j = 0; j < vert; j++)
        {
            if(marc[j] == 0 && i != j && m[i][j] < temp)
            {
                temp = m[i][j];
                l.first[counter] = j+1;
            }
        }
        marc[l.first[counter]-1] = 1;
        res+=temp;
        i = l.first[counter]-1;
        if(counter == vert-1)
        {
            break;
        }
    }
    res+=m[inicio-1][l.first[vert-1]-1];
    l.first[vert] = l.first[0];
    l.second = res;

    /*for(int i = 0; i < vert; i++)
    {
        printf("%d ", l.first[i]);
    }
    printf("MAIS PRÓXIMO RES: %d\n", l.second);*/
}

void construcaoAleatoria(int vert, pair<int*,int>& l, int **m, int inicio)
{
    int counter = 0;
    l.second = 0;
    pair<pair<int,int>*,int*> vertDistMarc;
    vertDistMarc.first = (pair<int,int>*)malloc((vert) * sizeof(pair<int,int>));
    vertDistMarc.second = (int*)malloc((vert) * sizeof(int));

    for(int i = 0; i < vert; i++)
    {
        vertDistMarc.second[i] = 0;
    }
    l.first[counter] = inicio;
    vertDistMarc.second[inicio-1] = 1;
    for(int i = inicio - 1; ;)
    {
        counter++;
        int counter2 = 0;
        for(int j = 0; j < vert; j++)
        {
            if(i != j && vertDistMarc.second[j] == 0)
            {
                vertDistMarc.first[counter2].first = j;
                vertDistMarc.first[counter2].second = m[i][j];
                counter2++;
            }
        }
        quickSort(vertDistMarc.first, 0, vert-(vert-counter2)-1);
        int random = (rand() % (int)(ceil((vert-(vert-counter2))/2)+1));
        l.first[counter] = vertDistMarc.first[random].first + 1;
        l.second += vertDistMarc.first[random].second;
        vertDistMarc.second[vertDistMarc.first[random].first] = 1;
        i = l.first[counter]-1;
        if(counter == vert-1)
        {
            break;
        }
    }
    l.first[vert] = l.first[0];
    l.second += m[l.first[vert-1]-1][l.first[vert]-1];
}

void vizinhoMaisDistante(int vert, pair<int*,int>& l, int **m, int inicio)
{
    int counter = 0;
    int res = 0;
    int marc[vert];
    l.first[counter] = inicio;

    for(int i = 0; i < vert; i++)
    {
        marc[i] = 0;
    }
    marc[inicio-1] = 1;
    for(int i = inicio-1; ;)
    {
        counter++;
        int temp = INT_MIN;
        for(int j = 0; j < vert; j++)
        {
            if(marc[j] == 0 && i != j && m[i][j] > temp)
            {
                temp = m[i][j];
                l.first[counter] = j+1;
            }
        }
        marc[l.first[counter]-1] = 1;
        res+=temp;
        i = l.first[counter]-1;
        if(counter == vert-1)
        {
            break;
        }
    }
    res+=m[inicio-1][l.first[vert-1]-1];
    l.first[vert] = l.first[0];
    l.second = res;

    /*for(int i = 0; i < vert; i++)
    {
        printf("%d ", l.first[i]);
    }
    printf("MAIS DISTANTE RES: %d\n", l.second);*/
}

void maisBarata(int vert, pair<int*,int>& l, int **m, int inicio)
{
    int counter = 0;
    int res = 0;
    int marc[vert];
    l.first[counter] = inicio;

    for(int i = 0; i < vert; i++)
    {
        marc[i] = 0;
    }
    marc[inicio-1] = 1;
    for(int i = inicio-1; ;)
    {
        counter++;
        if(counter == 1)
        {
            int temp = INT_MAX;
            for(int j = 0; j < vert; j++)
            {
                if(marc[j] == 0 && i != j)
                {
                    if(m[i][j] < temp)
                    {
                        temp = m[i][j];
                        l.first[counter] = j+1;
                    }
                }
            }
            marc[l.first[counter]-1] = 1;
            i = l.first[counter]-1;
        }
        else
        {
            if(counter == 2)
            {
                int temp = INT_MAX;
                for(int j = 0; j < vert; j++)
                {
                    if(marc[j] == 0 && i != j)
                    {
                        if((m[l.first[0]-1][j] + m[l.first[1]-1][j]) < temp)
                        {
                            temp = m[0][j] + m[1][j];
                            l.first[counter] = j+1;
                        }
                    }
                }
                marc[l.first[counter]-1] = 1;
                res+=m[l.first[0]-1][l.first[counter]-1] + m[l.first[1]-1][l.first[counter]-1] + m[l.first[0]-1][l.first[1]-1];
            }
            else
            {
                if(counter <= vert-1)
                {
                    int temp = INT_MAX, tempI, pos;
                    for(int k = counter-1; k >= 1; k--)
                    {
                        for(int j = 0; j < vert; j++)
                        {
                            if(marc[j] == 0 && (l.first[k]-1) != j && (l.first[k-1]-1) != j)
                            {
                                if((m[l.first[k]-1][j] + m[l.first[k-1]-1][j] - m[l.first[k]-1][l.first[k-1]-1]) < temp)
                                {
                                    temp = (m[l.first[k]-1][j] + m[l.first[k-1]-1][j] - m[l.first[k]-1][l.first[k-1]-1]);
                                    tempI = j+1;
                                    pos = k;
                                }
                            }
                        }
                    }
                    for(int j = 0; j < vert; j++)
                    {
                        if(marc[j] == 0 && (l.first[0]-1) != j && (l.first[counter-1]-1) != j)
                        {
                            if((m[l.first[0]-1][j] + m[l.first[counter-1]-1][j] - m[l.first[0]-1][l.first[counter-1]-1]) < temp)
                            {
                                temp = (m[l.first[0]-1][j] + m[l.first[counter-1]-1][j] - m[l.first[0]-1][l.first[counter-1]-1]);
                                tempI = j+1;
                                pos = counter;
                            }
                        }
                    }
                    res+=temp;
                    marc[tempI-1] = 1;
                    if(pos != counter)
                    {
                        int j;
                        for(j = counter; j > pos; j--)
                        {
                            l.first[j] = l.first[j-1];
                        }
                        l.first[j] = tempI;
                    }
                    else
                    {
                        l.first[counter] = tempI;
                    }        
                }
                else
                {
                    break;
                }
            }            
        }
    }
    l.first[vert] = l.first[0];
    l.second = res;

    /*for(int i = 0; i < vert; i++)
    {
        printf("%d ", l.first[i]);
    }
    printf("MAIS BARATO RES: %d\n", l.second);*/
}

int refinamento2Opt(int vert, pair<int*,int>& l, int **m)
{
    int temp = l.second, temp2 = l.second;
    pair<int,int> pos;
    pos.first = -1;
    pos.second = -1;
    for(int i = 0; i < vert; i++)
    {
        for(int j = 0; j < vert; j++)
        {
            temp2 = l.second;
            if(l.first[j] != l.first[i] && l.first[j+1] != l.first[i] && l.first[j] != l.first[i+1] && l.first[j+1] != l.first[i+1])
            {
                temp2-=m[l.first[i]-1][l.first[i+1]-1];
                temp2-=m[l.first[j]-1][l.first[j+1]-1];
                temp2+=m[l.first[i]-1][l.first[j]-1];
                temp2+=m[l.first[i+1]-1][l.first[j+1]-1];
                if(temp2 < temp)
                {
                    temp = temp2;
                    pos.first = i+1;
                    pos.second = j;
                }
            }
        }
    }
    if(pos.first > -1 && pos.second > -1)
    {
        troca2Opt(pos.first, pos.second, l);
        l.second = temp;
        return 1;
    }
    else
    {
        return 0;
    }
}

void troca2Opt(int first, int second, pair<int*,int>& l)
{
    int aux;
    for(int i = first, j = second, count = 0; count <= floor((second-first)/2); i++, j--, count++)
    {
        aux = l.first[i];
        l.first[i] = l.first[j];
        l.first[j] = aux;
    }
}

int refinamentoReinsercao(int vert, pair<int*,int>& l, int **m)
{
    int temp = l.second, temp2 = l.second, temp3 = l.second;
    pair<int,int> pos;
    pos.first = -1;
    pos.second = -1;
    for(int i = 1; i < vert; i++)
    {
        for(int j = 1; j < vert; j++)
        {
            temp2 = l.second;
            if(i > j)
            {
                temp2-=m[l.first[i-1]-1][l.first[i]-1];
                temp2-=m[l.first[i]-1][l.first[i+1]-1];
                temp2+=m[l.first[i-1]-1][l.first[i+1]-1];
                temp2-=m[l.first[j-1]-1][l.first[j]-1];
                temp2+=m[l.first[j-1]-1][l.first[i]-1];
                temp2+=m[l.first[i]-1][l.first[j]-1];
                if(temp2 < temp)
                {
                    temp = temp2;
                    pos.first = i;
                    pos.second = j;
                }
            }
            else if(i < j)
            {
                temp2-=m[l.first[i-1]-1][l.first[i]-1];
                temp2-=m[l.first[i]-1][l.first[i+1]-1];
                temp2+=m[l.first[i-1]-1][l.first[i+1]-1];
                temp2-=m[l.first[j]-1][l.first[j+1]-1];
                temp2+=m[l.first[i]-1][l.first[j+1]-1];
                temp2+=m[l.first[j]-1][l.first[i]-1];
                if(temp2 < temp)
                {
                    temp = temp2;
                    pos.first = i;
                    pos.second = j;
                }
            }
        }
    }
    if(pos.first > -1 && pos.second > -1)
    {
        pushVertice(pos.first, pos.second, l);
        l.second = temp;
        return 1;
    }
    else
    {
        return 0;
    }   
}

void pushVertice(int posAntiga, int posNova, pair<int*,int>& l)
{
    int aux = l.first[posAntiga];
    if(posNova < posAntiga)
    {
        for(int i = posAntiga-1; i >= posNova; i--)
        {
            l.first[i+1] = l.first[i];
        }
    }
    else
    {
        for(int i = posAntiga+1; i <= posNova; i++)
        {
            l.first[i-1] = l.first[i];
        }
    }
    
    l.first[posNova] = aux;
}

int VND(int vert, pair<int*,int>& l, int **m)
{
    int temp = INT_MAX;
    while(true)
    {
        while(refinamento2Opt(vert,l,m));
        refinamentoReinsercao(vert,l,m);
        if(l.second < temp)
        {
            temp = l.second;
        }
        else
        {
            return temp;
        }
    }
}

int multiStart(int vert, pair<int*,int>& l, int **m, int inicio, int times)
{
    int temp = INT_MAX;
    for(int i = 0; i < times; i++)
    {
        construcaoAleatoria(vert, l, m, inicio);
        VND(vert, l, m);
        if(l.second < temp)
        {
            temp = l.second;
        }
    }
    return temp;
}

int partition(pair<int,int>*& v, int start, int end)
{
    int pivot = start, i = start, j = end, temp1, temp2;
    while(i < j)
    {
        while(v[i].second <= v[pivot].second && i <= end)
        {
            i++;
        }
        while(v[j].second > v[pivot].second && j >= start)
        {
            j--;
        }
        if(i < j)
        {
            temp1 = v[i].second;
            v[i].second = v[j].second;
            v[j].second = temp1;
            temp2 = v[i].first;
            v[i].first = v[j].first;
            v[j].first = temp2;
        }
    }
    temp1 = v[j].second;
    v[j].second = v[pivot].second;
    v[pivot].second = temp1;
    temp2 = v[j].first;
    v[j].first = v[pivot].first;
    v[pivot].first = temp2;

    return j;
}

void quickSort(pair<int,int>*& v, int start, int end)
{
    if(start < end)
    {
        int pivot = partition(v, start, end);
        quickSort(v, start, pivot-1);
        quickSort(v, pivot+1, end);
    }
}