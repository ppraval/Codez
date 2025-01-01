import os
from PIL import Image
import pillow_heif

def convert_and_upscale_images(input_folder, output_folder, scale_factor=2):
    if not os.path.exists(output_folder):
        os.makedirs(output_folder)

    for filename in os.listdir(input_folder):
        if filename.lower().endswith('.heic'):
            heic_file_path = os.path.join(input_folder, filename)
            heif_file = pillow_heif.open_heif(heic_file_path)

            # Convert HEIF image to PNG
            image = Image.frombytes(heif_file.mode, heif_file.size, heif_file.data)
            png_filename = f"{os.path.splitext(filename)[0]}.png"
            png_file_path = os.path.join(output_folder, png_filename)
            image.save(png_file_path, format='PNG')

            # Upscale the PNG image
            upscaled_image = image.resize((image.width * scale_factor, image.height * scale_factor), Image.LANCZOS)
            upscaled_file_path = os.path.join(output_folder, f"upscaled_{png_filename}")
            upscaled_image.save(upscaled_file_path)
            
            print(f'Processed: {filename}')

input_folder = "D:/Editing/Clips for editing/dump_2024/photos_copy"
output_folder = "D:/Editing/Clips for editing/dump_2024/upscaled_images"

convert_and_upscale_images(input_folder, output_folder)

print('Batch conversion and upscaling completed!')