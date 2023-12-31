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
 
enum GameOption {
    displayLeft=1,
    displayRight=2,
    Guess=3,
    Reset=4,
    Exit=5
};
int guess(int& guess1,int& points,int& int1,int& int2, int matrix2[][COLUMNS]);
void setdisplayLeft(int&int1, int& lowerbound);
void setdisplayRight(int&int2, int& upper_bound);
bool allZeros(int matrix[][COLUMNS]);
void eliminate(int & guess1,int matrix[][COLUMNS],int matrix2[][COLUMNS]);
void showMatrix(int & guess1,int matrix[][COLUMNS],int matrix2[][COLUMNS]);
string getName(string&  name)
{
    cout <<"enter a name\n";
    getline(cin,name);
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
    
   for(int i = 0 ; i < ROWS; i++)
    {
        for(int j =0; j < COLUMNS; j++)
        {
            matrix2[i][j] = (rand()%((upper_bound-lower_bound+1)))+lower_bound;
        }
    }
    cout <<endl;
    /*
    for(int i = 0 ; i <ROWS; i++)
    {
        for(int j =0; j <COLUMNS; j++)
        {
           cout<<  matrix2[i][j] << " ";
        }
        cout <<endl;
    }
    cout <<endl;
     */
}
void initialization (int& lower_bound , int& upper_bound,int matrix2[ROWS][COLUMNS]);

