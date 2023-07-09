#include<iostream>
using namespace std;
#include<string.h>
#include<list>
#include<algorithm>

class passenger
{
  private:
  string name;//to store the name of the person
  string flight_name;//to store the flight name
  string flight_date;//to store the flight date in mm/dd/yyyy format
  string fromCity;//to store start city 
  string toCity;//to store destination
  bool isReserved;//to store if flight is reserved
  int ticket_no;// to store ticket number

  public:
  passenger()
  {
    name="";
    flight_name="";
    flight_date="";
    fromCity="";
    toCity="";
    isReserved=false;
    ticket_no=0;
  } 
  int get_ticket_no(){return ticket_no;}// to return ticket number
  string get_name(){return name;}//to return name of passenger
  string get_flight_name(){return flight_name;}// to return flight airlines that passenger has booked
  string get_flightDate(){return flight_date;}//to return flight date
  string get_fromCity(){return fromCity;}//to return the starting city
  string get_toCity(){return toCity;}//to return the destination
  bool get_isReserved(){return isReserved;}//to return if flight seat is reserved
  
  void set_details(string nam,string fnam,string fdat,string start_point,string destination)
  {
    //function to set the passenger's details
     name=nam;
     flight_name=fnam;
     flight_date=fdat;
     fromCity=start_point;
     toCity=destination;
     
  }
 
   void set_isReserved(bool b)
   {
     //function to set to true if flight seat is reserved ;else false 
       isReserved=b;
   }
   
  
   friend class flightReserve;// so that flight class can access all members of passenger class
   friend ostream& operator<<(ostream& o,passenger &p);//to make things easier while displaying details
};
 ostream& operator<<(ostream& o,passenger &p)
{
    o<<"TICKET NUMBER:"<<p.get_ticket_no()<<endl;
    o<<"NAME:"<<p.get_name()<<endl;
    o<<"FLIGHT NAME:"<<p.get_flight_name()<<endl;
    o<<"FROM:"<<p.get_fromCity()<<endl;
    o<<"TO:"<<p.get_toCity()<<endl;
    o<<"FLIGHT DATE(MM/DD/YYYY):"<<p.get_flightDate()<<endl;
    return o;
}
class flightReserve
{
   private:
   list<passenger> ll;
   std::list<passenger>::iterator itr;
   int capacity;
   int filledSeats;
   int ticket_no;

