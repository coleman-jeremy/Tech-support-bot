// tech_support.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <thread>
using namespace std;

//typewriter effect

void type(string text, int delay = 50)
{
    for (char c : text)
    {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;
}

// script

int main()
{
    string issue;
    string restart;
    bool transfer = false;

    type("Hello, my name is Xara.");
    cout << endl;
    type("I'm sorry you're having a problem with your device today.");
    cout << endl;
    type("Please tell me about your device's issue and I'll do my best to resolve your problem.");
    cout << endl;
    cin.ignore();
    getline(cin, issue);
    cout << endl;
    type("Thinking...");
    cout << endl;
    type("Thinking...");
    cout << endl;
    type("Thinking...");
    cout << endl;
    type("I show that the most likely fix would be to restart your device.");
    cout << endl;
    type("Have you tried restarting your device yet?");
    cout << endl;
    getline(cin, restart);
    cout << endl;
  
    while (restart != "Yes" && restart != "yes" && restart != "No" && restart != "no")
    {
        type("Please answer 'Yes' or 'No'.");
        cout << endl;
        getline(cin, restart);
        cout << endl;
    } 
        
    while (restart == "No" || restart == "no")
    {
        transfer = false;
        type("Please restart your device now.");
        cout << endl;
        type("Waiting...");
        cout << endl;
        type("Waiting...");
        cout << endl;
        type("Waiting...");
        cout << endl;
        type("Have you restarted your device?");
        cout << endl;           
        getline(cin, restart);
        cout << endl;
    }


    if (restart == "Yes" || restart == "yes")
    {
         transfer = true;
         type("I see, if that didn't resolve your issue then let me escalate this and transfer you to one of our tech support agents.");
         cout << endl;
         type("Transfering...");
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
