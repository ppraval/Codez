import os
import PyPDF2

folder = r"D:\Textbooks\verilog"
total = 0

for f in os.listdir(folder):
    if f.lower().endswith(".pdf"):
        with open(os.path.join(folder, f), "rb") as fp:
            reader = PyPDF2.PdfReader(fp)
            n = len(reader.pages)
            print(f"{f}: {n}")
            total += n

print("Total pages:", total)