   public:
   flightReserve();
   void addPassenger(passenger &p);
   void display();//displays tickets of all passengers of all airlines
   void search(int ticket);//to search for a particular ticket based on ticket number
   void cancel_ticket(int ticket, string flight);//to cancel passenger ticket
   bool listEmpty();//to check is passenger list is empty or not
};
int main()
{ 
  int choice;// to store user choice
  string name,f_name,f_date,f_start,f_destination;
  flightReserve indigo,airasia,airindia,vistara;//objects of flightReserve classs
  passenger pas;//object of class passenger
  std::list<passenger>::iterator itr;//iterator created for the ll.insert(iterator,object) function in STL; 
  do{
    //used do loop specifically so that the loop runs at least once
    cout<<"Airline Reservation System"<<endl;
    cout<<"Enter"<<endl;
    cout<<"1->Reserve a ticket"<<endl;
    cout<<"2->cancel ticket"<<endl;
    cout<<"3->check ticket"<<endl;
    cout<<"4->display passengers ticket"<<endl;
    cout<<"5->Exit Program"<<endl<<endl;
    cout<<"Enter Your Choice:";
    cin>>choice;
    cout<<endl;
       switch(choice)
       {
          case 1:
             //to reserve ticket
             int dd,mm;
             cout<<"Enter Passenger Name:";
             getline(cin,name);
             getline(cin,name);// to get name of passenger
             cout<<endl;
             
             
             cout<<"Enter date of Departure in mm/dd/yyyy format:"<<endl;
             cout<<"Enter MM :";
             cin>>mm;// to get the month of travel
             cout<<endl;
             if(mm<1 || mm>12)
              {
                 cout<<"Month doesn't exist"<<endl;
                 break;
              }
              else{
                cout<<"Enter DD:";
                cin>>dd;// to get date of travel
                if(dd<1 || dd>31)
                {
                  cout<<"Date doesn't Exist"<<endl;
                  break;
                }
                else
                {
                  if(mm==4 ||mm==6 ||mm==9 || mm==11)
                  {
                    if(dd>30)
                     {
                      cout<<"Date doesn't exist"<<endl;
                      break;
                     }
                  }
                  else if(mm==2)
                  {
                    if(dd>28)
                    {
                       cout<<"Date doesn't exist"<<endl;
                       break;
                    }
                  }
                }
              }
              
             f_date=to_string(mm)+"/"+to_string(dd)+"/2023";//converting the numbers to strings to display as one variable
             cout<<endl;
             
             cout<<"Enter Start Point:";
             getline(cin,f_start);
             getline(cin,f_start);//getting the starting point of flight
             transform(f_start.begin(), f_start.end(), f_start.begin(), ::tolower);
             cout<<endl;
             
             cout<<"Enter destination:";
             getline(cin,f_destination);//getting the destination of flight
             transform(f_destination.begin(), f_destination.end(), f_destination.begin(), ::tolower);
             cout<<endl;
             
             int choose1; //to choose desired airlines
             cout<<"Select Flight Service:"<<endl;
             cout<<"1->INDIGO AIRLINES"<<endl;
             cout<<"2->AIR INDIA"<<endl;
             cout<<"3->VISTARA"<<endl;
             cout<<"4->AIR ASIA"<<endl;
             cout<<endl<<"Enter your choice:";
             cin>>choose1;
             cout<<endl;
             switch(choose1)
             {
              //setting flight name based on user's choice
                  case 1:
                  f_name="Indigo";
                  break;
                  case 2:
                  f_name="Air India";
                  break;
                  case 3:
                  f_name="Vistara";
                  break;
                  case 4:
                  f_name="Air Asia";
                  default:
                  cout<<"Invalid choice";
                  f_name="";
             }
             
             if(f_name!="")
             {
                 pas.set_details(name,f_name,f_date,f_start,f_destination);//setting passenger details
                 cout<<endl;
                 
                 if(choose1==1)
                 indigo.addPassenger(pas);//adding passenger to indigo airlines
                 else if(choose1==2)
                 airindia.addPassenger(pas);//adding passenger to airindia airlines
                 else if(choose1==3)
                 vistara.addPassenger(pas);//adding passenger to vistara airlines
                 else
                 airasia.addPassenger(pas);//adding passenger to airasia airlines
             }
            break;
            
          case 2:
          // to cancel a ticket by entering the ticket number and selecting airline
             int temp;//to get ticket number
             cout<<"Enter Ticket Number :";
             cin>>temp;
             cout<<endl;
             
             cout<<"Select Flight Service:"<<endl;
             int choose2;
             cout<<"1->INDIGO AIRLINES"<<endl;
             cout<<"2->AIR INDIA"<<endl;
             cout<<"3->VISTARA"<<endl;
             cout<<"4->AIR ASIA"<<endl;
             cout<<endl<<"Enter your choice:"<<endl;
             cin>>choose2;
             cout<<endl;
             switch(choose2)
             {
                  case 1:
                  f_name="Indigo";
                  break;
                  case 2:
                  f_name="Air India";
                  break;
                  case 3:
                  f_name="Vistara";
                  break;
                  case 4:
                  f_name="Air Asia";
                  default:
                  cout<<"Invalid choice";
                  f_name="";
             }
                 if(choose2==1)
                 indigo.cancel_ticket(temp,f_name);
                 else if(choose2==2)
                 airindia.cancel_ticket(temp,f_name);
                 else if(choose2==3)
                 vistara.cancel_ticket(temp,f_name);
                 else if(choose2==4)
                 airasia.cancel_ticket(temp,f_name);
                 else
                 cout<<"Invalid Details Entered"<<endl;
             break;
          case 3:
          //to check ticket
             int temp2;// to get ticket number
             cout<<"Enter Ticket Number :";
             cin>>temp2;
             cout<<endl;
             
             cout<<"Select Flight Service:"<<endl;
             int choose3;
             cout<<"1->INDIGO AIRLINES"<<endl;
             cout<<"2->AIR INDIA"<<endl;
             cout<<"3->VISTARA"<<endl;
             cout<<"4->AIR ASIA"<<endl;
             cout<<endl<<"Enter your choice:";
             cin>>choose3;
             cout<<endl;
             switch(choose3)
             {
                  case 1:
                  indigo.search(temp2);
                  break;
                  case 2:
                  airindia.search(temp2);
                  break;
                  case 3:
                  vistara.search(temp2);
                  break;
                  case 4:
                  airasia.search(temp2);
                  default:
                  cout<<"Invalid choice";
             }
            break;
          case 4:
            //to display elements of linkedlist
            cout<<"Indigo"<<endl;
            indigo.display();
            cout<<"*********"<<endl;
            cout<<"AirIndia"<<endl;
            airindia.display();
            cout<<"*********"<<endl;
            cout<<"Vistara"<<endl;
            vistara.display();
            cout<<"*********"<<endl;
            cout<<"AirAsia"<<endl;
            airasia.display();
            cout<<"*********"<<endl;
            break;
          case 5:
             break;
          default:
          cout<<"Please choose one of the forementioned choices"<<endl;
       }    
       /*if(!fR.listEmpty())
       {
         //fR.sortList();
       }*/
    } while(choice!=5);  
    return 0;
}
 flightReserve::flightReserve()
   {
    itr=ll.begin();//initializing iterator to begining of linkedlist
    capacity=1000;//only thousand seats per airline
    filledSeats=0;
    ticket_no=0;
   }
   void flightReserve::addPassenger(passenger &p)
   {
     
     if(filledSeats<capacity)
      {
          
         if(p.get_toCity()!=p.get_fromCity()) 
         {
          /*Only if seats are available and the destination and starting are not same , it will proceed to ticket booking*/
          filledSeats++;
          ticket_no=filledSeats;
          p.ticket_no=ticket_no;
          ll.insert(itr,p);
          itr++;
          p.set_isReserved(true);
          cout<<"Flight Reserved"<<endl;
          cout<<"Ticket Number :"<<ticket_no<<endl;
         }
         else
         {
           cout<<"Destination and Starting point cannot be the same"<<endl;
         }
       }
     else
     {
      cout<<"Flight Not Reserved...Seats Full"<<endl;
     }
   }

   void flightReserve::display()
   {
     //to display all tickets of a particular airlines
     if(!(ll.empty()))
      { for(auto it=ll.begin();it!=ll.end();it++)
         {
           cout<<*it<<endl;
         }
      }
      else
      cout<<"No Tickets booked yet"<<endl;//if no tickets are booked from that airline
   }
  void flightReserve::search(int ticket)
   {
    //searching for a ticket by taking the ticket number
       int flag=0;
       for(auto it=ll.begin();it!=ll.end();it++)
       {
           if(ticket==it->ticket_no)
           {
               cout<<*it<<endl;
               flag=1;
               break;
           }
       }
       if(flag==0)
        cout<<"Ticket Not found.....Please check the details entered correctly"<<endl;
   }
   void flightReserve::cancel_ticket(int ticket, string flight)
   {
      //to remove the passenger and the node storing his details 
        for(auto it=ll.begin();it!=ll.end();it++)
        {
           if(ticket==it->ticket_no && flight==it->flight_name)
           {
                   itr--;
                   ll.erase(it);
                   capacity++;
                   break;
           }
        }
        cout<<"Ticket Cancelled"<<endl;
   }
   bool flightReserve::listEmpty(){return ll.empty();}
