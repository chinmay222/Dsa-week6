#include<stdio.h>

#define MAX 5

//have to check the no possible path case.

typedef struct location
{
    int i;
    int j;
} location;

location stack[100];
int tp = -1;

void push(int i, int j)
{
    ++tp;
    stack[tp].i = i;
    stack[tp].j = j;
}
int pop_i()
{
    return stack[tp].i;
}

int pop_j()
{
    return stack[tp--].j;
}

int moves_possible(int maze[][MAX], int solution[][MAX], int curr_i, int curr_j)
{
    if((curr_j < MAX - 1)&&(maze[curr_i][curr_j + 1] == 1) && (solution[curr_i][curr_j+1] == 0))
    {
        return 1;
    }
    else if((curr_i < MAX - 1)&&(maze[curr_i+1][curr_j] == 1)&&(solution[curr_i+1][curr_j] == 0))
    {
        return 1;
    }
    else if((curr_j > 0) && (maze[curr_i][curr_j-1] == 1) && (solution[curr_i][curr_j-1] == 0))
    {
        return 1;
    }
    else if((curr_i > 0) && (maze[curr_i-1][curr_j] == 1) && (solution[curr_i-1][curr_j] == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int path_possible(int solution[][MAX])
{
    int i,j;
    for(i=0; i<MAX; i++)
    {
        for(j=0; j<MAX; j++)
        {
            if(solution[i][j] == 1) return 1;
        }
    }
    return 0;
}

void find_path(int maze[][MAX], int solution[][MAX])
{
    int curr_i = 0;
    int curr_j = 0;
    solution[curr_i][curr_j] = 1;
    while(solution[MAX-1][MAX-1] != 1)
    {
        if((curr_j < MAX-1)&&(maze[curr_i][curr_j + 1] == 1) && (solution[curr_i][curr_j+1] == 0))
        {
            curr_j++;;
            push(curr_i, curr_j);
            solution[curr_i][curr_j] = 1;
        }
        else if((curr_i < MAX-1)&&(maze[curr_i+1][curr_j] == 1)&&(solution[curr_i+1][curr_j] == 0))
        {
            curr_i++;
            push(curr_i, curr_j);
            solution[curr_i][curr_j] = 1;
        }
        else if((curr_j > 0) && (maze[curr_i][curr_j-1] == 1) && (solution[curr_i][curr_j-1] == 0))
        {
            curr_j--;
            push(curr_i, curr_j);
            solution[curr_i][curr_j] = 1;
        }
        else if((curr_i > 0) && (maze[curr_i-1][curr_j] == 1) && (solution[curr_i-1][curr_j] == 0))
        {
            curr_i--;
            push(curr_i, curr_j);
            solution[curr_i][curr_j] = 1;
        }
        else
        {
            solution[curr_i][curr_j] = -1;
            curr_i = pop_i();         //we are here now
            curr_j = pop_j();         //we are here now
            curr_i = pop_i();         // previous location
            curr_j = pop_j();         //previous location
            while(! moves_possible(maze, solution, curr_i, curr_j))
            {
                solution[curr_i][curr_j] = -1;
                curr_i = pop_i();
                curr_j = pop_j();
                if(! path_possible(solution)) break;
            }
        }
        if(! path_possible(solution))
        {
            printf("NO PATH POSSIBLE");
            break;
        }
    }
}

int main()
{
    int maze[MAX][MAX];
    int i,j;
    int solution[MAX][MAX];
    for(i=0; i<MAX; i++)
    {
        for(j=0; j<MAX; j++)
        {
            scanf("%d", &maze[i][j]);
            solution[i][j] = 0;
        }
    }
    find_path(maze, solution);
    if(path_possible(solution))
    {
        printf("**************************\n");
        for(i=0; i<MAX; i++)
        {
            for(j=0; j<MAX; j++)
            {
                if(solution[i][j] == -1)
                {
                    printf("0");
                    printf(" ");
                }
                else
                {
                    printf("%d ", solution[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
