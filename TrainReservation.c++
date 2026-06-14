#include<iostream>
#include<vector>
#include<string>

using namespace std;

class passenger
{
    public:
        int ticketno;
        string name;
        int age;
        string ageCategory;
        string source;
        string sourceDate;
        string designation;
        string desigDate;
        char gender;
        string classtype;
        int fare=250;
        int pnr;
};
vector<passenger>passengers;

//          BOOKING TICKET
void bookticket()
{
    int i,nextticketno;
    passenger p;
    cout<<"\nEnter the ticket no: ";
    cin>>nextticketno;

    for(int i=0;i<passengers.size();i++)
    {
        if(passengers[i].ticketno == nextticketno)
        {
            cout<<"\nTicket Number Already Exists!";
            cout<<"\nPlease Enter Another Ticket Number.\n";
            return;
        }
    }

    p.ticketno = nextticketno++;

    cout<<"\nEnter the name: ";
    cin>>p.name;

    cout<<"\nEnter the Age: ";
    cin>>p.age;

    cout<<"\nEnter the Source: ";
    cin>>p.source;
   
   
   cout<<"\nEnter the Sourcedate: ";
   cin>>p.sourceDate;

   
   cout<<"\nEnter the designation: ";
    cin>>p.designation;
   
   
   cout<<"\nEnter the Designation Date: ";
    cin>>p.desigDate;
    
    //       calculate pnr numbner

    cout<<"\nEnter the pnr number: ";
    cin>>p.pnr;
    

    cout<<"\nEnter the gender(M/F): ";
    cin>>p.gender;

//             gender qualification

     if(p.gender=='m'|| p.gender=='M')
    {
        cout<<"\nMale";
    }
    else if(p.gender=='F' || p.gender=='f')
    {
        cout<<"\nFemale";
    }
    else
    {
        cout<<"\nInvalid Gender";
    }
            // Age Category

    if(p.age<18)
    {
        p.ageCategory="Child";
    }
    else if(p.age>=60)
    {
        p.ageCategory="Senior Citizen";
    }
    else
    {
        p.ageCategory="Adult";
    }
    cout<<"Age Category: "<<p.ageCategory<<endl;

            //sleeper or AC

    cout<<"\nEnter the classtype: ";
    cin>>p.classtype;

    if(p.classtype=="AC" || p.classtype=="Ac"||p.classtype=="ac")
    {
        p.fare=1200;
    }
    else if(p.classtype=="Sleeper")
    {
        p.fare=300;
    }
    else
    {
        cout<<"Reserved"<<endl;
    }
    
    cout<<"Fare: "<<p.fare<<endl;
    
    passengers.push_back(p);

    cout<<"Ticket Booked Successfully..."<<endl;
    cout<<"\nTicket Number: "<< p.ticketno << endl;
}
//         VEIW TICKET
void viewTickets()
{
    if(passengers.empty())
    {
        cout<<"Ticket not found...";
        return;
    }
    cout<<"Ticket Available..";
    for(int i=0;i<passengers.size();i++)
    {
        cout<<"===========ticket==============";
        
        cout<<"\nTicketno: "<< passengers[i].ticketno;
        cout<<"\nPNR Number: "<<passengers[i].pnr;
        cout<<"\nname: "<< passengers[i].name;
        cout<<"\nAge: "<< passengers[i].age;
        cout<<"\nAge Category: "<< passengers[i].ageCategory;
        cout<<"\nGender: "<< passengers[i].gender;
        cout<<"\nClass Type:  "<<passengers[i].classtype;
        cout<<"\nsource: "<< passengers[i].source;
        cout<<"\nSource Date: "<<passengers[i].sourceDate;
        cout<<"\ndesgination: "<< passengers[i].designation;
        cout<<"\nDesignation date: "<<passengers[i].desigDate;
        cout<<"\n================================";
    }
    cout<<endl;
}
//              search ticket
void searchticket()
{
    int ticketno;
    cout<<"Enter the ticket number: ";
    cin>>ticketno;

    for(int i=0;i<passengers.size();i++)
    {
        if(passengers[i].ticketno == ticketno)
        {
            cout<<"\nTicket Found.....";
            cout<<"\nTicketno: "<< passengers[i].ticketno<<endl;
            cout<<"\nPNR Number: "<<passengers[i].pnr<<endl;
            cout <<"\nName        : " << passengers[i].name << endl;
            cout <<"\nAge         : " << passengers[i].age << endl;
             cout<<"\nAge Category: "<< passengers[i].ageCategory<<endl;
            cout<<"\nGender       : "<< passengers[i].gender<<endl;
            cout<<"\nClasss Type  : "<< passengers[i].classtype<<endl;
            cout <<"\nSource      : " << passengers[i].source << endl;
            cout <<"\nDestination : " << passengers[i].designation << endl;
            return;
        }
    }
    cout<<"Ticket not found....";
}
//              cancel ticket
void cancelticket()
{
    int ticketno;

    cout<<"Enter the ticketno: ";
    cin>>ticketno;

    for(int i=0;i<passengers.size();i++)
    {
        if(passengers[i].ticketno == ticketno)
        {
            passengers.erase(passengers.begin()+i);
            cout<<"\nTicket Cancelled Successfully....";
            return;
        }
    }
    cout<<"Ticket Cannot Canceled...";
}
bool login()
{
    string username,password;

    for(int i=0;i<=3;i++)
    {
        cout<<"\nUsername: ";
        cin>>username;
        cout<<"\npassword: ";
        cin>>password;

        if(username=="INDIAN-RAILWAYS" && password=="1234")
        {
              cout<<"\nLogin Successfully...!";
              return true;
        }
    cout<<"\nLogin Unsuccessfull  and Attempt Lefts..."<< 2-i <<endl;
    }
    return false;
}
int main()
{
    int choice;
    if (login()==1)
    {
        cout<<"Welcome";
    }
    else{
        cout<<"Acess denied";
        return 0;
    }

    do
    {
        cout<<"\n\n=========Railway Reservation System==============\n";
        cout<<"1.Book Ticket\n";
        cout<<"2.view Ticket\n";
        cout<<"3.search ticket\n";
        cout<<"4.cancel ticket\n";
<<<<<<< HEAD
        cout<<"5.Search Pnr\n";
=======
>>>>>>> 1828dbde46219c41f412aff7bbdd86246504f2c4
        cout<<"5.exit\n";

        cout<<"\nEnter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                bookticket();
                break;
            case 2:
                viewTickets();            
                break;
            case 3:
                searchticket();
                break;
            case 4:
                cancelticket();
                break;
            case 5:
                cout<<"Exiting!!  Thanking You.....";
                break;
            default:
                cout<<"Invalid Choice...";
        }
    }while (choice !=5);
    return 0;
    
}
