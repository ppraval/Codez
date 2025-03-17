from graphviz import Digraph

def generate_er_diagram():
    dot = Digraph('ER Diagram', filename='er_diagram', format='png')
    
    # Entities
    dot.node('DoctoralStudent', shape='box')
    dot.node('Supervisor', shape='box')
    dot.node('PhDCoordinator', shape='box')
    dot.node('Exam', shape='box')
    dot.node('ExamRequest', shape='box')
    dot.node('SWAYAMRegistration', shape='box')
    dot.node('Feedback', shape='box')
    dot.node('Document', shape='box')
    dot.node('Course', shape='box')
    
    # Relationships
    dot.edge('DoctoralStudent', 'ExamRequest', label='Submits')
    dot.edge('ExamRequest', 'Exam', label='For Exam')
    dot.edge('DoctoralStudent', 'SWAYAMRegistration', label='Registers')
    dot.edge('DoctoralStudent', 'Feedback', label='Submits')
    dot.edge('Feedback', 'Supervisor', label='To')
    dot.edge('DoctoralStudent', 'Document', label='Uploads')
    dot.edge('DoctoralStudent', 'Course', label='Requests')
    dot.edge('Supervisor', 'ExamRequest', label='Approves')
    dot.edge('PhDCoordinator', 'Exam', label='Publishes')
    
    dot.render()
    

def generate_class_diagram():
    dot = Digraph('Class Diagram', filename='class_diagram', format='png')
    
    # Classes
    dot.node('DoctoralStudent', """DoctoralStudent|+ studentID: int\n+ name: String\n+ email: String\n+ login()\n+ register()\n+ submitExamRequest()""", shape='record')
    dot.node('Supervisor', """Supervisor|+ supervisorID: int\n+ name: String\n+ email: String\n+ approveExamRequest()\n+ provideFeedback()""", shape='record')
    dot.node('PhDCoordinator', """PhDCoordinator|+ coordinatorID: int\n+ name: String\n+ email: String\n+ manageSWAYAMRegistration()\n+ publishExamResults()""", shape='record')
    dot.node('Exam', """Exam|+ examID: int\n+ examName: String\n+ examDate: Date""", shape='record')
    dot.node('ExamRequest', """ExamRequest|+ requestID: int\n+ status: String""", shape='record')
    dot.node('SWAYAMRegistration', """SWAYAMRegistration|+ registrationID: int\n+ status: String""", shape='record')
    dot.node('Feedback', """Feedback|+ feedbackID: int\n+ content: String""", shape='record')
    dot.node('Document', """Document|+ documentID: int\n+ title: String\n+ category: String""", shape='record')
    dot.node('Course', """Course|+ courseID: int\n+ courseName: String""", shape='record')
    
    # Relationships
    dot.edge('DoctoralStudent', 'ExamRequest', label='Submits')
    dot.edge('ExamRequest', 'Exam', label='For Exam')
    dot.edge('DoctoralStudent', 'SWAYAMRegistration', label='Registers')
    dot.edge('DoctoralStudent', 'Feedback', label='Submits')
    dot.edge('Feedback', 'Supervisor', label='To')
    dot.edge('DoctoralStudent', 'Document', label='Uploads')
    dot.edge('DoctoralStudent', 'Course', label='Requests')
    dot.edge('Supervisor', 'ExamRequest', label='Approves')
    dot.edge('PhDCoordinator', 'Exam', label='Publishes')
    
    dot.render()

generate_er_diagram()
generate_class_diagram()