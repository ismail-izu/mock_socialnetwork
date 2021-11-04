/**********

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*********/

#include <iostream>
#include<string>
#include<cstdio>
#include<conio.h>
#include <cstring>
int n = 0;

using namespace std;

class user
{
  public:string name;
  int height;
  int age;
  string hobbies;
  string gender;
  string password;
  int id = 1;
  bool status = false;
  string friendname[10];
  int friendid[10];
  int fcount=0;
  void SignUp ()
  {
    n++;


    cout << "\nEnter your name: ";
    cin >> name;
    while (name == "")
      {
	cout << "\n name cannot be null: ";
	cout << "\nEnter your name: ";
	cin >> name;
      }

    cout << "Enter your height: ";
    cin >> height;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Enter your hobbies: ";
    cin >> hobbies;
    cout << "Enter your gender (M/F): ";
    cin >> gender;
    cout << "Enter your password: ";
    cin >> password;


    id++;


  }
  void AddFriend(int id,string name){
    friendid[fcount]=id;
    friendname[fcount]=name;
    fcount++;
  }
  void Login ()
  {

    string pass;
    cout << "\nEnter your password: ";
    cin >> pass;
    if (pass == password)
      {
	cout << "Login Success ";
	status = true;
      }
    else
      {
	cout << "Login Failed ";
	status = false;
      }


  }

  void LogOut ()
  {
    status = false;
  }

  void PrintDetails ()
  {
    cout << "\nName: " << name;
    cout << "\nHeight: " << height;
    cout << "\nAge: " << age;
    cout << "\nHobbies: " << hobbies;
    cout << "\nGender (M/F): " << gender;
  }
  
  void DisplayFriends(){
      cout<<"\n";
      if(fcount==0){
          cout<<"No Friends to Display";
          return;
      }
      for(int i=0;i<fcount;i++){
          cout<<friendid[i]<<" ";
      }
  }

  bool searchUserByName (string name1, user x)
  {

    if (x.name == name1)
      return true;

    return false;
  }
  
  bool searchUserByAge(int age1, user x){
      if (x.age==age1)
      return true;
      return false;
  }


    bool searchUserByHobby(string hobby1, user x){
      if (x.hobbies==hobby1)
      return true;
      return false;
  }


};


int
searchUserByName (string name, string users[10])
{
  bool flag = false;
  int i;
  for (i = 0; i < n; i++)
    {

      if (users[i] == name)
	{
	  cout << "user found ";
	  cout << "id=" << i;
	  flag = true;
	  return i;
	}


    }
  if (!flag)
    {
      cout << "user not found ";
      return -1;
    }
}

int
searchUserByHobby (string hobby, string users[10])
{
  bool flag = false;
  int i;
  for (i = 0; i < n; i++)
    {

      if (users[i] == hobby)
	{
	  cout << "user found ";
	  cout << "id=" << i;
	  flag = true;
	  return i;
	}


    }
  if (!flag)
    {
      cout << "user not found ";
      return -1;
    }
}

int
searchUserById (int id, string users[10])
{
  if (id < n)
    {
      cout << "\nuser found ";
      cout << "\nid=" << id;
      return id;
    }
  else
    return -1;
}

int
searchUserByAge (int age, int users[10])
{
   bool flag = false;
  int i;
  for (i = 0; i < n; i++)
    {

      if (users[i] == age)
	{
	  cout << "user found ";
	  cout << "id=" << i;
	  flag = true;
	  return i;
	}


    }
  if (!flag)
    {
      cout << "user not found ";
      return -1;
    }
}

int
main ()
{
  int i = 0;
  string name2;
  user U[10];
  string users[10];
  int age[10];
  string hobby[10];



  U[0].SignUp ();
  users[0] = U[0].name;
  age[0]=U[0].age;
  hobby[0]=U[i++].hobbies;

  char ch;
  char choice;
  while (1)
    {
      cout << "\nMENU";
      cout << "\n1.Log In";
      cout << "\n2.Sign Up";
      cout << "\n";
      cout << "\n";
      cout << "\nEnter your choice: ";
      getchar ();
      ch = getchar ();
      cout << "Choice is " << ch;
      int id = 0;
      int searchid = 0;
      int id2;
      int age2;
      string hobby2;
      if (ch == '1')
	{
	  cout << "\nLog In";
	  cout << "\nEnter name: ";
	  cin >> name2;
	  id = searchUserByName (name2, users);
	  if (id == -1)
	    {
	      cout << "\nUser not found";
	    }
	  U[id].Login ();
	  while (U[id].status == true)
	    {
	      cout << "\nMENU";
	      cout << "\n1.Search By Name";
	      cout << "\n2.Search By Id";
	      cout << "\n3.Search By Age";
	      cout << "\n4.Search By Hobbies";
	      cout << "\n5.Print my Details";
	      cout << "\n6.Update Friends";
	      cout << "\n7.Display Friends";
	      cout << "\n8.Log Out";
	      cout << "\nEnter your choice: ";
	      cin >> choice;
	      if (choice == '1')
		{
		  cout << "\nEnter name: ";
		  cin >> name2;
		  searchid = searchUserByName (name2, users);
		  if (searchid == -1)
		    {
		      cout << "\nUser not found";
		    }
		  U[searchid].PrintDetails ();
		}
	      else if (choice == '2')
		{
		  cout << "\nEnter id: ";
		  cin >> id2;
		  searchid = searchUserById (id2, users);
		  if (searchid == -1)
		    {
		      cout << "\nUser not found";
		    }
		  U[searchid].PrintDetails ();
		}
		else if(choice=='3'){
		    cout << "\nEnter Age: ";
		    cin >> age2;
		    searchid = searchUserByAge (age2, age);
		    if (searchid == -1)
		    {
		      cout << "\nUser not found";
		    }
		  U[searchid].PrintDetails ();
		}
		else if(choice=='4'){
		    cout << "\nEnter Hobby: ";
		    cin >> hobby2;
		    searchid = searchUserByHobby(hobby2,hobby);
		    if (searchid == -1)
		    {
		      cout << "\nUser not found";
		    }
		    U[searchid].PrintDetails ();
		}
		else if (choice == '6')
		{
            cout << "\nEnter name: ";
		  cin >> name2;
		  searchid = searchUserByName (name2, users);
		  if (searchid == -1)
		    {
		      cout << "\nUser not found";
		    }
		  U[searchid].PrintDetails ();
		  U[id].AddFriend(U[searchid].id,U[searchid].name);
		}
	      else if (choice == '5')
		{

		  U[id].PrintDetails ();
		}
		else if (choice == '7')
		{

		  U[id].DisplayFriends ();
		}
	      else if (choice == '8')
		{

		  U[id].LogOut ();
		  break;
		}
	    }
	}
      else if (ch == '2')
	{
	  U[i].SignUp ();
	  users[i] = U[i].name;
	  hobby[i]=U[i].hobbies;
	  age[i]=U[i].age;
	  i++;
	}
      else
	break;
    }
  // for(i=0;i<n;i++)
  // {

  //     if(users[i]==name2){
  //         cout<<"user found ";
  //         cout<<"id="<<i;
  //         flag=true;
  //     }


  // }
  // if(!flag)
  // {
  //   cout<<"user not found "; 
  // }

  return 0;
}
