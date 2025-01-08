import matplotlib.pyplot as plt

student_marks = {
    'Alice': 85,
    'Bob': 78,
    'Charlie': 92,
    'David': 88,
    'Eva': 76
}

average_marks = sum(student_marks.values()) / len(student_marks)
print(f"Average Marks = {average_marks}")

print("Students scoring above the average:")
for student, marks in student_marks.items():
    if marks > average_marks:
        print(student)

names = list(student_marks.keys())
marks = list(student_marks.values())

plt.bar(names, marks, color='skyblue')
plt.xlabel('Students')
plt.ylabel('Marks')
plt.title('Distribution of Marks')
plt.show()
