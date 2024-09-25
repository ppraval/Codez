#include<bits/stdc++.h>
using namespace std;

class Task
{
    string name;
    string deadline;
    string priority;

    public:
        Task(string name, string deadline, string p) : name(name), deadline(deadline), priority(p) {}

        virtual ~Task() {}

        string getName()
        {
            return name;
        }
        string getDeadline()
        {
            return deadline;
        }
        string getPriority()
        {
            return priority;
        }
        virtual void display()
        {
            cout << "Task: " << name << " Deadline: " << deadline << " priority: " << priority << endl;
        }
};

class ToDo
{
    private:  
        vector<Task*> list;
    public:
        ~ToDo()
        {
            for(Task * t : list)
            {
                delete t;
            }
        }

        void addTask(Task *task)
        {
            list.push_back(task);
        }

        void deleteTask(string task_name)
        {
            list.erase(std::remove_if(list.begin(), list.end(),
            &task_name {
                if (task->getName() == taskName) {
                    delete task;
                    return true;
                }
                return false;
            }), list.end());
        }

        void completeTask(string task_name)
        {
            deleteTask(task_name);
        }

        void showNextTask()
        {
            if(list.empty())
            {
                cout << "No more pending tasks" << endl;
                return;
            }
            auto next_task = min_element(list.begin(), list.end()
            {
                return a->getPriority() < b->getPriority();
            });

            (*next_task)->display();
        }
        void displayAllTasks()
        {
            for(auto t : list)
            {
                t->display();
            }
        }
};

int main()
{
    cout << "I am in so much pain" << endl;
    ToDo todolist;
    todolist.addTask(new Task("Sleep", "2024-09-20", "High"));
    todolist.displayAllTasks();
    return 0;
}