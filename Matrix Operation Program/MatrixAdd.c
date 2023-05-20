#include<stdio.h>
#include<stdlib.h>

void printMatrix(int rows,int columns,int matrix[rows][columns])
{
    for(int row=0;row<rows;row++)
    {
        for(int column=0;column<columns;column++)
            printf("%d ", matrix[row][column]);
        printf("\n");
    }
}

void addition()
{
    int rows,columns;
    int nMatrices;
    printf("NUMBER OF MATRICES:");
    scanf("%d", &nMatrices);
    printf("ENTER NUMBER OF ROWS:");
    scanf("%d", &rows);
    printf("ENTER NUMBER OF COLUMNS:");
    scanf("%d", &columns);
    int result[rows][columns];
    for(int row=0;row<rows;row++)
        for(int column=0;column<columns;column++)
            result[row][column]=0;
    for(int nthMatrix=1;nthMatrix<=nMatrices;nthMatrix++)
    {
        printf("MATRIX %d\n", nthMatrix);
        int input;
        int matrix[rows][columns];
        for(int row=0;row<rows;row++)
        {
            for(int column=0;column<columns;column++)
            {
                printf("MATRIX%d[%d][%d]:",nthMatrix,row,column);
                scanf("%d", &input);
                matrix[row][column]=input;
                result[row][column]+=input;
            }
        }
        printMatrix(rows,columns,matrix);
    }
    printf("THE RESULTANT MATRIX:-\n");
    printMatrix(rows,columns,result);
}

void subraction()
{
    int rows,columns;
    int nMatrices;
    printf("NUMBER OF MATRICES:");
    scanf("%d", &nMatrices);
    printf("ENTER NUMBER OF ROWS:");
    scanf("%d", &rows);
    printf("ENTER NUMBER OF COLUMNS:");
    scanf("%d", &columns);
    int result[rows][columns];
    for(int nthMatrix=1;nthMatrix<=nMatrices;nthMatrix++)
    {
        printf("MATRIX %d\n", nthMatrix);
        int input;
        int matrix[rows][columns];
        for(int row=0;row<rows;row++)
        {
            for(int column=0;column<columns;column++)
            {
                printf("MATRIX%d[%d][%d]:",nthMatrix,row,column);
                scanf("%d", &input);
                matrix[row][column]=input;
                if(nthMatrix!=1)
                    result[row][column]-=input;
                else
                    result[row][column]=input;
            }
        }
        printMatrix(rows,columns,matrix);
    }
    printf("THE RESULTANT MATRIX:-\n");
    printMatrix(rows,columns,result);
}

void multiplication()
{
    int row1,column1,row2,column2;
    printf("MATRIX1:-\n");
    printf("ENTER THE NUMBER OF ROWS:");
    scanf("%d",&row1);
    printf("ENTER THE NUMBER OF COLUMNs:");
    scanf("%d", &column1);
    int matrix1[row1][column1];
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<column1;j++)
        {
            printf("MATRIX[%d][%d]:",i,j);
            scanf("%d", &matrix1[i][j]);
        }
    }
    printMatrix(row1,column1,matrix1);
    printf("MATRIX2:\n");
    printf("ENTER THE NUMBER OF ROWS:");
    scanf("%d", &row2);
    printf("ENTER THE NUMBER OF COLUMNS:");
    scanf("%d", &column2);
    int matrix2[row2][column2];
    for(int i=0;i<row2;i++)
    {
        for(int j=0;j<column2;j++)
        {
            printf("MATRIX[%d][%d]:",i,j);
            scanf("%d", &matrix2[i][j]);
        }
    }
    printMatrix(row2,column2,matrix2);
    int result[row1][column2];
    for(int i=0;i<row1;i++)
    {
        for(int j=0;j<column2;j++)
        {
            result[i][j]=0;
            for(int k=0;k<column1;k++)
                result[i][j]+=(matrix1[i][k]*matrix2[k][j]);
        }
    }
    printf("RESULTANT MATRIX:-\n");
    printMatrix(row1,column2,result);
}

