//
//  main.cpp
//  Project 2
//
//  Created by Dorothy Ntende on 6/26/23.
//

#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLUMNS = 5;
 
//int matrix[ROW_SIZE][COLUMN_SIZE];

enum GameOption {
    displayLeft=1,
    displayRight=2,
    Guess=3,
    Reset=4,
    Exit=5
};

void guess(int& guess,int& points,int& int1,int& int2, int matrix2[][COLUMNS]);

bool allZeros(int matrix[][COLUMNS]);
void eliminate(int & guess,int matrix[][COLUMNS],int matrix2[][COLUMNS]);

void showMatrix(int & guess,int matrix[][COLUMNS],int matrix2[][COLUMNS]);
string getName(string name)
{
    char a;
    for(int i = 0 ; i<name.length(); i++)              //this is to check if the name is valid
        {
            a= name.at(i);
            while(!isalpha(a)&&!isspace(a))
            {
                
                cout<<"enter a valid username"<<endl;
                getline(cin,name);
                for(int i = 0 ; i<name.length(); i++)
                {
                    a= name.at(i);
                }
                
                
            }
        }
    return name;
    
}

void genShowMatix(int matrix[ROWS][COLUMNS]);


void  genHideMatrix(int& lower_bound , int& upper_bound,int matrix2[ROWS][COLUMNS])
{
   
    
    lower_bound = (rand()%100)+100;
    upper_bound = (rand()%100)+200;
   cout<<endl;
    
   // cout << lower_bound << " " << upper_bound<<endl;
    
   // int matrix[ROW_SIZE][COLUMN_SIZE];
    
   for(int i = 0 ; i < ROWS; i++)
    {
        for(int j =0; j < COLUMNS; j++)
        {
            
            matrix2[i][j] = (rand()%((upper_bound-lower_bound+1)))+lower_bound;
        }
    }
    cout <<endl;
    for(int i = 0 ; i <ROWS; i++)
    {
        for(int j =0; j <COLUMNS; j++)
        {
           cout<<  matrix2[i][j] << " ";
        }
        cout <<endl;
    }
    cout <<endl;
}
void initialization (int& lower_bound , int& upper_bound,int matrix2[ROWS][COLUMNS]);




int main(int argc, const char * argv[])
{
     int matrix[ROWS][COLUMNS];
    int matrix2[ROWS][COLUMNS];
    
    
   // int matrix[ROW_SIZE][COLUMN_SIZE];
    srand(time(NULL));
    string name;
    cout <<"enter a name\n";
    getline(cin,name);
    getName(name);
    
    cout <<"your name is "<< name<<endl;

    genShowMatix(matrix);
    
    
    int points,lower_bound, upper_bound,int1,int2;
    int1=-1;
    int2=-2;
    points = 100;
    
    int gamechoice ;
    cout<<"enter you choice\n";
    cin >>gamechoice;
    
   
    
    
    while(points >0)
    {
        int guess;
        genHideMatrix(lower_bound, upper_bound,matrix2);
        switch(gamechoice)
        {
                
            case displayLeft:
                
                
                break;
            case displayRight:
                
                break;
            case Guess:
            
                cout<< "guess a number\n";
                cin >>guess;
                
                
                
                eliminate(guess,matrix,matrix2);
                
                break;
            case Reset:
                
                initialization(lower_bound , upper_bound,matrix2);
                points--;
                break;
            case Exit:
                
                break;
                
        }
        
        int num_guess;
        
        showMatrix(guess, matrix, matrix2);
        cout<<"current points balance " << points <<" " <<endl;
                        cout<<"enter your choice ";
                        cin >> gamechoice;
        
        
        
        
    }
    
    
    
    
    
    
    cout << lower_bound<<endl;
    cout<<endl;
    
    
    // insert code here...
    cout << "Hello, World!\n";
    return 0;
}


void genShowMatix(int matrix[ROWS][COLUMNS])
{
    
    for(int i = 0 ; i < ROWS; i++)
    {
        for(int j =0; j < COLUMNS; j++)
        {
            matrix[i][j]=-1;
        }
    }
    for(int i = 0 ; i < ROWS; i++)
    {
        for(int j =0; j <COLUMNS; j++)
        {
           cout<<  matrix[i][j] << " ";
        }
        cout <<endl;
    }

}

void eliminate(int & guess,int matrix[][COLUMNS],int matrix2[][COLUMNS])
{
    for(int i = 0 ; i < ROWS; i++)
                     {
                         for(int j =0; j < COLUMNS; j++)
                         {
                            if(guess == matrix2[i][j])
                            {
                                matrix[i][j]=0;
                            }
                             
                         }
                     }


}
void showMatrix(int& guess,int matrix[][COLUMNS],int matrix2[][COLUMNS])
{
    
    for(int i = 0 ; i < ROWS; i++)
    {
        for(int j =0; j < COLUMNS; j++)
        {
            matrix[i][j]=-1;
        }
    }
    
    
    for(int i = 0 ; i < ROWS; i++)
                     {
                         for(int j =0; j < COLUMNS; j++)
                         {
                            if(guess == matrix2[i][j])
                            {
                                matrix[i][j]=0;
                            }
                             
                         }
                     }
   
    for(int i = 0 ; i < ROWS; i++)
    {
        for(int j =0; j <COLUMNS; j++)
        {
           cout<<  matrix[i][j] << " ";
        }
        cout <<endl;
    }
    
}

void initialization (int& lower_bound , int& upper_bound,int matrix2[ROWS][COLUMNS])
{
    lower_bound = (rand()%100)+100;
    upper_bound = (rand()%100)+200;
   cout<<endl;
    
   // cout << lower_bound << " " << upper_bound<<endl;
    
   // int matrix[ROW_SIZE][COLUMN_SIZE];
    
   for(int i = 0 ; i < ROWS; i++)
    {
        for(int j =0; j < COLUMNS; j++)
        {
            
            matrix2[i][j] = (rand()%((upper_bound-lower_bound+1)))+lower_bound;
        }
    }
    cout <<endl;
    for(int i = 0 ; i <ROWS; i++)
    {
        for(int j =0; j <COLUMNS; j++)
        {
           cout<<  matrix2[i][j] << " ";
        }
        cout <<endl;
    }
    cout <<endl;
}

bool allZeros(int matrix[][COLUMNS])
{
    for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                if (matrix[i][j] != 0) {
                    return false; // Found a non-zero element, return false
                }
            }
        }
        return true; // All elements are zero
}

void guess(int& guess,int& points,int&int1, int& int2, int matrix2[][COLUMNS])
{
    
    for(int i = 0 ; i < ROWS; i++)
                     {
                         for(int j =0; j < COLUMNS; j++)
                         {
                            if(guess == matrix2[i][j]&& (int1==-1&&int2==-1))
                            {
                                cout <<" you guessed correctly and you have not used any bounds\n";
                                points+=5;
                            }
                             
                             
                         }
                     }
}

