from PIL import Image
import os

def upscale_image(input_path, output_path, upscale_factor):
    with Image.open(input_path) as img:
        # Calculate new size
        new_size = (int(img.width * upscale_factor), int(img.height * upscale_factor))
        # Resize image
        upscaled_img = img.resize(new_size, Image.LANCZOS)
        # Save the upscaled image
        upscaled_img.save(output_path)

# Set your parameters
input_folder = "D:/Editing/Clips for editing/dump_2024/photos_copy"
output_folder = "D:/Editing/Clips for editing/dump_2024/upscaled_images"
upscale_factor = 2  # Example upscale factor

# Create output directory if it doesn't exist
os.makedirs(output_folder, exist_ok=True)

# Loop through each file in the input folder
for filename in os.listdir(input_folder):
    # if filename.endswith('.jpg') or filename.endswith('.png') or filename.endswith('.HEIC'):
    if filename.endswith('.HEIC'):
        input_path = os.path.join(input_folder, filename)
        output_path = os.path.join(output_folder, 'upscaled_' + filename)
        upscale_image(input_path, output_path, upscale_factor)

print("Upscaling complete for all images!")
