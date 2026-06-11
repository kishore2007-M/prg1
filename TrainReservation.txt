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
        string source;
        string designation;
};
vector<passenger>passengers;
int nextticketno=1001;

//          BOOKING TICKET
void bookticket()
{
    passenger p;

    p.ticketno = nextticketno++;

    cout<<"\nEnter the name: ";
    cin>>p.name;

    cout<<"\nEnter the Age: ";
    cin>>p.age;

    cout<<"\nEnter the Source: ";
    cin>>p.source;

    cout<<"\nEnter the designation: ";
    cin>>p.designation;

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
        cout<<"\nname: "<< passengers[i].name;
        cout<<"\nAge: "<< passengers[i].age;
        cout<<"\nsource: "<< passengers[i].source;
        cout<<"\ndesgination: "<< passengers[i].designation;
        cout<<"================================";
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
            cout << "Name        : " << passengers[i].name << endl;
            cout << "Age         : " << passengers[i].age << endl;
            cout << "Source      : " << passengers[i].source << endl;
            cout << "Destination : " << passengers[i].designation << endl;
            return;
        }
        else
        {
            cout<<"Ticket Not Found.....";
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

int main()
{
    int choice;

    do
    {
        cout<<"\n\n=========Railway Reservation System==============\n";
        cout<<"1.Book Ticket\n";
        cout<<"2.view Ticket\n";
        cout<<"3.search ticket\n";
        cout<<"4.cancel ticket\n";
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