int main(int argc, const char * argv[])
{
     int matrix[ROWS][COLUMNS];
    int matrix2[ROWS][COLUMNS];
    
    
    srand(time(NULL));
    string name;
    getName(name);
    cout <<endl;
    cout <<"Hello "<< name<<endl;
    cout <<endl;
    genShowMatix(matrix);
    
    
    int points,lower_bound, upper_bound,int1,int2;
    int1=-1;
    int2=-1;
    points = 100;
    
    int gamechoice ;
    cout <<endl;
    
    cout << int1 << " " << int2<<endl;
    cout <<endl;
    cout <<" enter what game option you want\n displayLeft = 1 \n displayRight = 2 \n Guess = 3\n Change = 4\n or Exit = 5 \n";
    
    cout<<"enter you choice\n";
    cin >>gamechoice;

     genHideMatrix(lower_bound, upper_bound,matrix2);
    
    while(points >0)
    {

        int guess1;
       // genHideMatrix(lower_bound, upper_bound,matrix2);
        switch(gamechoice)
        {
  
            case displayLeft:
                setdisplayLeft(int1,lower_bound);
                points--;
                break;
            case displayRight:
                setdisplayRight(int2, upper_bound);
                points--;
                break;
            case Guess:
                eliminate(guess1,matrix,matrix2);
                guess(guess1, points, int1, int2, matrix2);
         
                break;
            case Reset:
                
                initialization(lower_bound , upper_bound,matrix2);
                points--;
                break;
            case Exit:
                cout << "bye " << name <<endl;
                cout << " final points are " << points<<endl;
                
                exit(0);
                break;
                
        }

        showMatrix(guess1, matrix, matrix2);
        cout <<endl;
        if(allZeros(matrix))
        {
            cout <<" you have won the game"<<endl;
            char playagain;
            cout <<"do you want to play again enter y or n \n";
            cin >>playagain;
            if( playagain == 'y' || playagain == 'Y')
            {
                cout <<"restarting the game\n";
                initialization(lower_bound, upper_bound, matrix2);
            }
            else
            {
                cout <<"thank you for playing the game\n";
                exit(0);
            }
            
        }
 cout <<" enter what game option you want\n displayLeft = 1 \n displayRight = 2 \n Guess = 3\n Change = 4\n or Exit = 5 \n";
                cout << int1 << " " << int2<<endl;

                cout<<"updated points balance " << points <<" " <<endl;
                        cout<<"enter your choice ";
                        cin >> gamechoice;
    
 
        while(gamechoice ==1 &&(int2!=-1))
        {
            cout <<"you have already used your upperbound enter a valid game choice\n";
            cin >> gamechoice;
        }
        while(gamechoice ==2 &&(int1!=-1))
        {
            cout <<"you have already used your upperbound enter a valid game choice\n";
            cin >> gamechoice;
        }
    }
 
    cout << "thank you for playing the game"<<endl;
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

void eliminate(int & guess1,int matrix[][COLUMNS],int matrix2[][COLUMNS])
{
    cout<< "guess a number\n";
     cin >>guess1;
    
    
    for(int i = 0 ; i < ROWS; i++)
                     {
                         for(int j =0; j < COLUMNS; j++)
                         {
                            if(guess1 == matrix2[i][j])
                            {
                                matrix[i][j]=0;
                            }
                             
                         }
                     }


}
void showMatrix(int& guess1,int matrix[][COLUMNS],int matrix2[][COLUMNS])
{
    
    /*for(int i = 0 ; i < ROWS; i++)
    {
        for(int j =0; j < COLUMNS; j++)
        {
            matrix[i][j]=-1;
        }
    }*/
    
    
   for(int i = 0 ; i < ROWS; i++)
                     {
                         for(int j =0; j < COLUMNS; j++)
                         {
                            if(guess1 == matrix2[i][j])
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
void initialization (int& lower_bound , int& upper_bound, int matrix2[ROWS][COLUMNS])
{
    lower_bound = (rand()%100)+100;
    upper_bound = (rand()%100)+200;
   cout<<endl;
  
   for(int i = 0 ; i < ROWS; i++)
    {
        for(int j =0; j < COLUMNS; j++)
        {
          matrix2[i][j] = (rand()%((upper_bound-lower_bound+1)))+lower_bound;
        }
    }
    cout <<endl;
    /*
    for(int i = 0 ; i <ROWS; i++)
    {
        for(int j =0; j <COLUMNS; j++)
        {
           cout<<  matrix2[i][j] << " ";
        }
        cout <<endl;
    }
    cout <<endl;
     */
     
}

bool allZeros(int matrix[][COLUMNS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
            {
                if (matrix[i][j] != 0)
                {
                    return false; // Found a non-zero element, return false
                }
            }
        }
        return true; // All elements are zero
}

int guess(int& guess1,int& points,int&int1, int& int2, int matrix2[][COLUMNS])
{
    
    
    for(int i = 0 ; i < ROWS; i++)
                     {
                         
                         for(int j =0; j < COLUMNS; j++)
                         {
                             if(guess1 == matrix2[i][j]&& (int1==-1&&int2==-1))
                             {
                                 points+=5;
                                 cout<<"You guessed correctly and have not used any bounds. +5 points"<<endl;
                                return points;
                                 break;
                             }
                            }
                     }

    cout <<endl;
    for(int i = 0 ; i < ROWS; i++)
                     {
                         for(int j =0; j < COLUMNS; j++)
                         {
                             if(guess1 == matrix2[i][j]&& (int1!=-1||int2!=-1))
                             {
                                // cout <<" you guessed correctly and you have not used any bounds\n";
                                 points+=1;
                                 cout<<"You guessed correctly. +1 will be added to your points "<<endl;
                                 return points;
                                 break;
                             }
                        }
                         
                     }
    cout <<endl;
    
    for(int i = 0 ; i < ROWS; i++)
                     {
                         
                         for(int j =0; j < COLUMNS; j++)
                         {
                             if(guess1 != matrix2[i][j]&& (int1!=-1||int2!=-1))
                             {
                                // cout <<" you guessed correctly and you have not used any bounds\n";
                                 points-=10;
                                 cout<<"You guessed incorrectly and used an upper or lower bound. -10 points "<<endl;
                                return points;
                                 break;
                             }
                        }

                     }
  
    cout <<endl;
    
    for(int i = 0 ; i < ROWS; i++)
    {
                         for(int j =0; j < COLUMNS; j++)
                         {
                             if((  guess1 != matrix2[i][j] ))
                             {
                                 
                                 points-=1;
                                 cout<<" You guessed incorrectly. You lose 1 point."<<endl;
                                 //guess2= true;
                                 //var4 = true;
                                return points;
                                 break;
                             }
                         }

                     }
    return  points;
}

void setdisplayLeft(int&int1, int& lower_bound)
{
    cout <<"here is the lowerbound\n";
    int1 = lower_bound;
    cout <<endl;
    
}
void setdisplayRight(int&int2, int& upper_bound)
{
    cout <<"here is the upperbound\n";
    int2 = upper_bound;
    cout<<endl;
}
