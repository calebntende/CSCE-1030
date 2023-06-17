//
//  main.cpp
//  Project 1
//
//  Created by Dorothy Ntende on 6/16/23.
//

#include <iostream>

using namespace std;

enum GameOption {
    displayLeft=1,
    displayRight=2,
    Guess=3,
    Change=4,
    Exit=5
};




int main()
{
    
    string name1;
    char a ;
    cout << "enter a name\n";
   getline(cin, name1);
   // bool password = true;

    srand(time(NULL));
    
    
  for(int i = 0 ; i<name1.length(); i++)              //this is to check if the name is valid
    {
        a= name1.at(i);
        while(!isalpha(a)&&!isspace(a))
        {
            cout<<"enter a valid username"<<endl;
            getline(cin,name1);
            for(int i = 0 ; i<name1.length(); i++)
            {
                a= name1.at(i);
            }
        }
    }
    
    int rand1= (rand() % +101)+100;            // this is to store random numbers into variable
    int rand2= (rand() % +101)+100;
   
    while ( rand1 > rand2 )
    {
         rand2= (rand() % +101)+100;
        
    }
    
    int int1,int2 ;
    int1= -1;
    int2=-1;
    
    
    
    
    cout <<" enter what game option you want\n displayLeft =1 \n, displayRight =2 \n, Guess = 3\n, Change = 4\n or Exit = 5 \n";
    int gamechoice ;
    cout<<"enter your choice ";
    cin >>gamechoice;
    
    int points = 100;
    
    
    
    while(points > 0)

    {
        //cout << "name: "<<name1<<endl;
      
        
      
        
        int number_guess;
        
        switch (gamechoice)
        {
                
            case displayLeft:
                cout << " here is the lower bound\n";
                int1 = rand1;
                points--;
                
                cout<<endl;
                
                
                break;
            case displayRight:
                cout<<"here is the upper bound\n";
                int2 = rand2;
                
                cout<<endl;
                points--;
                break;
            case Guess:
                cout<< "guess a number in between\n";
                cin >> number_guess;
                
                if((number_guess > rand1 && number_guess<rand2) &&(int1 ==-1 &&int2==-1))
                {
                    cout<<" your point is within range" <<endl;
                    points+=5;
                }
                else if((number_guess > rand1 && number_guess<rand2) &&(int1 ==-1 ||int2==-1))
                {
                    cout<<" your point is within range but you used an upper or lower bound guess" <<endl;
                    points+=1;
                }
                
                else if ((!(number_guess > rand1 && number_guess<rand2))&&(int1 ==-1 ||int2==-1))
                {
                    cout<<"your guess is not within the bounds and you one of the bounds and you used one of the bounds"<<endl;
                    points-=10;
                }
                
                break;
            case Change:
                cout<<"new random numbers\n";
                rand1= (rand() % +101)+100;
                rand2= (rand() % +101)+100;
                while ( rand1 > rand2 )
                {
                    rand2= (rand() % +101)+100;
                    
                }
                int1= -1;
                int2=-1;
                
                points--;
                cout << points <<endl;
                break;
            case Exit:
                //cout<<"bye "<< name1  << " ";
                exit(0);
            default:
                cout << "incorrect option "<<endl;
                break;
        }
        
        
        
        cout << int1 << " " << int2<<endl;
        
        cout <<" enter what game option you want\n displayLeft =1 \n displayRight =2 \n Guess = 3\n Change = 4\n or Exit = 5 \n";
        cout << int1 << " " << int2<<endl;
        cout<<"current points balance " << points <<" " <<endl;
        cout<<"enter your choice ";
        cin >> gamechoice;
        
        while(gamechoice == 2 && int1 !=-1)
        {
            cout<<"error you are trying to get the upperbound"<<endl;
            cout <<"enter another gamechoice that is not 2"<<endl;
            cin>>gamechoice;
        }
        
        while(gamechoice == 1 && int2 !=-1)
        {
            cout<<"error you are trying to get the lowerbound"<<endl;
            cout <<"enter another gamechoice that is not 1"<<endl;
            cin>>gamechoice;
        }
        
        
        
        cout<<endl;
        
        
    }
   
    
    
    cout<<endl;
    //cout << rand2 << endl;
    // insert code here...
    cout<<"you ran out of points "<< name1<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
