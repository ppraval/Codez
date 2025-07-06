import os
import glob

target_dir = r"E:\Codez\cplusplus"

exe_files = glob.glob(os.path.join(target_dir, "*.exe"))

for file_path in exe_files:
    try:
        os.remove(file_path)
        print(f"Deleted: {file_path}")
    except Exception as e:
        print(f"Failed to delete {file_path}: {e}")