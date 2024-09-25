#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <optional>

// Base class Task
class Task {
protected:
    std::string name;
    std::optional<std::string> deadline;
    std::string priority;

public:
    // Constructor
    Task(const std::string& name, const std::optional<std::string>& deadline, const std::string& priority)
        : name(name), deadline(deadline), priority(priority) {}

    // Virtual destructor
    virtual ~Task() {}

    // Getters
    std::string getName() const { return name; }
    std::optional<std::string> getDeadline() const { return deadline; }
    std::string getPriority() const { return priority; }

    // Virtual function to display task details
    virtual void display() const {
        std::cout << "Task: " << name << ", Priority: " << priority;
        if (deadline) {
            std::cout << ", Deadline: " << *deadline;
        }
        std::cout << std::endl;
    }
};

// Derived class ToDo
class ToDo {
private:
    std::vector<Task*> tasks;

public:
    // Destructor to clean up dynamically allocated tasks
    ~ToDo() {
        for (Task* task : tasks) {
            delete task;
        }
    }

    // Add a task to the list
    void addTask(Task* task) {
        tasks.push_back(task);
    }

    // Delete a task from the list
    void deleteTask(const std::string& taskName) {
        tasks.erase(std::remove_if(tasks.begin(), tasks.end(),
            &taskName {
                if (task->getName() == taskName) {
                    delete task;
                    return true;
                }
                return false;
            }), tasks.end());
    }

    // Complete a task (remove from list)
    void completeTask(const std::string& taskName) {
        deleteTask(taskName);
    }

    // Show the next pending task based on priority
    void showNextTask() const {
        if (tasks.empty()) {
            std::cout << "No tasks pending." << std::endl;
            return;
        }

        auto nextTask = std::min_element(tasks.begin(), tasks.end(),
             {
                return a->getPriority() < b->getPriority();
            });

        (*nextTask)->display();
    }

    // Display all tasks
    void displayAllTasks() const {
        for (const Task* task : tasks) {
            task->display();
        }
    }
};

int main() {
    ToDo todoList;

    // Adding tasks
    todoList.addTask(new Task("Complete assignment", "2024-09-20", "High"));
    todoList.addTask(new Task("Buy groceries", std::nullopt, "Low"));
    todoList.addTask(new Task("Schedule meeting", "2024-09-18", "Medium"));

    // Display all tasks
    std::cout << "All tasks:" << std::endl;
    todoList.displayAllTasks();

    // Show next task
    std::cout << "\nNext task:" << std::endl;
    todoList.showNextTask();

    // Complete a task
    todoList.completeTask("Buy groceries");

    // Display all tasks after completing one
    std::cout << "\nAll tasks after completing one:" << std::endl;
    todoList.displayAllTasks();

    return 0;
}
