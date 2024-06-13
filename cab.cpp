#include<bits/stdc++.h>
using namespace std;
class Cab{
    public:
    int cabId;
    string cabType;
    int cabCapacity;
    float fare;
    bool status;
    string bookname;
    Cab(){};
    Cab(int id, string type, int capacity, float fare){
      cabId = id;
      cabType = type;
      cabCapacity = capacity;
      this->fare = fare;
      status = false;
      bookname = "";
    }
    void cabDetails()
    {
      cout<<"CabID is :"<<cabId<<endl;
      cout<<"CabType is :"<<cabType<<endl;
      cout<<"CabCapacity is :"<<cabCapacity<<endl;
      cout<<"Fare is :"<<fare<<endl;
      cout<<"Cab Status is :"<<status<<endl;
      cout<<"Cab bookingName is :"<<bookname<<endl;
    }
    virtual void bookcab(){};
    virtual void canclecab(){};
    
};
class Trip {
  public:
  int tripId;
  int cabId;
  string passname;
  float distance;
  float driverrating;
  float passrating;
  Trip(){};
  Trip(int id,int cabId, float dist,string name){
    this->tripId = id;
    this->cabId=cabId;
    distance = dist;
    passname= name;
    driverrating=0;
    passrating=0;
  }
  virtual float calFare(int){};
  virtual void startrip(){};
  virtual void endtrip(){};
 