void division()
{
    int row,column,divider;
    printf("ENTER THE NUMBER OF ROWS:");
    scanf("%d", &row);
    printf("ENTER THE NUMBER OF COLUMNS:");
    scanf("%d", &column);
    int matrix[row][column];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            printf("MATRIX[%d][%d]:", i,j);
            scanf("%d", &matrix[i][j]);
        }
    }
    printMatrix(row,column,matrix);
    printf("ENTER THE DENOMINATOR:");
    scanf("%d", &divider);
    int result[row][column];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            result[i][j]=matrix[i][j]/divider;
        }
    }
    printf("RESULTANT MATRIX:-\n");
    printMatrix(row,column,result);
}

int determinantofMatrix(int call,int row,int column,int matrix[row][column])
{
    int result=0;
    int newMatrix[row-1][column-1];
    int iNMrow=0,iNMcolumn=0;
    // printf("CALL:%d\nREPEATING:--------------------\n",call);
    if(row>2)
    {
        for(int i=0;i<column;i++)
        {
            // printf("CALL:%d\ni:%d\nITERATING-------------------\n",call,i);
            iNMrow=0,iNMcolumn=0;
            for(int r=1;r<row;r++)
            {
                for(int c=0;c<column;c++)
                {
                    if(c!=i)
                    {
                        newMatrix[iNMrow][iNMcolumn++]=0;
                    }
                }
                iNMcolumn=0;
                iNMrow++;
            }
            iNMrow=0,iNMcolumn=0;
            for(int r=1;r<row;r++)
            {
                for(int c=0;c<column;c++)
                {
                    if(c!=i)
                    {
                        newMatrix[iNMrow][iNMcolumn++]=matrix[r][c];
                    }
                }
                iNMcolumn=0;
                iNMrow++;
            }
            // printMatrix(row-1,column-1,newMatrix);
            if(i%2==0)
            { 
                result=result+(matrix[0][i] * (determinantofMatrix(call+1,row-1,column-1,newMatrix)));
                // printf("CALL:%d\ni:%d\nRESULT:%d\n", call,i,result);
            }
            else
            {
                result=result-(matrix[0][i] * (determinantofMatrix(call+1,row-1,column-1,newMatrix)));
                // printf("CALL:%d\ni:%d\nRESULT:%d\n", call,i,result);
            }
        }
        // printf("CALL:%d\nTHE DETERMINANT :%d\n",call, result);
        return result;
    }
    else
    {
        result=(matrix[0][0]*matrix[1][1])-(matrix[0][1]*matrix[1][0]);
        // printf("CALL:%d\n%d\n", call,result);
        return result;
    }
}

int main()
{
    int loop=1;
    while(loop)
    {
        int choice;
        printf("MATRIX OPERATIONS:\n1.ADDITION\n2.SUBRACTION\n3.MULTIPLICATION\n4.DIVISION\n5.DETERMINANT\n6.EXIT\n");
        printf("ENTER YOUR CHOICE:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                addition();
                break;
            }
            case 2:
            {
                subraction();
                break;
            }
            case 3:
            {
                multiplication();
                break;
            }
            case 4:
            {
                division();
                break;
            }
            case 5:
            {
                int row,column;
                printf("ENTER THE ROW:");
                scanf("%d", &row);
                column=row;
                int matrix[row][column];
                for(int i=0;i<row;i++)
                {
                    for(int j=0;j<column;j++)
                    {
                        printf("MATRIX[%d][%d]:",i,j);
                        scanf("%d", &matrix[i][j]);
                    }
                }
                printMatrix(row,column,matrix);
                int answer=determinantofMatrix(0,row,column,matrix);
                printf("DETERMINANT:%d\n", answer);
                break;
            }
            case 6:
            {
                loop=0;
                break;
            }
        }
    }
    printf("-------------------------");
}