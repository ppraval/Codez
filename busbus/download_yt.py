from pytube import YouTube

# Step 1: Provide the YouTube video URL
video_url = input("Enter the YouTube video URL: ")

# Step 2: Create YouTube object
yt = YouTube(video_url)

# Step 3: Display available streams (progressive = video + audio)
print("\nAvailable video streams:")
streams = yt.streams.filter(progressive=True, file_extension='mp4').order_by('resolution').desc()
for i, stream in enumerate(streams):
    print(f"{i}: {stream.resolution} - {stream.fps}fps - {stream.mime_type}")

# Step 4: Choose a stream to download
choice = int(input("\nEnter the number of the stream you want to download: "))
selected_stream = streams[choice]

# Step 5: Download to specified folder
download_path = r"C:\Users\pprav\Downloads"
print(f"\nDownloading to: {download_path}")
selected_stream.download(output_path=download_path)
print("Download complete!")