/*
In Second year Computer Engineering class of M students, set A of students play cricket and
set B of students play badminton. Write C/C++ program to find and display

i.Set of students who play either cricket or badminton or both

ii. Set of students who play both cricket and badminton

iii. Set of students who play only cricket

iv. Set of students who play only badminton

v. Number of students who play neither cricket nor badminton
 (Note- While realizing the set duplicate entries are to avoided)

*/
/*

Instructions:
The code uses STL,
It uses:
SET
Vector

Refer comments in all functions and specially Neither_Nor function for clarity.
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class sports{
    /*
    by default members of class are private and it is good programming to have private members. Fundamentals of OOP
    */
    int total;
    int badminton;
    int cricket;
    /*
    Use of vectors has been done to dynamically have the number of players at runtime. As handling them is easy
    e.g. vector<int> A;
    use of vector is same as arrays for e.g. A[1], A[2] and so on.

    Use of Pointers to dynamically add player numbers yields garbage values at times.
    e.g.
    int *A, and then dynamically allocating value to it. A = new int(10);

    Static arrays can be helpful only when the number of players is known beforehand. e.g. int A[20];
    */
    vector<int> Total;
    vector<int> Badminton ;
    vector<int>Cricket;
public:
    void initiator_fn();
    void Either_Both();
    void Cricket_Badminton();
    void Cricket_only();
    void Badminton_only();
    void Neither_Nor();
};


void sports::Neither_Nor(){
    /*A set has been used in every function . Set only allows unique values to go into it. Therefore taking union of
    2 sets is very easy
    For e.g.
    A = {1,2,4,3}
    B = {1,4,6}
    If we want union of these two then with insert
    using A values
    insert(1)
    insert(2)
    insert(4)
    insert(3)
    using B values
    insert(1) -- it wont insert as set in C++ (STL) takes only unique elements
    insert(4) -- not allowed
    insert(6) -- done
    final result will be {1,2,4,3,6}
    */
    set<int> Union;
    int flag = 0;
    //flag is used as a marker so that if output is zero then it will print no players.
    for(int i = 0; i < cricket ; i++)
        Union.insert(Cricket[i]);

    for(int i = 0; i < badminton ; i++)
        Union.insert(Badminton[i]);
    /*
    find function return an iterator if the value is found in the set Union else it returns end.
    Here I am checking every element of Total vector with the Union .
    So I need all the elements who do not play any game
    All except players
    if the player is in union list do not print it else print.
    */
    for(int i = 0 ; i < total ; i++)
           if(Union.find(Total[i]) == Union.end()){
                cout<<Total[i]<<"  ";
                flag = 1;
    }

    if(flag == 0)
        cout<<"no players";

    cout<<endl;
}

void sports::Badminton_only(){

    set<int> cricket_set;
    int flag = 0;
    for (int i = 0; i < cricket; i++)
        cricket_set.insert(Cricket[i]);

    for (auto i = 0; i < badminton; i++)
        if (cricket_set.find(Badminton[i]) == cricket_set.end()){
            cout << Badminton[i] << " ";
            flag = 1;
    }

    if(flag == 0)
        cout<<"no players";

    cout<<endl;
    cout<<"\nPlayers who play neither badminton nor cricket are: ";
    Neither_Nor();
}

void sports::Cricket_only(){

    set<int> Badminton_set;
    int flag = 0;
   for (int i = 0; i < badminton; i++)
        Badminton_set.insert(Badminton[i]);

    for (auto i = 0; i < cricket; i++)
     if (Badminton_set.find(Cricket[i]) == Badminton_set.end()){
            cout << Cricket[i] << " ";
            flag = 1;
    }

    if(flag == 0)
        cout<<"no players";

    cout<<endl;
    cout<<"\nPlayers who play only badminton are: ";
    Badminton_only();
}
void sports::Cricket_Badminton(){

    set<int> intersection;
    int i;
    int flag = 0;

    for ( i = 0; i < cricket; i++)
        intersection.insert(Cricket[i]);

    for ( i = 0; i < badminton; i++)
    if (intersection.find(Badminton[i]) != intersection.end()){
            cout << Badminton[i] << " ";\
            flag = 1;
    }

    if(flag == 0)
        cout<<"no players";

    cout<<endl;
    cout<<"\nPlayers who play only cricket are: ";
    Cricket_only();

}

void sports::Either_Both(){

   set<int> Union;
   int flag = 0;
   for (int i = 0; i < cricket; i++)
        Union.insert(Cricket[i]);

    for (int i = 0; i < badminton; i++)
        Union.insert(Badminton[i]);

    for (auto it = Union.begin(); it != Union.end(); it++){
        cout << *it << " ";
        flag = 1;
    }
    if(flag == 0)
        cout<<"no players";

    cout<<endl;

    cout<<"\nThe players who play cricket or badminton or both are: ";
    Cricket_Badminton();
}

void sports::initiator_fn(){

    cout<<"Enter total number of students, cricket and badminton players, respectively, followed by their roll numbers.\
    \nDo not enter cricket, badminton players and/or their total more than total students! \
    \nAnd do not enter duplicate values of roll numbers"<<endl;

    cin>>total;
    cin>>cricket;
    cin>>badminton;

    //check if no of players exceed total.
    if(cricket>total || badminton>total || cricket+badminton > 2*total){
        cout<<"The number of players are more than total, exiting.";
        exit(1);
    }

    int input;

    cout<<"Enter all people's roll number's."<<endl;
    for(auto i = 0; i < total ; i++){           //auto keyword automatically detects the type of data type
            cin>>input;
            Total.push_back(input);
    }
//Check if any roll number is duplicate
    sort(Total.begin(),Total.end());
    for(auto i = 0; i < total-1; i++){
        if(Total[i] == Total[i+1]){
            cout<<"Duplicate elements in vector Total. Exiting from code.";
            exit(1);
        }
    }

    cout<<"Enter cricketer's roll number's."<<endl;
    for(auto i = 0; i < cricket ; i++){
            cin>>input;
            Cricket.push_back(input);
    }

    sort(Cricket.begin(),Cricket.end());
    for(auto i = 0; i < cricket-1; i++){
        if(Cricket[i] == Cricket[i+1]){
            cout<<"Duplicate elements in vector Cricket. Exiting from code.";
            exit(1);
        }
    }

    cout<<"Enter badminton guys' roll number's."<<endl;
    for(auto i = 0; i < badminton ; i++){
           cin>>input;
            Badminton.push_back(input);
    }

    sort(Badminton.begin(),Badminton.end());
    for(auto i = 0; i < badminton-1; i++){
        if(Badminton[i] == Badminton[i+1]){
            cout<<"Duplicate elements in vector Badminton. Exiting from code.";
            exit(1);
        }
    }


    cout<<"\nThe players who play either cricket or badminton or both are: ";
    Either_Both();
}


int main(){

    sports obj;
    obj.initiator_fn();
    return 0;
}




/*

Sample output

Enter total number of students, cricket and badminton players, respectively, followed by their roll numbers.
Do not enter cricket, badminton players and/or their total more than total students!
And do not enter duplicate values of roll numbers
5
2
3
Enter all people's roll number's.
1
2
3
4
5
Enter cricketer's roll number's.
2
3
Enter badminton guys' roll number's.
4
5
2

The players who play either cricket or badminton or both are: 2 3 4 5

The players who play cricket or badminton or both are: 2

Players who play only cricket are: 3

Players who play only badminton are: 4 5

Players who play neither badminton nor cricket are: 1

*/
