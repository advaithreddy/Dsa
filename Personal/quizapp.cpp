#include<iostream>
#include<string>

std::string name;
std::string str;
int mcq;
std::string ans;


signed main(){

    // Title
    std::cout<<"*****************************************************************\n";
    std::cout<<"*      ********       *      *       ********        *******    *\n";
    std::cout<<"*      *      *       *      *          **                *     *\n";
    std::cout<<"*      *      *       *      *          **               *      *\n";
    std::cout<<"*      *     **       *      *          **              *       *\n";
    std::cout<<"*      *********      *      *          **             *        *\n";
    std::cout<<"*              **     ********       ********        *******    *\n";
    std::cout<<"*****************************************************************\n";
    std::cout<<std::endl;
    // Intro
    std::cout<<"Welcome to the Best Quix app\n";
    std::cout<<"Choose any one option\n";
    int choice;
    std::cout<<"1. To start the Quiz app\n";
    std::cout<<"2. Instructions\n";
    std::cout<<"3. Quit the app\n";
    std::cout<<"Enter your choice: ";
    std::cin>>choice;

    // Base
    while(choice != 1 && choice != 3 && choice != 2){
        std::cout<<"\nSorry You choose wrong option Check again\n";
        std::cout<<"Enter again: ";
        std::cin>>choice;
    }

    if(choice == 2){
            std::cout<<"\n     INSTRUCTIONS      \n";
            std::cout<<"\nThis is a Quiz app Made only using C++\n";
            std::cout<<"1. There will be 10 questions\n";
            std::cout<<"2. The Questions will be divided into 5 each\n";
            std::cout<<"3. 5 fill in the blanks and 5 choose the correct answer\n";
            std::cout<<"4. If you answer more then 5 questions wrong the test will automatically close\n";
            std::cout<<std::endl;
            std::cout<<"Now shall we start the quiz\n";
            std::cout<<"Enter '1' to start or '3' to quit\n Enter your choice: ";
            std::cin>>choice;
    }

    while(choice != 1 && choice != 3){
        std::cout<<"\nSorry You choose wrong option Check again\n";
        std::cout<<"Enter again: ";
        std::cin>>choice;
    }

    // app structure
    switch(choice){
        case 1:
            // Quiz app

            std::cout<<"Please enter your name: ";
            std::cin>>name;
            std::cout<<"Hey there I hope you are ready to start the quiz\n";
            std::cout<<std::endl;
            std::cout<<"Enter 'start' If you want to start the Quiz else enter 'end'\n";
            std::cout<<"Please enter the text: ";
            std::cin>>str;

            while (str != "start" && str != "end"){
                std::cout<<"\nInvalid Input Try again\n";
                std::cout<<"Please enter the text: ";
                std::cin>>str;
                if(str == "start" || str == "end"){
                    break;
                }
            }
            

            if(str == "start"){
                int wrong = 5;
                int score = 0;
                int atm = 0;
                while(wrong > 0){
                    std::cout<<"\nFill in the blanks\n";
                    //Q1
                    std::cout<<"\nQuestion 1 \n";
                    std::cout<<"In C++, a class is a ____ that encapsulates data for the object.\n";
                    std::cout<<"Enter your answer (without extra space as a single word): ";
                    std::cin>>ans;
                    atm++;
                    if(ans == "blueprint"){
                        std::cout<<"\nCorrect answer\n";
                        score++;
                    }else{
                        wrong--;
                        std::cout<<"Wrong answer Still "<<wrong<<" can be made wrong after that exam will quit\n";
                        std::cout<<"Correct Answer : Blueprint\n";
                    }
                    // Q2
                    std::cout<<"\nQuestion 2 \n";
                    std::cout<<"A ____ function is defined inside a class.\n";
                    std::cout<<"Enter your answer (without extra space as a single word): ";
                    std::cin>>ans;
                    atm++;
                    if(ans == "member"){
                        std::cout<<"Correct answer\n";
                        score++;
                    }else{
                        wrong--;
                        std::cout<<"Wrong answer Still "<<wrong<<" can be made wrong after that exam will quit\n";
                    }
                    // Q3
                    std::cout<<"\nQuestion 3 \n";
                    std::cout<<"A ____ is a special member function of a class that is executed whenever a new object of it's class is created.\n";
                    std::cout<<"Enter your answer (without extra space as a single word): ";
                    std::cin>>ans;
                    atm++;
                    if(ans == "constructor"){
                        std::cout<<"Correct answer\n";
                        score++;
                    }else{
                        wrong--;
                        std::cout<<"Wrong answer Still "<<wrong<<" can be made wrong after that exam will quit\n";
                    }
                    // Q4
                    std::cout<<"\nQuestion 4 \n";
                    std::cout<<"The keyword used to declare a variable that cannot be modified is ____.\n";
                    std::cout<<"Enter your answer (without extra space as a single word): ";
                    std::cin>>ans;
                    atm++;
                    if(ans == "const"){
                        std::cout<<"Correct answer\n";
                        score++;
                    }else{
                        wrong--;
                        std::cout<<"Wrong answer Still "<<wrong<<" can be made wrong after that exam will quit\n";
                    }
                    // Q5 
                    std::cout<<"\nQuestion 5 \n";
                    std::cout<<"The ____ operator is used to compare two values.\n";
                    std::cout<<"Enter your answer (without extra space as a single word): ";
                    std::cin>>ans;
                    atm++;
                    if(ans == "comparison"){
                        std::cout<<"Correct answer\n";
                        score++;
                    }else{
                        wrong--;
                        if(wrong == 0){
                            std::cout<<"Wrong answer You have lost all your attempts\n";
                            break;
                        }else{
                            std::cout<<"Wrong answer Still "<<wrong<<" can be made wrong after that exam will quit\n";
                        }
                    }
                    std::cout<<"\nHey you have passed the Fill in Blank lets move to MCQ\n";
                    std::cout<<"Still "<<wrong<<" can be made wrong after that exam will quit\n";
                    std::cout<<"\nMultiple Choice Questions\n";
                    // Q6
                    std::cout<<"\nQuestion 6\n";
                    std::cout<<"What does the cin object in C++ handle?\n1. Output\n2. File Handling\n3. Input\n4. Error Handling\n";
                    std::cout<<"Enter your Choice: ";
                    std::cin>>mcq;
                    atm++;
                    if(mcq == 3){
                        std::cout<<"Correct answer\n";
                        score++;
                    }else{
                        wrong--;
                        if(wrong == 0){
                            std::cout<<"Wrong answer You have lost all your attempts\n";
                            break;
                        }else{
                            std::cout<<"Wrong answer Still "<<wrong<<" can be made wrong after that exam will quit\n";
                        }
                    }
                    if(wrong == 0) break;
                    // Q7
                    std::cout<<"\nQuestion 7\n";
                    std::cout<<"Which keyword is used to dynamically allocate memory in C++?\n1. new\n2. malloc\n3. alloc\n4. allocate\n";
                    std::cout<<"Enter your Choice: ";
                    std::cin>>mcq;
                    atm++;
                    if(mcq == 1){
                        std::cout<<"Correct answer\n";
                        score++;
                    }else{
                        wrong--;
                        if(wrong == 0){
                            std::cout<<"Wrong answer You have lost all your attempts\n";
                            break;
                        }else{
                            std::cout<<"Wrong answer Still "<<wrong<<" can be made wrong after that exam will quit\n";
                        }
                    }
                    if(wrong == 0) break;
                    // Q8
                    std::cout<<"\nQuestion 8\n";
                    std::cout<<"Which of the following is a valid way to comment out multiple lines of code in C++?\n1. // This is a comment\n2. /* This is a comment */\n3. # This is a comment\n4. ' This is a comment\n";
                    std::cout<<"Enter your Choice: ";
                    std::cin>>mcq;
                    atm++;
                    if(mcq == 2){
                        std::cout<<"Correct answer\n";
                        score++;
                    }else{
                        wrong--;
                        if(wrong == 0){
                            std::cout<<"Wrong answer You have lost all your attempts\n";
                            break;
                        }else{
                            std::cout<<"Wrong answer Still "<<wrong<<" can be made wrong after that exam will quit\n";
                        }
                    }
                    if(wrong == 0) break;
                    // Q9
                    std::cout<<"\nQuestion 9\n";
                    std::cout<<"What is the purpose of the break statement in a loop?\n1. To exit the loop and continue with the next iteration\n2. To terminate the program\n3. To skip a specific iteration of the loop\n4. To print a message to the console\n";
                    std::cout<<"Enter your Choice: ";
                    std::cin>>mcq;
                    atm++;
                    if(mcq == 1){
                        std::cout<<"Correct answer\n";
                        score++;
                    }else{
                        wrong--;
                        if(wrong == 0){
                            std::cout<<"Wrong answer You have lost all your attempts\n";
                            break;
                        }else{
                            std::cout<<"Wrong answer Still "<<wrong<<" can be made wrong after that exam will quit\n";
                        }
                    }
                    if(wrong == 0) break;
                    // Q10
                    std::cout<<"\nQuestion 10\n";
                    std::cout<<"What is the name of the founder of C++?\n1. Bjarne Stroutsup\n2. Advaith\n3. You\n4. I dont know man\n";
                    std::cout<<"Enter your Choice: ";
                    std::cin>>mcq;
                    atm++;
                    if(mcq == 1){
                        std::cout<<"Correct answer\n";
                        score++;
                    }else{
                        wrong--;
                        if(wrong == 0){
                            std::cout<<"Wrong answer You have lost all your attempts\n";
                            break;
                        }else{
                            std::cout<<"Wrong answer Still "<<wrong<<" can be made wrong after that exam will quit\n";
                        }
                    }
                    wrong = -1;
                }
                std::cout<<"\nHooray You have completed your exam successfully: \n";
                std::cout<<name<<" stats:\n";
                std::cout<<"\tAttempted : "<<atm<<"\n";
                std::cout<<"\tUnattempted : "<<10 - atm<<"\n";
                std::cout<<"\tCorrect : "<<score<<"\n";
                if(wrong == 0){
                    std::cout<<"\tWrong : "<<5<<"\n";
                }else{
                    std::cout<<"\tWrong : "<<10-score<<"\n";
                }
                std::cout<<"All the best for your future endevours\n"; 
            }else{
                std::cout<<"\nOhh you don't want to start It's Ok come after practicing\n";
                std::cout<<std::endl;
            }
            break;
        case 3:
            // quit
            std::cout<<"\nOhh you don't want to start It's Ok come after practicing\n";
            std::cout<<std::endl;
            break;
    }

    std::cout<<std::endl;
    std::cout<<"Thanks for choosing the Best Quiz App\n";

    return 0;
}