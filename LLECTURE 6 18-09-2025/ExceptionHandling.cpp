/*
An exception is an unexpected problem that arises during the execution of a program.
Our program terminates suddenly with some errors/issues. Exception occurs during running of the program

The try keyword represents a block of code that may throw an exception placed inside the try block. It's followed by one or more catch blocks.
If an exception occurs, try block throws that exception

The catch statement represents a block of code that is executed when a particular exception is thrown from the try block.
The code to handle the exception is written inside the catch block.

An exception in c++ can be thrown using the throw keyword.
When a program encounters a throw statement, then it immediately terminates the current function and starts finding a matching catch block to handle the thrown exception.
*/

#include<iostream>
#include<new>
#include<exception>
using namespace std;

class exceptions{
    protected:
    string message;

    public:
    exceptions(string message){
        this->message = message;
    }

    string what(){
        return message;
    }
};

class runtime_errors : public exceptions{
    public:
    runtime_errors(const string &message): exceptions(message){}
};

class Customer{
    string name;
    int bal,account_number;
    public:

    Customer(string name,int bal,int account_number){
        this->name = name;
        this->bal = bal;
        this->account_number = account_number;
    };

    // Deposit
    void deposit(int amount){
        
        if(amount>0){
            bal += amount;
            cout<<amount<<" rs is credited successfully."<<endl;
        }
        else throw runtime_error("Amount should be greater than 0\n");
    }

    // Withdraw
    void withdraw(int amount){
        if(amount>0 && amount<=bal){
            bal -= amount;
            cout<<amount<<" is debited successfully.";
        }
        else if(amount<0) throw runtime_error("Amount should be greater than 0\n");
        else throw runtime_error("Your balance is low.");
    }
};

// int main(){
//     Customer c1("Prince",5000,10);
//     try{
//         c1.deposit(100);
//         c1.withdraw(6000);
//     }
//     catch(const char *e){
//         cout<<"Enception Occured : "<<e<<endl;
//     }

//     try{
//         int *ptr = new int[1000000000];
//         cout<<"Memory allocation succeed"<<endl;
//         delete []ptr;
//     }
//     catch(const runtime_error &e){
//         cout<<"Exception Occured : "<<e.what()<<endl;
//     }
// }

int main(){
    try{
        int *ptr = new int[1000000000]; // still big but not insane
        cout<<"Memory allocation succeed"<<endl;
        delete []ptr;
    }
    catch(const bad_alloc &e){
        cout<<"Exception Occurred: "<<e.what()<<endl;
    }
}