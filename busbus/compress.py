import subprocess

def compress_video(input_file, output_file):
    try:
        subprocess.run([
            'ffmpeg', 
            '-i', input_file, 
            '-vf', 'scale=1920:1080', 
            '-c:v', 'libx264', 
            '-crf', '23', 
            '-preset', 'medium', 
            '-c:a', 'copy', 
            output_file
        ], check=True)
        print("Video compressed successfully.")
    except subprocess.CalledProcessError as e:
        print(f"Error occurred: {e}")

input_video = 'E:\Videos\SE_course_project\IMG_2609.MOV'
output_video = 'part4.mov'

compress_video(input_video, output_video)