  void driverating(Trip &t)
  {
    float n;
    cout<<"How would you rate Your driver out of 5:"<<endl;
    cin>>n;
    fflush(stdin);
    t.driverrating=n;
  }
  void passengerrating(Trip &t)
  {
    float n;
    cout<<"How would you rate Your passenger out of 5:"<<endl;
    cin>>n;
    fflush(stdin);
    t.passrating=n;
  }
  void dispalytrip()
  {
    cout<<"TripID is: "<<tripId<<endl;
    cout<<"CabID is: "<<cabId<<endl;
    cout<<"Passenger Name is: "<<passname<<endl;
    cout<<"Distance of Trip: "<<distance<<endl;
    cout<<"Passenger Rating of Trip: "<<passrating<<endl;
    cout<<"Driver Rating of Trip: "<<driverrating<<endl;
  }

};
class CabService : public Cab, public Trip {
  public:
  vector<Cab>C;
  vector<Trip>T;
  void addcab()
  {
    int n;
    do{
      Cab c;
      cout<<"Enter Cab ID: ";
      cin>>c.cabId;
      fflush(stdin);
      cout<<"Enter Cab Type: ";
      cin>>c.cabType;
      fflush(stdin);
      cout<<"Enter Cab Capacity: ";
      cin>>c.cabCapacity;
      fflush(stdin);
      cout<<"Enter Cab Fare: ";
      cin>>c.fare;
      fflush(stdin);
      C.push_back(c);
      cout<<"Cab is Added Successfully"<<endl;
      cout<<"Do you want to add more cabs?"<<endl;
      cout<<"[1]-> Yest\t[0]-> No: ";
      cin>>n;
      fflush(stdin);
    }while(n);
    cout<<"Press any key to continue...\n";
    cin.get();
    menu();
  }
  void removecab()
  {
    int n;
    do{
        int id,check=1;
        cout<<"Enter the cab ID to remove the cab:"<<endl;
        cin>>id;
        fflush(stdin);
        if(C.size()==0)
        {
          cout<<"No cabs available to remove"<<endl;
          cout<<"Press any key to continue...\n";
          cin.get();
          menu();
        }
        else
        {
        for(int i=0;i<C.size();i++)
        {
          if(C[i].cabId==id)
          {
            C.erase(C.begin()+i);
            cout<<"Cab is Removed Successfully"<<endl;
            check=0;
          }
        }
          if(check)
          {
            cout<<"Cab does not exist with this ID"<<endl;
          }
        }
      cout<<"Do you want to Remove more cabs?"<<endl;
      cout<<"[1] for Yes & [0] for No?"<<endl;
      cin>>n;
      fflush(stdin);
    }while(n);
    cout<<"Press any key to continue...\n";
    cin.get();
    menu();
  }
  void findCab()
  {
    int id;
    cout<<"Enter the cab ID to find the cab:"<<endl;
    cin>>id;
    fflush(stdin);
    if(C.size()==0)
    {
      cout<<"No cabs available to find"<<endl;
      cout<<"Press any key to continue...\n";
      cin.get();
      menu();
    }
    else
    {
      for(int i=0;i<C.size();i++)
      {
        if(C[i].cabId==id)
        {
          cout<<"Cab Details:"<<endl;
          C[i].cabDetails();
        }
         else
        {
          cout<<"Cab does not exist with this ID"<<endl;
        }
      }
    }
    cout<<"Press any key to continue...\n";
    cin.get();
    menu();
  }
  void freeCab()
  {
    cout<<"Available Cabs :"<<endl;
    int c=0;
    for(int i=0;i<C.size();i++)
    {
      if(!C[i].status)
      {
        C[i].cabDetails();
        cout<<"----------------------\n";
        c++;
      }
    }
    if(c==0)
    {
      cout<<"No Cab is Available Sorry!"<<endl;
    }
    cout<<"Press any key to continue...\n";
    cin.get();
    menu();
  }
  void bookcab()
  {
    int cabId,n,check=1;
    string name;
    do{
        cout<<"Enter the Cab ID you want to book: ";
        cin>>cabId;
        fflush(stdin);
        cout<<"Enter the Passenger Name: ";
        getline(cin,name);
        fflush(stdin);
        for(int i=0;i<C.size();i++)
        {
          if(C[i].cabId==cabId&&C[i].status!=1)
          {
            C[i].bookname=name;
            C[i].status=true;
            check=0;
          }
        }
        if(check)
        { 
          cout<<"Cab is Aready Booked! or Cab does not Exist\nChoose another cab"<<endl; 
        }
        cout<<"Do you want to book more Cab?\n[1]->Yes\t[0]->No :";
        cin>>n;
        fflush(stdin);
    }while(n);
    cout<<"Press any key to continue...\n";
    cin.get();
    menu();
  }
  void canclecab()
  {
    int cabId;
    cout<<"Enter the Cab ID you want to cancel :";
    cin>>cabId;
    fflush(stdin);
    for(int i=0;i<C.size();i++)
    {
      if(C[i].cabId==cabId)
      {
        C[i].status=false;
        C[i].bookname="";
        cout<<"Cab has been Canceld"<<endl;
        break;
      }
    }
    cout<<"Press any key to continue...\n";
    cin.get();
    menu();
  }
  void startrip()
  {
    int pin;
    cout<<"Enter the PIN to start Trip:";
    cin>>pin;
    fflush(stdin);
    int tid,n=1;
    float dis;
    Trip t;
    for(int i=0;i<C.size();i++)
    {
        if(pin==C[i].cabId)
        {
          cout<<"Enter Trip ID:";
          cin>>tid;
          fflush(stdin);
          cout<<"Enter Travel Distance: ";
          cin>>dis;
          fflush(stdin);
          t=Trip(tid,C[i].cabId,dis,C[i].bookname);
          T.push_back(t);
          n=0;
        }
    }
    if(n)
    {
      cout<<"Invalid PIN"<<endl;  
    }
    cout<<"Press any key to continue...\n";
    cin.get();
    menu();
}
  float calfare(int tid)
  {
      for(int i=0;i<T.size();i++)
      {
        if(T[i].tripId==tid)
        {
          float dis=T[i].distance;
          for(int j=0;j<C.size();j++)
          {
            if(T[i].cabId==C[j].cabId)
            {
              return dis*C[j].fare;
              break;
            }
          }
        }
      }
  }
  void endtrip()
  {
      int tid;
      cout<<"Enter the Trip ID: ";
      cin>>tid;
      fflush(stdin);
      cout<<"Please Pay the Amount: "<<calfare(tid)<<endl;
      float amt;
      cin>>amt;
      fflush(stdin);
      if(amt>=calfare(tid))
      {
        cout<<"Payment Successful"<<endl;
      }
      cout<<"The Trip Has been ended successfully :)"<<endl;
      for(int i=0;i<T.size();i++)
      {
        if(T[i].tripId==tid)
        {
          driverating(T[i]);
          passengerrating(T[i]);
          for(int j=0;j<C.size();j++)
          {
            if(T[i].cabId==C[j].cabId)
            {
              C[j].status=false;
              C[j].bookname="";
            }
          }
        }
      }
    cout<<"Press any key to continue...\n";
    cin.get();
    menu();
  }
  void viewAllCab()
  {
    if(C.size()==0)
    {
      cout<<"No Cab is Present"<<endl;
    }
    else
    {
      cout<<"The Details Of All Cabs:"<<endl;
      for(int i=0;i<C.size();i++)
      {
        C[i].cabDetails();
      }
    }
    cout<<"Press any key to continue...\n";
    cin.get();
    menu();
  }
  void viewAllTrips()
  {
    if(T.size()==0)
    {
      cout<<"No Trip is started"<<endl;
    }
    else 
    {
      cout<<"The Details Of All Trips:"<<endl;
      for(int i=0;i<T.size();i++)
      {
        T[i].dispalytrip();
      }
    }
    cout<<"Press any key to continue...\n";
    cin.get();
    menu();
  }
  void menu();
  void Exit();
};
void CabService::Exit()
{
  cout<<"Exiting the Program..."<<endl;
  exit(0);
}
void CabService::menu()
{
  int choice;
  cout<<"------------------"<<endl;
  cout<<"1: Add a Cab"<<endl;
  cout<<"2: Find a Cab"<<endl;
  cout<<"3: Book a Cab"<<endl;
  cout<<"4: Start a Trip"<<endl;
  cout<<"5: End a Trip"<<endl;
  cout<<"6: Cancle a Cab"<<endl;
  cout<<"7: View All Cabs"<<endl;
  cout<<"8: View All Trips"<<endl;
  cout<<"9: Remove a Cab"<<endl;
  cout<<"0: Exit"<<endl;
  cout<<"-------------------"<<endl;
  cout<<"Enter Your Choice: ";
  cin>>choice;
  fflush(stdin);
  switch (choice)
  {
  case 1: addcab();
          break;
  case 2: freeCab();
          break;
  case 3: bookcab();
          break;
  case 4: startrip();
          break;
  case 5: endtrip();
          break;
  case 6: canclecab();
          break;
  case 7: viewAllCab();
          break;
  case 8: viewAllTrips();
          break;
  case 9: removecab();
          break;
  case 0: Exit();
          break;
  default:cout<<"Enter a Valid Option!"<<endl;
          menu();
          break;
  }
}
int main()
{
  CabService cs;
  cout<<"Welcome to Cab Booking System"<<endl;
  cs.menu();
  return 0;
}