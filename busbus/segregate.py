from PIL import Image
import os

def create_directories(base_path):
    landscape_dir = os.path.join(base_path, 'landscape')
    portrait_dir = os.path.join(base_path, 'portrait')

    if not os.path.exists(landscape_dir):
        os.makedirs(landscape_dir)

    if not os.path.exists(portrait_dir):
        os.makedirs(portrait_dir)

    return landscape_dir, portrait_dir

def segregate_images(base_path):
    landscape_dir, portrait_dir = create_directories(base_path)

    for filename in os.listdir(base_path):
        file_path = os.path.join(base_path, filename)
        if os.path.isfile(file_path) and not filename.lower().endswith('.heic'):
            with Image.open(file_path) as img:
                width, height = img.size
                if width > height:
                    img.save(os.path.join(landscape_dir, filename))
                else:
                    img.save(os.path.join(portrait_dir, filename))

if __name__ == "__main__":
    # Replace 'your_image_folder_path' with the path to the folder containing your images
    base_path = "D:/Editing/Clips for editing/dump_2024/trimmed_vids"
    segregate_images(base_path)
