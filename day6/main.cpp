#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

using namespace std;

struct Task{
    string description;
    bool done;
};

class ToDoList{
    private:
        vector<Task> tasks;
        const string filename = "tasks.txt";

        void clearInputBuffer(){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    public:
        ToDoList(){
            loadFromFile();
        }
        ~ToDoList(){
            saveToFile();
        }

        void addTask(){

            cout<<"Enter task description: ";
            string desc;
            getline(cin, desc);
            if(!desc.empty()){
                tasks.push_back({desc,false});
                cout<<"task added \n";    
            }
            else{
                cout<<"task description can not be empty.\n";
            }

        }

        void viewTasks() const{
            if(tasks.empty()){
                cout<<"\nYour to-do list is empty\n";
                return;
            }
            cout<<"\n-----Your TO-DO List-----\n";
            for(size_t i =0;i<tasks.size();++i){// increments i and return a refernce to the updated value directly wihtout copy of the old value;
                cout<<i+1<<".["<<(tasks[i].done ?"X":" ")<<"]"<<tasks[i].description<<"\n";
            };
            cout<<"---------------------\n";
        }
        void markedComplete(){
            viewTasks();
            if(tasks.empty()) return;
            cout<<"Enter task number to mark as completed: ";
            size_t index;
            if(!(cin >> index) || index< 1|| index >tasks.size()){
                cout<<"Invalid task number.\n";
                clearInputBuffer();
                return;
            }
            clearInputBuffer();
            tasks[index-1].done - true;
            cout<<"Task marked as completed \n";
        }
        void deleteTask(){
            viewTasks();
            if(tasks.empty()) return;
             cout<<"Enter task number to delete";
             size_t index;
             if(!(cin >> index) || index< 1|| index >tasks.size()){
                cout<<"Invalid task number.\n";
                clearInputBuffer();
             }
             clearInputBuffer();
             tasks.erase(tasks.begin()+ (index -1));
             cout<<"task deleted\n";
        }

        void saveToFile() const{
            ofstream outFile(filename);
            if(!outFile) return;

            for(const auto& task: tasks){
                outFile << task.done << "|"<<task.description<<"\n";
        }
        }
        void loadFromFile(){
            ifstream inFile(filename);
            if(!inFile) return;

            tasks.clear();
            string line;
            while (getline(inFile, line)){
                size_t delimiterPos = line.find('|');
                if(delimiterPos != string::npos) {
                    bool completed = (line.substr(0,delimiterPos) == "1") ;
                    string desc = line.substr(delimiterPos + 1);
                    tasks.push_back({desc, completed});
                }
            }
        }

        void run(){
            int choice = 0;
            while(true){
                cout<< "\n1. View Tasks\n"
                    << "2. Add Task\n"
                    << "3. Mark Task Completed\n"
                    << "4. Delete Task\n"
                    << "5. Save & Exit\n"
                    << "Choose an option: ";
                if(!(cin >> choice)){
                    cout<<"Please enter a valid number\n";
                    clearInputBuffer();
                    continue;
                }
                clearInputBuffer();
                switch (choice){
                    case 1: viewTasks(); break;
                    case 2: addTask(); break;
                    case 3: markedComplete(); break;
                    case 4: deleteTask(); break;
                    case 5:
                        saveToFile();
                        cout<<"Tasks saved \n";
                        return;
                    default:
                        cout<<"Invalid option. Try again. \n";
                }
            }
        }

};



int main(){
    ToDoList List;
    List.run();
    return 0;
}