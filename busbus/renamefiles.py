import os

def rename_files(folder_path):
    # Get list of files in the folder
    files = os.listdir(folder_path)
    
    # Filter out directories and keep only files
    files = [f for f in files if os.path.isfile(os.path.join(folder_path, f))]
    
    # Sort files to ensure consistent order
    files.sort()

    # Loop through the files and rename them
    for index, filename in enumerate(files, start=1):
        # Get file extension
        file_extension = os.path.splitext(filename)[1]
        
        # Generate new file name with index
        new_filename = f"video_{index}{file_extension}"
        
        # Get full path for old and new file names
        old_file_path = os.path.join(folder_path, filename)
        new_file_path = os.path.join(folder_path, new_filename)
        
        # Rename the file
        os.rename(old_file_path, new_file_path)
        print(f"Renamed {filename} to {new_filename}")

# Example usage
folder_path = "D:\Editing\Clips for editing\dump_2024\\videos"  # Replace with the path to your folder
rename_files(folder_path)
